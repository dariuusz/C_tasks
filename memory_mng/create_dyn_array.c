/* create_dyn_array.c       - uses malloc() to create an array and show the content of an array.*/ 

#include <stdio.h>
#include <stdlib.h>

/* function definitions */
int * CreateArray( int elem );
int * AcceptValue( int array[], int size );
void ShowArray( const int array[], int n );
void CLearBuffer();

int main( void )
{
    int * pnt;
    int size, value ;

    printf( "Enter the number of elements: " );
    while( scanf( "%d", &size ) == 1 && size > 0 )
    {
        pnt = CreateArray( size );
        AcceptValue( pnt, size );
        
        if( pnt )
        {
            ShowArray( pnt, size );
            free( pnt );
        }
        printf( "\nEnter the number of elements ( <1 - end ): " );
    }
    printf( "End\n" );

    return 0;
}

int * AcceptValue( int array[ ], int size)
{
    /* Inserts values into the array 
        @param int      array
        @param int      size
        @return int     pointer to array
    */
    int value;
    int count = 0;

    while( count < size )
    {
        printf( "Enter %d value: ", count + 1 );
        if( scanf( "%d", &value ) != 1 )
        {
            printf( "Incorrect format.\n" );
            CLearBuffer();
            continue;
        }
        array[ count ] = value;
        count++;
    }
    return array;
}

int * CreateArray( int elem )
{
    /* Creates a dynamic array 
        @param  int         number of elements
        @param  int         a value
        @return int         a pointer to the array
    */
    int * pnt = ( int * ) malloc( elem * sizeof( int ));
    if ( pnt == NULL )
    {
        printf( "Memory allocation failed!\n" );
        return NULL;  // Return NULL if memory allocation fails
    }
    return pnt; 
}

void ShowArray( const int array[], int n )
{
    /* Show a content of an array 
        @param const int        an array
        @param int              size
    */
    for( int i = 0; i < n ; i ++ )
    {
        printf( "%10d", array[ i ]);
        if( ( i + 1 ) % 8 == 0 )
            printf( "\n" ); 
    }
}

void CLearBuffer( )
{
    /* Clears buffer
    */
    int n;
    while(( n = getchar()) != '\n' && n != EOF );
}

