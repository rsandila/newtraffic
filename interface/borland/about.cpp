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
//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "about.h"
#if defined(_ISCLIENT)
#include "client_gui.h"
#endif
#if defined(_ISSERVER)
#include "server_gui.h"
#endif
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::OKButtonClick(TObject *Sender)
{
  AboutBox->Visible=false;
#if defined(_ISCLIENT)
  TrafficClientForm->Enabled=true;
#else
#if defined(_ISSERVER)
  ServerGuiForm->Enabled=true;
#else
#error This must be defined
#endif
#endif
}
//---------------------------------------------------------------------------

