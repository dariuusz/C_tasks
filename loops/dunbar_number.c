/* dunbar_number.c  -   calculates the number of friends joined to the group according to the relation when for 5 people 1 us turned down and the rest 4 are doubled*/
#include <stdio.h>
#define DUNBAR  150

int main( void )
{
    int profesor = 5;

    for( int week = 1; profesor <= 150 ; week++ )
    {
        profesor -=1;
        profesor *=2;
        if( profesor >= DUNBAR )
        {
            printf( "It took him %d weeks to find %d friends.\n", week, profesor );
        }
    }    

    return 0;
}