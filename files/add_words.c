/* add_words.c      - This is a modification of an example from the book. The modification
                        involves numbering words in the order in which there were 
                        added to the list. During the second time you start the program
                        numbering should start from the point where it was terminatted.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX     41              // word's length

int main( void )
{
    FILE * file;
    char word[ MAX ];
    int wordNumber = 0;


    if(( file = fopen( "words.txt", "a+")) == NULL )
    {
        fprintf( stderr, "Can not open file \"words\".\n" );
        exit( EXIT_FAILURE );
    }
    
    // Check the file content to find the last word number
    while( fscanf( file, "%d %40s", &wordNumber, word ) == 2 )
        ; // This loop goes to the end of the file and finds the last word number

    // Increment to start numbering from the next word
    wordNumber++;
    
    puts( "Enter words that should be added into file:" );
    puts( "To exit, enter #" );

    while(( fscanf( stdin, "%40s", word ) == 1 ) && ( word[ 0 ] != '#' ))
    {
        fprintf( file, "%d %s\n", wordNumber, word );
        wordNumber++;
    }
    puts( "File content: " );
    
    rewind( file );

    while( fscanf( file, " %d %s", &wordNumber, word ) == 2 )
        fprintf( stdout, "%d %s\n", wordNumber, word );

    puts( "Done!." );

    if( fclose( file ) != 0 )
        fprintf( stderr, "Error while closing file.\n" );

    return 0;
}