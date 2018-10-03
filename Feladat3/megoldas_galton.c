#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

// háromszög magassága (felosztas)
#define felosztas 20

// golyok szama
#define golyok_osszes 500000

int main() {
    
	// vektorok
	int golyok_szama[felosztas] = { golyok_osszes };
	int atmeneti_tarolo[felosztas] = { 0 };

	// Galton-szimulacio
	for (int szint = 1; szint < felosztas; ++szint) {

               // adott szinten levő golyók száma
	       for (int i = 0; i < szint; ++i) {

			int balra = golyok_szama[i] / 2;
			int jobbra = golyok_szama[i] - balra;
			atmeneti_tarolo[i] += balra;
			atmeneti_tarolo[i + 1] += jobbra;
		}

		// atmeneti taroloba masolas
		// golyok szamanak nullazasa
		for (int i = 0; i < felosztas; ++i) {
			golyok_szama[i] = atmeneti_tarolo[i];
			atmeneti_tarolo[i] = 0;
		}
	}

	// tomb abrazolasa
	for (int x = 0; x < felosztas; ++x) {

		int y = golyok_szama[x] * 80.0 / golyok_osszes;
		for (int space = 0; space < y; ++space) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n\n");

	// Gauss-eloszlás rajzolása
	for (int x = 0; x < felosztas; x += 1) {

		float mu = felosztas * 0.5;
		float sigma = sqrt(felosztas * 0.25);

		float z = (x - mu) / sigma;
		int y = 40.0 * 1.0 / sqrt(2.0 * PI) * exp(-z * z / 2.0);
		for (int space = 0; space < y; ++space) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
