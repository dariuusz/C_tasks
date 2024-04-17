/* min_number.c     -   uses a function to pick up smalest number and return it*/
#include <stdio.h>
double min( double, double );

int main( void )
{
    double num1, num2;
    int condition;

    printf( "Enter two numbers: \n" );
    while(( condition = scanf( "%lf %lf", &num1, &num2 )) == 2 )
    {
        printf( "The smalest number is: %.2lf\n", min( num1, num2 ));
    } 
    return 0;
}

double min( double num1, double num2 )
{
    double min;
    if( num1 > num2 )
    {
        min = num2;
    }
    else
    {
        min = num1;
    }
    return min;
}