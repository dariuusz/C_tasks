/*payroll.c     ->  calculates the gross payroll based on the given numbers */
#include <stdio.h>
#include <ctype.h>

#define TAX_1                   0.15
#define TAX_2                   0.2
#define TAX_3                   0.25
#define BASE_THRESHOLD          1200
#define MIDDLE_THRESHOLD        1800
#define PER_HOUR                40
#define OVERTIME                1.5

float net_pay( float , float );
void print_payroll( float, float );

int main( void )
{
    int hours = 0;
    float gross_pay = 0, tax = 0;

    printf( "Programs return the payroll based on weekly working hours.\n" );
    printf( "Enter the number of hours you have done [ or q to exit ]: \n" );

    while( scanf( "%d", &hours ) == 1 )
    {
        if( hours <= 0 )
        {
            printf( "Incorrect number of hours. Try again! \n" );
            scanf( "%d", &hours );
        }
        
        if( hours > 0 && hours <= 40 )
            gross_pay = hours * PER_HOUR;
        else
            gross_pay = (( 40 * PER_HOUR ) + (( hours - 40) * ( PER_HOUR * OVERTIME )));
        
        if( gross_pay <= BASE_THRESHOLD )
        {
            tax = gross_pay * TAX_1;
            print_payroll( gross_pay, tax );
        }
        else if( gross_pay <= MIDDLE_THRESHOLD )
        {
            tax = ( BASE_THRESHOLD * TAX_1 ) + (( gross_pay - BASE_THRESHOLD ) * TAX_2 );
            print_payroll( gross_pay, tax );
        }
        else
        {
            tax = ( BASE_THRESHOLD * TAX_1 ) + (( MIDDLE_THRESHOLD - BASE_THRESHOLD ) * TAX_2 ) + (( gross_pay - MIDDLE_THRESHOLD ) * TAX_3 );
            print_payroll( gross_pay, tax );
        }

    printf( "Enter another number of hours [ or press q to quit]\n " );
    }
    printf( "See you again.!" );
    return 0;
}

float net_pay( float gross_pay, float tax )
{
    return gross_pay - tax;
}

void print_payroll( float gross_pay, float tax)
{
    printf( "--------------------YOUR PAYROLL--------------------\n" );
    printf( "Gross pay: %10.2f          Tax: %10.2f\n", gross_pay, tax );
    printf( "Net pay:   %10.2f\n", net_pay( gross_pay, tax ) );
}