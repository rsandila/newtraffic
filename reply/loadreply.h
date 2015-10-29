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
#ifndef __LOAD_REPLY_H__
#define __LOAD_REPLY_H__

class reply
{
 public:
  reply( char *pathname );
  virtual ~reply();
  int isOk() { return( installed ); };
  void *InitReply();
  void DestroyReply( void *handle );
  char *GetReply( void *handle, char *packet, unsigned size, unsigned *reply_size );
  void DeleteReply( void *handle, char *reply, unsigned reply_size );
 protected:  
  void *libhandle;
  void * EXPORT (*MyInitReply)();
  void  EXPORT (*MyDestroyReply)( void *handle );
  char * EXPORT (*MyGetReply)( void *handle, char *packet, unsigned size, unsigned *reply_size );
  void  EXPORT (*MyDeleteReply)( void *handle, char *reply, unsigned reply_size );
 private:
  int installed;
};

struct server_reply
{
  reply *rep;
};

#endif
