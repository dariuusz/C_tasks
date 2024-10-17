/* print_rows.c     - Accepts 2 files passed in command line and prints their rows
                        interchanchaebly. 1 file 1 row, 2 file 1 row, etc.
*/

#include <stdio.h>
#include <stdlib.h>

#define FILE_ERROR      1
#define ARGUMENT_ERROR  2

/* functions */
FILE * OpenFile( const char * filename, const char * mode );
void HandleError( const char * message, const char * filename, FILE * file, int errorType );

int main( int argc, char * argv[ ])
{
    FILE * ff, *sf;
    int ch;

    if( argc != 3 )
        HandleError( "Usage: %s <file1> <file2>", argv[ 0 ], NULL, ARGUMENT_ERROR );

    ff = OpenFile( argv[ 1 ], "r" );
    sf = OpenFile( argv[ 2 ], "r" );


    return 0;
}

FILE * OpenFile( const char * filename, const char * mode )
{
    /*Opens file
        @param const char *         filename
        @param const char *         mode
        @return FILE *              opened file
    */
    FILE * file;
    file = fopen( filename, mode );

    if( file == NULL )
        HandleError( "Cannot open file.", filename, file, FILE_ERROR );
    return file;
}

void HandleError( const char * message, const char * filename, FILE * file, int errorType )
{
    /* Handles errors
        @param const char *         message
        @param const char *         filename
        @param FILE *               opened file
        @param int                  defined error type
        @return EXIT_FAILURE        exits program
    */
    if( errorType == FILE_ERROR )
        fprintf( stderr, "%s: %s.\n", message, filename );
    else if( errorType == ARGUMENT_ERROR )
        fprintf( stderr, message, filename );
    exit( EXIT_FAILURE );
}