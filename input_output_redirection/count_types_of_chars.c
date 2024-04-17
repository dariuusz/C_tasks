/* count_types_of_chars.c   -   counts number of small and capital letters, as well as the other characters.c*/

#include <stdio.h>

int main( void )
{
    printf( "The program count occurences of small and capital letters. " );
    printf( "Also it counts the rest of characters in the file or typed by a user.\n\n" );

    int characters, small_letters = 0, capital_letters = 0, other_chars = 0, total = 0;

    while( ++total, ( characters = getchar()) != EOF )
    {
        if( characters >= 'A' && characters <= 'Z' )
        {
            capital_letters++;
        }
        else if( characters >= 'a' && characters <= 'z' )
        {
            small_letters++;
        }
        else
        {
            other_chars++;
        }
    }
    printf( "\n\n*********************************************************\n" );
    printf( "Total characters : %d\n", total );
    printf( "Small letters :    %d                 Capital letters :    %d\n", small_letters, capital_letters );
    printf( "Other characters:  %d\n ", other_chars );    
    return 0;
}