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
#ifndef __TCP_PROTO_H__
#define __TCP_PROTO_H__

#include "tcp_connection.h"
#include "tcp_server.h"
#include <deque>

class tcp_proto
{
public:
  tcp_proto( int client_server );
  virtual ~tcp_proto();
  int isOk() { return( installed ); };
  tcp_connection *create_connection( char *dest_addr, unsigned dest_port, char *local_addr, unsigned local_port, void *other );
  void destroy_connection( tcp_connection *conn, int waiting );
  int write( tcp_connection *conn, char *data, int len );
  int read( tcp_connection *conn, char *data, int len, char *remote_addr, int remote_len, int flags );
  tcp_server *listen( unsigned port, unsigned num_connections, void *other );
  void destroy_server( tcp_server *serv, int waiting );
  tcp_connection *accept( tcp_server *serv, void *other );
  void transfered( tcp_connection *conn, LONGLONG *read, LONGLONG *write );
  int ready( void *handle, int why );
protected:
  LONGLONG dead_read;
  LONGLONG dead_write;
  std::deque <tcp_connection *> connections;
  std::deque <tcp_server *> servers;
private:
  int installed;
};

#endif
