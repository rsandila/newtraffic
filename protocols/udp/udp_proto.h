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
#ifndef __UDP_PROTO_H__
#define __UDP_PROTO_H__

#include "udp_connection.h"
#include "udp_server.h"
#include <deque>

class udp_proto
{
public:
  udp_proto( int client_server );
  virtual ~udp_proto();
  int isOk() { return( installed ); };
  udp_connection *create_connection( char *dest_addr, unsigned dest_port, char *local_addr, unsigned local_port, void *other );
  void destroy_connection( udp_connection *conn, int waiting );
  int write( udp_connection *conn, char *data, int len );
  int read( udp_connection *conn, char *data, int len, char *remote_addr, int remote_len, int flags );
  udp_server *listen( unsigned port, unsigned num_connections, void *other );
  void destroy_server( udp_server *serv, int waiting );
  udp_connection *accept( udp_server *serv, void *other );
  void transfered( udp_connection *conn, LONGLONG *read, LONGLONG *write );
  int ready( void *handle, int why );
protected:
  LONGLONG dead_read;
  LONGLONG dead_write;
  std::deque <udp_connection *> connections;
  std::deque <udp_server *> servers;
private:
  int installed;
};

#endif
