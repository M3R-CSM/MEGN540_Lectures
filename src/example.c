/*
         MEGN540 Mechatronics Lab
    Copyright (C) Andrew Petruska, 2023.
       apetruska [at] mines [dot] edu
          www.mechanical.mines.edu
*/

/*
    Copyright (c) 2023 Andrew Petruska at Colorado School of Mines

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
   deal in the Software without restriction, including without limitation the
   rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
   sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
   IN THE SOFTWARE.

*/

#include <inttypes.h>  // define integer types like uint8_t
#include <stdio.h>     // printf - print to terminal
#include <stdlib.h>    // atoi - convert ascii to integer

const char* byte_to_binary( uint8_t value )
{
    // create a static char array to return.
    // The static here means the memory stays allocated and valid. Useful here, but note this funciton would not be thread safe.
    static char ret_str[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for( uint8_t i = 0; i < 8; i++ ) {
        // use bit-wise and (&) and left sift operator to determine bit value. Left to right print order means start at a sift of 7 and work backwords
        ret_str[i] = ( value & ( 1 << ( 7 - i ) ) ) ? '1' : '0';
    }

    return ret_str;
}

int main( int argc, char* argv[] )
{
    if( argc > 1 ) {

        // Create a union to map integers and bytes across the same memery space
        union {
            int input_value;
            uint8_t byte_array[sizeof( int )];
        } int_byte_u;

        // Map user input to integer value and check for 1-byte sizing ( [0, 255] or [-128,127] )
        int_byte_u.input_value = atoi( argv[1] );

        // print output
        printf( "Binary of %i is: 0b", int_byte_u.input_value );

        // run through bytes in reverse order to print from left to right
        for( int i = sizeof( int ) - 1; i >= 0; i-- ) {
            if( int_byte_u.byte_array[i] || i == 0 )  // only a null_value (all binary 0) returns false, anything else returns true
            {
                printf( "%s ", byte_to_binary( int_byte_u.byte_array[i] ) );
            }
        }

        printf( "\n" );  // end with newline

        // This is a print statement. It will not work with the car, but it will work for non-car work.
    } else {
        printf( "No Input Value Provided...\n" );
    }
    printf( "Program done.\n\n" );

    // the main function returns completion status. 0 means no error
    return 0;
}