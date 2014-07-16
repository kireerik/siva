#include <string.h>
#include <math.h>
#include "fps.h"
#include "list.h"
#include "emitter.h"
#include "particle.h"
#include "animation.h"

void selectType(char *type, Particle **p) {
	if (!strcmp(type, "bouble"))		bouble(&(*p));
	if (!strcmp(type, "smoke"))		smoke(&(*p));
	if (!strcmp(type, "water"))		water(&(*p));
	if (!strcmp(type, "ball"))			ball(&(*p));
	if (!strcmp(type, "wind"))			wind(&(*p));
	if (!strcmp(type, "siva"))			siva(&(*p));
	if (!strcmp(type, "sun"))			sun(&(*p));
}

void addParticle(Emitter e) {
	Particle *p;
	p = (Particle*) malloc(sizeof(Particle));

	p->name = e.name;
	p->zIndex = NULL;

	double randRotation = e.alpha != 0 ? rand()%e.alpha / 360.0 * 2 * M_PI : e.alpha;
	p->state.p.x = e.p.x + e.startR * cos(e.rotation / 360.0 * 2 * M_PI + randRotation);
	p->state.p.y = e.p.y + e.startR * sin(e.rotation / 360.0 * 2 * M_PI + randRotation);
	p->state.v.x = 0;
	p->state.v.y = 0;

	p->animation.preDuration = 0;
	double randR = e.rMin < e.rMax ? (e.rMin + rand()%(e.rMax - e.rMin)) : e.rMin;
	p->animation.end.p.x = e.startR * cos(e.rotation / 360.0 * 2 * M_PI + randRotation)
		+ e.p.x + randR * cos(e.rotation / 360.0 * 2 * M_PI + randRotation);
	p->animation.end.p.y = e.startR * sin(e.rotation / 360.0 * 2 * M_PI + randRotation)
		+ e.p.y + randR * sin(e.rotation / 360.0 * 2 * M_PI + randRotation);
	p->animation.end.v.x = 0;
	p->animation.end.v.y = 0;

	selectType(e.type, &p);

	p->animation.preDuration += e.preDuration;
	p->animation.start = p->state;
	p->emitter = e;

	addItem(p);
}

void collideBorderParticle(Particle **p) {
	if ((*p)->state.p.x - (*p)->state.size < 0 || w.width < (*p)->state.p.x + (*p)->state.size) {
		(*p)->state.v.x *= -1;
		if ((*p)->state.p.x - (*p)->state.size < 0) (*p)->state.p.x = 0 + (*p)->state.size;
		else (*p)->state.p.x = w.width - (*p)->state.size;
	}
	if ((*p)->state.p.y - (*p)->state.size < 0 || w.height < (*p)->state.p.y + (*p)->state.size) {
		(*p)->state.v.y *= -1;
		if ((*p)->state.p.y - (*p)->state.size < 0) (*p)->state.p.y = 0 + (*p)->state.size;
		else (*p)->state.p.y = w.height - (*p)->state.size;
	}
}

int animateParticle(Particle **p) {
	if (0 < (*p)->animation.preDuration)
		(*p)->animation.preDuration -= 1000 / fps.fps;
	else if ((*p)->animation.startTime == NULL) {
		(*p)->animation.preDuration = 0;
		(*p)->animation.startTime = timeInMillSec();
	}

	if ((*p)->animation.startTime != NULL) {
		double time = timeInMillSec() - (*p)->animation.startTime;
		if (time <= (*p)->animation.duration) {
			double animationType;
			if (strcmp((*p)->animation.type, "linear") == 0)
				animationType = time;
			(*p)->state.p.x = (*p)->animation.start.p.x + ((*p)->animation.end.p.x - (*p)->animation.start.p.x) / (*p)->animation.duration * animationType;
			(*p)->state.p.y = (*p)->animation.start.p.y + ((*p)->animation.end.p.y - (*p)->animation.start.p.y) / (*p)->animation.duration * animationType;
			(*p)->state.v.x = (*p)->animation.start.v.x + ((*p)->animation.end.v.x - (*p)->animation.start.v.x) / (*p)->animation.duration * animationType;
			(*p)->state.v.y = (*p)->animation.start.v.y + ((*p)->animation.end.v.y - (*p)->animation.start.v.y) / (*p)->animation.duration * animationType;
			(*p)->state.size = (*p)->animation.start.size + ((*p)->animation.end.size - (*p)->animation.start.size) / (*p)->animation.duration * animationType;
			(*p)->state.opacity = (*p)->animation.start.opacity + ((*p)->animation.end.opacity - (*p)->animation.start.opacity) / (*p)->animation.duration * animationType;
			(*p)->state.rotation = (*p)->animation.start.rotation + ((*p)->animation.end.rotation - (*p)->animation.start.rotation) / (*p)->animation.duration * animationType;

			(*p)->state.texture.outline.size = (int) ((*p)->animation.start.texture.outline.size + ((*p)->animation.end.texture.outline.size - (*p)->animation.start.texture.outline.size) / (*p)->animation.duration * animationType);
			(*p)->state.texture.outline.color.r = (int) ((*p)->animation.start.texture.outline.color.r + ((*p)->animation.end.texture.outline.color.r - (*p)->animation.start.texture.outline.color.r) / (*p)->animation.duration * animationType);
			(*p)->state.texture.outline.color.g = (int) ((*p)->animation.start.texture.outline.color.g + ((*p)->animation.end.texture.outline.color.g - (*p)->animation.start.texture.outline.color.g) / (*p)->animation.duration * animationType);
			(*p)->state.texture.outline.color.b = (int) ((*p)->animation.start.texture.outline.color.b + ((*p)->animation.end.texture.outline.color.b - (*p)->animation.start.texture.outline.color.b) / (*p)->animation.duration * animationType);
			(*p)->state.texture.outline.color.a = (int) ((*p)->state.opacity);

			(*p)->state.texture.color.r = (int) ((*p)->animation.start.texture.color.r + ((*p)->animation.end.texture.color.r - (*p)->animation.start.texture.color.r) / (*p)->animation.duration * animationType);
			(*p)->state.texture.color.g = (int) ((*p)->animation.start.texture.color.g + ((*p)->animation.end.texture.color.g - (*p)->animation.start.texture.color.g) / (*p)->animation.duration * animationType);
			(*p)->state.texture.color.b = (int) ((*p)->animation.start.texture.color.b + ((*p)->animation.end.texture.color.b - (*p)->animation.start.texture.color.b) / (*p)->animation.duration * animationType);
			(*p)->state.texture.color.a = (int) ((*p)->state.opacity * 255);
		} else {
			if ((*p)->animation.reverse == 1) {
				State tmpState = (*p)->animation.start;
				(*p)->animation.start = (*p)->animation.end;
				(*p)->animation.end = tmpState;
			}
			if ((*p)->animation.repeat == NULL || 1 < (*p)->animation.repeat) {
				if ((*p)->animation.repeat != NULL)
					(*p)->animation.repeat--;
				(*p)->animation.startTime = NULL;
			} else {
				// add new emitter
				if (0 < (*p)->emitter.reStart) {
					(*p)->emitter.reStart--;
					(*p)->emitter.p.x = (*p)->state.p.x;
					(*p)->emitter.p.y = (*p)->state.p.y;
					addEmitter((*p)->emitter);
				}
				// free up particle
				return 1;
			}
		}
	}
	return 0;
}
