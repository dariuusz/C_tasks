/* display_key_value.c  -   accepts user's input or the text from a file and displays it in key-value format.
                            It should displays 10 key-value in one line.*/

#include <stdio.h>
#define SIGNS       10

int main( void )
{
    int character;
    int count;

    printf( "Program accept user's input or text's content and displays the characters " );
    printf( "with their key-values.\n\n" );

    while( count++, ( character = getchar( )) != EOF )
    {
        if( character != '\n' )
            printf( "%c - %d ", character, character );
        
        if( count % SIGNS == 0 )
            printf( "\n" );

        
    }

    printf( "\n Number of letters: %d \n", count );

    return 0;
}