/* investments.c    -   calculates the difference between two types of investments */
#include <stdio.h>

int main( void )
{
    float ewa, kasia;
    ewa = kasia = 100;
    for( int years = 0 ; ewa >= kasia; years++ )
    {
        ewa = ewa + 100 * 0.1;
        kasia = kasia + kasia * 0.05;
        printf("Ewa %.2f %10.2f kasia.\n", ewa, kasia );
        
        if( kasia > ewa )
        {
            printf( "After %d years Kasia gained more profit from here investments.\n", years );
        }
    }

    return 0;
}