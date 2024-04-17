/* rec_power.c  -   it has the same functionalities as file power.c but it uses recursion*/
#include <stdio.h>
double power( double, int );

int main( void )
{
    double x, x_pow;
    int n;

    printf( "Enter the number and the power number" );
    printf( " to which the number will be increased." );
    printf( " Enter q to exit.\n" );

    while( scanf( "%lf %d", &x, &n ) == 2 )
    {
        if( x == 0 && n == 0 )
        {
            printf( "Invalid operation.\n" );
            continue;
        }
        printf( "%.3g to power %d equals %.5g\n", x, n, power( x, n ));
        printf( "Enter another numbers.\n" );

    }
    printf( "Goodbye!\n" );
    return 0;
}

double power( double a, int b )
{
    if (b == 0)
    {
        return 1.0;
    }
    else if (b > 0)
    {
        return a * power(a, b - 1);
    }
    else // b < 0
    {
        return 1.0 / (a * power(a, -b - 1));
    }
}