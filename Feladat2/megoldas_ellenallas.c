#include <stdio.h>
#include <stdbool.h>

#define SOROS  0
#define PARHUZAMOS  1
#define BACK  -1
#define RESET -2
#define EXIT  -3

int main() {

	// változók a beolvasáshoz
	float r = 0.0;
	int mod = 0;

	// változók a az eredő ellenálláshoz
	float r_e = 0.0;
	float r_e_elozo = 0.0;
	bool volt_torles = false;

	// Üdvözlés és útmutató
	printf("Ellenallas szamito program.\n");
	printf("Uj ellenallas csatolasa: R mod \n");
	printf("Utolso lepes torlese: NA -1 \n");
	printf("Reset: NA -2 \n");
	printf("Kilepes: NA -3 \n");

	// elindítjuk a menüt
	printf("Csatolando uj ellenallas:  \n");
	scanf("%f %d", &r, &mod);

	while (mod != -3) {

		switch (mod) {
		case RESET: // reset esete
			r_e = 0.0;
			r_e_elozo = 0.0;
			volt_torles = false;
			break;
		case BACK: // visszalépés korábbi állapotra
			if (!volt_torles) {
				r_e = r_e_elozo;
				volt_torles = true;
			}
			else {
				printf("Warning: mar egyszer toroltel! Ez az utasitas nem kerul vegrehajtasra.\n");
			}
			break;
		case SOROS: // soros kapcsolás
			if (r > 0) {
				r_e_elozo = r_e;     // elmentjük az aktuális változót a törléshez
				r_e = r_e + r;
				volt_torles = false;  // ha új értéket adunk hozzá, akkor már lehet törölni
			}
			else {
				printf("Error: rossz ellenallas ertek! Adj meg uj erteket.\n");
			}
			break;
		case PARHUZAMOS: // párhuzamos kapcsolás
			if (r > 0) {
				r_e_elozo = r_e; // elmentjük az aktuális változót a törléshez
				r_e = 1.0 / (1.0 / r_e + 1.0 / r);
				volt_torles = false;
			}
			else {
				printf("Error: rossz ellenallas ertek! Adj meg uj erteket.\n");
			}
			break;
		default:
			printf("Error: rossz kapcsolasi mod! Adj meg uj erteket.\n");
		}

		// új lépés a menüben
		printf("Jelenlegi ellenallas: %.4f \n", r_e);
		printf("Csatolando uj ellenallas: \n");
		scanf("%f %d", &r, &mod);
	}

	printf("A rendszer ellenallasa: %.4f \n", r_e);
	printf("Kilpes megtortent! \n");

	return 0;
}