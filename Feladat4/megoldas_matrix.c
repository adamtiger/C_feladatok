#include <stdio.h>

// matrix struktúra
typedef struct {
	int m;
	int sz;
	int elemek[1000];
} Matrix;


// függvény a kiiratáshoz
void print_matrix(Matrix mtx) {

	for (int i = 0; i < mtx.m; ++i) {

		for (int j = i * mtx.sz; j < (i + 1) * mtx.sz; ++j) {
			printf("%3d ", mtx.elemek[j]);
		}

		printf("\n");
	}
}

// szorzás
Matrix multiply(Matrix a, Matrix b) {

	// méret ellenőrzés
	if (a.sz != b.m) {
		printf("Rossz meretek! %d != %d", (a.sz, b.m));
		return (Matrix){ -1, -1, {0} };  // kasztolás egy default hibás eredmény visszaadásához
	}

	// a kimenet inicializálása
	Matrix out = { a.m, b.sz, {0} };

	// szorzás
	int k1= 0, k2 = 0;
	for (int i = 0; i < a.m; ++i) {
		for (int j = 0; j < b.sz; ++j) {
			int idx = i * out.sz + j;
			out.elemek[idx] = 0;

			for (int k = 0; k < a.sz; ++k) {
				k1 = i * a.sz + k;
				k2 = j + b.sz * k;
				out.elemek[idx] += a.elemek[k1] * b.elemek[k2];
			}
		}
	}

	return out;
}

int main() {

	// kiíró függvény tesztelése
	Matrix mtx = { 2, 3, {1, 0, 4, 5, 2, 1} };
	print_matrix(mtx);

	// szorzás tesztelése
	Matrix a = { 2, 3, {2, 0, 3, 1, 1, 1} };
	Matrix b = { 3, 2, {1, 3, 1, 1, 1, 4} };
	Matrix out = { 2, 2, {0} };
	out = multiply(a, b, out);
	print_matrix(out);

	return 0;
}