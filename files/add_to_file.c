/* add_to_file.c    - Adds a content of targetted files to a source file. It uses arguments passed
                        from a command line to define such files.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER      4096

/*functions*/
void add_content( FILE * sf, FILE * tf );
void read_content( FILE * sf );
FILE * open_file( const char * filename, const char * mode, int buffer_size );
void handle_error( const char * message, FILE * file );

int main( int argc, char * argv[ ])
{
    FILE * sf, * tf;
    int files = 0;
    int counter = 2;
    
    if( argc < 3 )
    {
        fprintf( stderr, "You need to pass at least 2 arguments.\n"
                        "The first: source file.\n" 
                        "The second: target file.\n" );
    }

    sf = open_file( argv[ 1 ], "a+", BUFFER );

    while( argv[ counter ] != NULL )
    {
        if( strcmp( argv[ counter ], argv[ 1 ] ) == 0 )
            fputs( "Can not add a file to itself.\n", stderr );
        else if(( tf = fopen( argv[ counter ], "r" )) == NULL )
            fprintf( stderr, "Erro while opening target file: %s\n", argv[ counter ]);
        else
        {
            tf = open_file( argv[ counter ], "r", BUFFER );
            add_content( sf, tf );
            fclose( tf );
            files++;
            printf( "File %s added.\n", argv[ counter ]);
        }
        counter++;
    }
    puts( "End." );
    printf( "Added %d files.\n", files );
    rewind( sf );
    printf( "%s includes:\n", argv[ 1 ]);
    read_content( sf );  
    puts( "\nEnd." );
    fclose( sf );
    return 0;
}

void add_content( FILE * source, FILE * target )
{
    /* Adds a content of target file into source file using fread() and fwrite() functions
        @param FILE         source file
        @param FILE         target file
    */
    size_t bytes;
    static char temp[ BUFFER ];

    fputc( '\n', source );              /* adds a new line before the content of a new file*/
    while(( bytes = fread( temp, sizeof( char ), BUFFER, target )) > 0 )
        fwrite( temp, sizeof( char ), bytes, source );
}

void read_content( FILE * source )
{
    /* Reads a content of the source file
        @param FILE         source file
    */
    int ch;
    
    while(( ch = getc( source )) != EOF )
        putchar( ch );
}

FILE * open_file( const char * filename, const char * mode, int buffer_size )
{
    /* Opens files and set a buffer for them.
        @param const char               filename
        @param const char               mode
        @param int                      buffer size
        @return FILE                    opened file
    */
    FILE * file = fopen( filename, mode );

    if( file == NULL )
        handle_error( "Cannot open file", NULL );
    
    if( setvbuf( file, NULL, _IOFBF, buffer_size ) != 0 )
        handle_error( "Buffer cannot be set", file );
    
    return file;
}

void handle_error( const char * message, FILE * file )
{
    /* Handles errors 
        @param const char           a message
        @param FILE                 a filename
    */
    fprintf( stderr, "%s.\n", message );
    if( file != NULL )
        fclose( file );
    exit( EXIT_FAILURE );
}