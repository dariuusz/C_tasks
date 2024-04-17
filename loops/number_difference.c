/* number_difference.c  -   displays the difference between two numbers when divided by their ratio*/
#include <stdio.h>
float difference_divisble_numbers( float f_number, float s_number );

int main( void )
{
    float f_number, s_number;

    printf( "This application calculates the difference between ratio of two numbers.\n" );
    printf( "Enter two numbers: \n" );
    while( scanf( "%f%f", &f_number, &s_number) == 2 )
    {
        printf( "The difference is %f \n", difference_divisble_numbers( f_number, s_number ) );
        printf( "Enter another numbers:\n " );
    }
    return 0;
}

float difference_divisble_numbers( float f_number, float s_number )
{
    return( f_number - s_number ) / ( f_number * s_number );
}