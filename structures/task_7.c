/* This is a simple task that uses structures and pointers to structures
    to print values*/

#include <stdio.h>

#define CHARS   20
#define TYPE   30

struct daneos
{
    char name[ CHARS ];
    char surname[ CHARS ];
};

struct bem 
{
    int legs;
    struct daneos title;
    char type[ TYPE ];
};

int main( void )
{
    struct bem *wb;
    struct bem deb = {
        6,
        { "Berbnazel", "Gwolkapwolk" },
        "Arkturianin"
    };

    wb = &deb;

    // Task 7a
    printf( "%d\n", deb.legs );
    printf( "%s\n", wb->type );
    printf( "%s\n", wb->type +2 );

    // Task 7b -> printing Gwolkapwold
    printf( "%s\n", wb->title.surname );
    printf( "%s\n",  deb.title.surname );

    // Task 7c -> printing "Berbnazel Gwolkapwolk is Arkturianinem with 6 legs"
    printf( "%s %s is %s with %d legs\n", 
            wb->title.name,
            deb.title.surname,
            wb->type,
            deb.legs
        );

    return 0;
}