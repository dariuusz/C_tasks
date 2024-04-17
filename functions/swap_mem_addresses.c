/* swap_mem_addresses.c     -   takes three addresses and using a function changes them*/
#include <stdio.h>
void swap_addresses( double *, double *, double* );

int main( void )
{
    double num1, num2, num3;

    printf( "Enter three double numbers. (Enter q to exit)\n" );
    
    while( scanf( "%lf %lf %lf", &num1, &num2, &num3 ) == 3 )
    {
        printf( "First: %.2lf , %p     Second: %.2lf , %p     Third: %.2lf , %p \n\n", num1, &num1, num2, &num2, num3, &num3 );
        swap_addresses( &num1, &num2, &num3 );
        printf( "First: %.2lf , %p     Second: %.2lf , %p     Third: %.2lf , %p \n\n", num1, &num1, num2, &num2, num3, &num3 );
        printf( "Enter three double numbers. (Enter q to exit)\n" );
    }
    return 0;
}

void swap_addresses( double * num1 , double * num2 , double * num3 )
{
    
     double temp;

    // Arrange the values in ascending order - first way
    // if (*num1 > *num2)
    // {
    //     temp = *num1;
    //     *num1 = *num2;
    //     *num2 = temp;
    // }
    // if (*num2 > *num3)
    // {
    //     temp = *num2;
    //     *num2 = *num3;
    //     *num3 = temp;
    // }
    // if (*num1 > *num2)
    // {
    //     temp = *num1;
    //     *num1 = *num2;
    //     *num2 = temp;
    // }

    /*second way*/
    if( *num3 < *num2 )
    {
        temp = *num3;
        *num3 = *num2;
        *num2 = temp;   
    }
    if( *num2 < *num1 )
    {
        temp = *num2;
        *num2 = *num1;
        *num1 = temp;
    }
    if( *num3 < *num2 )
    {
        temp = *num3;
        *num3 = *num2;
        *num2 = temp;

    }

}