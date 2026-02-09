#include <stdio.h> 

#define MONTHS      12

// Structure definition
struct month
{
    char name[ 20 ];
    char abbrev[ 4 ];
    int days;
    int monthNumber;
};

//Function prototype
void initializeMonths( struct month m[] );
int calculateNumberOfDays( int monthNumber, struct month m[] );

int main( void )
{
    struct month months[ MONTHS ];
    initializeMonths( months );
    
    for( int i = 0; i < MONTHS; i++ )
    {
        printf( "Month: %s, Abbreviation: %s, Days: %d, Month Number: %d\n",
                months[ i ].name,
                months[ i ].abbrev,
                months[ i ].days,
                months[ i ].monthNumber );
    }

    printf( "\n %d days have passed from the beginning of the year.", calculateNumberOfDays( 3, months ));
}

int calculateNumberOfDays( int monthNumber, struct month m[] )
{
    // This function is intentionally left empty as the number of days are initialized in main.

    if( monthNumber > MONTHS || 
        monthNumber < 1 )
    {
        printf( "Invalid month number.\n" );
        return -1;
    }

    int daysFromBeginningOfYear = 0;

    for( int i = 0; i <= monthNumber; i++ )
    {       
        daysFromBeginningOfYear += m[ i ].days;
    }
    
    return daysFromBeginningOfYear;
}

void initializeMonths( struct month m[] )
{
    // This function is intentionally left empty as the months are initialized in main.
    m[ 0 ] = (struct month){ "January", "Jan", 31, 1 };
    m[ 1 ] = (struct month){ "February", "Feb", 28, 2 };
    m[ 2 ] = (struct month){ "March", "Mar", 31, 3 };
    m[ 3 ] = (struct month){ "April", "Apr", 30, 4 };
    m[ 4 ] = (struct month){ "May", "May", 31, 5 };
    m[ 5 ] = (struct month){ "June", "Jun", 30, 6 };
    m[ 6 ] = (struct month){ "July", "Jul", 31, 7 };
    m[ 7 ] = (struct month){ "August", "Aug", 31, 8 };
    m[ 8 ] = (struct month){ "September", "Sep", 30, 9 };
    m[ 9 ] = (struct month){ "October", "Oct", 31, 10 };
    m[ 10 ] = (struct month){ "November", "Nov", 30, 11 };
    m[ 11 ] = (struct month){ "December", "Dec", 31, 12 };
}