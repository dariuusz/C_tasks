/* random_numbers2.c    Share similar logic like random_numbers.c but generates 1000 numbers in a range 1 - 10
                        and shows the number of occurences of specific numbers
*/
#include "random_numbers.h"

int main( void )
{   
    unsigned int seeds[ SEEDS ] = { 1234, 5467, 2345, 9999, 2828, 3345, 6789, 9876, 3456, 6789 };
    int counts[ NUMBER_COUNTS ] = { 0 };

    generate_numbers( counts, seeds );    
    
    // Display the counts
    for (int i = 0; i < NUMBER_COUNTS; i++) 
    {
        printf("%d: %d times\n", i + 1, counts[i]);
    }
    return 0;
}


void generate_numbers( int * counts, unsigned int * seeds )
{
    /* Generates NUMBERS2 random numbers using seeds array
        @param  int             an array
        @param  unsigned int    seed
        @return                 nothing
    */
    for( int i = 0; i < NUMBERS2; i++ )
    {
        unsigned int * seed = &seeds[ i % SEEDS ];
        int rand_num = random_seeds( seed );
        
        counts[ rand_num - 1 ]++;
    }
        
}

unsigned int custom_random( unsigned int * seed )
{
    /* Generates random numbers with a parameter
        @param unsigned int         a seed
        @return unsigned int        a random number
     */
    *seed = (*seed) * 1102743 + 12345;
    return (*seed / 65536) % 32768;
}

int random_seeds( unsigned int * seed )
{
    /* Generates a random number in a range 1 - 10
        @param unsigned int         a seed
        @return int                 a random seed from a range 1 - 10
    */
   return ( custom_random( seed ) % 10 ) + 1;
}


