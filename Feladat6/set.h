#ifndef __SET__
#define __SET__

#include <stdbool.h>


typedef struct {
	int length;
	int* storage;
} Set;

Set create_empty();

void init(Set* set);

Set copy(const Set* set);

void add(Set* set, int item);

void add_array(Set* set, int* items, int num_items);

bool is_contain(const Set* set, int item);

bool compare(const Set* a, const Set* b);

Set merge(const Set* a, const Set* b);

Set diff(const Set* a, const Set* b);

Set section(const Set* a, const Set* b);

void print_set(const Set* set);

typedef struct {
	int length;
	int* item1;
	int* item2;
} Pairs;

Pairs descartes(const Set* a, const Set* b);

void free_set(Set* set);

void free_pairs(Pairs* pairs);

#endif __SET__
