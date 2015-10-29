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
#ifndef __SERVER_H__
#define __SERVER_H__

#include "../include/loadprotocol.h"
#include "../include/loadreply.h"

/*
 Template for servers
 */

/*
  This initializes the server with the needed protocol and reply structures. Returns a handle
 */
extern "C" void *InitServer( struct client_protocol **proto, int num_protocol, struct server_reply **rep, int num_reply );

/*
  This stops the server
 */
extern "C" void DestroyServer( void *handle );

/*
  This starts the server listening for clients
 */
extern "C" int StartServer( void *handle );

/*
  This stops the server listening for clients
 */
extern "C" int StopServer( void *handle );

/*
  This get's the total data transfered by this server
 */
extern "C" void ServerTransferedData( void *handle, long long *readd, long long *writed );

#endif
