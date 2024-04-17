/* harmonic_mean.c  -   accepts to numbers, passes them into a function that calculates the harmonic mean and return it*/
#include <stdio.h>
double harmonic_mean( double, double );

int main( void )
{
    double num1, num2;
    printf( "Enter two numbers to calculate the harmonic mean number.\n" );

    while( scanf( "%lf %lf", &num1, &num2 ) == 2 )
    {
        if( scanf( "%*s" ) )
            continue;
        printf("The harmonic mean is: %lf\n", harmonic_mean( num1, num2 ));
        printf( "Enter another two numbers ( Enter q to exit ): \n" );
    }

    return 0;
}

double harmonic_mean( double num1, double num2 )
{

    num1 = 1 / num1;
    num2 = 1 / num2;
    return 2 / ( num1 + num2 );

}