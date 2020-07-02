#include <stdio.h>
#include <iostream>

short get_set_bits( int n ) {
    short count = 0;
    while ( n > 0 ) {
        count += n & 1, n >>= 1;
    }
    return count;
}

int main( int argc, char **argv ) {
    printf( "%d\n", get_set_bits(13) );
    return 0;
}