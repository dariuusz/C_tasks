/* count_sum.c  -   takes positioned elements from two arrays, calculates it and save to the third array*/
#include <stdio.h>
#define SIZE        5

#define COLUMNS     3  
#define ROWS        5

void sum_elements( int [], int [], int [], int );
void doubling_value( int [][ ROWS ]);
void print_two_dim_array( int [][ ROWS ]);

int main( void )
{
    /* common arrays */
    int array1[ SIZE ] = { 2, 4, 6, 1, 9 };
    int array2[ SIZE ] = { 9, 1, 5, 6, 3 };
    int result[ SIZE ];

    /* two dimensional arrays*/
    int two_dim[ COLUMNS ][ ROWS ]= 
    {
        { 4, 6, 23, 78, 23 },
        { 65, 98, 33, 3, 4 },
        { 34, 55, 234, 43, 22 }
    };

    int i;


    sum_elements( array1, array2, result, SIZE );
    printf( "Elements in result array: \n" );
    for( i = 0; i < SIZE; i++ )
        printf( "%d ", result[ i ]);    

    printf( "\n\nTwo dimensional array:\n" );
    print_two_dim_array( two_dim );
    printf( "\nNew values:\n" );
    doubling_value( two_dim );
    print_two_dim_array( two_dim );

    return 0;
}

void sum_elements( int source1[], int source2[], int result[], int size )
{
    int i;

    for( i = 0; i < size; i++ )
    {
        result[ i ] = source1[ i ] + source2[ i ];
    }
}

void doubling_value( int source[ ][ ROWS ] )
{
    int i, j;
    for( i = 0; i < COLUMNS; i++ )
    {
        for( j = 0; j < ROWS; j++ )
        {
            source[ i ][ j ] *= 2;
        }
    }
}

void print_two_dim_array( int source[ ][ ROWS ] )
{
    int i, j;
    for( i = 0; i < COLUMNS; i++ )
    {
        for( j = 0; j < ROWS; j++ )
        {
            printf( "%d ", source[ i ][ j ]);
        }
        printf( "\n" );
    }

}