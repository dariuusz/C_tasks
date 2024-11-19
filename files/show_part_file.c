/* show_parts_file.c        It is a program that opens a file in interactive manner. The program
                            must use a loop to let user pick up a location in the file and displays
                            the file content to the end of the line.    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define FILE_NAME       50

// Function definitions
char * read( char * ch, int size );

int main( void )
{
    // variable initialisation
    char fileName[ FILE_NAME ];
    FILE * file;
    char ch;
    long position;
    long fileSize;

    puts( "Enter the file name: " );
    read( fileName, FILE_NAME );

    if(( file = fopen( fileName, "r+" )) == NULL )
    {
        fprintf( stderr, "Cannot open a file %s\n", fileName );
        exit( EXIT_FAILURE );
    }

    // Calculation of the file size and file rewind
    fseek( file, 0, SEEK_END );
    fileSize = ftell( file );
    rewind( file );

    printf( "File is successfully opened. Enter a position in a file or exit "
            "the program by entering not numeric value or negative number.\n" );

    while( true )
    {
        puts( "Enter position in a file: " );
        if( scanf( "%ld", &position ) != 1 || position < 0 )
        {
            fprintf( stdout, "You have entered not numeric value or negative number.\nEnding the program." );
            break;
        }
        
        // Reset EOF state before any seek operation
        clearerr( file );

        if( position >= fileSize )
        {
            printf( "Invalid position. File size id %ld byte.\n", fileSize );
            continue;
        }

        if( fseek( file, position, SEEK_SET ) != 0 )
        {
            puts( "Error while moving a pointer in the file." );
            continue;
        }

        printf( "Content of the file from the position %ld to the end of line:\n", position );
        while(( ch = fgetc( file )) != EOF )
        {
            putchar( ch );
            if( ch == '\n' )
                break;
        }

        if( feof( file ))
        {
            fprintf( stderr, "The end of file reached.\n" );
            break;
        }

    }

    if( fclose( file ) != 0 )
        fprintf( stderr, "Error while closing file." );

    return 0;
}

 /**
  * Reads users input and saves it into array.
  * 
  * This function uses fgets() for user input. If the input is longer than 1 line it replaces
  * '\n' with '\0' signalising the end of the input and handling the content in the buffer.
  * 
  * @param ch           A single character for user input.
  * @param size         A size of the array where the input will be stored.
  * @return result      Successfully read input assigned to the file.
  * 
  */
char * read( char * ch, int size )
{
    char * result;
    char * here;

    result = fgets( ch, size, stdin );
    
    if( result )
    {
        here = strchr( ch, '\n' );               // searching for a new line
        if( here )
            *here = '\0';
        else
            while( getchar() != '\n' )          // clearing buffer
                continue;
    }
    return result;
}