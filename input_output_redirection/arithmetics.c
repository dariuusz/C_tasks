/* arithmetics.c    -   performs basis maths calculation such as addition, subtration multiplication and division*/
#include <stdio.h>
#include <ctype.h>

void display_menu( );
float addition( float, float );
float subtration( float, float );
float multiplication( float, float );
float division( float, float );

int main( void )
{
    int option;
    float f_number, s_number, sum;
    display_menu();

    while( scanf( "%d", &option ) == 1 && option != 5 )
    {
        if(( option < 0 ) || 
            ( option > 5 ))
        {
            printf( "Incorrect choice. Try again\n" );
            continue;
        }
        printf( "Enter the first number: \n" );
        scanf( "%f", &f_number );
        printf( "Enter the second number: \n" );
        scanf( "%f", &s_number );

        switch ( option )
        {
        case 1:
            printf( "%.2f + %.2f = %.2f\n", f_number, s_number, addition( f_number, s_number ));
            break;
        case 2:
            printf( "%.2f - %.2f = %.2f\n", f_number, s_number, subtration( f_number, s_number ));
            break;
        case 3:
            printf( "%.2f * %.2f = %.2f\n", f_number, s_number, multiplication( f_number, s_number ));
            break;
        case 4:
            printf( "%.2f / %.2f = %.2f\n", f_number, s_number, division( f_number, s_number ));
            break;
        default:
            printf( "Goodbye!.\n" );
            break;
        }
        display_menu();
        
    }

    return 0;
}

void display_menu( )
{
    printf( "Select one mathematical operation: \n" );
    printf( "1) Addition            2) Subtraction\n" );
    printf( "3) Multiplication      4) Division\n" );
    printf( "5) Quit\n\n" );
}

float addition( float f_number, float s_number )
{
    return f_number + s_number;
}

float subtration( float f_number, float s_number )
{
    return f_number - s_number;
}

float multiplication( float f_number, float s_number )
{
    return f_number * s_number;
}

float division( float f_number, float s_number )
{
    return f_number / s_number;
}
