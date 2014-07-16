#ifndef OBJLIST_H_INCLUDED
#define OBJLIST_H_INCLUDED

#include "obj.h"
#include "particle.h"

typedef struct Item {
	Particle *p;
	struct Item *prev, *next;
} Item;

typedef struct {
	Item *start, *end;
	int db;
} List;

extern List l;

void initList();
void delList();

void addItem(Particle *p);
Item *delItem(Item *i);

#endif
