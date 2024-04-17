/* read_stdinput.c  - readst the standard input to the end of the file and returns the aplhabetical occurence*/
#include <stdio.h>
#include <ctype.h>
int convert_to_number( int );

int main( void )
{
    int     ch;
    int     alph_reflection; 

    while(( ch = getchar( )) != EOF )
    {
        if( ch == '\n' )
                continue;
        if( isalpha( ch ))
        {
            printf( "%c :   %d\n", ch, convert_to_number( ch ));
        }
        else
        {
            printf( "%d\n", EOF );
        }

    }
    return 0;
}

int convert_to_number( int ch )
{
    int new_ch = toupper( ch );
    return new_ch - 64;
    
}