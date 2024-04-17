/*payroll2.c    ->  displays is using switch statement to display the initial menu with hourly rates*/
#include <stdio.h>
#include <ctype.h>

#define TAX_1                   0.15
#define TAX_2                   0.2
#define TAX_3                   0.25
#define BASE_THRESHOLD          1200
#define MIDDLE_THRESHOLD        1800
#define HOUR_RATE_1              35
#define HOUR_RATE_2              37
#define HOUR_RATE_3              40
#define HOUR_RATE_4              45   
#define OVERTIME                1.5

void print_info( );
int select_hourly_rate( int, int * );
float net_pay( float , float );
void print_payroll( float, float );
float calculate_payroll( int *, float *, float *, int * );

int main( void )
{
    int hours = 0;
    int option, hourly_rate = 0;
    float gross_pay = 0, tax = 0;

    printf( "Programs return the payroll based on weekly working hours.\n" );
    print_info( );

    while( scanf( "%d", &option ) == 1 && option != 5 )
    {
        if ( option > 5 )
        {
            printf( "Incorrect choice. Try again\n" );
            continue;
        }
        select_hourly_rate( option, &hourly_rate );
        printf( "Hourly rate is : %d \n", hourly_rate );
        printf( "Enter the number of hours [ enter q to exit ]: " );
        calculate_payroll( &hours, &gross_pay, &tax, &hourly_rate );

        print_info();
    }
    return 0;
}

void print_info( )
{
        printf( "****************************************************\n" );
        printf( "Enter the number reflecting the hourly rate: \n" );
        printf( "1) 35 GBP/hour               2) 37 GBP/hour\n" );
        printf( "3) 40 GBP/hour               4) 45 GBP/hour\n" );
        printf( "5) Exit\n" );
        printf( "****************************************************\n" );
}

int select_hourly_rate( int option, int *hourly_rate )
{
    switch( option )
        {
            case 1:
                *hourly_rate = HOUR_RATE_1;
                break;
            case 2:
                *hourly_rate = HOUR_RATE_2;
                break;
            case 3:
                *hourly_rate = HOUR_RATE_3;
                break;
            case 4:
                *hourly_rate = HOUR_RATE_4;
                break;
            default:
                printf( "Incorrect choice.\n" );

        }
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

float calculate_payroll( int *hours, float *gross_pay, float *tax, int *hourly_rate )
{
    while( scanf( "%d", hours ) == 1 )
    {
        if( *hours <= 0 )
        {
            printf( "Incorrect number of hours. Try again! \n" );
            scanf( "%d", hours );
        }
        
        if( *hours <= 40 )
            *gross_pay = *hours * *hourly_rate;
        else
            *gross_pay = (( 40 * *hourly_rate ) + (( *hours - 40) * ( *hourly_rate * OVERTIME )));
        
        if( *gross_pay <= BASE_THRESHOLD )
        {
            *tax = *gross_pay * TAX_1;
            print_payroll( *gross_pay, *tax );
        }
        else if( *gross_pay <= MIDDLE_THRESHOLD )
        {
            *tax = ( BASE_THRESHOLD * TAX_1 ) + (( *gross_pay - BASE_THRESHOLD ) * TAX_2 );
            print_payroll( *gross_pay, *tax );
        }
        else
        {
            *tax = ( BASE_THRESHOLD * TAX_1 ) + (( MIDDLE_THRESHOLD - BASE_THRESHOLD ) * TAX_2 ) + (( *gross_pay - MIDDLE_THRESHOLD ) * TAX_3 );
            print_payroll( *gross_pay, *tax );
        }
        break;
    }
}