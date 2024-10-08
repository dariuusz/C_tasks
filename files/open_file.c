/* open_file.c      It is a simple program that opens a file by taking from user the name of a file.*/

#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int ch;
    FILE *wp;                           /* file pointer */
    unsigned long count = 0;

    if(( wp = fopen( "file1.txt", "r" )) == NULL )
    {
        printf( "Can not open a file %s\b", wp );
        exit( EXIT_FAILURE );
    }

    while(( ch = getc( wp )) != EOF )
    {
        putc( ch, stdout );
        count++;
    }
    fclose( wp );
    printf( "\nFile %s contains %lu characters.\git statusn", wp, count );
    return 0;
}