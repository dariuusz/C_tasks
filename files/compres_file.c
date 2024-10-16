/* compres_file.c   -   Compresses a file by two thirds using very simple algorithm. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME   50   

/* functions */
void change_extension( const char * source_file, char * target_file );

int main( void )
{
    FILE *sf, *tf;
    int ch;
    char source_file[ FILE_NAME ];
    char target_file[ FILE_NAME ];
    int counter = 0;

    puts( "Enter the name of source file: " );
    scanf( "%49s", source_file ); 
    change_extension( source_file, target_file );

    if(( sf = fopen( source_file, "r" )) == NULL )
    {
        fprintf( stderr, "Error while opening the file: %s\n", source_file );
        exit( EXIT_FAILURE );
    }

    if(( tf = fopen( target_file, "w" )) == NULL )
    {
        fprintf( stderr, "Error while opening the file: %s\n", target_file );
        exit( EXIT_FAILURE );
    }

    while(( ch = getc( sf )) != EOF )
        if( counter++ % 3 == 0 )
            putc( ch, tf );
    
    if( fclose( sf ) || fclose( tf ) != 0 )
        fprintf( stderr, "Error while closing files.\n");

    return 0;
}

void change_extension( const char * source_file , char * target_file )
{
    /* Changes extension of file into .red whether or not prefiks '.' is found
        @param const char           source_file
        @param char                 target_file
     */
    char * dot_position = strrchr( source_file, '.' );

    if( dot_position != NULL )
    {
        strncpy( target_file, source_file, dot_position - source_file );
        target_file[ dot_position - source_file ] = '\0';
        strcat( target_file, ".red" );
    }
    else                /* if '.' not found in source file */
    {
        strncpy( target_file, source_file, FILE_NAME - 5 );
        target_file[ FILE_NAME - 5 ] = '\0';
        strcat( target_file, ".red" );
    }    
}