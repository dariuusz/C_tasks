/* save_a_word.c    -   takes a user input and save it into an array. The function takes only one word and the rest 
 33                      of the line leaves. It also skips any signs before a word */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define WORD            40
#define TEST_CASES      6

/* Function used to print repeated information and clearing buffor*/
void write_word( char * );
void write_word2( char *, int );
void input_user_data( char * word, char *character );
void print_info();
void clear_input_buffer();
void print_found_info( char *, char );
void print_found_info2( char *, char * );
void print_found_info3( char *, char* );
/* End of repeating functions */

/* Switch cases */
void print_case1( char *, char  );
void print_case2( char *, char );
void print_case3( char *, char * );
void print_case4( char *, char * );
void print_case5( char * );
/* End of switch cases */

/* String manipulation functions */
bool validate_input( int *, int * );
char * copy_str( char * restrict, const char * restrict, size_t );
char * is_in( const char *, char * );
char * reverse_elements_of_array( char * );
char * find_element( const char *, char );
bool element_in_array( char *, const char * );
char * read( char *, int );
/* End of string manipulation */

int main( void )
{
    char word[ WORD ];
    char word2[ WORD ];
    char character;
    int option;
    bool valid_con, choice = true;    
    int result = 1;     /* assuming valid condition for while loop to start with*/
    
    while( result && choice )
    {   
        print_info();
        result = scanf( "%d", &option );

        if( !validate_input( &option, &result ))
            continue;
       
        switch( option )
        {
            case 1:
                print_case1( word, character );
                break;
            case 2:
                print_case2( word, character );
                break;
            case 3:
                print_case3( word, word2 );
                break;
            case 4:
                print_case4( word, word2 );
                break;
            case 5:
                print_case5( word );
                break;
            case 6:
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

void print_case1( char * word, char character )
{
    puts( "This function searches only for one character." );
    input_user_data( word, &character );
    print_found_info( word, character );
}

void print_case2( char * word, char character )
{
    puts( "This function searches for more than one character at any poin in source string." );
    input_user_data( word, &character );
    print_found_info2( word, &character );
}

void print_case3( char * word, char * word2 )
{
    clear_input_buffer();
    puts( "Enter a word to copy:" );
    read( word, WORD );
    copy_str( word2, word, strlen( word ) + 1 );
    printf( "Result:    %s", word2 );
}

void print_case4( char *  word, char * word2 )
{
    input_user_data( word, word2 );
    print_found_info3( word, word2 );
}

void print_case5( char * word )
{
    clear_input_buffer();
    puts( "Enter a word to reverse:" );
    read( word, WORD );
    reverse_elements_of_array( word );
    printf( "Reversed array : %s\n", word ); 
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
    if( sizeof( character) == 1 )
        scanf( " %c", character );
    else
        read( character, WORD);
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
    /* Prints whether element has been found or not. Function searches for more than
        one character in sourced string.
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
    /* Prints a pointer and its address. Otherwise appropriate info. This function searches only for
        one character in source string.
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

void print_found_info3( char * word, char * word2 )
{
    /* Prints a pointer and its address. Otherwise appropriate info
        @param char[]         a word
        @param char           a character
    */
    char * result;
    result = is_in( word, word2 );
    if( result == NULL )
        printf( "Element has not been found.\n" );
    else
        printf( "Element returned is %s at address %p\n", result, &result);
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
    printf( "\n1 Test find_element function              2 Test element_in_array function" );
    printf( "\n3 Test copy() function                    4 Test is_in() function" );
    printf( "\n5 Reverse an array                        6 Exit\n" );
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
    int i = 0, j;

    while (character[ i ] != '\0') 
    {
        j = 0;
        while ( word[ j ] != '\n' && word[ j ] != '\0') {
            if ( word[ j ] == character[ i ]) 
            {
                return true;
            }
            j++;
        }
        i++;
    }
    return false;
}

char *read( char *ch, int number )
{
    /* Reads user input and save it into an array.
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

char * is_in( const char * word, char * word2 )
{
    /* Function that uses pointer to iterate a word to look for whether the word2 is
        in word. If adjacent letters are found inside targetted array, it returns pointer to the first letter
        @param  word    targetted word
        @param  word2   searched word
        @return char    pointer or NULL
     */
    const char *start = word;
    const char *w2 = word2;

    while ( *word ) 
    {
        // Check if word2 matches word starting at the current position
        while ( *word && *w2 && ( *word == *w2 )) 
        {
            word++;
            w2++;
        }
        // If we reached the end of word2, we found a match
        if ( *w2 == '\0' ) 
            return ( char * )( word - ( w2 - word2 ));

        // Reset word to the next character after the starting character
        word = start + 1;
        start = word;
    }

    return NULL;
}

char * reverse_elements_of_array( char * array )
{
    /* Function that reverse elements of an array and save them into the same array.
        @param array        targetted array
        @return array       targetted array
    */
   char temp;
   int index = 0;
   int length = strlen( array );
   int back_index = length - 1;


   while( index < back_index )
   {    
        temp = array[ index ];
        array[ index ] = array[ back_index ];
        array[ back_index ] = temp;
        index++;
        back_index--;
   }
   return array;
}