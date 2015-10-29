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
#ifndef __TCP_CONNECTION_H__
#define __TCP_CONNECTION_H__
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if defined(__WIN32__)
#include <winsock.h>
#endif

class tcp_connection
{
public:
  tcp_connection(char *dest_addr, unsigned dest_port, char *local_addr, unsigned local_port, void *other);
  tcp_connection( int listen_sock, void *other );
  virtual ~tcp_connection();
  int isOk() { return( installed ); }; 
  int write( char *data, int len );
  int read( char *data, int len, char *remote_addr, int remote_len, int flags );
  void transfered( LONGLONG *readr, LONGLONG *writew );
  int ready( int why );
  int operator==( tcp_connection &other );
protected:
  LONGLONG readd;
  LONGLONG writed;
  int sock;
  struct sockaddr_in addr;
  struct sockaddr_in local_address;
private:
  int installed;
};

#endif
