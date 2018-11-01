
#include <stdio.h>
#include <stdlib.h>

#include "set.h"


Set create_empty() {
	Set set = { 0, NULL };
	return set;
}

void init(Set* set) {
	if (set->storage != NULL) {  // ha már üres, nem kell csinálni semmit
		free(set->storage);
		set->storage = NULL;
		set->length = 0;
	}
}

Set copy(const Set* set) {
	Set replica;
	replica.length = set->length;

	replica.storage = (int*)malloc(set->length * sizeof(int));  // elemek másolása másik memória területre
	for (int i = 0; i < replica.length; ++i) {
		replica.storage[i] = set->storage[i];
	}

	return replica;
}

void add(Set* set, int item) {
	if (set->length == 0) {
		set->storage = (int*)malloc(1 * sizeof(int));
		set->storage[0] = item;
		set->length = 1;
	}
	else if(!is_contain(set, item)){
		int new_length = set->length + 1;
		int* temp = (int*)malloc(new_length * sizeof(int));

		bool placed = false;  // csak egyszer szúrjuk be az elemet
		int j = 0;
		for (int i = 0; i < set->length; ++i) {
			if (!placed && item < set->storage[i]) {  // növekvő sorrendben tárol 
				temp[j] = item;   
				temp[j + 1] = set->storage[i];
				j = j + 2;  // két elem lett egyszerre beszúrva
				placed = true;
			}
			else {
				temp[j] = set->storage[i];
				j += 1;
			}
		}

		if (!placed)
			temp[j] = item;  // ha a végére kell az elemet szúrni

		set->length = new_length;
		free(set->storage);
		set->storage = temp;
	}
}

void add_array(Set* set, int* items, int num_items) {
	for (int i = 0; i < num_items; ++i) {
		add(set, items[i]);  // újra hasznosítjuk a függvényt (lehetne hatékonyabban, de most nem ez a cél)
	}
}

bool is_contain(const Set* set, int item) {
	for (int i = 0; i < set->length; ++i) {
		if (set->storage[i] == item)
			return true;
	}

	return false;
}

bool compare(const Set* a, const Set* b) {
	if (a->length != b->length) {
		return false;
	}

	for (int i = 0; i < a->length; ++i) {
		if (a->storage[i] != b->storage[i]) {   // a tömbök rendezettek, így egyező elemeknél elég az azonos helyen állók összehasonlítása
			return false;
		}
	}

	return true;
}

Set merge(const Set* a, const Set* b) {
	Set merged = create_empty();
	add_array(&merged, a->storage, a->length);
	add_array(&merged, b->storage, b->length);
	return merged;
}

Set diff(const Set* a, const Set* b) {
	Set diffed = create_empty();
	for (int i = 0; i < a->length; ++i) {
		if (!is_contain(b, a->storage[i])) {
			add(&diffed, a->storage[i]);
		}
	}

	return diffed;
}

Set section(const Set* a, const Set* b) {
	Set common = create_empty();
	for (int i = 0; i < a->length; ++i) {
		if (is_contain(b, a->storage[i])) {
			add(&common, a->storage[i]);
		}
	}

	return common;
}

void print_set(const Set* set) {
	for (int i = 0; i < set->length; ++i) {
		printf("%d ", set->storage[i]);
	}
	printf("%\n");
}

Pairs descartes(const Set* a, const Set* b) {
	Pairs pairs;
	pairs.length = a->length * b->length;
	pairs.item1 = (int*)malloc(pairs.length * sizeof(int));
	pairs.item2 = (int*)malloc(pairs.length * sizeof(int));

	int k = 0;
	for (int i = 0; i < a->length; ++i) {
		for (int j = 0; j < b->length; ++j) {
			pairs.item1[k] = a->storage[i];
			pairs.item2[k] = b->storage[j];
			k += 1;
		}
	}

	return pairs;
}

void free_set(Set* set) {
	if (set->length != 0 && set->storage != NULL) {
		set->length = 0;
		free(set->storage);
		set->storage = NULL;
	}
}

void free_pairs(Pairs* pairs) {
	if (pairs->length != 0 && pairs->item1 != NULL && pairs->item2 != NULL) {
		pairs->length = 0;
		free(pairs->item1);
		free(pairs->item2);
		pairs->item1 = NULL;
		pairs->item2 = NULL;
	}
}
