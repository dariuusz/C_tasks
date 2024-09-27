/* user_words.c     - asks user about a number of words to store in a dynamic array and print them out */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WORDS           400
#define WORDS_LENGTH    40

/* Functions definitions*/
void ClearBuffer();
char ** CreateArray( int size );
void AcceptWords( char ** array, int size );
void ShowArray( char ** array, int n );
void FreeArray( char ** array, int size );

int main( void )
{
    int size;
    char ** pnt;
    bool FLAG = true;

    while( FLAG )
    {
        printf( "Enter the number of words you want to store: " );

        if( scanf( "%d", &size ) != 1 || size < 1 )
        {
            printf( "Incorrect format. Please enter positive integer number.\n" );
            ClearBuffer();
            continue;
        }
        pnt = CreateArray( size );

        if( pnt == NULL )
        {
            return 1;
        }
        AcceptWords( pnt, size );
        ShowArray( pnt, size );
        FreeArray( pnt, size );

        // Optionally provide a way to exit the loop
        printf( "Do you want to enter more words? (1 for yes, 0 for no): " );
        ClearBuffer();
        if ( scanf( "%d", &FLAG ) != 1 ) 
        {
            printf( "Invalid input. Exiting the program.\n" );
            break; // Exit if input is not valid
        }
        ClearBuffer(); // Clear buffer after input
    }
    

    return 0;
}

void AcceptWords( char ** array, int size )
{
    /* Store words in the array
        @param char **      a pointer to the array
        @param int          the size of the array
    */
    char word[ WORDS ];
    int count = 0;

    while( count < size )
    {
        printf( "Enter %d word: ", count + 1 );
        scanf( "%s", word );
        strcpy( array[ count ], word );
        count++;
    }

}

char ** CreateArray( int size )
{
    /* Creates the dynamic array
        @param int      the size of the array
        @return char    a pointer to the array
    */
    char ** pnt = ( char ** )malloc( size * sizeof( char * ));
    if( pnt == NULL )
    {
        printf( "Memory allocation failed.\n" );
        return NULL;
    }

    for ( int i = 0; i < size; i++ )
    {
        pnt[ i ] = ( char * )malloc( WORDS_LENGTH * sizeof( char ));
        if ( pnt[ i ] == NULL ) 
        {
            printf( "Memory allocation for word %d failed.\n", i );
            // Handle memory cleanup if necessary
            for ( int j = 0; j < i; j++ ) 
            {
                free( pnt[ j ]);  // Free previously allocated memory
            }
            free( pnt );
            return NULL; // Return NULL if allocation failed
        }
    }
    return pnt;
}

void ShowArray( char **array, int n )
{
    /* Show a content of an array 
        @param const int        an array
        @param int              size
    */
    for( int i = 0; i < n ; i ++ )
    {
        printf( "%s\n", array[ i ]);

    }
}

void ClearBuffer()
{
    /* Clears buffer */
    int n;
    while( ( n = getchar()) != '\n' && n != EOF );
}

void FreeArray( char **array, int size )
{
    /* Frees the allocated memory for the array of strings
       @param char** array: the array to free
       @param int size: number of words
    */
    for ( int i = 0; i < size; i++ )  
    {
        free( array[ i ]); // Free each word
    }
    free( array ); // Free the main array
}
