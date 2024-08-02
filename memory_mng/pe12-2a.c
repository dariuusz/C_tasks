#include <stdio.h>
#include "pe12-2a.h"

static float distance = 0;
static float fuel_consumption = 0;
extern int mode;

void choose_mode( int mode )
{    
    /* Accept distance input
        @param int      mode 
        @return         nothing
    */
    printf( "Enter a distance in %s ", mode == 0 ? "kilometers" : "miles" );
    scanf( "%f", &distance );

}

void retrive_data()
{
    /* Accepts fuel consumption input
        @param      nothing
        @return     nothing
    */
    printf( "Enter used fuel in %s ", mode == 0 ? "liters" : "gallons" );
    scanf( "%f", &fuel_consumption );
}

void display_data()
{
    /* Calculates fuel consumption
        @param      nothing
        @return     nothing
    */
    float sum = 0;
    if( mode == 0 )
        sum = ( fuel_consumption / distance ) * 100;
    else if( mode == 1 )
        sum = distance / fuel_consumption; 
    printf( "Fuel consumed was %.2f\n", sum );
}