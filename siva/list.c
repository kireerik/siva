#include <stdio.h>
#include "list.h"

List l;

void initList() {
	l.start = (Item*) malloc(sizeof(Item));
	l.end = (Item*) malloc(sizeof(Item));
	l.start->prev = NULL;
	l.start->next = l.end;
	l.end->prev = l.start;
	l.end->next = NULL;
	l.db = 0;
}

void delList() {
	Item *ptr;

	for(ptr = l.start->next; ptr != l.end; ptr = ptr->next)
		ptr = delItem(ptr);
}

void addItem(Particle *p) {
	Item *i;
	i = (Item*) malloc(sizeof(Item));
	i->p = p;
	i->next = l.end;
	i->prev = l.end->prev;
	l.end->prev->next = i;
	l.end->prev = i;
	l.db++;
}

Item *delItem(Item *i) {
	Item *tmp = i->prev;
	i->next->prev = i->prev;
	i->prev->next = i->next;
	free(i->p);
	free(i);
	l.db--;
	return tmp;
}
