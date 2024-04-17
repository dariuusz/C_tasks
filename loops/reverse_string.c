/* reverse_string.c     -   displays the string in reverse order*/
#include <stdio.h>
#include <string.h>
#define SIZE    255

int main( void )
{
    char array[ SIZE ];
    int count = 0;

    scanf( "%s", array );

    for( int index = strlen( array ) ; index >= 0 ; index-- )
    {
        printf( "%c", array[ index ]);
        
    }
    return 0;
}