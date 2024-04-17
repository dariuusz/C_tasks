/* lucky_JIm.c  -   won 1 000 000 dollars and program calculates how many years it will take to withdraw all by takins out 100 000 every year*/
#include <stdio.h>


int main( void )
{
    long JIM = 1000000;

    printf( "Jim has %ld.\n", JIM );

    for( int years = 0; JIM > 0; years++ )
    {
        JIM = JIM + JIM * 0.08;
        JIM -= 100000;
        if( JIM <= 0 )
        {
            printf( "It has taken him %d years to withdraw it all.\n", years );
        }
    }
    return 0;
}