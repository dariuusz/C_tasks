/* tabela.c -   displays tabel in formatted way*/
#include <stdio.h>

int main( void )
{
    int first_number, last_number;
    printf( "This application display the square and cube numbers of between the first and the last number entered by the user.\n" );
    printf( "Enter the first number: " );
    scanf( "%d", &first_number );
    printf( "Enter the second number: " );
    scanf( "%d", &last_number );

    printf( "----------------------------\n" );
    printf( "|Number     Square     Cube|\n" );
    for( first_number ; first_number < last_number ; first_number ++ )
    {
        printf( "|  %d %10d %10d |\n", first_number, first_number* first_number, first_number * first_number * first_number );
    }
    printf( "---------------------------" );
    return 0;
}