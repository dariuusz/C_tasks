/* calculate_all_signs.c    -   calculates the number of occurences of all specific signs and displys them */
#include <stdio.h>
#define SPACE ' '
#define NEW_LINE '\n'

int main( void )
{
    int new_lines = 0;
    int spaces = 0;
    int all_signs = 0;
    char ch;

    printf( "Program counts the number of new lines, spaces and the rest signs until the sign #.\n" );

    while(( ch = getchar( )) != '#' )
    {
        if( ch == SPACE )
            spaces++;
        else if( ch == NEW_LINE )
            new_lines++;
        else
            all_signs++;
    }

    printf( "There are %d numbers of new lines, %d spaces and %d all signs", new_lines, spaces, all_signs );
    return 0;
}