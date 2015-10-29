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
#ifndef __SERVER_LISTENER_H__
#define __SERVER_LISTENER_H__

#include "../../os/os.h"
#include "../../protocols/loadprotocol.h"
#include "../../reply/loadreply.h"
#include "server_client.h"
#include <deque>

class server_listener: public MThread
{
 public:
  server_listener( struct client_protocol *prot, struct server_reply *rep );
#if defined(__WIN32__)
  _fastcall virtual ~server_listener();
#else
  virtual ~server_listener();
#endif
  int isOk() { return( installed ); };
  void TransferedData( LONGLONG *readd, LONGLONG *writed );
 protected:
  struct client_protocol *proto; 
  struct server_reply *sreply;
  std::deque<server_client *> clients;

  virtual void *Run();
 private:
  int installed;
};

#endif
