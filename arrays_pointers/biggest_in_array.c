/* biggest in array.c   -   return the biggest number in array*/
#include <stdio.h>

#define SIZE    20
int biggest_number( int [], int );
int biggest_index( int [], int );
int smallest_number( int [], int );
int biggest_smallest_difference( int [], int );
int reverse_elements( int [], int );

int main( void )
{
    
    int numbers[ 20 ] = { 10, 4, 14, 2, 90, 6, 156, 789, 1, 5678, 25000,
                            56, 25001, 435, 768, 3230, 23449, 596, 34, 768 };
    int size = sizeof( numbers ) / sizeof( numbers[ 0 ]);
    
    printf( "The biggest number in array is : %d\n\n", biggest_number( numbers, size ));
    printf( "The biggest index in array is : %d\n\n", biggest_index( numbers, size ));
    printf( "The smallest number in array is : %d\n\n", smallest_number( numbers, size ));
    printf( "The difference between smallest and biggest number");
    printf( "in array is : %d\n\n", biggest_smallest_difference( numbers, size ));
    printf( "Reversed elements in array:\n");
    reverse_elements( numbers, size );
    printf( "\n\n" );
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}

int biggest_number( int numbers [], int size )
{
    int biggest, i;
    biggest = numbers[ 0 ];
    for( i = 0; i < size; i++ )
    {           
        if( biggest > numbers[ i ])
            continue;
        else
            biggest = numbers[ i ];
       
    }
    return biggest;    
}

int biggest_index( int numbers [], int size )
{
    int * biggest, * wsk1;
    int i;
    
    wsk1 = numbers;
    biggest = numbers;


    for( i = 0; i < size; i++ )
    {           
        if( *biggest > numbers[ i ])
            continue;
        else
        {
            biggest = &numbers[ i ];
        }
    }
    return biggest - wsk1;  
}

int smallest_number( int numbers [], int size )
{
    int smallest, i;
    smallest = numbers[ 0 ];
    for( i = 0; i < size; i++ )
    {           
        if( smallest < numbers[ i ])
            continue;
        else
            smallest = numbers[ i ];       
    }
    return smallest;    
}

int biggest_smallest_difference( int numbers [], int size )
{
    int difference;
    return biggest_number( numbers, size ) - smallest_number( numbers, size );
}

int reverse_elements( int numbers [], int size )
{
    int *start = numbers;           // Pointer to the beginning of the array
    int *end = numbers + size - 1;  // Pointer to the end of the array
    int temp;

    // Reverse the elements by swapping them from both ends
    while (start < end)
    {
        // Swap the elements pointed by start and end
        temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers towards the center
        start++;
        end--;
    }

    return *numbers;
}