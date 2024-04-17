#include <stdio.h>
#include <string.h>

int main( void )
{
    char jedzenie[ ] = "Mniam";
    char *wsk;
    wsk = jedzenie + strlen( jedzenie );
    puts( jedzenie );

    while( --wsk >= jedzenie )
        puts( wsk );
    return 0;
}