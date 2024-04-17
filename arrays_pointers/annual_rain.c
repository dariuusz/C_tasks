/* annual_rain.c    -   finds the annual rain sum, annual average and monthly average for data about rainy days*/
#include <stdio.h>
#define MONTHS      12
#define YEARS       5

int main( void )
{
    const float rain[ YEARS ][ MONTHS ] =
    {
        { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 },
        { 8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3 },
        { 9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4 },
        { 7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2 },
        { 7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2 }
    };

    int year, month; 
    float sum, total_sum = 0;

    printf( " YEAR          RAIN ( in inches )\n" );
    for( year = 0; year < YEARS; year++  )
    {
        const float *sub_sum = rain[ year ];

        for( month = 0, sum = 0; month < MONTHS; month++, sub_sum++ )
            sum += *sub_sum;
        printf( "%5d %14.1f\n", 2010 + year, sum );
        total_sum += sum;
    }
    printf( "\nAverage annual rain is %.1f inches\n\n", total_sum/YEARS );
    
    printf( "MONTHLY AVERAGE\n\n" );
    printf( " Sty  Lut  Mar  Kwi  Maj  Cze  Lip  Sie  Wrz  Paz  Lis  Gru\n" );

    for( month = 0; month < MONTHS; month++ )
    {
        const float *sub_sum = &rain[ 0 ][ month ];
        for( year = 0, sum = 0; year < YEARS; year++, sub_sum += MONTHS )
            sum += *sub_sum;
        printf( "%4.1f ", sum/YEARS );
    }
    printf( "\n" );
    return 0;
}