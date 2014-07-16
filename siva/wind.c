#include "particle.h"

void wind(Particle **p) {
	(*p)->state.size = 0;
	(*p)->state.opacity = 1;
	(*p)->state.rotation = 0;
	(*p)->state.texture.outline.size = 0;
	(*p)->state.texture.outline.color.r = rand()%256;
	(*p)->state.texture.outline.color.g = rand()%256;
	(*p)->state.texture.outline.color.b = rand()%256;
	(*p)->state.texture.outline.color.a = (int) ((*p)->state.opacity * 255);
	(*p)->state.texture.color.r = rand()%256;
	(*p)->state.texture.color.g = rand()%256;
	(*p)->state.texture.color.b = rand()%256;
	(*p)->state.texture.color.a = (int) ((*p)->state.opacity * 255);

	(*p)->animation.duration = 1000;
	(*p)->animation.preDuration = rand()%2000;
	(*p)->animation.startTime = NULL;
	(*p)->animation.type = "linear";
	(*p)->animation.repeat = NULL;
	(*p)->animation.reverse = 1;
	(*p)->animation.start = (*p)->state;
	(*p)->animation.end.size = 20;
	(*p)->animation.end.opacity = 0;
	(*p)->animation.end.rotation = 0;
	(*p)->animation.end.texture.outline.size = 0;
	(*p)->animation.end.texture.outline.color.r = rand()%256;
	(*p)->animation.end.texture.outline.color.g = rand()%256;
	(*p)->animation.end.texture.outline.color.b = rand()%256;
	(*p)->animation.end.texture.outline.color.a = (int) ((*p)->animation.end.opacity * 255);
	(*p)->animation.end.texture.color.r = rand()%256;
	(*p)->animation.end.texture.color.g = rand()%256;
	(*p)->animation.end.texture.color.b = rand()%256;
	(*p)->animation.end.texture.color.a = (int) ((*p)->animation.end.opacity * 255);
}
