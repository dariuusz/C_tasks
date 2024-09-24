
#include <stdio.h>
#include <string.h>

static unsigned int seed = 7;
#define NUMBERS             100
#define NUMBERS2            1000
#define SEEDS               10
#define NUMBER_COUNTS       10


/* returns value */
unsigned int random();
unsigned int custom_random( unsigned int * );
int random_seeds( unsigned int * );

/* void functions*/
void produce_random_numbers( int [] );
void selection_sort( int [] );
void print_numbers( int [] );
void generate_numbers( int [], unsigned int []);
