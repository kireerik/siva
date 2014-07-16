#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

typedef struct {
	int width, height;
	char *title;
} Window;

typedef struct {
	int fps, max;
} Fps;

typedef struct {
	double r, g, b, a;
} Color;

typedef struct {
	int size;
	Color color;
} Outline;

typedef struct {
	double x, y;
} Point;

typedef Point Vector;

#endif
