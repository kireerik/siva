#include "fps.h"
#include "particle.h"

#include "move.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));

	init();

	initButton();

	t1 = timeInMillSec();
	timer = SDL_AddTimer(1000 / fps.fps, pushEvent, NULL);

	mainLoop();

	SDL_RemoveTimer(timer);
	SDL_Quit();

	delList();

	return 0;
}
