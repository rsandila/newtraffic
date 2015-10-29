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
#include "../../config.h"
#ifdef HAVE_MEMORY_H
#include <memory.h>
#endif
#ifdef HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if defined(__WIN32__)
#include <winsock.h>
#endif

struct ack_packet
{
  char head[4];
  UINT32 size;
};

/*
  Returns a handle to use for all reply function calls
 */
extern "C" void * EXPORT InitReply()
{
  struct ack_packet *ack;
  ack=new struct ack_packet();
  if (!ack) return( NULL );
  memcpy( ack->head, "TRAF", 4 );
  ack->size=htonl( 8 );
  return( ack );
}

/*
  Destroys the handle used for reply's
 */
extern "C" void EXPORT DestroyReply( void *handle )
{
  struct ack_packet *ack;
  if (!handle) return;
  ack=(struct ack_packet *)handle;
  delete ack;
}

/*
  Get's reply packet to send back to client. Uses same header as payload.

  Takes the handle and the received packet as data with it's size.
  Returns a pointer to the reply payload and returns the size of that
  in reply_size
 */
extern "C" char * EXPORT GetReply( void *handle, char *packet, unsigned size, unsigned *reply_size )
{
  if (reply_size) *reply_size=8;
  return( (char *)handle );
}

/*
  Deletes the reply packet as returned by GetReply
 */
extern "C" void  EXPORT DeleteReply( void *handle, char *reply, unsigned reply_size )
{ // do nothing we do the same thing over and over again!
}

