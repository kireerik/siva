#include "particle.h"

void bouble(Particle **p) {
	(*p)->state.size = 20;
	(*p)->state.opacity = 0;
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
	(*p)->animation.repeat = 1 + rand()%10;
	(*p)->animation.reverse = 0;
	(*p)->animation.start = (*p)->state;
	(*p)->animation.end.size = 0;
	(*p)->animation.end.opacity = 1;
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
