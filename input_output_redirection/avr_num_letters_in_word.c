/*avr_num_letters_in_word.c     -   returnr the average number of letters included in a word*/
#include <stdio.h>
#include <ctype.h>

int main( void )
{
    int character, sum = 0, count = 0;
    float average = 0;

    while( ++count, ( character = getchar()) != EOF )
    {
        if( isalpha( character ))
        {
            sum += character;
            average = sum / count;
        }
    }
    printf( "\n**********************************\n" );
    printf( "Sum : %d        Average : %.2f \n", sum, average );
    return 0;
}