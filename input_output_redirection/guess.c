/* guess.c  -   guessing users chosen number based on binary seach*/
#include <stdio.h>
int calculate_middle( int , int );

int main( void )
{
    int guesses, user_number, lower_threshold = 1, upper_threshold = 0, middle_number = 0;

    printf( "Program guesses the chosen number.\n\n" );
    printf( "Enter the upper threshold: \n" );
    scanf( "%d", &upper_threshold );
    printf( "Choose your number between 1 and 100: \n" );
    scanf( "%d", &user_number );

    middle_number = calculate_middle( upper_threshold, lower_threshold );
    
    while( ++guesses, middle_number != user_number )
    {  
        
        if( middle_number != user_number && middle_number < user_number )
        {
            lower_threshold = middle_number;       
            printf( "Is this %d your number ?\n", middle_number );
        }
        else if( middle_number != user_number && middle_number > user_number )
        {
            upper_threshold = middle_number;   
            printf( "Is this %d your number ?\n", middle_number );
        }
        
        middle_number = calculate_middle( upper_threshold, lower_threshold );
            
    }
    printf( "This is your number: %d    It took %d guesses.\n", middle_number, guesses );

    return 0;
}

int calculate_middle( int upper_threshold, int lower_threshold )
{
    return ( int )(( upper_threshold + lower_threshold ) / 2 );
}