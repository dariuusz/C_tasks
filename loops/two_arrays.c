/* two_arrays.c -   creates two arrays and in the second one it saves the cumulitive sum of the first elements*/
#include <stdio.h>
#define SIZE    8

int main( void )
{
    int f_array[ SIZE ], s_array[ SIZE ], count = 0;
    printf( "Enter the 8 numbers: \n" );

    for( int index = 0 ; index < SIZE ; index++ )
        scanf( "%d", &f_array[ index ]);

    for( int index = 0 ; index < SIZE ; index++ )
    {
        if( index == 0 )
            s_array[ index ] = f_array[ index ];
        else
            s_array[ index ] = f_array[ index ] + s_array[ index - 1 ];
    }

    while( count < SIZE )
    {
        printf( "%5d", f_array[ count ]);
        count++;
    }
    count = 0;
    printf("\n");
        while( count < SIZE )
    {
        printf( "%5d", s_array[ count ]);
        count++;
    }

    return 0;
}