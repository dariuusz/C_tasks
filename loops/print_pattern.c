/* print_pattern.c  -   prints a F FE FED FEDC FEDCB FEDCBA, each in the new line*/
#include <stdio.h>
#define ROW         7

int main( void )
{
    char letter;
    int rzad;
    int column;

    for( rzad = 0; rzad < ROW; rzad++ )
    {
        for( letter = 'F', column = 0; column < rzad; letter--, column++ )
            printf( "%c", letter );
        printf( "\n" );
    }
    return 0;
}