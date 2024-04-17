/* first_numbers.c  -   accpet user's input and returns all first numbers less and equal given number*/
#include <stdio.h>
#include <stdbool.h>

bool is_prime( int number )
{
    if( number < 2 )
    {
        return false;
    }

    for( int i = 2; i * i <= number; i++ )
    {
        if( number % i == 0 )
        {
            return false;
        }
    }

    return true;
}

int main( void )
{
    int number;

    scanf( "%d", &number );

    for( int i = 2; i <= number ; i++ )
    {
        if( is_prime( i ))
            printf( "%d\n", i );
        
    }
    printf( "\n" );

    return 0;
}