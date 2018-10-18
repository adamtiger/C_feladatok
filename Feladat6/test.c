# include <stdio.h>
#include "set.h"


// Segéd függvények
void check_solution(const char* test_name, const Set* calculated, const Set* expected);
Set create_set(int* items, int length);

// Teszt függvények
void test_f1();
void test_f2();
void test_f3();
void test_f4();
void test_f5();
void test_f6();
void test_f7();
void test_f8();
void test_f9();
void test_f10();
void test_f11();
void test_f12();


int main() {

	test_f1();
	test_f2();
	test_f3();
	test_f4();
	test_f5();
	test_f6();
	test_f7();
	test_f8();
	test_f9();
	test_f10();
	test_f12();
	test_f11(); // kiiras

	// (egyik) de Morgan azonosság egy egyszerű példán
	// https://hu.wikipedia.org/wiki/De_Morgan-azonoss%C3%A1gok
	
	int a[3] = { 2, 4, 7 };
	Set set_a = create_empty();
	add_array(&set_a, a, 3);

	int b[4] = { 2, 4, 8, 9 };
	Set set_b = create_empty();
	add_array(&set_b, b, 4);

	int u[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // alaphalmaz
	Set set_u = create_empty();
	add_array(&set_u, u, 10);


	Set a_sect_b = section(&set_a, &set_b);
	Set a_sect_b_compl = diff(&set_u, &a_sect_b);

	Set a_compl = diff(&set_u, &set_a);
	Set b_compl = diff(&set_u, &set_b);
	Set a_compl_union_b_compl = merge(&a_compl, &b_compl);

	free_set(&set_a);
	free_set(&set_b);
	free_set(&set_u);
	free_set(&a_sect_b);
	free_set(&a_sect_b_compl);
	free_set(&a_compl);
	free_set(&b_compl);
	free_set(&a_compl_union_b_compl);

	if (compare(&a_sect_b_compl, &a_compl_union_b_compl))
		printf("De Morgen: Egyezes. \n");
	else
		printf("De Morgen: Lehet megse igaz. \n");

	return 0;
}

// Függvények definíciója

/**
* Teszt: F1 (üres halmaz készítés)
*/
void test_f1() {
	Set set = create_empty();
	Set expected = { 0, NULL };
	check_solution("F1", &set, &expected);
}

/**
* Teszt: F2 (inicializálás)
*/
void test_f2() {
	int a[5] = { 1, 4, 7, 9, 10 };
	Set set = create_set(a, 5);
	Set expected = { 0, NULL };

	init(&set);

	check_solution("F2", &set, &expected);
	free(set.storage);
}

/**
* Teszt: F3 (mély másolat)
*/
void test_f3() {
	int a[5] = { 1, 4, 7, 9, 10 };
	int b[5] = { 1, 4, 7, 9, 10 };
	Set set = create_set(a, 5);
	Set expected = create_set(b, 5);

	Set repl = copy(&set);

	check_solution("F3", &repl, &expected);
	free(set.storage);
}

/**
* Teszt: F4 (új elem hozzáadása)
*/
void test_f4() {
	int a[5] = { 1, 4, 7, 9, 10 };
	int b[6] = { 1, 4, 5, 7, 9, 10 };
	Set set = create_set(a, 5);
	Set expected = create_set(b, 6);

	add(&set, 5);

	check_solution("F4", &set, &expected);
	free(set.storage);
	free(expected.storage);
}

/**
* Teszt: F5 (tömb elemeinek hozzáadása)
*/
void test_f5() {
	int a[5] = { 1, 4, 7, 9, 10 };
	int b[9] = { 0, 4, 5, 7, 8, 9, 10, 12, 45 };
	int c[10] = { 0, 1, 4, 5, 7, 8, 9, 10, 12, 45 };
	Set set = create_set(a, 5);
	Set expected = create_set(c, 10);

	add_array(&set, b, 9);

	check_solution("F5", &set, &expected);
	free(set.storage);
	free(expected.storage);
}

/**
* Teszt: F6 (elem létének ellenőrzése)
*/
void test_f6() {
	int a[5] = { 1, 4, 7, 9, 10 };
	Set set = create_set(a, 5);

	bool result = is_contain(&set, 9);

	if (result)
		printf("F6: Ok \n");
	else
		printf("F6: Failed \n");
	free(set.storage);
}

/**
* Teszt: F7 (struktúrák egyezése)
*/
void test_f7() {
	int a[6] = { 1, 4, 7, 9, 10, 12 };
	int b[6] = { 1, 4, 7, 8, 10, 12 };
	Set seta = create_set(a, 6);
	Set setb = create_set(b, 6);

	bool result = compare(&seta, &setb);

	if (!result)
		printf("F7: Ok \n");
	else
		printf("F7: Failed \n");
	free(seta.storage);
	free(setb.storage);
}

/**
* Teszt: F8 (halmazok úniója)
*/
void test_f8() {
	int a[7] = { 0, 1, 4, 7, 9, 10, 12 };
	int b[8] = { 1, 4, 5, 7, 8, 10, 12, 14 };
	int c[10] = { 0, 1, 4, 5, 7, 8, 9, 10, 12, 14 };
	Set seta = create_set(a, 7);
	Set setb = create_set(b, 8);
	Set expected = create_set(c, 10);

	Set merged = merge(&seta, &setb);

	check_solution("F8", &merged, &expected);
	free(seta.storage);
	free(setb.storage);
	free_set(&merged);
	free(expected.storage);
}

/**
* Teszt: F9 (halmazok különbsége)
*/
void test_f9() {
	int a[7] = { 0, 1, 4, 7, 9, 10, 12 };
	int b[8] = { 1, 4, 5, 7, 8, 10, 12, 14 };
	int c[2] = { 0, 9 };
	Set seta = create_set(a, 7);
	Set setb = create_set(b, 8);
	Set expected = create_set(c, 2);

	Set diffed = diff(&seta, &setb);

	check_solution("F9", &diffed, &expected);
	free(seta.storage);
	free(setb.storage);
	free_set(&diffed);
	free(expected.storage);
}

/**
* Teszt: F10 (halmazok metszete)
*/
void test_f10() {
	int a[7] = { 0, 1, 4, 7, 9, 10, 12 };
	int b[8] = { 1, 4, 5, 7, 8, 10, 12, 14 };
	int c[5] = { 1, 4, 7, 10, 12 };
	Set set = create_set(a, 7);
	Set setb = create_set(b, 8);
	Set expected = create_set(c, 5);

	Set cross = section(&set, &setb);

	check_solution("F10", &cross, &expected);
	free(set.storage);
	free(setb.storage);
	free_set(&cross);
	free(expected.storage);
}

/**
* Teszt: F12 (halmazok Descartes-szorzata)
*/
void test_f12() {
	int a[7] = { 0, 1, 4 };
	int b[8] = { 2, 3, 5 };
	int c[9] = { 0, 0, 0, 1, 1, 1, 4, 4, 4 };
	int d[9] = { 2, 3, 5, 2, 3, 5, 2, 3, 5 };
	Set set = create_set(a, 3);
	Set setb = create_set(b, 3);

	Pairs pairs = descartes(&set, &setb);

	bool correct = true;
	if (pairs.length != 9) {
		correct = false;
	}
	for (int i = 0; correct && i < pairs.length; ++i) {
		// a tömbök rendezettek, így egyező elemeknél elég az azonos helyen állók összehasonlítása
		if (pairs.item1[i] != c[i] || pairs.item2[i] != d[i]) { 
			correct = false;
		}
	}

	if (correct)
		printf("F12: Ok \n");
	else
		printf("F12: Failed \n");

	free(set.storage);
	free(setb.storage);
	free_pairs(&pairs);
}

/**
* Teszt: F11 (halmaz kiírása)
*/
void test_f11() {
	int a[5] = { 1, 4, 7, 9, 10 };
	Set set = create_set(a, 5);

	print_set(&set);
	free_set(&set);
}

/* ************************************************************
*/
void check_solution(const char* test_name, const Set* calculated, const Set* expected) {

	bool correct = true;
	if (calculated->length != expected->length) {
		correct = false;
	}


	for (int i = 0; correct && i < calculated->length; ++i) {
		// a tömbök rendezettek, így egyező elemeknél elég az azonos helyen állók összehasonlítása
		if (calculated->storage[i] != expected->storage[i]) {  
			correct = false;
		}
	}

	if (correct)
		printf("%s: Ok \n", test_name);
	else
		printf("%s: Failed \n", test_name);
}

Set create_set(int* items, int length) {
	Set set;
	set.length = length;
	set.storage = (int*)malloc(length * sizeof(int));

	for (int i = 0; i < length; ++i) {
		set.storage[i] = items[i];
	}

	return set;
}