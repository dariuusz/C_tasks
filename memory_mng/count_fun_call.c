/* Program counts how many time a function was called using static variable */
#include <stdio.h>
int count = 0;
void print_func();

int main( void )
{
    extern int count;

    for( int i = 0; i < 10; i++ )
        print_func();
    return 0;
}

void print_func( void )
{
    /* Prints local and static variable with external linkage */
    int counter = 0;
    counter++;
    count++;

    printf( "Count %d, Counter %d \n", count, counter );
}