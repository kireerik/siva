#include "fps.h"
#include "particle.h"
#include "list.h"

void draw() {
	Item *ptr;

	for(ptr = l.start->next; ptr != l.end; ptr = ptr->next)
		drawParticle(*(ptr->p));

	logFps();
	logParticleDb();
	logAllocatedMemory();
}

void logFps() {
	char str[4];
	sprintf(str, "fps: %i", fps.fps);
	stringRGBA(screen, 10, 10, str, 255, 255, 255, 255);
}

void logParticleDb() {
	char str[10];
	sprintf(str, "particle: %i", l.db);
	stringRGBA(screen, 10, 10 + 20, str, 255, 255, 255, 255);
}

void logAllocatedMemory() {
	char str[100];
	sprintf(str, "allocated memory: %0.f MB", ((l.db + 2) * sizeof(Item) / (2.0 * 1024)));
	stringRGBA(screen, 10, 10 + 2 * 20, str, 255, 255, 255, 255);
}

void drawParticle(Particle p) {
	if (p.animation.startTime != NULL || p.animation.duration == NULL) {
		filledCircleRGBA(screen, (int) p.state.p.x, (int) p.state.p.y, p.state.size, p.state.texture.color.r, p.state.texture.color.g, p.state.texture.color.b, p.state.texture.color.a);
		for(int k = 0; k <= p.state.texture.outline.size - 1; k++)
			aacircleRGBA(screen, (int) p.state.p.x, (int) p.state.p.y, p.state.texture.outline.size + k, p.state.texture.outline.color.r, p.state.texture.outline.color.g, p.state.texture.outline.color.b, p.state.texture.outline.color.a);
	}
}
