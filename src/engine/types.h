/*
 * =====================================================================================
 *
 *       Filename:  types.h
 *
 *    Description:  Podstawowe typy używane w enginie.
 *
 *        Version:  1.0
 *        Created:  2011.05.31 21:09:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rafał Hirsz (evol), rafal@hirsz.co
 *        Company:  
 *
 * =====================================================================================
 */


#ifndef  types_INC
#define  types_INC

#include	"SDL.h"

struct Point {
  int x,y;
};				/* ----------  end of struct Point  ---------- */

typedef SDL_Rect Rect;

#endif   /* ----- #ifndef types_INC  ----- */
