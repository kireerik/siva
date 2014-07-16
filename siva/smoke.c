#include "particle.h"

void smoke(Particle **p) {
	(*p)->state.size = 1;
	(*p)->state.opacity = rand()%18 / 100.0;
	(*p)->state.rotation = 0;
	(*p)->state.texture.outline.size = 0;
	(*p)->state.texture.outline.color.a = (int) ((*p)->state.opacity * 255);
	(*p)->state.texture.color.r = 255;
	(*p)->state.texture.color.g = 255;
	(*p)->state.texture.color.b = 255;
	(*p)->state.texture.color.a = (int) ((*p)->state.opacity * 255);

	(*p)->animation.duration = 1000;
	(*p)->animation.preDuration = rand()%1000;
	(*p)->animation.startTime = NULL;
	(*p)->animation.type = "linear";
	(*p)->animation.repeat = NULL;
	(*p)->animation.reverse = 0;
	(*p)->animation.start = (*p)->state;
	(*p)->animation.end.size = 6;
	(*p)->animation.end.opacity = 0;
	(*p)->animation.end.rotation = 0;
	(*p)->animation.end.texture.outline.size = 0;
	(*p)->animation.end.texture.color.r = 255;
	(*p)->animation.end.texture.color.g = 255;
	(*p)->animation.end.texture.color.b = 255;
	(*p)->animation.end.texture.color.a = (int) ((*p)->animation.end.opacity * 255);
}
