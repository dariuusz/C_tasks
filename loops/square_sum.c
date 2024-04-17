/* square_sum.c     -   takes to numbers and calculates the sum of the numbers between them*/
#include <stdio.h>
int square( int number );
int sum( int f_number, int s_number );

int main( void )
{
    int f_number, s_number;

    printf( "This program calculates the sum of the numbers that are between two given numbers.\n" );
    printf( "Enter two numbers: \n" );
    while( scanf( "%d%d", &f_number, &s_number ) == 2 )
    {
        if( f_number >= s_number)
            break;
        printf( "The sum of squares from %d to %d is %d\n", square( f_number ), square( s_number ), sum( f_number , s_number ));        
        
        printf( "Enter two numbers: \n" );
    }
    printf( "End of the program \n" );
    return 0;
}

int square( int number )
{
    return number * number;
}

int sum( int f_number, int s_number )
{
    int sum;
    for( f_number ; f_number <= s_number ; f_number++ )
        sum += square( f_number );
    printf( "Sum is %d\n", sum );
    return sum;
} 