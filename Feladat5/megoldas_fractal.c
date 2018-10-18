#include "draw_fractal.h"
#include <math.h>


int fraktal_creater(Point* points, int level) {

	Point points_temp[3500];  // sok szintig (6-ig) elég

	// kezdeti csúcsok
	const double rad_60 = 3.145 / 3.0;

	int x0 = 1000, y0 = 400, a = 1000;

	points[0] = (Point) { x0, y0 };
	points[1] = (Point) { x0 - a / 2, y0 + a * sin(rad_60) };
	points[2] = (Point) { x0 + a / 2, y0 + a * sin(rad_60) };

	// új csúcsok beillesztése szintenként
	int length = 3;
	for (int i = 1; i < level; ++i) {
		int temp_idx = 0;
		// végig iterálunk a sokszög oldalain és illesztünk rá egy szabályos háromszöget,
		// aminek oldalhossza a jelenlegi szakasz (oldal) harmada
		for (int idx = 0; idx < length; ++idx) {  
			Point a = points[idx];
			Point b = points[(idx + 1) % length];

			Point p0 = { 0.0, 0.0 };  // az új háromszög első pontja, ez még rajta van az aktuális oldalon
			p0.x = (b.x - a.x) / 3.0 + a.x;
			p0.y = (b.y - a.y) / 3.0 + a.y;

			Point p2 = { 0.0, 0.0 };  // az új háromszög utolsó pontja, ez még rajta van az aktuális oldalon
			p2.x = 2.0*(b.x - a.x) / 3.0 + a.x;
			p2.y = 2.0*(b.y - a.y) / 3.0 + a.y;

			Point p1 = { 0.0, 0.0 };  // a második pont az oldalon kívül van
			double factor = sin(rad_60);
			p1.x = -(p2.y - p0.y) * factor + (p2.x + p0.x) / 2.0;  // koordináta geometriából levezethető
			p1.y = (p2.x - p0.x) * factor + (p2.y + p0.y) / 2.0;

			// új pontok elhelyezése az aktuális szakasz végpontaji között
			points_temp[temp_idx] = a;
			points_temp[temp_idx + 1] = p0;
			points_temp[temp_idx + 2] = p1;
			points_temp[temp_idx + 3] = p2;
			points_temp[temp_idx + 4] = b;
			temp_idx += 4;
		}

		length *= 4;  // ennyi csúcs van az új szinten

		// az átmeneti mátrix másolása
		for (int j = 0; j < length; ++j) {
			points[j] = points_temp[j];
		}
	}

	return length;
}

int main() {

	Point pontok[3500];
	int length = fraktal_creater(pontok, 6);

	draw_fractal(pontok, length);

	return 0;
}
