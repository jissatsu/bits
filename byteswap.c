#include <stdio.h>
#include <stdint.h>

uint32_t b32swap( uint32_t num )
{
    uint32_t rtv, a, b;

    rtv = 0x00000000;
    a   = (num >> 16) & 0xffff;
    b   = num & 0xffff;
    return (rtv = (((rtv >> 16) | b) << 16) | a);
}

uint16_t b16swap( uint16_t num )
{
    uint16_t rtv, a, b;

    rtv = 0x0000;
    a   = (num >> 8) & 0xff;
    b   = num & 0xff;
    return (rtv = (((rtv >> 8) | b) << 8) | a);
}

int main( int argc, char **argv )
{
    // 3232235621 = 1100000010101000 0000000001100101
    
    // b32swap( 3232235621 )

    // 3232235621 = 0000000001100101 1100000010101000
    printf( "%u\n", b32swap( 3232235621 ) );
    printf( "%u\n", b16swap( 46863 ) );
    return 0;
}