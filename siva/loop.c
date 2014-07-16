#include "fps.h"
#include "particle.h"

#include "move.h"

void mainLoop() {
	int run = 1;
	while (run) {
		SDL_WaitEvent(&event);
		switch (event.type) {
			case SDL_USEREVENT:
				if (mouseButtonLeftDown)
					addEmitter(newEmitter("clickedEmitter", 0, 0, "smoke", 10, mX, mY, 0, 360, 0, 5, 8));

				boxRGBA(screen, 0, 0, w.width, w.height, 0, 0, 0, 255);

				update();
				draw();

				SDL_Flip(screen);
				calculateFps();
			break;

			case SDL_MOUSEMOTION:
				if (mouseButtonRightDown)
					move(event.motion.x - mX, event.motion.y - mY);
				mX = event.motion.x;
				mY = event.motion.y;
			break;
			case SDL_MOUSEBUTTONDOWN:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT: mouseButtonLeftDown = 1; break;
					case SDL_BUTTON_RIGHT: mouseButtonRightDown = 1; break;
				}
			break;
			case SDL_MOUSEBUTTONUP:
				switch (event.button.button) {
					case SDL_BUTTON_LEFT: mouseButtonLeftDown = 0; break;
					case SDL_BUTTON_RIGHT: mouseButtonRightDown = 0; break;
				}
			break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
					case 27:					run = 0; break;
					case SDLK_LEFT:		b.x = -1 * b.m; break;
					case SDLK_UP:			b.y = -1 * b.m; break;
					case SDLK_RIGHT:		b.x = 1 * b.m; break;
					case SDLK_DOWN:		b.y = 1 * b.m; break;
					default: ;
				}
			break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym) {
					case 27:					run = 0; break;
					case SDLK_LEFT:		b.x = 0; break;
					case SDLK_UP:			b.y = 0; break;
					case SDLK_RIGHT:		b.x = 0; break;
					case SDLK_DOWN:		b.y = 0; break;
					default: ;
				}
			break;
			case SDL_QUIT: run = 0; break;
		}
	}
}
