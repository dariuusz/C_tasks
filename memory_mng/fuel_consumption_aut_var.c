/* Program works in the same manner as fuel consumption but uses automatic variables and void functions. */
#include <stdio.h>

#include <stdio.h>
#include "fuel_consumption_definition.h"


int main( void )
{
    int mode;
    float distance;
    float fuel_consumption;

    printf( "Choose: 0 - metric system, 1 - US system: ");

    while( scanf( "%d", &mode ) ==1 && mode >= 0 )
    {
        if( mode > 1 )
        {
            printf( "Incoreect input. Try again.\n" );
            printf( "Choose: 0 - metric system, 1 - US system: ");
            continue;
        }
        choose_mode( mode, &distance );
        retrive_data( mode, &fuel_consumption );
        display_data( mode, distance, fuel_consumption );
        printf( "Choose: 0 - metric system, 1 - US system: ");
        printf( " ( -1 to exit ): " );
    }

    printf( "End\n" );
    return 0;
}