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
#ifndef __FIXED_CLIENT_H__
#define __FIXED_CLIENT_H__

#include "fixed_workers.h"

class fixed_client
{
public:
  fixed_client( struct client_protocol *proto, int num_proto, struct client_payload *pld, int num_payload, int num_clients );
  virtual ~fixed_client();
  int isOk() { return( installed ); };
  int Start();
  int Stop();
  void GetClientDataTransfered( LONGLONG *readd, LONGLONG *writed );
  void ResetClientSequence();
protected:
  fixed_workers **workers;
  int num_workers;
  struct client_protocol *my_proto;
  int my_num_proto;
  struct client_payload *my_pld;
  int my_num_pld;
private:
  int installed;
};

#endif
