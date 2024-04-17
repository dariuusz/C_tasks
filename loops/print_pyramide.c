/* print_pattern3.c     -   displays letter in the pyramides pattern from A to the given one by the end user */
#include <stdio.h>

int main( void )
{
    char user_letter;

    int row, rows, space, count, number_of_letters;

    printf( "Enter the capital letter to produce a pyramide: ");
    scanf( "%c", &user_letter );

    int number_of_rows = number_of_letters = (user_letter - 'A') + 1;
    
    printf( "It is %d\n", number_of_letters);

    for(  row = 0; row < number_of_rows; row++ )
    {
        for( space = 0; number_of_rows - row - 1 > space; space++ )
            printf( "-" );
        for( char f_letter = 'A'; f_letter <= 'A' + row; f_letter++ )
            printf( "%c", f_letter );
        for( char f_letter = 'A' + row -1 ; f_letter >= 'A'; f_letter-- )
            printf( "%c", f_letter );
        printf( "\n" );
    }

    return 0;
}