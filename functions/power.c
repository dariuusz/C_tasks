/* power.c  - uses a function to compute the power number. It is modified version from the chapter 6*/
#include <stdio.h>
double power( double, int );

int main( void )
{
    double x, x_pow;
    int n;

    printf( "Enter the number and the power number" );
    printf( "to which the number will be increased." );
    printf( "Enter q to exit.\n" );

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
    double pot = 1;
    int i;

    if( a == 0 && b > 0)
        pot = 0;

    if( b == 0 && a > 0 )
        pot = 1;
      
    for( i = 1; i <= b; i++ )
    {
        pot *= a;
    }
    
    if( a < 0 && b < 0 )
    {
        for( i = -1; i >= b; i-- )
        {
            pot = pot * a;
        }
        pot = 1 / pot;
    }

    return pot;
}