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
void clear_input_buffer();
void sortstr( char *[], int );
void print_array_content( char *[], int );
void print_info();

char * read_input( char *, int );
bool validate_input( int *, int * );

int main( void )
{
    char sentences [ NUM_OF_LITERALS ][ LETTERS ];
    char *poin[ NUM_OF_LITERALS ];
    int count = 0;
    int k;
    bool loop_condition = true;
    int result = LOOP_CONDITION;
    int option;

    printf( "Enter to 10 literals: \n" );
    while( count < NUM_OF_LITERALS && 
            read_input( sentences[ count ], LETTERS ) != NULL &&
            sentences[ count ][ 0 ] != '\0' )
    {
        poin[ count ] = sentences[ count ];
        count++;        
    }
    while( loop_condition )
    {
        print_info();
        result = scanf( "%d", &option );

        if( !validate_input( &option, &result ))
            continue;

        switch( option )
        {
            case 1:
                print_array_content( poin, count );
                break;
            case 2:
                sortstr( poin, count );
                print_array_content( poin, count );
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                loop_condition = false;
                break;
            default:
                loop_condition = false;
                break;
        }

    }

    sortstr( poin, count );
    print_array_content( poin, count );
    return 0;

}

void print_info()
{
    /*
        Prints options 
    */
    printf( "\n1 Print original stings                              2 Print arrays in ASCI order" );
    printf( "\n3 Print array according to the length of array       4 Print arrays according to the length of the first word" );
    printf( "\n5 Exit\n" );
}

void print_array_content( char * array[], int count )
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

void clear_input_buffer()
{
    /* 
        Clears input buffer
        @return     Nothing
    */
   int c;
   while(( c = getchar()) != '\n' && c != EOF );
}

char * read_input( char * ch, int number )
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
            clear_input_buffer();   
    }
    return result;
}

void sortstr( char *arrays[], int num )
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

bool validate_input( int *option, int *result )
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
        clear_input_buffer();
        *result = LOOP_CONDITION;
        return false;
    }

    return true;    
}