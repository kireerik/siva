#include <stdio.h>
#include <sys/time.h>
#include "fps.h"

long long t1, t2;
Fps fps;

long long timeInMillSec() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return t.tv_sec * 1000LL + t.tv_usec / 1000;
}

void calculateFps() {
	t2 = timeInMillSec();

	fps.fps = 1000 / (t2 - t1);
	if (fps.max < fps.fps)
		fps.fps = fps.max;

	t1 = timeInMillSec();
}
