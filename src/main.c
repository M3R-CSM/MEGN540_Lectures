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

#include <inttypes.h>  // for uint8_t etc
#include <stdio.h>

int main( int argc, char* argv[] )
{
    // print type sizing
    printf( "A float is %lu bytes\n", sizeof( float ) );

    printf( "A int is %lu bytes\n", sizeof( int ) );

    printf( "A uint16_t is %lu bytes\n", sizeof( uint16_t ) );

    printf( "\n\n" );

    /////////   Lets make an array  //////////
    int8_t my_array[3];

    printf( "Size of my_array: %lu\n", sizeof( my_array ) );  // when the array in in scope the compiler knows how bit it is.

    // put data in my array
    my_array[0] = 6;  // arrays indexing starts at 0
    my_array[1] = 7;
    my_array[2] = 8;

    // print the data
    for( uint8_t i = 0; i < sizeof( my_array ); i++ ) {
        /* ****** CAUTION!!  **********
        sizeof(my_array) only works in the scope of the array instantiation (int my_array[3]).
        When passed to a function it will return the size of the array pointer (8 on a 64bit machine).
        */

        printf( "my_array @ index %i is %i.\n", i, my_array[i] );
    }

    printf( "\n\n" );

    /////////   Lets make a struct  //////////

    typedef struct __attribute__( ( __packed__ ) ) {
        // NOTE: __attribute__((__packed__)) is only requried to prevent memory padding on desktop systems, but it costs in run-time efficiency
        float a;
        uint8_t b;
    } My_Struct_t;

    My_Struct_t my_struct;
    my_struct.a = 3.0;
    my_struct.b = 6;

    printf( "Size of My_Struct_t: %lu\n", sizeof( My_Struct_t ) );

    printf( "Size of my_struct float part: %f\n", ( my_struct.a ) );
    printf( "Size of my_struct uint8 part: %i\n", ( my_struct.b ) );

    printf( "\n\n" );

    /////////  Lets Talk unions   /////////////

    typedef union {
        int asInt;
        uint8_t asByteArray[sizeof( int )];
    } Float_Char_Union_t;

    Float_Char_Union_t my_union;

    printf( "Size of Float_Char_Union_t: %lu\n", sizeof( Float_Char_Union_t ) );

    my_union.asInt = 15;
    for( int8_t i = 0; i < 4; i++ )
        printf( "int of %i: byte %i is 0x%X\n", my_union.asInt, i, my_union.asByteArray[i] );

    // the main function returns completion status. 0 means no error
    return 0;
}