/* usa_tax_bracket.c    -    calculates the tax bracket for given income*/
#include <stdio.h>
#include <ctype.h>

#define INCOME_1            17850.00
#define INCOME_2            23900.00     
#define INCOME_3            28750.00
#define INCOME_4            14875.00
#define TAX_BRACKET_1       0.15
#define TAX_BRACKET_2       0.28

void print_info( );
int select_tax_format( int, float *, float * );
float income_1( float *, float *);
float income_2( float *, float *);
float income_3( float *, float *);
float income_4( float *, float *);

int main( void )
{
    float income = 0, tax = 0;
    int choice;

    printf( "Program calculates tax bracket for chosen income.\n\v" );

    print_info();

    while( scanf( "%d", &choice ) == 1 && choice !=5 )
    {
        if( choice > 5 )
        {
            printf( "Wrong choice. Please, try again.\n" );
            continue;
        }
        
        printf( "Enter your income: \n" );
        scanf( "%f", &income );
        select_tax_format( choice,  &tax, &income );
        printf( "You have earned %.2f and need to pay %.2f tax.\n", income, tax );
        print_info();
    }    


    return 0;
}

void print_info( )
{
        printf( "********************************************************************************\n" );
        printf( "Choose the income category: \n" );
        printf( "1) Free status                              2) Family head\n" );
        printf( "3) Marriage, joint settlement               4) Marriage, separete settlement\n" );
        printf( "5) Exit\n" );
        printf( "********************************************************************************\n" );
}

int select_tax_format( int choice, float *tax, float * income )
{
    switch( choice )
        {
            case 1:
                income_1( tax, income );
                break;
            case 2:
                income_2( tax, income );
                break;
            case 3:
                income_3( tax, income );
                break;
            case 4:
                income_4( tax, income );
                break;
            case 5:
                printf( "Goodbye.\n" );
        }
}

float income_1( float *tax, float *income)
{
    if( *income < 17850.00 && *income > 0 )
    {
        *tax = *income * TAX_BRACKET_1;
    }
    else
    {
        *tax = ( INCOME_1 * TAX_BRACKET_1 ) + (( *income - INCOME_1 ) * TAX_BRACKET_2 );  
}
}

float income_2( float *tax, float *income )
{
    if( *income < 23900.00 && *income > 0)
    {
        *tax = *income * TAX_BRACKET_1;
    }
    else
    {
        *tax = *income * TAX_BRACKET_1;
    }
}


float income_3( float *tax, float *income )
{
    if ( *income < 28750.00 && *income > 0 )
    {
        *tax = *income * TAX_BRACKET_1;
    }
    else
    {
        *tax = ( INCOME_3 * TAX_BRACKET_1 ) + (( *income - INCOME_3 ) * TAX_BRACKET_2 );
    }
}

float income_4( float *tax, float *income )
{
    if( *income < 14875.00 && *income > 0)
    {
        *tax = *income * TAX_BRACKET_1;
    }
    else
    {
        *tax = ( INCOME_4 * TAX_BRACKET_1 ) + (( *income - INCOME_4 ) * TAX_BRACKET_2 );
    }
}