#include <stdio.h>
#include <stdint.h>

// swap 2 halves of a 32 bit int
uint32_t bh32swap( uint32_t num )
{
    uint32_t rtv, a, b;

    rtv = 0x00000000;
    a   = (num >> 16) & 0xffff;
    b   = num & 0xffff;
    return (rtv = (((rtv >> 16) | b) << 16) | a);
}

// swap 2 halves of a 16 bit int
uint16_t bh16swap( uint16_t num )
{
    uint16_t rtv, a, b;

    rtv = 0x0000;
    a   = (num >> 8) & 0xff;
    b   = num & 0xff;
    return (rtv = (((rtv >> 8) | b) << 8) | a);
}

// swap 2 halves of a 8 bit int
uint8_t bh8swap( uint8_t num )
{
    uint8_t rtv, a, b;

    rtv = 0x00;
    a   = (num >> 4) & 0xf;
    b   = num & 0xf;
    return (rtv = (((rtv >> 4) | b) << 4) | a);
}

int main( int argc, char **argv )
{
    // 3232235621 = 1100000010101000 0000000001100101
    
    // bh32swap( 3232235621 )

    // 3232235621 = 0000000001100101 1100000010101000
    printf( "%u\n", bh32swap( 3232235621 ) );
    printf( "%u\n", bh16swap( 46863 ) );
    printf( "%u\n", bh8swap( 223 ) );
    return 0;
}
