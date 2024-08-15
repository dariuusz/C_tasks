/* random_numbers2.c    Share similar logic like random_numbers.c but generates 1000 numbers in a range 1 - 10
                        and shows the number of occurences of specific numbers
*/
#include "random_numbers.h"

int main( void )
{   
    int numbers [ NUMBERS2 ];
    produce_random_numbers( numbers );
    selection_sort( numbers );
    print_numbers( numbers );
    
    return 0;
}