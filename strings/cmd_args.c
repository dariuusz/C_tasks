/* Program reads date to the end of the file and displays them on the screen. 
    Additionally, it accepts command line arguments:
    -p      showing data without change
    -u      capitalize all letters
    -l      lower all letters
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ProcessFile( FILE *, int );

int main( int argc, char *argv[ ])
{
    int option = 'p';
    FILE *file;

    if( argc > 1 )
    {
        if( strcmp( argv[ 1 ], "-u" ) == 0 )
            option = 'u';
        else if( strcmp( argv[ 1 ], "-l" ) == 0 )
            option = 'l';
        else if( strcmp( argv[ 1 ], "-p" ) != 0 )
        {
            fprintf( stderr, "Unknown argument: %s\n", argv[ 1 ]);
            return 1;
        }                                                                                                                                                            
    }

    file = stdin;

    ProcessFile( file, option );

    return 0;
}

void ProcessFile( FILE *file, int option ) {
    int ch;
    while (( ch = fgetc( file )) != EOF ) 
    {
        switch ( option ) {
            case 'u':
                putchar( toupper( ch ));
                break;
            case 'l':
                putchar( tolower( ch ));
                break;
            case 'p':
            default:
                putchar( ch );
                break;
        }
    }
}