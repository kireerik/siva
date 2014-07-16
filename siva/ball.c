#include <stdlib.h>
#include "particle.h"

void ball(Particle **p) {
	(*p)->state.size = 1 + rand()%10;
	int tmpPosition = w.width - 2 * (*p)->state.size;
	(*p)->state.p.x = (*p)->state.size + rand()%tmpPosition;
	(*p)->state.p.y = (*p)->state.size + rand()%tmpPosition;
	(*p)->state.v.x = (rand()%2 == 0 ? 1 : -1) * (.1 + 2 * (rand()%10 / 10.0));
	(*p)->state.v.y = (rand()%2 == 0 ? 1 : -1) * (.1 + 2 * (rand()%10 / 10.0));
	(*p)->state.texture.outline.size = 0;
	(*p)->state.texture.color.r = rand()%256;
	(*p)->state.texture.color.g = rand()%256;
	(*p)->state.texture.color.b = rand()%256;
	(*p)->state.texture.color.a = rand()%50;
	(*p)->animation.duration = NULL;
}
