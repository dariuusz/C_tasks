/*change_signs.c    -   reads stdin and replaces each '.' with '!', and '!' with '!!' using switch statement*/
#include <stdio.h>
#include <ctype.h>
#define EXCLAMATION_MARK    '!'
#define DOUBLE_EXCLAMATION_MARK     "!!"

int main( void )
{
    char ch;

    printf( "The program read given input till '#' and replaces '.' with '!' " );
    printf( "amd '!' with '!!' using switch statement.\n" );

    while(( ch = getchar( )) != '#' )
    {
        switch( ch )
        {
            case '.' :
                putchar( EXCLAMATION_MARK );
                break;
            case '!':
                printf( DOUBLE_EXCLAMATION_MARK );
                break;
            default:
                putchar( ch );
        }
    }
    printf( "See you next time." );
    return 0;
}