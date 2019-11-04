#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// convert 32bit integer to big endian
uint32_t host32BE( uint32_t num )
{
    uint32_t rtv;
    
    rtv = 0x00000000;
    rtv = (((((((rtv >> 24) | (num & 0xff)) << 8) | ((num >> 8) & 0xff)) << 8) | ((num >> 16) & 0xff)) << 8) | ((num >> 24) & 0xff);
    return rtv;
}

int main( int argc, char **argv )
{
    printf( "%u\n", host32BE( 3232235621 ) );
    printf( "%u\n", htonl( 3232235621 ) );
    return 0;
}