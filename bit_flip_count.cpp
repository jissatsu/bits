#include <stdio.h>
#include <iostream>

short bit_flip_count( int n1, int n2 ) {
    short res   = n1 ^ n2;
    short count = 0;

    while ( res > 0 ) {
        if ( res & 1 ) ++count;
        res >>= 1;
    }
    return count;
}

int main( int argc, char **argv ) {
    printf( "%d\n", bit_flip_count(10, 20) );
    return 0;
}