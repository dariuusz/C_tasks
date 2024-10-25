/* print_rows.c     - Accepts 2 files passed in command line and prints their rows
                        interchanchaebly. 1 file 1 row, 2 file 1 row, etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CNTL_Z              '\032'          /*EOF in DOS*/
#define FILE_ERROR          1
#define ARGUMENT_ERROR      2
#define CLOSE_FILE_ERROR    3
#define BUFFER_LINE_SIZE    256


/* functions */
FILE * OpenFile( const char * filename, const char * mode );
void HandleError( const char * message, const char * filename, FILE * file, int errorType );
void CloseFile( FILE * file, const char * filename );
int readLineWithFseek(FILE *file, long *position);


int main( int argc, char * argv[ ])
{
    FILE * ff, *sf;
    long posFile1 = 0, posFile2 = 0; // Track each file's position
    bool file1Active = true, file2Active = true;

    if( argc != 3 )
        HandleError( "Usage: %s <file1> <file2>", argv[ 0 ], NULL, ARGUMENT_ERROR );

    ff = OpenFile( argv[ 1 ], "r" );
    sf = OpenFile( argv[ 2 ], "r" );

    while ( file1Active || file2Active )
    {
        // Read one line from the first file if it's still active
        if ( file1Active )
        {
            fseek( ff, posFile1, SEEK_SET ); // Set position to last saved position
            if ( readLineWithFseek( ff, &posFile1 ))
                file1Active = false; // Mark as inactive if EOF reached
        }

        // Read one line from the second file if it's still active
        if ( file2Active )
        {
            fseek( sf, posFile2, SEEK_SET ); // Set position to last saved position
            if ( readLineWithFseek( sf, &posFile2 ))
                file2Active = false; // Mark as inactive if EOF reached
        }
    }


    /* Close files with error handling */
    CloseFile( ff, argv[ 1 ]);
    CloseFile( sf, argv[ 2 ]);

    return 0;
}

void CloseFile( FILE * file, const char * filename )
{
    /* Closes file
        @param FILE         pointer to a file
        @param const char   filenam
    */
    if( fclose( file ) != 0 )
        HandleError( "Error while closing file.", filename, file, CLOSE_FILE_ERROR );
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
   switch( errorType )
   {
        case FILE_ERROR:
            fprintf( stderr, "%s: %s.\n", message, filename );
            break;
        case ARGUMENT_ERROR:
            fprintf( stderr, "%s: %s.\n", message, filename );
            break;
        case CLOSE_FILE_ERROR:
            fprintf( stderr, "%s: %s.\n", message, filename );
            break;
        default:
            fprintf( stderr, "Unknown error occured.\n");
   }
   if( file != NULL )
    fclose( file );
    
    exit( EXIT_FAILURE );
}

int readLineWithFseek( FILE *file, long *position )
{
    /* Reads lines with fseek() function 
        @param FILE         file
        @param long         file position
        @return             */
    char ch;
    char buffer[ BUFFER_LINE_SIZE ];
    int i = 0;

    // Read characters until newline or EOF
    while (( ch = fgetc( file )) != EOF && ch != '\n' && i < BUFFER_LINE_SIZE - 1 )
        buffer[ i++ ] = ch;

    buffer[ i ] = '\0'; // Null-terminate the buffer

    if ( i > 0 ) // Only print if there's content in the buffer
        puts( buffer );

    // Update position to next character after this line
    *position = ftell( file );

    if ( ch == EOF && i == 0 ) // No more lines to read
        return 1;
    return 0;
}