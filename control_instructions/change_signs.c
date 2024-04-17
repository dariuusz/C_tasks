/*change_signs.c    -   reads stdin and replaces each '.' with '!', and '!' with '!!' */
#include <stdio.h>
#include <ctype.h>
#define EXCLAMATION_MARK    '!'
#define DOUBLE_EXCLAMATION_MARK     "!!"
int main( void )
{
    char ch;

    printf( "The program read given input till '#' and replaces '.' with '!' " );
    printf( "amd '!' with '!!'.\n" );

    while(( ch = getchar()) != '#')
    {
        if( ch == '.' )
            putchar( EXCLAMATION_MARK );
        else if( ch == '!' )
            printf( DOUBLE_EXCLAMATION_MARK );
        else
            putchar( ch );
    }
    printf( "See you next time.\n" );
}