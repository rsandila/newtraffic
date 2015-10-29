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
#ifndef __LOAD_SERVER_H__
#define __LOAD_SERVER_H__

class server
{
 public:
  server( char *path );
  virtual ~server();
  int isOk() { return( installed ); };
  void *InitServer( struct client_protocol **proto, int num_protocol, struct server_reply **rep, int num_reply );
  void DestroyServer( void *handle );
  int StartServer( void *handle );
  int StopServer( void *handle );
  void ServerTransferedData( void *handle, LONGLONG *readd, LONGLONG *writed );
 protected:
  void *lib_handle;

  void * EXPORT (*MyInitServer)( struct client_protocol **proto, int num_protocol, struct server_reply **rep, int num_reply );
  void  EXPORT (*MyDestroyServer)( void *handle );
  int  EXPORT (*MyStartServer)( void *handle );
  int  EXPORT (*MyStopServer)( void *handle );
  void  EXPORT (*MyServerTransferedData)( void *handle, LONGLONG *readd, LONGLONG *writed );
 private:
  int installed;
};
#endif
