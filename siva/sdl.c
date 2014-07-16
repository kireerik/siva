#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include "sdl.h"
#include "fps.h"

SDL_Event event;
SDL_Surface *screen;
SDL_TimerID timer;

Window w;

Uint32 pushEvent(Uint32 ms, void *p) {
	SDL_Event event;
	event.type = SDL_USEREVENT;
	SDL_PushEvent(&event);
	return fps.fps;
}

Color getColor(SDL_Surface *surface, int x, int y) {
	int pixel = getPixel(surface, x, y);
	Color c;
	c.r = (pixel >> 16) & 0xff;
	c.g = (pixel >> 8) & 0xff;
	c.b = pixel & 0xff;
	c.a = 255;
	return c;
}

// resource: http://sdl.beuc.net/sdl.wiki/Pixel_Access
Uint32 getPixel(SDL_Surface *surface, int x, int y) {
	int bpp = surface->format->BytesPerPixel;
	// Here p is the address to the pixel we want to retrieve
	Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch(bpp) {
		case 1: return *p; break;
		case 2: return *(Uint16 *)p; break;
		case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
				return p[0] << 16 | p[1] << 8 | p[2];
			else
				return p[0] | p[1] << 8 | p[2] << 16;
		break;
		case 4: return *(Uint32 *)p; break;
		default: return 0;
	}
}

void initWindow() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	#ifdef __WIN32__
		freopen("CON", "w", stdout);
		freopen("CON", "w", stderr);
	#endif
	const SDL_VideoInfo *info = SDL_GetVideoInfo();
	w.width = info->current_w;
	w.height = info->current_h;
	screen = SDL_SetVideoMode(w.width, w.height, 0, SDL_HWSURFACE | SDL_FULLSCREEN);
	if (!screen) {
		fprintf(stderr, "Nem sikerult megnyitni az ablakot!\n");
		exit(1);
	}
	SDL_WM_SetCaption(w.title, w.title);

	SDL_EnableUNICODE(1);
}
