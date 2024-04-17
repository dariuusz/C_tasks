/*  letter.c    -    creates a list of 26 elements and displays them */
#include <stdio.h>
#define SIZE 26

int main( void )
{
    char letters[ SIZE ];
    char letter;
    int count;

    for( letter = 'a' , count = 0 ; count < SIZE ; letter++, count++ )
    {
        letters[ count ] = letter;
    }

    for( int count = 0; count < SIZE; count++ )
        printf("The %d letter is %10.c\n", count + 1, letters[ count ]);
    return 0;
}