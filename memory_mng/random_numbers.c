/* random_numbers.c     Generates 100 numbers from a range 1 - 10 in descending order
                        Sorts numbers using selection sort*/
#include <stdio.h>
#include <string.h>

static unsigned int seed =  7;
#define NUMBERS             100

int random();
void produce_random_numbers( int [] );
void selection_sort( int [] );
void print_numbers( int [] );

int main( void )
{   
    int numbers[ NUMBERS ];
    produce_random_numbers( numbers );
    selection_sort( numbers );
    print_numbers( numbers );
        
    return 0;
}

int random( void )
{
    /* Generates random number*/
    seed = seed * 123456789 + 123454;
    return ( int )( seed / 65536 ) % 10 + 1;
}

void produce_random_numbers( int * array )
{
    /* Generates n = NUMBERS random numbers
        @param  int             an array
        @return                 nothing
    */
    for( int i = 0; i < NUMBERS; i++ )
        array[ i ] = random();
}

void selection_sort( int * array)
{
    /* Selection sort 
        @param  int         an array
        @return             nothing
    */
    int temp;
    for( int i = 0; i < NUMBERS - 1; i ++ )
    {
        for( int j = i + 1; j < NUMBERS; j++ )
            if( array[ i ] < array[ j ])
            {
                temp = array[ i ];
                array[ i ] = array[ j ];
                array[ j ] = temp;
            }
    }
}

void print_numbers( int * array )
{
    /* Prints all numbers
        @param  int         an array
        @return             nothing
    */
    for( int i = 0; i < NUMBERS; i++ )
        printf( "%d\n", array[ i ]);
}