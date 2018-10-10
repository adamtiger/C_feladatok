#ifndef __DRAW_FRACTAL__
#define __DRAW_FRACTAL__

typedef struct{
	double x;
	double y;
} Point;

/*
points - egy Point struktúrákat tartalmazó tömb, ami a fraktál csúcsait tartalmazza
length - ennyi csúcsa van a fraktálnak
*/
void draw_fractal(const Point* points, int length);

#endif __DRAW_FRACTAL__

