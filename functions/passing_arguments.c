/* passing_arguments.c  -   accepts three arguments in a function and prints the given character in the number of columns and rows */
#include <stdio.h>
void print_character( char, int, int );

int main( void )
{
    int rows, columns;
    char character;
    
    printf( "Enter the character: " );
    scanf( "%c", &character );

    printf( "Enter two numbers: \n" );
    scanf( "%d %d", &rows, &columns );
    print_character( character, rows, columns );

    return 0;
}

void print_character( char character, int rows, int columns )
{
    for( int i = 0; i < rows; i++ )
    {
        for( int j = 0; j < columns; j++ )
            printf( "%c", character );
        putchar( '\n' );
    }
}