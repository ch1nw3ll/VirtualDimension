/* 
 * Virtual Dimension -  a free, fast, and feature-full virtual desktop manager 
 * for the Microsoft Windows platform.
 * Copyright (C) 2003 Francois Ferrand
 *
 * This program is free software; you can redistribute it and/or modify it under 
 * the terms of the GNU General Public License as published by the Free Software 
 * Foundation; either version 2 of the License, or (at your option) any later 
 * version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with 
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple 
 * Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#include "StdAfx.h"
#include "alwaysontop.h"
#include "settings.h"

AlwaysOnTop::AlwaysOnTop(HWND hWnd): m_hWnd(hWnd), m_ontop(false)
{
   Settings settings;

   SetAlwaysOnTop(settings.LoadAlwaysOnTop());
}

AlwaysOnTop::~AlwaysOnTop(void)
{
   Settings settings;

   settings.SaveAlwaysOnTop(m_ontop);
}

void AlwaysOnTop::SetAlwaysOnTop(bool onTop)
{
   DWORD style;

   if (onTop == m_ontop)
      return;

   m_ontop = onTop;

   if (onTop)
      SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
   else
      SetWindowPos(m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}
