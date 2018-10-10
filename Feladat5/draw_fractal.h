#ifndef __DRAW_FRACTAL__
#define __DRAW_FRACTAL__

typedef struct{
	double x;
	double y;
} Point;

/*
points - egy Point strukt�r�kat tartalmaz� t�mb, ami a frakt�l cs�csait tartalmazza
length - ennyi cs�csa van a frakt�lnak
*/
void draw_fractal(const Point* points, int length);

#endif __DRAW_FRACTAL__

