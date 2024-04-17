/* bigger_number.c  -   accepts user two numbers and assign the biggest number to both of them.*/
#include <stdio.h>
void bigger_number( double *, double * );

int main( void )
{
    double num1, num2;

    printf( "Enter two numbers to check which one is bigger.\n" );

    while( scanf( "%lf %lf", &num1, &num2 ) == 2 )
    {
        printf( "Number 1: %lf      Number 2: %lf\n", num1, num2 );
        bigger_number( &num1, &num2 );
        printf( "Number 1: %lf      Number 2: %lf\n", num1, num2 );
    }
    return 0;
}

void bigger_number( double * num1, double * num2 )
{
    double temp;

    if( *num1 > *num2 )
        *num2 = *num1;
    else
        *num1 = *num2;
}