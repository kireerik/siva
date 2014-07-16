#include <string.h>
#include <math.h>
#include "fps.h"
#include "list.h"
#include "emitter.h"
#include "particle.h"
#include "animation.h"

void addEmitter(Emitter e) {
	for (int i = 0; i < e.db; i++)
		addParticle(e);
}

Emitter newEmitter(char *name, int preDuration, int reStart, char *type, int db
	, double x, double y, int rotation, int alpha, int startR, int rMin, int rMax
) {
	Emitter e;
	e.name = name;
	e.preDuration = preDuration;
	e.reStart = reStart;
	e.type = type;
	e.db = db;
	e.p.x = x;
	e.p.y = y;
	e.rotation = rotation;
	e.alpha = alpha;
	e.startR = startR;
	e.rMin = rMin;
	e.rMax = rMax;
	return e;
}

void addEmitterGroup(char *img, double scaleX, double scaleY, double density, Emitter e) {
	SDL_Surface *imgSurface = IMG_Load(img);

	for(int i = 1; i < imgSurface->w; i += (int) (imgSurface->w * density < 1 ? 1 : imgSurface->w * density))
		for(int j = 1; j < imgSurface->h; j += (int) (imgSurface->h * density < 1 ? 1 : imgSurface->h * density)) {
			Color c = getColor(imgSurface, i, j);
			if (c.r == 0 && c.g == 0 && c.b == 0) {
				Emitter tmpE = e;
				tmpE.p.x += i * imgSurface->w * scaleX / imgSurface->w - imgSurface->w * scaleX / 2;
				tmpE.p.y += j * imgSurface->h * scaleY / imgSurface->h - imgSurface->h * scaleY / 2;
				addEmitter(tmpE);
			}
		}

	SDL_FreeSurface(imgSurface);
}
