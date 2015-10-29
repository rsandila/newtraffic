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
#ifndef __LOAD_CLIENTS_H__
#define __LOAD_CLIENTS_H__

#include "../protocols/loadprotocol.h"
#include "../payload/loadpayload.h"

class client
{
 public:
  client( char *pathname );
  virtual ~client();
  int isOk() { return( installed ); };
  void *InitClient( struct client_protocol *proto, int num_proto, struct client_payload *pld, int num_payload, int min, int max, int incr, int time );
  void DestroyClient( void *handle );
  int StartClient( void *handle );
  int StopClient( void *handle );
  void GetClientDataTransfered( void *handle, LONGLONG *readd, LONGLONG *writed );
  void ResetClientSequence( void *handle );
 protected:
  void *libhandle;
  void * EXPORT (*MyInitClient)( struct client_protocol *proto, int num_proto, struct client_payload *pld, int num_payload, int min, int max, int incr, int time );
  void  EXPORT (*MyDestroyClient)( void *handle );
  int  EXPORT (*MyStartClient)( void *handle );
  int  EXPORT (*MyStopClient)( void *handle );
  void  EXPORT (*MyGetClientDataTransfered)( void *handle, LONGLONG *readd, LONGLONG *writed );
  void  EXPORT (*MyResetClientSequence)( void *handle );
 private:
  int installed;
};

#endif
