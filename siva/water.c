#include "particle.h"

void water(Particle **p) {
	(*p)->state.size = 50;
	(*p)->state.opacity = (80 + rand()%10) / 100.0;
	(*p)->state.rotation = 0;
	(*p)->state.texture.outline.size = 0;
	(*p)->state.texture.outline.color.a = (int) ((*p)->state.opacity * 255);
	(*p)->state.texture.color.r = 0;
	(*p)->state.texture.color.g = 153;
	(*p)->state.texture.color.b = 204;
	(*p)->state.texture.color.a = (int) ((*p)->state.opacity * 255);

	(*p)->animation.duration = 1000;
	(*p)->animation.preDuration = rand()%1000;
	(*p)->animation.startTime = NULL;
	(*p)->animation.type = "linear";
	(*p)->animation.repeat = NULL;
	(*p)->animation.reverse = 1;
	(*p)->animation.start = (*p)->state;
	(*p)->animation.end.size = 100;
	(*p)->animation.end.opacity = (90 + rand()%10) / 100.0;
	(*p)->animation.end.rotation = 0;
	(*p)->animation.end.texture.outline.size = 0;
	(*p)->animation.end.texture.color.r = 0;
	(*p)->animation.end.texture.color.g = 102;
	(*p)->animation.end.texture.color.b = 204;
	(*p)->animation.end.texture.color.a = 1;
}
