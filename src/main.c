#include <stdio.h>

int main( int argc, char* argv[] )
{
    // This is a print statement. It will not work with the car, but it will work for non-car work.
    printf( "Number of Inputs is: %i\n", argc );

    // This is how we make a for loop
    for( int i = 0; i < argc; i++ ) {
        printf( "Input %i is %s\n", i, argv[i] );
    }
    printf( "Program done.\n\n" );

    // the main function returns completion status. 0 means no error
    return 0;
}