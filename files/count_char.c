/* count_char.c        Counts passed character in n numbers of files passed in command line. If none passed
                        counts the number of sign appeared in standard input taken from user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER                      256
#define FILE_OPEN_ERROR             1
#define CHAR_ERROR                  2
#define CLOSE_FILE_OPEN_ERROR       3
#define NO_ARGUMENTS                4

/* functions */
char * Read( char * ch, int size );
int CountInStdin( char * arg );
int CountFileChar( FILE * filename, char * arg );
void ProcessFiles( char * arg, char ** argv );
void handle_error( const char * message, FILE * file );
FILE * OpenFile( const char * filename, const char * mode);
void HandleError( const char * message, const char * file, int errorType );

int main( int argc, char* argv[ ])
{
    if( argc < 2 )
        HandleError( "You need to pass a character while executing program",
        NULL, NO_ARGUMENTS );

    if( strlen( argv[ 1 ]) != 1 )
        HandleError( "You need to pass 1 character", NULL, CHAR_ERROR );

    if( argc == 2 )
    {
        int stdinCounter = 0;
        stdinCounter = CountInStdin( argv[ 1 ]);
  
        fprintf( stdout, "OCCURENCES          SIGN\n "
                         "%5d %15c", stdinCounter, argv[ 1 ][ 0 ]);

    }
    else
    {
        ProcessFiles( argv[ 1 ], argv );
    }
    return 0;
}

/**
 * Processing n number of files passed ad command-line arguments.
 * 
 * This function processes n number of files passed as command line arguments
 * after a specified character that is also passed in command-line. When function
 * will not encounter a file, will stop.
 * 
 * @param arg       Pointer to a character string representing command-line 
 *                  character.
 * @param files     Pointer to array containing files passed in command-line.
 */
void ProcessFiles( char * arg, char ** files )
{
    // Counter = 2  -> Signals the beginning of the files
    int fileCounter = 2;
    int charCounter = 0;
    FILE * file;

    fprintf( stdout, "OCCURENCES          SIGN          FILENAME\n" );
    while( files[ fileCounter ] != NULL )
    {

        file = OpenFile( files[ fileCounter ], "r" );
        charCounter = CountFileChar( file, arg);

        fprintf( stdout, "%5d %16c %20s\n", charCounter, arg[ 0 ], files[ fileCounter ]);
        
        if( fclose( file ) != 0 )
            HandleError( "Error while closing file", files[ fileCounter ], CLOSE_FILE_OPEN_ERROR );

        fileCounter++;
    }
}

/**
 * Counts occurences of a specified character in user-provided file.
 * 
 * @param arg               Pointer to a character string representing
 *                          command-line character.
 * @param filename          Pointer to a filename.
 * @return counter          The count of occurences of the target character
 *                          in passed file.
 */
int CountFileChar( FILE * filename, char * arg )
{

    char sign = arg[ 0 ];
    int ch = 0;
    int counter = 0;

    while(( ch = getc( filename )) != EOF )
    {
        if( ch == sign )
            counter++;
    }

    return counter;
}

/** 
 * Counts occurences of a specified character in user-provided input 
 * when no files are passed.
 * 
 * This function reads a line of user input into an array and counts 
 * the occurences of the specified character in that input.
 * 
 * @param target        Pointer to a character string representing 
 *                      command-line argument. 
 * @return counter      The count of occurences of the target character
 *                      in the user input.
 */
int CountInStdin( char * arg )
{
    char target = arg[ 1 ];
    char array[ BUFFER ];          
    int ch = 0;
    int counter = 0;

    printf( "Enter a string literal to count passed character: \n" );

    /* Reads user input of BUFFER size and saves into array*/
    Read( array, BUFFER );                                         

    while( array[ ch ] != '\0' )
    {
        if( array[ ch ] == target )
            counter++;
        ch++;
    }
    return counter;
}

/**
 * Reads user input and stores it in the provided character array.
 * 
 * This function captures user input to the specified buffer size, 
 * replacing any newline character at the end with a null terminator. 
 * If the input exceeds the buffer, it discards the excess character.
 * 
 * @param ch            Pointer to a character array .
 * @param size          Maximum number of characters to read, incuding the null terminator.
 * @return array        Pointer to the input string ( or NULL if input fails )
 * 
 */
char * Read( char * ch, int size )
{
    char * result;
    int i = 0;

    // Read input from stdin up to specified size
    result = fgets( ch, BUFFER, stdin );

    if ( result )
    {
        // Replace newline with null terminator, if present
        while( ch[ i ] != '\n' && ch[ i ] != '\0' )
            i++;
            if( ch[ i ] == '\n' )
                ch[ i ] = '\0';
            else
                // Discard excess characters if input exceeds buffer
                while( getchar() != '\n' )
                    continue;
    }

    return result;
}

/**
 * Opens files passed in command-line.
 * 
 * This function opens files passed in command-line. When an error
 * will be encountered HandleError function is called.
 * 
 * @param filename      Pointer to array of filenames passed in command-line.
 * @param mode          Pointer to a specified character characterised for
 *                      opening mode.
 * @return file         Successfully opened file. Otherwise NULL.
 */
FILE * OpenFile( const char * filename, const char * mode)
{
    /* Opens files and set a buffer for them.
        @param const char               filename
        @param const char               mode
        @param int                      buffer size
        @return FILE                    opened file
    */
    FILE * file = fopen( filename, mode );

    if( file == NULL )
        HandleError( "Cannot open file", file, FILE_OPEN_ERROR );
    
    return file;
}

/**
 * Handles different error messages characterised for various scenarios.
 * 
 * @param message       Message that will be displayed for associated error.
 * @param file          Pointer to filename that is associated with an error.
 * @param errorType     Macro for a specified error type.
 */
void HandleError( const char * message, const char * file, int errorType )
{
    
    switch( errorType )
   {
        case FILE_OPEN_ERROR:
            fprintf( stderr, "%s: %s.\n", message, file );
            break;
        case CHAR_ERROR:
            fprintf( stderr, "%s.\n", message );
            break;
        case CLOSE_FILE_OPEN_ERROR:
            fprintf( stderr, "%s: Unable to close file '%s'.\n", message, file );
            break;
        case NO_ARGUMENTS:
            fprintf( stderr, "%s.\n", message );
            break;
        default:
            fprintf( stderr, "Unknown error occured.\n");
   }

   if( file != NULL )
    fclose( file );
    
    exit( EXIT_FAILURE );
}