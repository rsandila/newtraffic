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
#ifndef __LOAD_PAYLOAD_H__
#define __LOAD_PAYLOAD_H__

class payload
{
 public:
  payload( char *pathname );
  virtual ~payload();
  int isOk() { return( installed ); };
  void *InitializePayload( unsigned min, unsigned max, unsigned increment, unsigned time, void *other );
  void DestroyPayload( void *handle );
  char *GetPayload( void *handle, unsigned *size );
  void ReleasePayload( void *handle, char *payload );
  void ResetPayloadSequence( void *handle );
 protected:
  void *libhandle;
  void * EXPORT (*MyInitializePayload)( unsigned min, unsigned max, unsigned increment, unsigned time, void *other );
  void  EXPORT (*MyDestroyPayload)( void *handle );
  char * EXPORT (*MyGetPayload)( void *handle, unsigned *size );
  void  EXPORT (*MyReleasePayload)( void *handle, char *payload );
  void  EXPORT (*MyResetPayloadSequence)( void *handle );
 private:
  int installed;
};

/*
 structure to contain an initialized payload with it's handle
 */
struct client_payload
{
  payload *pld;
  void *handle;
};


#endif
