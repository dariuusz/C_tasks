/* create_arrays.c  takes user inputs crating three arrays, then merges it into one two dimensional array
    calculates a mean of each array and for all of them, find the biggest value and print all values */

#include <stdio.h>
#include <stdbool.h>

#define COLUMNS     3
#define ROWS        5

void validate_number( int *, int *, double[ * ][ * ]);
void print_array( double[ ][ ROWS ]);
void calculate_set_mean( double [ ][ ROWS ]);
double calculate_mean( double[ ][ ROWS ]);
double biggest_number( double [ ][ ROWS ]);

int main( void )
{

    double two_dim_array[ COLUMNS ][ ROWS ];
    int i, j;
    int count = 0;
    
    for( i = 0; i < COLUMNS; i++ )
    {
        printf( "Enter 5 numbers for set %d:\n", i + 1 );
        for( j = 0; j < ROWS; j++ )
        {
            validate_number( &i, &j, two_dim_array );
        }
    }

    print_array( two_dim_array );
    printf( "\n\n" );
    calculate_set_mean( two_dim_array );
    printf( "Mean of all sets is %.2f\n",  calculate_mean( two_dim_array ));
    printf( "\n\n" );
    printf( "Biggest number is %.2f\n", biggest_number( two_dim_array ));
    return 0;
}

void validate_number( int *column, int *row, double array[ *column ][ *row ])
{
    double input;
    while( true )
    {
        printf( "Enter number %d: ", *row + 1 );
        if( scanf( "%lf", &input ) != 1 || input < 0 )
        {
            printf( "Invalid input. Please enter a valid number.\n" );
            while ( getchar() != '\n' );     
        }
        else
        {
            array[ *column ][ *row ] = input;
            break;
        }
    }
}

void print_array( double array[ ][ ROWS ])
{
    int i, j;
    for( i = 0; i < COLUMNS; i++ )
    {
        for( j = 0; j < ROWS; j++ )
        {
            printf( "%.2f ", array[ i ][ j ]);
        }
        printf( "\n" );
    }
}

void calculate_set_mean( double array[ ][ ROWS ])
{
    double mean;
    int i, j;

    printf( "Mean values:\n" );
    for( i = 0; i < COLUMNS; i++ )
    {
        mean = 0;
        for( j = 0; j < ROWS; j++ )
        {
            mean += array[ i ][ j ];
        }
        mean /= ROWS;
        printf( "Mean of array %d is %.2f\n", i + 1, mean );
    }    
}

double calculate_mean( double array[ ][ ROWS ])
{
    double sum, mean;
    int i, j;

    printf( "Mean value: \n" );
    for( i = 0; i < COLUMNS; i++ )
    {
        sum = 0;
        for( j = 0; j < ROWS; j++ )
        {
            sum += array[ i ][ j ];
        }
        mean += sum;
    }
    return mean / ( ROWS * COLUMNS );    
}

double biggest_number( double array[ ][ ROWS ])
{
    double biggest = array[ 0 ][ 0 ];
    int i, j;

    for( i = 0; i< COLUMNS; i++ )
    {
        for( j = 1; j < ROWS; j++ )
        {
            if( array[ i ][ j ] > biggest )
            {
                biggest = array[ i ][ j ];
            }
        }
    }
    return biggest;
}