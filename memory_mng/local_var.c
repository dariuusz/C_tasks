/* A simple quess program that uses local variables */  
#include <stdio.h>

void response( int * );

int main( void )
{
    int quess = 0;
    printf( "How many pounds of butter are in a barrel?\n" );
    scanf( "%d", &quess );

    while( quess != 56 )
        response( &quess );
    printf( "You have quessed! Congratulations.\n" );
    return 0;
}

void response( int *quess )
{
    /* Prints information about wrong answer
        @param  int     quess
        @return         nothing
    */
    printf( "Your answer is incorrect. Try again!\n" );
    scanf( "%d", quess );
}