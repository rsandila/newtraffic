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
#include "fixed_client.h"

fixed_client::fixed_client( struct client_protocol *proto, int num_proto, struct client_payload *pld, int num_payload, int num_clients )
{
  installed=0;
  workers=NULL;
  num_workers=0;
  my_proto=NULL;
  my_num_proto=0;
  my_pld=NULL;
  my_num_pld=0;
  if (!proto || num_proto<=0 || !pld || num_payload<=0 || !num_clients) return;
  my_proto=proto;
  my_pld=pld;
  my_num_proto=num_proto;
  my_num_pld=num_payload;
  num_workers=num_clients;
  workers=new fixed_workers *[num_workers];
  if (!workers) return;
  for (int cnt=0;cnt<num_workers;cnt++)
    {
      workers[cnt]=new fixed_workers( &(my_proto[cnt%my_num_proto]), &(my_pld[cnt%my_num_pld]) );
      if (!workers[cnt]) return;
      if (!workers[cnt]->isOk()) return;
    }
  installed=1;
}

fixed_client::~fixed_client()
{
  if (workers)
    {
      for (int cnt=0;cnt<num_workers;cnt++)
	{
	  if (workers[cnt]) delete workers[cnt];
	  workers[cnt]=NULL;
	}
      delete []workers;
      workers=NULL;
    }
  my_pld=NULL;
  my_proto=NULL;
}

int fixed_client::Start()
{
  if (!isOk()) return( -1 );
  for (int cnt=0;cnt<num_workers;cnt++)
    {
      if (workers[cnt]->Start()) return( -1 );
    }
  return( 0 );
}

int fixed_client::Stop()
{
  if (!isOk()) return( -1 );
  for (int cnt=0;cnt<num_workers;cnt++)
    {
      if (workers[cnt]->Stop()) return( -1 );
    }
  return( 0 );
}

void fixed_client::GetClientDataTransfered( LONGLONG *readd, LONGLONG *writed )
{
  if (!isOk()) return;
  LONGLONG r, rr, w, ww;
  rr=0;
  ww=0;
  for (int cnt=0;cnt<my_num_proto;cnt++)
    {
      my_proto->proto->TransferedData( my_proto[cnt].proto_handle, my_proto[cnt].connection, &r, &w );
      rr+=r;
      ww+=w;
    }
  if (readd) *readd=rr;
  if (writed) *writed=ww;
}

void fixed_client::ResetClientSequence()
{
  if (!isOk()) return;
  for (int cnt=0;cnt<my_num_pld;cnt++)
    {
      my_pld->pld->ResetPayloadSequence( my_pld->handle );
    }
}
