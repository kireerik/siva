#include "sdl.h"
#include "list.h"
#include "particle.h"
#include "move.h"

Button b;

void initButton() {
	b.x = 0;
	b.y = 0;
	b.m = 6;
}

int mX = 0, mY = 0, moveX, moveY
, mouseButtonLeftDown = 0, mouseButtonRightDown = 0;

void move(int moveX, int moveY) {
	Item *ptr;

	for(ptr = l.start->next; ptr != l.end; ptr = ptr->next) {
		if (!strcmp(ptr->p->name, "ball")) {
			ptr->p->state.p.x += moveX;
			ptr->p->state.p.y += moveY;
			ptr->p->animation.start.p.x += moveX;
			ptr->p->animation.start.p.y += moveY;
			ptr->p->animation.end.p.x += moveX;
			ptr->p->animation.end.p.y += moveY;
		}
	}
}
