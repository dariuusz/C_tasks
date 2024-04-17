/* count_characters.c   -   calculates the occrences of all characters in the file.*/
#include <stdio.h>

int main( void )
{
    int character;
    int count = 0;

    printf( "The program calculates the number of characters in the file.\n\n" );

    while(( character = getchar()) != EOF )
    {    
        putchar( character );
        count++;
    }

    printf( "\n\nThere are %d characters.\n", count );
    return 0;
}