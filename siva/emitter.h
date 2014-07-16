#ifndef OBJEMITTER_H_INCLUDED
#define OBJEMITTER_H_INCLUDED

#include "obj.h"
#include "particle.h"

typedef struct {
	char *name;
	int preDuration;
	int reStart;
	char *type;
	int db;
	Point p;
	int rotation, alpha, startR, rMin, rMax;
} Emitter;

void addEmitterGroup(char *img, double scaleX, double scaleY, double density, Emitter e);
void addEmitter(Emitter e);

Emitter newEmitter(char *name, int preDuration, int reStart, char *type
	, int db, double x, double y, int rotation, int alpha
	, int startR, int rMin, int rMax
);

#endif
