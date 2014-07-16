#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

typedef struct {
	int x, y;
	double m;
} Button;

extern Button b;

void initButton();

extern int mX, mY, moveX, moveY
, mouseButtonLeftDown, mouseButtonRightDown;

void move(int moveX, int moveY);

#endif
