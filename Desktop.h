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

#ifndef __DESKTOP_H__
#define __DESKTOP_H__

#include <list>
#include "settings.h"
#include "tooltip.h"
#include <wininet.h>
#include <shlobj.h>
#include <ocidl.h>
#include "HotKeyManager.h"
#include "WallPaper.h"

using namespace std;
class Window;

class Desktop: public ToolTip::Tool, HotKeyManager::EventHandler
{
public:
   Desktop(int i);
   Desktop(Settings::Desktop * desktop);
   ~Desktop(void);

   HMENU BuildMenu();
   void OnMenuItemSelected(HMENU menu, int cmdId);
   
   void Draw(HDC dc);
   void resize(LPRECT rect);
   void UpdateLayout();
   Window* GetWindowFromPoint(int x, int y);
   
   void Rename(char * name);
   void Remove();
   void Save();

   void Activate(void);
   void Desactivate(void);
   bool IsActive() const      { return m_active; }

   int GetHotkey() const      { return m_hotkey; }
   void SetHotkey(int hotkey);

   void SetIndex(int index)   { m_index = index; }
   int GetIndex() const       { return m_index; }

   LPTSTR GetWallpaper()      { return m_wallpaperFile; }
   void SetWallpaper(LPTSTR fileName);

   char * GetText()           { return m_name; }
   void GetRect(LPRECT rect)  { *rect = m_rect; }

   static bool deskOrder(Desktop * first, Desktop * second);

   bool Configure(HWND hDlg);

protected:
   void OnHotkey();

   static LRESULT CALLBACK DeskProperties(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

   bool m_active;

   int m_index;
   char m_name[80];
   int m_hotkey;
   RECT m_rect;
   WallPaper m_wallpaper;
   TCHAR m_wallpaperFile[MAX_PATH];

   class DesktopProperties
   {
   public:
      DesktopProperties(Desktop * desktop);
      ~DesktopProperties();
      void InitDialog(HWND hDlg);
      bool Apply(HWND hDlg);
      void OnWallpaperChanged(HWND hDlg, HWND ctrl);
      void OnBrowseWallpaper(HWND hDlg);
      void OnDrawItem(LPDRAWITEMSTRUCT lpDrawItem);

   protected:
      Desktop * m_desk;
      IPicture * m_picture;
      TCHAR m_wallpaper[MAX_PATH];
   };
};

#endif /*__DESKTOP_H__*/
