#include "draw_fractal.h"

int main() {

	Point a = { 1.0, 1.0 };
	Point b = { 1000.0, 1000.0 };
	Point pontok[2] = { a, b };
	int length = 2;

	draw_fractal(pontok, length);

	return 0;
}