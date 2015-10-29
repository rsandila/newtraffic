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
#ifndef __FIXED_WORKERS_H__
#define __FIXED_WORKERS_H__

#include "../../protocols/loadprotocol.h"
#include "../../payload/loadpayload.h"
#include "../../os/os.h"

class fixed_workers: public MThread
{
 public:
  fixed_workers( struct client_protocol *prot, struct client_payload *pay );
#if defined(__WIN32__)
  _fastcall virtual ~fixed_workers();
#else
  virtual ~fixed_workers();
#endif
  int isOk() { return( installed ); };

  virtual void * Stop();
 protected:
  struct client_protocol *myprot;
  struct client_payload *mypay;

  void *Run();
 private:
  int installed;
};

#endif
