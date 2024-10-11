/* copy_file2.c     - Copies a source file into a target file taken from the user input. 
                        If a target file does not exist the program will create a new one.
                        Program needs to change all characters into capitale ones and 
                        uses the text mode
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define FILE_NAME   80   

int main( void )
{
    FILE * sf, * tf;
    int ch;
    char s_file[ FILE_NAME ];
    char t_file[ FILE_NAME ];

    puts( "Enter the file name to be copied: " );
    scanf( "%s", s_file );
    if(( sf = fopen( s_file, "r" )) == NULL )
    {
        fprintf( stderr, "The file \"s_file\" can not be opened.\n" );
        exit( EXIT_FAILURE );
    }

    puts( "Enter the file name where the content must be copied: " );
    scanf( "%s", t_file );
    if(( tf = fopen( t_file, "w" )) == NULL )
    {
        fprintf( stderr, "The target file can not be opened.\n" );
        exit( EXIT_FAILURE );
    }

    while(( ch = getc( sf )) != EOF )
        putc( toupper( ch ), tf );

    if( fclose( sf ) != 0 ||
        fclose( tf ) != 0 )
        fprintf( stderr, "Error while closing files.\n" );

    return 0;
}