/* print_pattern3.c     -   displays letter in the pyramides pattern from A to the given one by the end user */
#include <stdio.h>

int main( void )
{
    char user_letter;

    int letter_occurence, f_letter, l_letter, space, number_of_letters, count;

    printf( "Enter the capital letter to produce a pyramide: ");
    scanf( "%c", &user_letter );

    int rows = number_of_letters = (user_letter - 'A');
    
    printf( "It is %d\n", rows);

    for( rows ; rows >= 0; rows-- )
    {
        for( space = 1; rows - space >= 0; space++ )
            printf( "-" );
        for( f_letter = 'A', letter_occurence = rows ; letter_occurence - 1 < number_of_letters; letter_occurence++ , f_letter++ )
            printf( "%c", f_letter );
        for( l_letter = user_letter - rows - 1 ; l_letter >= 'A' ; l_letter++ )
            printf( "%c", l_letter );
        printf( "\n" );
    }

    return 0;
}