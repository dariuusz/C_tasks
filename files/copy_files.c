/* copy_files.c     - a simple program that copies a source file into a target file using arguments from the command line. 
                        Arguments that must be passed are the name of the source file and the target file. */

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{

    int ch;
    FILE * sf, * tf;

    if( argc < 3 )
    {
        fprintf( stderr, "You need to pass a source file and a target file.\n" );
        exit( EXIT_FAILURE );
    }

    /* source file */
    if(( sf = fopen( argv[ 1 ], "rb" )) == NULL )
    {
        fprintf( stderr, "The file can not be opened: %s\n", argv[ 1 ]);
        exit( EXIT_FAILURE );
    }    
    /* target file */
    if(( tf = fopen( argv[ 2 ], "wb" )) == NULL )
    {
        fprintf( stderr, "The file can not be opened: %s\n", argv[ 2 ]);
        exit( EXIT_FAILURE );
    }

    /* copying a content*/
    while(( ch = getc( sf )) != EOF )
        putc( ch, tf ); 

    if( fclose( sf ) != 0 ||
        fclose( tf ) != 0 )
        fprintf( stderr, "Error while closing files.\n" );      

    return 0;
}