/* read_numbers_to_array.c  -   writes numbers to the array*/
#include <stdio.h>
#define SIZE    8

int main( void )
{
    int array[ SIZE ];

    printf( "This program takes 8 numbers and returns them in reverse order.\n" );

    for( int index = 0 ; index < SIZE ; index++ )
        scanf( "%d", &array[ index ]);

    for( int index = SIZE ; index >= 0 ; index-- )
        printf( "%d\n", array[ index ]);
    return 0;
}