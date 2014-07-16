#include "fps.h"
#include "particle.h"

#include "move.h"

void addExamples() {
	int db = 50;

	for (int i = 1; i < 50; i += 12 + rand()%10)
		for (int j = 1; j < 50; j += 12 + rand()%10)
			addEmitter(newEmitter("smoke", 80 * 1000, 0, "smoke", 100, 400 + i, 400 + j, 0, 360, 0, 10, 14));

	addEmitter(newEmitter("ball", 0, 0, "ball", 100, 0, 0, 0, 0, 0, 0, 0));

	addEmitterGroup("img/siva.png", .4, .4, .01, newEmitter("siva", 0, 0, "siva", 1, (1-.618) * w.width, .618 * w.height, 0, 360, 0, 0, 0));

	int wait = 50 * 1000;
	addEmitter(newEmitter("sun", wait, 0, "sun", 1000, .618 * w.width, (1-.618) * w.height, 0, 360, 50, 30, 100));
	addEmitter(newEmitter("sun", wait, 0, "sun", 100, .618 * w.width - 20, (1-.618) * w.height -20, 0, 360, 0, 10, 10));
	addEmitter(newEmitter("sun", wait, 0, "sun", 100, .618 * w.width + 20, (1-.618) * w.height - 20, 0, 360, 0, 10, 10));
	addEmitter(newEmitter("sun", wait, 0, "sun", 100, .618 * w.width, (1-.618) * w.height + 20, 0, 360, 10, 10, 10));

	for(int i = 1; i <= 4; i++) {
		char str[20];
		sprintf(str, "img/idezet%i.png", i);
		addEmitterGroup(str, 2, 2, .003, newEmitter(str, i * 8 * 1000, 0, "siva", 1, w.width / 2.0, w.height / 2.0, 0, 360, 0, 0, 0));
	}

	//for(int j = 1; j <= 60; j+=50)
	//	for(int i = 1; i <= w.width; i+=50)
	//		addEmitter(newEmitter("water", rand()%1000, 0, "water", 1, i, .9 * w.height + j, 0, 0, 0, 3, 6));
	//addEmitter(newEmitter("smoke", 0 * 1000, 4, "smoke", 10, 400, 200, 0, 360, 0, 5, 10));

	for (int i = 1; i <= 4; i++)
		addEmitter(newEmitter("demoBoubleGroup", 0 * 1000, 0, "bouble", db, i * 100, i * 100, 0, 360, 0, 50, 50));
	addEmitter(newEmitter("demoBoubleGroup5", 40 * 1000, 0, "bouble", 2 * db, 300, 600, 0, 260, 0, 150, 200));

	addEmitter(newEmitter("centeredBouble", 40 * 1000, 0, "bouble", db, w.width / 2.0, w.height / 2.0, 0, 360, 0, 50, 50));
	addEmitter(newEmitter("centeredWind", 40 * 1000, 0, "wind", db, w.width / 2, w.height / 2, 45, 4, 0, 400, 400));

}

void init() {
	fps.max = fps.fps = 24;

	w.title = "siva";
	initWindow();

	initList();

	addExamples();
}
