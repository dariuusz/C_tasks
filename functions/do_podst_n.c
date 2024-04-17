/* do_podst_n.c -   accepts user input from the range 2 to 10 and calculates its reflection in the number system*/
#include <stdio.h>
void do_podst_n( unsigned long, int );

int main( void )
{
    unsigned long number;
    int range;

    printf( "Enter the first number you want to compute and " );
    printf( "select the second number in range 2 - 10 to select ");
    printf( " the number system. Enter q to exit.\n" );

    while( scanf( "%lu %d", &number, &range ) == 2 )
    {
        printf( "Reflection in base-%d: ", range);
        do_podst_n( number, range );
        putchar( '\n' );
        printf( "Enter another numbers: \n" );
    }

    return 0;
}

void do_podst_n( unsigned long n, int base)
{
    int r;

    r = n % base;
    if (n >= base)
        do_podst_n(n / base, base);
    /* below printf is used to return value for hexadecimal representation of the numbers*/
    printf("%c", (r < 10) ? ('0' + r) : ('A' + (r - 10)));

}