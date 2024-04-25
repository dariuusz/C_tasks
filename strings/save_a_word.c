/* save_a_word.c    -   takes a user input and save it into an array. The function takes only one word and the rest 
 33                      of the line leaves. It also skips any signs before a word */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define WORD            40
#define TEST_CASES      4

void write_word( char * );
void write_word2( char *, int );
char * find_element( const char *, char );
bool element_in_array( char *, const char * );
char * read( char *, int );
void print_info();
void clear_input_buffer();
void print_found_info( char *, char );
void print_found_info2( char *, char * );
bool validate_input( int *, int * );
char * copy_str( char * restrict, const char * restrict, size_t );
void input_user_data( char * word, char *character );

int main( void )
{
    char word[ WORD ];
    char word2[ WORD ];
    char character;
    int option;
    bool valid_con, choice = true;    
    int result = 1;     /* assuming valid condition for while loop to start with*/


    /* write_word test*/
    // printf( "Enter a word you want to save: " );
    // write_word( word);
    // printf( "\nEntered characters are: \n%s", word );
    // printf( "\n\n" );

    /* write_word2 test*/
    // printf( "Enter a second word you want to save: ");
    // write_word2( word2, 5 );
    // printf( "\nEntered characters are: \n%s", word2 );
    
    
    while( result && choice )
    {   
        print_info();
        result = scanf( "%d", &option );

        if( !validate_input( &option, &result ))
            continue;
       
        switch( option )
        {
            case 1:
                input_user_data( word, &character );
                print_found_info( word, character );
                break;
            case 2:
                input_user_data( word, &character );
                print_found_info2( word, &character );
                break;
            case 3:
                copy_str( word2, "bread", 6 );
                printf( "Result:    %s", word2 );
                break;
            case 4:
                choice = false;
                break;
            default:
                choice = false;
                break;
        }       
    }

    printf( "Goodbye" );
    return 0;
}

void input_user_data( char *word, char *character )
{
    /* Function to accept users data
        @param      No
        @return     Nothing
    */
    clear_input_buffer();
    puts( "Enter a word:" );
    read( word, WORD );
    puts( "Enter searched character:" );
    scanf( " %c", character );
}

bool validate_input( int *option, int *result )
{
    /* Function to validate users choice
        @param  int         user's choice
        @param  int         condition to terminate while loop
        @return boolean     true or fale
    */   
    if( *result == 0 ||
        ( *option > TEST_CASES || 
          *option <= 0 ))
    {
        printf( "Incorrect input. Enter positive number from 1 to 3.\n" );
        clear_input_buffer();
        *result = 1;
        return false;
    }

    return true;    
}

void print_found_info2(char * word, char * character )
{
    /* Prints whether element has been found or not.
        @param char[]         a word
        @param char         a character
    */
    bool found;
    found = element_in_array( word, character );
    if( found )
        printf( "Element has been found.\n" );
    else
        printf( "Element has not been found.\n");
}

void print_found_info( char * word, char character )
{
    /* Prints a pointer and its address. Otherwise appropriate info
        @param char[]         a word
        @param char           a character
    */
    char * result;
    result = find_element( word, character );
    if( result == NULL )
        printf( "Element has not been found.\n" );
    else
        printf( "Element returned is %c at address %p\n", *result, &result);
}

void clear_input_buffer() {
    /* Clears input buffer
        @return     Nothing
    */
    int c;
    while (( c = getchar()) != '\n' && c != EOF );
}

void print_info()
{
    /*Prints options */
    printf( "\n1 Test find_element function              2 Test element_in_array function \n" );
    printf( "3 Test copy() function                      4 Exit \n" );
}

void write_word( char * array )
{
    /*  Accept user input using getchar()
        Skip any whitespace characters.
        @param  char[]   a word
    */
    int count = 0;
    char character;

    while( ( character = getchar()) != EOF )
    {
        if( character == '\t' ||
            character == ' '  ||
            character == '\r' ||
            character == '\f' ||
            character == '\v' ||
            character == '\n' )
            continue;
        array[ count ] = character;
        count++;
    }
    array[ count ] = '\0';
     
}

void write_word2( char * array, int number )
{
    /* Accept user input using getchar().
       Skip any whitespace characters and return word with the length of passed argument
       @param char[]     a word
       @param int        a length of the word 
    */
    int count = 0;
    char character;

    while(( character = getchar()) != EOF && count < number )
    {
        if( character == '\t' ||
            character == ' '  ||
            character == '\r' ||
            character == '\f' ||
            character == '\v' ||
            character == '\n' )
            continue;
        array[ count ] = character;
        count++;   

    }
    array[ count ] = '\0';
}

char * find_element( const char * word, char character )
{
    /* Find an element in a word and return whether a pointer or NULL.
        @param  char[]            a word
        @param  char              searched character
        @result char              A pointer or NULL
    */
    int count = 0;

    while( word[ count ] != '\0' && word[ count ] != '\0' )
    {
        if( word[ count ] == character )
            return (char *) &word[ count ];  
        count++;
    }
    return NULL;
}

bool element_in_array( char * character, const char * word )
{
    /* Searching for an element in a word.
        @param  char        searched character
        @param  char[]      a word
        @result bool        Returns TRUE or FALSE
    */
    int count = 0;

    while(word[ count ] != '\n' && word[ count ] != '\0' )
    {
        if( word[ count ] == *character )
            return true;
        count++;
    }
    return false;
}

char *read( char *ch, int number )
{
    /* Reads user into and save it into an array.
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
            while( getchar() != '\n' )
                continue;
    }

   return result;
}

char * copy_str( char * restrict s1, const char* restrict s2, size_t n )
{
    /* Function copy_str works as strncpy(). It shortens s2 or adds '\0'. It can
        not end with '\0'
        @param char     targeted char
        @param char     char to copy
        @param size_t   number of chars 
        @return char    s1
    */
    size_t i = 0;

    while( i < n && s2[ i ] != '\0' )
    {
        s1[ i ] = s2[ i ];
        i++;
    }
    while( i < n )
    {
        s1[ i ] = '\0';
        i++;
    }

    return s1;
}