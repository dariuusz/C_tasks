/* two_dimensional_array.c  -   initialises two dimensional array and copy their content into another one.*/
#include <stdio.h>
#define     ROWS        3
#define     COLUMNS     3
#define     ROWS2       5

void copy_array( int [][ ROWS ], int [][ ROWS ]);
void copy_vla( int, int, double[ * ][ * ], double[ * ][ * ]);

int main( void )
{
    int two_dim_array[ COLUMNS ][ ROWS ] = 
    {
        { 3, 5, 7 },
        { 4, 9, 2 },
        { 8, 7, 1 }
    };

    double vla_array[ COLUMNS ][ ROWS2 ] =
    {
        { 2.2, 1.1, 4.2, 5.6, 7.2 },
        { 5.1, 1.3, 8.7, 3.3, 6.3 },
        { 6.5, 7.7, 2.2, 1.4, 1.1 }
    };

    int targeted_array[ ROWS ][ COLUMNS ];
    double targeted_array2[ ROWS2 ][ COLUMNS ];
    int i, j;

    copy_array( two_dim_array, targeted_array);
    for( i = 0; i < COLUMNS; i++ )
    {
        for( j = 0; j < ROWS; j++ )
        {
            printf( "%d ", targeted_array[ i ][ j ]);
        }
        printf( "\n" );
    }
    printf( "\n\nVLA approach\n" );
    copy_vla( COLUMNS, ROWS2, vla_array, targeted_array2 );
    for( i = 0; i < COLUMNS; i++ )
    {
        for( j = 0; j < ROWS; j++ )
        {
            printf( "%d ", targeted_array[ i ][ j ]);
        }
        printf( "\n" );
    }   

    return 0;
}

void copy_array( int source[][ ROWS ], int targeted_array[][ ROWS ])
{
    int i, j;
    for( i = 0; i < COLUMNS; i++ )
    {
        for( j = 0; j < ROWS; j++ )
        {
            targeted_array[ i ][ j ] = source[ i ][ j ];
        }
    }
}

void copy_vla( int columns, int rows, double source [ rows ][ columns ], double target[ rows ][ columns ])
{
    int i, j;
    for( i = 0; i < columns; i++ )
    {
        for( j = 0; j < rows; j++ )
        {
            target[ i ][ j ] = source[ i ][ j ];
        }
    }

}