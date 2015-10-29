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
#ifndef __UDP_SERVER_H__
#define __UDP_SERVER_H__

#include "udp_connection.h"

class udp_server
{
public:
  udp_server( unsigned port, unsigned num_connections, void *other );
  virtual ~udp_server();
  int isOk() { return( installed ); };
  udp_connection *accept( void *other );
  int ready( int why );
  int operator==( udp_server &other );
protected:
  int sock;
  struct sockaddr_in addr;

  int server_ok;
private:
  int installed;
};

#endif
