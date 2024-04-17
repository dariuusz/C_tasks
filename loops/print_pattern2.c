/* print_pattern2.c     -   prints A AB ABC ABCD ABCDE ABCDEF in new lines*/
#include <stdio.h>

int main( void )
{
    const int ROWS = 7;
    char letter;
    int row, columns;

    for( row = 0; row < ROWS; row++ )
    {
        for( letter = 'A', columns = 0; columns < row; columns++, letter++ )
            printf( "%c", letter );
        printf( "\n" );
    }
    return 0;
}