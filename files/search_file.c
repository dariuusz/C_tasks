/* search_file.c        This program accepts 2 arguments in command-line. The first is an array,
                        the second file name. The program should search the file and prints all
                        lines that contains the searched array.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH     255

int main( int argc, char * argv[] )
{

    if( argc != 3 )
    {
        fprintf( stderr, "Usage: %s <string> <filename>\n", argv[ 0 ]);
        exit( EXIT_FAILURE );
    }

    // Variables initialization after initial validation
    const char * searchString = argv[ 1 ];
    const char * fileName = argv[ 2 ];
    FILE * file;

    file = fopen( fileName, "r" );
    if( !file )
    {
        fprintf( stderr, "Can not open file.\n" );
        exit( EXIT_FAILURE );
    }

    // Line initialization
    char line[ MAX_LINE_LENGTH ];

    while( fgets( line, MAX_LINE_LENGTH, file ) != NULL )
    {
        //checking for searched string
        if( strstr( line, searchString ))
            printf( "%s", line );
    }

    if( fclose( file ) != 0 )
        fprintf( stderr, "Error while closing file.\n" );

    return 0;
}