/* draw_picture.c           This program procees numbers contained in the files and replaces them with
                            corresponding sign to draw a picture and saves it into another file.
                            Signs:
                            0   ->  ' '
                            1   ->  '.'
                            2   ->  '''
                            3   ->  ':'
                            4   ->  '~'
                            5   ->  '*'
                            6   ->  '='
                            7   ->  '!'
                            8   ->  '%'
                            9   ->  '#'
*/

#include <stdio.h>
#include <stdlib.h>

#define ROWS                20
#define COLUMNS             30
#define DRAWING_COLUMNS     31

/* Functions*/
void loadData( const char * filename, int data[ ROWS ][ COLUMNS ]);
void convertToDrawings( const int[ ROWS ][ COLUMNS ], char drawing[ ROWS ][ DRAWING_COLUMNS ], const char * filename );

int main( int argc, char * argv[] )
{
    // Argument validation
    if( argc != 2 )
    {
        fprintf( stderr, "Usage: <filename>", argv[ 0 ]);
        exit( EXIT_FAILURE );
    }

    // Variable initialization
    const char * numbersFile = argv[ 1 ];
    const char * drawingFile = "drawing.txt";
    int data[ ROWS ][ COLUMNS ];
    char drawing[ ROWS ][ DRAWING_COLUMNS ];

    loadData( numbersFile, data );
    convertToDrawings( data, drawing, drawingFile );

    return 0;
}

void loadData( const char * filename, int data[ ROWS ][ COLUMNS ])
{
    FILE * file = fopen( filename, "r" );
    if( !file )
    {
        fprintf( stderr, "Can not open file." );
        exit( EXIT_FAILURE );
    }

    for( int i = 0; i < ROWS; i++ )
        for( int j = 0; j < COLUMNS; j++ )
            fscanf( file, "%d", &data[ i ][ j ]);
    
    if( fclose( file ) != 0 )
        fprintf( stderr, "Error while closing file." );
}

void convertToDrawings( const int data[ ROWS ][ COLUMNS ], char drawing[ ROWS ][ DRAWING_COLUMNS ], const char * filename )
{
    // Reflecting signs to numbers
    const char symbols[ ] = " .':~*=!&#";

    // Number convertion
    for( int i = 0; i < ROWS; i++ )
    {        
        for( int j = 0; j < COLUMNS; j++ )
        {
            drawing[ i ][ j ] = symbols[ data[ i ][ j ]];
        }
        drawing[ i ][ COLUMNS ] = '\0';
    }

    FILE * file = fopen( filename, "w" );
    if( !file )
    {
        fprintf( stderr, "Can not open file." );
        exit( EXIT_FAILURE );
    }

    for( int i = 0; i < ROWS; i++ )
        fprintf( file, "%s\n", drawing[ i ]);

    if( fclose( file ) != 0 )
        fprintf( stderr, "Error while closing file." );
}