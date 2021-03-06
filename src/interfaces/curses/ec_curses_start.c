/*
    ettercap -- curses GUI

    Copyright (C) ALoR & NaGA

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

*/

#include <ec.h>
#include <wdg.h>
#include <ec_curses.h>

/* proto */

static void curses_start_sniffing(void);
static void curses_stop_sniffing(void);

/* globals */

struct wdg_menu menu_start[] = { {"Start",          'S',       "",    NULL},
                                 {"Start sniffing", CTRL('W'), "C-w", curses_start_sniffing},
                                 {"Stop sniffing",  CTRL('E'), "C-e", curses_stop_sniffing},
                                 {"-",              0,         "",    NULL},
                                 {"Exit",           CTRL('X'), "C-x", wdg_exit},
                                 {NULL, 0, NULL, NULL},
                               };

/*******************************************/


static void curses_start_sniffing(void)
{
   DEBUG_MSG("curses_start_sniffing");
   
   /* start the sniffing method */
   EXECUTE(EC_GBL_SNIFF->start);
}

static void curses_stop_sniffing(void)
{
   DEBUG_MSG("curses_stop_sniffing");
   
   /* terminate the sniffing engine */
   EXECUTE(EC_GBL_SNIFF->cleanup);
}


/* EOF */

// vim:ts=3:expandtab

