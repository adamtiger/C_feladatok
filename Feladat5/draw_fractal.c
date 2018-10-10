#include <math.h>
#include <stdio.h>             // zárójellel érjük el a default elérhető könyvtárakat
#include "draw_fractal.h"  // macska körömmel érjük el a lokálisan elérhető könyvtárakat


#define OUTPUT "fraktal.svg"
#define SIZE 20  // az ablak mérete a böngészőben, ami mutatja az alakzatot

/* *****************************
* Segéd függvények
*/

// Függvény a fájl megnyitásához és inicializálásához
FILE* open(const char* f_name) {

	FILE* fp = fopen(f_name, "w+");
	fprintf(fp, "<?xml version=\"1.0\" standalone=\"no\"?>\n");
	fprintf(fp, 
		"<svg width=\"%dcm\" height=\"%dcm\" viewBox=\"0 0 %d %d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", SIZE, SIZE, 100*SIZE, 100*SIZE);
	fprintf(fp, "<desc>Fraktal</desc>\n");

	return fp;
}

// Függvény a fájl bezárásához és végelgesítséhez
void close(FILE* fp) {
	fprintf(fp, "</svg>");
	fclose(fp);
}

// Egyenes rajzolás
void add_line(FILE * fp, Point a, Point b) {
	int x1 = round(a.x);
	int y1 = round(a.y);
	int x2 = round(b.x);
	int y2 = round(b.y);

	fprintf(fp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"blue\" stroke-width=\"2\"/>\n", x1, y1, x2, y2);
}

/* *****************************
* A header függvényének implementálása
*/

void draw_fractal(const Point* points, int length) {
	FILE* fp = open(OUTPUT);

	int idx = 0;
	int idx_next = 0;
	for (idx = 0; idx < length; ++idx) {
		idx_next = (idx + 1) % length;  // az alakzat zárt lesz; ciklikus indexelés
		add_line(fp, points[idx], points[idx_next]);
	}

	close(fp);
}