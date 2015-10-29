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
#include "../config.h"
#include "../os/os.h"
#include "loadreply.h"

reply::reply( char *pathname )
{
  installed=0;
  libhandle=NULL;

  libhandle=import_dynamic_library( pathname );
  if (!libhandle)
    {
      return;
    }
  MyInitReply=(void * EXPORT (*)())import_dynamic_symbol( libhandle, "InitReply" );
  if (!MyInitReply) return;
  MyDestroyReply=(void  EXPORT (*)( void *handle ))import_dynamic_symbol( libhandle, "DestroyReply" );
  if (!MyDestroyReply) return;
  MyGetReply=(char * EXPORT (*)( void *handle, char *packet, unsigned size, unsigned *reply_size ))import_dynamic_symbol( libhandle, "GetReply" );
  if (!MyGetReply) return;
  MyDeleteReply=(void  EXPORT (*)( void *handle, char *reply, unsigned reply_size ))import_dynamic_symbol( libhandle, "DeleteReply" );
  if (!MyDeleteReply) return;
  installed=1;
}

reply::~reply()
{
  if (libhandle) close_dynamic_library( libhandle );
  libhandle=NULL;
}

void *reply::InitReply()
{
  if (!isOk()) return( NULL );
  return( (*MyInitReply)() );
}

void reply::DestroyReply( void *handle )
{
  if (!isOk()) return;
  (*MyDestroyReply)( handle );
}

char *reply::GetReply( void *handle, char *packet, unsigned size, unsigned *reply_size )
{
  if (!isOk()) return( NULL );
  return( (*MyGetReply)( handle, packet, size, reply_size ) );
}

void reply::DeleteReply( void *handle, char *reply, unsigned reply_size )
{
  if (!isOk()) return;
  (*MyDeleteReply)( handle, reply, reply_size );
}
