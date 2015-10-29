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
#ifndef __REPLY_H__
#define __REPLY_H__

/* 
  This is the template for reply types. This is loaded by the server to reply to packets sent by the client
 */

/*
  Returns a handle to use for all reply function calls
 */
extern "C" void *InitReply();

/*
  Destroys the handle used for reply's
 */
void DestroyReply( void *handle );

/*
  Get's reply packet to send back to client. Uses same header as payload.

  Takes the handle and the received packet as data with it's size.
  Returns a pointer to the reply payload and returns the size of that
  in reply_size
 */
char *GetReply( void *handle, char *packet, unsigned size, unsigned *reply_size );

/*
  Deletes the reply packet as returned by GetReply
 */
void DeleteReply( void *handle, char *reply, unsigned reply_size );

#endif
