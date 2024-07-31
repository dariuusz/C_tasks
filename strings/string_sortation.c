/* String_sortation.c  ->   Accepts approximately 10 strin literals and sort them appropriately 
                            to user choice 
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LETTERS             100
#define NUM_OF_LITERALS     10
#define LOOP_CONDITION      1
#define EXIT_STATUS         5

/* Functions to clear buffer and display information*/
void ClearInputBuffer();
void SortStr( char *[], int );
void PrintArrayContent( char *[], int );
void PrintInfo();
void SortStrByLength( char *[], int );
void SortStrByFirstWord( char *[], int );

char * ReadInput( char *, int );
bool ValidateInput( int *, int * );
size_t FirstWordLength( const char * );

int main( void )
{
    char sentences [ NUM_OF_LITERALS ][ LETTERS ];
    char *ptr[ NUM_OF_LITERALS ];
    int count = 0;
    bool loop_condition = true;
    int result = LOOP_CONDITION;
    int option;

    printf( "Enter to 10 literals: \n" );
    while( count < NUM_OF_LITERALS && 
            ReadInput( sentences[ count ], LETTERS ) != NULL &&
            sentences[ count ][ 0 ] != '\0' )
    {
        ptr[ count ] = sentences[ count ];
        count++;        
    }

    while( loop_condition )
    {
        PrintInfo();
        result = scanf( "%d", &option );

        if( !ValidateInput( &option, &result ))
            continue;

        switch( option )
        {
            case 1:
                PrintArrayContent( ptr, count );
                break;
            case 2:
                SortStr( ptr, count );
                PrintArrayContent( ptr, count );
                break;
            case 3:
                SortStrByLength( ptr, count );
                PrintArrayContent( ptr, count );
                break;
            case 4:
                SortStrByFirstWord( ptr, count );
                PrintArrayContent( ptr, count );
                break;
            default:
                loop_condition = false;
                break;
        }

    }

    SortStr( ptr, count );
    PrintArrayContent( ptr, count );
    return 0;

}

void 

void PrintInfo()
{
    /*
        Prints options 
    */
    printf( "\n1 Print original stings                              2 Print arrays in ASCI order" );
    printf( "\n3 Print array according to the length of array       4 Print arrays according to the length of the first word" );
    printf( "\n5 Exit\n" );
}

void PrintArrayContent( char * array[], int count )
{
    /*
        Function used to print the content of the array.
        @param char     an array of string
        @param int      a number of elements to sort
    */
    int k;
    puts( "\nThis is sorted array: \n" );
    for( k = 0; k < count ; k++ )
    {
        if(  array[ k ] == NULL || *array[ k ] == '\0' )
            break;
        else
            puts( array[ k ]);
    }
}

void ClearInputBuffer()
{
    /* 
        Clears input buffer
        @return     Nothing
    */
   int c;
   while(( c = getchar()) != '\n' && c != EOF );
}

char * ReadInput( char * ch, int number )
{
    /* 
        Reads user input and save it into an array.
       It uses fgets() function.
       @param   char      entered character
       @param   int       the length of the array.
       @result  char      Returns saved array
    */
    char * result;
    int i = 0;

    result = fgets( ch, number, stdin );
    if( result )
    {
        while( ch[ i ] != '\n' && ch[ i ] != '\0' )
            i++;
        if( ch[ i ] == '\n' )
            ch[ i ] = '\0';
        else
            ClearInputBuffer();   
    }
    return result;
}

void SortStr( char *arrays[], int num )
{
    /*
        Function used to sort an array in ascending order using a bubble sort algorithm.
        @param char     an arrayof C strings.
        @param int      a number of strings in the array
    
    */
    char *temp;
    int dol, seek;          /* loop counters*/

    for( dol = 0; dol < num - 1; dol++ )
        for( seek = dol + 1; seek < num; seek++ )
            if( strcmp( arrays[ dol ], arrays[ seek ]) > 0 )
            {
                temp = arrays[ dol ];
                arrays[ dol ] = arrays[ seek ];
                arrays[ seek ] = temp;
            }
}

void SortStrByLength( char *arrays[], int num )
{
    /* Sorts an array in ascending order using Bubble Sort
        @param  char        an array
        @param  int         a number of string literals
        @return             nothing  
    */
    char *temp;
    for( int i = 0; i < num; i++ )
    {
        for( int j = 0; j < num - i - 1; j++ )
        {
            if( strlen( arrays[ j ]) > strlen( arrays[ j + 1 ]))
            {
                temp = arrays[ j ];
                arrays[ j ] = arrays[ j + 1 ];
                arrays[ j + 1 ] = temp;
            }
        }
    }
        
}

size_t FirstWordLength( const char *str )
{
    /* Calculates the number of character in a first word
        @param char         a word
        @return size_t      a length of the first word
    */
    size_t len = 0;

    // Skip leading spaces
    while (str[ len ] == ' ')
        len++;


    // Now, count the length of the first word
    size_t start = len;
    while ( str[ len ] != '\0' && str[ len ] != ' ') 
        len++;


    return len - start;
}

void SortStrByFirstWord( char *arrays[], int num )
{
    /* Sorts by the length of the first word in a string literal.
        @param char         an array
        @param int          a number of string literals
        @return             nothing
    */
    char * temp;
    for( int i = 0; i < num - 1; i++ )
    {
        for( int j = 0; j < num - i - 1; j++ )
        {
            if( FirstWordLength( arrays[ j ]) > FirstWordLength( arrays[ j + 1 ]))
            {
                temp = arrays[ j ];
                arrays[ j ] = arrays[ j + 1 ];
                arrays[ j + 1 ] = temp;
            }
        }
    }
}

bool ValidateInput( int *option, int *result )
{
    /* Function to validate users choice
        @param  int         user's choice
        @param  int         condition to terminate while loop
        @return boolean     true or fale
    */   
    if( *result == 0 ||
        ( *option > EXIT_STATUS || 
          *option <= 0 ))
    {
        printf( "Incorrect input. Enter positive number from 1 to 3.\n" );
        ClearInputBuffer();
        *result = LOOP_CONDITION;
        return false;
    }

    return true;    
}