/* writes_power_numbers.c   -   writes 8 power number into the array */
#include <stdio.h>
#define SIZE    8

int main( void )
{
    int array[ SIZE ], count;

    for( int index = 0 ; index < SIZE  ; index++ )
        scanf( "%d", &array[ index ]);
    
    while( count < SIZE )
    {
        printf( "%d to power is %d\n", array[ count ], array[ count ] * array[ count ]);
        count++;
    }
    return 0;
}