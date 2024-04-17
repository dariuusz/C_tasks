/* fibonacci_loop.c     - uses the loop to print fibonacci sequence*/
#include <stdio.h>
void Fibonacci( unsigned long );

int main( void )
{
    unsigned long number;
    printf( "This program display fibonnaci sequence.\n" );
    printf( "Enter the upper threshold when calculation should stop.\n" );
    scanf( "%lu", &number );
    Fibonacci( number );

    return 0;
}

void Fibonacci( unsigned long number )
{
    unsigned long fst_num, snd_num, next_num;
    fst_num = 0, snd_num = 1, next_num;

    printf( "%lu  %lu", fst_num, snd_num );
    next_num = fst_num + snd_num;

    while( next_num < number )
    {
        printf( "  %lu", next_num );
        fst_num = snd_num;
        snd_num = next_num;
        next_num = fst_num + snd_num;        
    }
}