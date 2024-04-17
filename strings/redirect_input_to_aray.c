/* redirect_input_to_array.c    -   accepts user input for n characters and redirect them into an array.*/
#include <stdio.h>

void write_characters( char *, int );

#define     SIGNS   30

int main( void )
{
    char array[ SIGNS ];
    printf( "Enter the string with any characters you want to.\n" );
    write_characters( array, SIGNS );
    printf( "Entered characters: %s", array );

    return 0;
}

void write_characters( char * array, int n )
{
    char * result;
    result = fgets( array, n, stdin );
    if( result )
    {
        while( *array != '\n' && *array != '\0' &&  *array != ' ' && *array != '\t')
            array++;

        *array = '\0';

    }
}