#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "sdl.h"
#include "obj.h"
#include "emitter.h"

typedef struct {
	Outline outline;
	Color color;
} Texture;

typedef struct {
	Point p;
	Vector v;
	double size, opacity, rotation;
	Texture texture;
} State;

typedef struct {
	int duration;
	int preDuration;
	long long startTime;
	char *type;
	int repeat;
	int reverse;
	State start;
	State end;
} Animation;

typedef struct {
	char *name;
	int zIndex;
	State state;
	Animation animation;
	Emitter emitter;
} Particle;

void addParticle(Emitter e);
void selectType(char *type, Particle **p);

void collideBorderParticle(Particle **p);
int animateParticle(Particle **p);

#endif
