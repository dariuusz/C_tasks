/* arrays_initialisation.c  -   initialises an array and copy its content into another two arrays. 
The first way uses pointers and the other one array notation.*/
#include <stdio.h>
#define SIZE    5
void copy_tab( double [], double [], int );
void copy_tab_pointers( double [], double [], int );
void copy_tab_pointers_out_of_range( double [], double [], double * );
void print_array( double [], int );

int main( void )
{
    double source[ 5 ] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double source2[ 7 ] = { 2.2, 3.2, 2.2, 1.1, 4.5, 6.7, 9.9 };
    double target1[ 5 ];
    double target2[ 5 ];
    double target3[ 5 ];
    double target4[ 3 ];
    

    int i;
    printf( "Source array\n" );
    print_array( source, SIZE );
    
    copy_tab( source, target1, SIZE );
    
    printf( "\n\nTarget 1 array\n" );
    print_array( target1, SIZE );

    copy_tab_pointers( source, target2, SIZE );

    printf( "\n\nTarget 2 array\n" );
    print_array( target2, SIZE );
    printf( "%.1lf  ", target2[ i ] );
    
    copy_tab_pointers_out_of_range( source, target3, source + 5 );

    printf( "\n\nTarget 3 array\n" );
    print_array( target3, SIZE );

    copy_tab( &source2[ 2 ], target4, 3 );
    printf( "\n\nCopying a few elements from the bigger array into a smaller one.\n" );
    print_array( target4, 3 );
    
    return 0;
}

void print_array( double array [], int size )
{
    int i;
    for( i = 0; i < size; i++ )
        printf( "%.1lf  ", array[ i ] );
}

void copy_tab( double source [], double target [], int size )
{
    int i;
    for( int i = 0; i < SIZE; i++ )
    {
        target[ i ] = source[ i ];
    }
}

void copy_tab_pointers( double source [], double target [], int size )
{
    int i;
    for( i = 0; i < SIZE; i ++, *source++ )
        target[ i ] = *source;
}

void copy_tab_pointers_out_of_range( double source [], double target [], double * out_element )
{
    int i;
    for( i = SIZE; i >= 0; i-- )
        target[ i ] = *( out_element-- );
}