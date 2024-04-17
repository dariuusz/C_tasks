/* display_asci_reflection.c    -   displays the asci reflection. 8 pair-signs in a line.*/
#include <stdio.h>
#define SIGNS_IN_LINE   9

int main( void )
{
    char ch;
    int counter = 0;

    while(( ch = getchar()) != '#' )
    {
        counter++;
        if(( counter % SIGNS_IN_LINE ) != 0 )
            printf( "%2.c %2.d ", ch, ch );
        else
            putchar( '\n' );
    }
    return 0;
}