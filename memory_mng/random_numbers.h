
#include <stdio.h>
#include <string.h>

static unsigned int seed = 7;
#define NUMBERS             100
#define NUMBERS2            1000

int random();
void produce_random_numbers( int [] );
void selection_sort( int [] );
void print_numbers( int [] );
