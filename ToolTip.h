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

#ifndef __TOOLTIP_H__
#define __TOOLTIP_H__

class ToolTip
{
public:
   class Tool 
   {
   public:
      virtual char * GetText() = 0;
      virtual void GetRect(LPRECT rect) = 0;
   };

   ToolTip(HWND hwnd);
   ~ToolTip(void);

   void SetTool(Tool * tool);
   void UnsetTool(Tool * tool);

   void OnGetDispInfo(LPNMTTDISPINFO lpnmtdi);

protected:
   HWND m_hWnd;
   HWND m_hOwnerWnd;
};

#endif /*__TOOLTIP_H__*/
