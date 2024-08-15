#include <stdio.h>
#include "fuel_consumption_definition.h"

void choose_mode( int mode, float *distance )
{    
    /* Accept distance input
        @param int                  mode
        @param pointer float        distance 
        @return                     nothing
    */
    printf( "Enter a distance in %s ", mode == 0 ? "kilometers" : "miles" );
    scanf( "%f", distance );

}

void retrive_data( int mode, float * fuel_consumption)
{
    /* Accepts fuel consumption input
        @param int              mode
        @param pointer float    fuel_consumption
        @return                 nothing
    */
    printf( "Enter used fuel in %s ", mode == 0 ? "liters" : "gallons" );
    scanf( "%f", fuel_consumption );
}

void display_data( int mode, float distance, float fuel_consumption )
{
    /* Calculates fuel consumption
        @param int              mode
        @param float            distance
        @param float            fuel_consumption
        @return                 nothing
    */
    float sum = 0;
    if( mode == 0 )
        sum = ( fuel_consumption / distance ) * 100;
    else if( mode == 1 )
        sum = distance / fuel_consumption; 
    printf( "Fuel consumed was %.2f\n", sum );
}