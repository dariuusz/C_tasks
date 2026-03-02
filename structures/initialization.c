/* This is initialisation task that uses 2 approaches. Fields initialization
    and designated initializer*/

#include <stdio.h>
#include <string.h>

#define LENSES_SIZE  3

typedef struct lens{
    float   focalLength;
    float   aperture;
    char    brand[ 30 ];
} LENS;

void printLenses( LENS lenses[]);
void intializeLensesByFields( LENS lenses[ ]);
void initializeLensesByDesignatedInitializer( LENS lenses[ ]);

int main( void )
{
    // Some random data initialization
    LENS lenses[ LENSES_SIZE ];
    intializeLensesByFields( lenses );

    // Designated initializer
    LENS lenses2[ LENSES_SIZE ];
    initializeLensesByDesignatedInitializer( lenses2 );

    printLenses( lenses );
    printLenses( lenses2 );

    return 0;
}

/*
* @brief    Prints the lens data in a formatted way 
* @return   Nothing
*/
void printLenses( LENS lenses[] )
{
    for( int i = 0; i < LENSES_SIZE; i++ )
    {
        printf( "Focal Length: %.1f, Aperature: %.1f, Brand: %s\n",
                lenses[ i ].focalLength,
                lenses[ i ].aperture,
                lenses[ i ].brand );
    }
}

/*
* @brief    Initializes the lens data by fields
* @return   Nothing
*/
void intializeLensesByFields( LENS lenses[ ] )
{
    lenses[ 0 ].focalLength = 50.0;
    lenses[ 0 ].aperture = 1.8;
    strcpy( lenses[ 0 ].brand, "Canon" );
    lenses[ 1 ].focalLength = 85.0;
    lenses[ 1 ].aperture = 1.4;
    strcpy( lenses[ 1 ].brand, "Nikon" );
    lenses[ 2 ].focalLength = 5000;
    lenses[ 2 ].aperture = 2.0;
    strcpy( lenses[ 2 ].brand, "Remarkatar" );
}

/*
* @brief    Initializes the lens data using designated initializer
* @return   Nothing
*/
void initializeLensesByDesignatedInitializer( LENS lenses[ ] )
{
    lenses[ 0 ] = (LENS){ 50.0, 1.8, "Canon" };
    lenses[ 1 ] = (LENS){ 85.0, 1.4, "Nikon" };
    lenses[ 2 ] = (LENS){ 35.0, 1.8, "Sony" };
}