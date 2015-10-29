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
#ifndef __SERVER_CLIENT_H__
#define __SERVER_CLIENT_H__

#include "../../os/os.h"
#include "../../reply/loadreply.h"
#include "../../protocols/loadprotocol.h"

#define MAX_BASIC_SERVER_PACKET_SIZE 102400

class server_client: public MThread
{
 public:
  server_client( struct client_protocol *prot, struct server_reply *rep );
#if defined(__WIN32__)
  _fastcall virtual ~server_client();
#else
  virtual ~server_client();
#endif
  int isOk() { return( installed ); };
  void TransferedData( LONGLONG *readd, LONGLONG *writed );
 protected:
  struct server_reply *sreply;
  struct client_protocol *proto;
  void *reply_handle;

  virtual void *Run();
 private:
  int installed;
};
#endif
