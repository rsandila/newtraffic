/*
 * Copyright (C) 2003 Robert Sandilands (Pty) Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
USA.
 */
#include "../../config.h"
#include "fixed_workers.h"

fixed_workers::fixed_workers( struct client_protocol *prot, struct client_payload *pay )
{
  installed=0;
  if (!MThread::isOk()) return; 
  if (!prot || !pay) return;
  myprot=prot;
  mypay=pay;
  installed=1;
}

#if defined(__WIN32__)
_fastcall fixed_workers::~fixed_workers()
#else
fixed_workers::~fixed_workers()
#endif
{
 Stop();
}

void *fixed_workers::Run()
{
  if (!isOk()) return( NULL );
  while (!stopping)
    {
      char *buf;
      unsigned size;
      
      buf=mypay->pld->GetPayload( mypay->handle, &size );
      if (buf)
	{
	  int result;
	  result=myprot->proto->SendConnectionData( myprot->proto_handle, myprot->connection, buf, size );
	  mypay->pld->ReleasePayload( mypay->handle, buf );
	  if (result>0)
	    {
	      buf=new char[size];
	      if (!buf)
		{ // Ok, not enough memory now... Let's sleep and hope there is available a bit later?
#if defined(__WIN32__)
          Sleep( 1000 );
#else
		  sleep( 1 );
#endif
		  buf=new char[size];
		}
	      if (buf)
		{
		  result=myprot->proto->ReadPacketData( myprot->proto_handle, myprot->connection, buf, size, NULL, 0 );
		  delete []buf;
		  if (result<0)
		    { // ok, could not read reply... We have to close down.. either server died or things very confused
		      return( NULL );
		    }
		}
	      else
		{ // We did not have enough memory to read the reply... We have to close down, we will hang because server will get confused
		  return( NULL );
		}
	    }
	  else
	    { // did not send data... Why? server died? Too much data in the queue? We have to close down, we will hang server?
	      return( NULL );
	    }
	}
      else
	{ // We did not get a payload... A temporary out of memory issue? Let's try again?
	}
    }
  return( NULL );
}

void * fixed_workers::Stop()
{
  // TODO: destroy protocol
  return( MThread::Stop() );
}

