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
#include "loadpayload.h"

payload::payload( char *pathname )
{
  installed=0;
  libhandle=NULL;

  libhandle=import_dynamic_library( pathname );
  if (!libhandle)
    {
      return;
    }
  MyInitializePayload=(void * EXPORT (*)( unsigned min, unsigned max, unsigned increment, unsigned time, void *other ))import_dynamic_symbol( libhandle, "InitializePayload" );
  if (!MyInitializePayload) return;
  MyDestroyPayload=(void  EXPORT (*)( void *handle ))import_dynamic_symbol( libhandle, "DestroyPayload" );
  if (!MyDestroyPayload) return;
  MyGetPayload=(char * EXPORT (*)( void *handle, unsigned *size ))import_dynamic_symbol( libhandle, "GetPayload" );
  if (!MyGetPayload) return;
  MyReleasePayload=(void  EXPORT (*)( void *handle, char *payload ))import_dynamic_symbol( libhandle, "ReleasePayload" );
  if (!MyReleasePayload) return;
  MyResetPayloadSequence=(void  EXPORT (*)( void *handle ))import_dynamic_symbol( libhandle, "ResetPayloadSequence" );
  if (!MyResetPayloadSequence) return;
  installed=1;
}

payload::~payload()
{
  if (libhandle) close_dynamic_library( libhandle );
  libhandle=NULL;
}

void *payload::InitializePayload( unsigned min, unsigned max, unsigned increment, unsigned time, void *other )
{
  if (!isOk()) return( NULL );
  return( (*MyInitializePayload)( min, max, increment, time, other ) );
}

void payload::DestroyPayload( void *handle )
{
  if (!isOk()) return;
  (*MyDestroyPayload)( handle );
}

char *payload::GetPayload( void *handle, unsigned *size )
{
  if (!isOk()) return( NULL );
  return( (*MyGetPayload)( handle, size ) );
}

void payload::ReleasePayload( void *handle, char *payload )
{
  if (!isOk()) return;
  (*MyReleasePayload)( handle, payload );
}

void payload::ResetPayloadSequence( void *handle )
{
  if (!isOk()) return;
  (*MyResetPayloadSequence)( handle );
}
