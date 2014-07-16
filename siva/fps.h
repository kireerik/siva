#ifndef FPS_H_INCLUDED
#define FPS_H_INCLUDED

#include "obj.h"

extern long long t1, t2;
extern Fps fps;

long long timeInMillSec();

void calculateFps();

#endif
