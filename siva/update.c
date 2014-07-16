#include "fps.h"
#include "particle.h"
#include "list.h"
#include "move.h"

void update() {
	Item *ptr;

	for(ptr = l.start->next; ptr != l.end; ptr = ptr->next)
		if (updateParticle(&(ptr->p)))
			ptr = delItem(ptr);
}

int updateParticle(Particle **p) {
	collideBorderParticle(&(*p));

	if (!strcmp((*p)->name, "sun")) {
		double addX = b.x * fps.max / fps.fps
		, addY = b.y * fps.max / fps.fps;
		(*p)->state.p.x += addX;
		(*p)->state.p.y += addY;
		(*p)->animation.start.p.x += addX;
		(*p)->animation.start.p.y += addY;
		(*p)->animation.end.p.x += addX;
		(*p)->animation.end.p.y += addY;
	}

	(*p)->state.p.x += (*p)->state.v.x * fps.max / fps.fps;
	(*p)->state.p.y += (*p)->state.v.y * fps.max / fps.fps;

	if ((*p)->animation.duration != 0)
		return animateParticle(&(*p));
}
