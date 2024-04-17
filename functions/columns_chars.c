/* columns_chars.c   -   displays sign in a column */
#include <stdio.h>
void columns_chars( char, int, int );

int main( void )
{
    int num1, num2;
    char character, ch;
    printf( "Enter character: ");
    scanf( "%c", &character );
    printf( "Enter two numbers: ");
    scanf( "%d %d", &num1, &num2 );
   
    columns_chars( character, num1, num2 );
    return 0;
}

void columns_chars( char ch, int num1, int num2 )
{
    while( num1++, num1 <= num2 )
    {
        printf( "%c\n", ch );
    }
}