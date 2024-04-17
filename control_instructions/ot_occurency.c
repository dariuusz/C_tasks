/*ot_occurency.c    ->  accepts user's input and returns the number of 'ot' occurences*/
#include <stdio.h>
#include <ctype.h>
#define OT      'ot'

int main( void )
{
    char ch;
    char ch_previous = ' ';
    int count = 0;

    printf( "Program accepts user's input until appearence of 'ot' and " );
    printf( "returns the number of 'ot' occurences.\n" );

    while(( ch = getchar( )) != '#' )
    {        
        if( ch == 'o' )
            ch_previous = ch;
        if( ch == 't' && ch_previous == 'o' )
            count++;

        putchar( ch );
    }
    printf( "Occurences: %10d\n", count );
    printf( "See you next time." );
    return 0;
}