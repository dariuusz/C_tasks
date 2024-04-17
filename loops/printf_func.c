#include <stdio.h>

int main( void )
{
    int k;

    for ( k = 1, printf( "%d: Czesc!\n", k); printf( "k = %d\n ", k ), k*k < 26; k +=2, printf( "Teraz k jest rowne %d\n", k))
        printf( "k w petli wynosi %d\n", k);
    return 0;
}