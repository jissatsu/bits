#include "stdio.h"
#include <stdint.h>

int8_t bit_pos( int32_t ent, int8_t pos )
{
    int8_t bit;
    if ( ent <= 0 )
        return -1;

    if ( pos < 0 || pos > 32 )
        return -1;
    
    bit = (ent >> (pos - 1)) & 01;
    return bit;
}

int main( int argc, char **argv )
{
    printf( "%d\n", bit_pos( 20, 5 ) );
    return 0;
}