/**
 *       @file  types.h
 *      @brief  Różne przydatne definicje typów.
 *
 *     @author  Rafał Hirsz, rafal@hirsz.co
 *     @author  Robert Pętlak, rpetlak@gmail.com
 *
 *   @internal
 *     Created  2011.06.04
 *   Copyright  Copyright (c) 2011 Rafał Hirsz, Robert Pętlak
 * =====================================================================================
 */



#ifndef  types_INC
#define  types_INC

#include	"SDL.h"

/**
 * @brief Reprezentuje punkt.
 */
struct Point {
  int x,y;
};				/* ----------  end of struct Point  ---------- */

typedef SDL_Rect Rect; ///< Reprezentuje prostokąt.

#endif   /* ----- #ifndef types_INC  ----- */
