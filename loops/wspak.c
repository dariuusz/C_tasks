/* wspak.c  -   display taken word backward*/
#include <stdio.h>
#include <string.h>

int main( void )
{
    int size;
    char word[ size ];

    printf( "This application display the word backward.\n" );
    printf( "Enter your word: " );
    scanf( "%s", word );

    for( int index = strlen( word ) ; index >= 0 ; index-- )
        printf( "%c", word[ index ]);
    printf( "\n" );
    return 0;
}