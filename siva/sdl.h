#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED

#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "obj.h"

extern SDL_Event event;
extern SDL_Surface *screen;
extern SDL_TimerID timer;

extern Window w;

Uint32 pushEvent(Uint32 ms, void *p);
Color getColor(SDL_Surface *surface, int x, int y);
Uint32 getPixel(SDL_Surface *surface, int x, int y);

void initWindow();

#endif
