#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main() {

	printf("Add meg gammat, a-t és b-t! Formatum: gamma a b \n");

	// változók az értékek bekéréséhez
	double gamma, a, b;
	scanf("%lf %lf %lf", &gamma, &a, &b);

	// gamma átváltása radiánba
	double gamma_rad = gamma / 180.0 * PI;

	// c oldal kiszámítása
	double c = sqrt(a * a + b * b - 2 * a * b * cos(gamma_rad));

	// alfa és béta kiszámítása cosinus tételből levezthető képletekkel
	double alpha_rad = acos((b *b + c *c - a * a)/(2 * b * c));
	double beta_rad = acos((a *a + c * c - b * b) / (2 * a * c));

	// radiánból fok
	double alpha = alpha_rad / PI * 180.0;
	double beta = beta_rad / PI * 180.0;

	// eredmény kiírása
	printf("c: %.3lf, alpha: %.3lf, beta: %.3lf \n", c, alpha, beta);

	/*
	TESZT
	-------------------------
	bemenet:
	gamma = 120
	a = 10
	b = 10

	elvárt kimenet:
	c = 17.32
	alpha = 30
	beta = 30
	*/

	return 0;
}