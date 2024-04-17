/*count_odd_even_numbers.c  -   counts occurences of odd and even numbers entered by users without 0 and showing the mean number.*/
#include <stdio.h>
#include <ctype.h>

int main( void )
{
    int number;
    int even_days = 0;
    int sum_even_days = 0;
    int sum_odd_days = 0;
    int odd_days = 0;
    while( scanf( "%d", &number ) == 1 && number != 0)
    {   
        if( number % 2 == 0 )
        {
            even_days++;
            sum_even_days += number;
        }
        else
        {
            odd_days++;
            sum_odd_days += number;
        }
    }

    printf( "Even days:\n" );
    printf("Number of days: %d           Mean: %d\n", even_days, sum_even_days / even_days );
    printf( "Odd days:\n" );
    printf("Number of days: %d           Mean: %d\n", odd_days, sum_odd_days / odd_days );
    
    return 0;
}