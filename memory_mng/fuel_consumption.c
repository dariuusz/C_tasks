/* Program calculates a fuel consumption in gallons and liters using static variables.
    It is learning program of static variables with block scope with internal linkage and static with external linkage*/

#include <stdio.h>
#include "pe12-2a.h"
int mode = 0;

int main( void )
{
    extern int mode;

    printf( "Choose: 0 - metric system, 1 - US system: ");

    while( scanf( "%d", &mode ) ==1 && mode >= 0 )
    {
        if( mode > 1 )
        {
            printf( "Incoreect input. Try again.\n" );
            printf( "Choose: 0 - metric system, 1 - US system: ");
            continue;
        }
        choose_mode( mode );
        retrive_data();
        display_data();
        printf( "Choose: 0 - metric system, 1 - US system: ");
        printf( " ( -1 to exit ): " );
    }

    printf( "End\n" );
    return 0;
}