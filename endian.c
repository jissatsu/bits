#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

char __Endian( void )
{   
    int c   = 0x000A;
    char *p = (char *) &c;
    char order;

    if ( *p == 0x0A ) order = 'L';
    if ( *p == 0x00 ) order = 'B';
    return order;
}

// convert 32bit integer to big endian
uint32_t host32BE( uint32_t num )
{
    char order;
    uint32_t rtv;
    
    order = __Endian();
    if ( order == 'L' )
        rtv = 0x00000000;
        rtv = (((((((rtv >> 24) | (num & 0xff)) << 8) | ((num >> 8) & 0xff)) << 8) | ((num >> 16) & 0xff)) << 8) | ((num >> 24) & 0xff);
    
    if ( order == 'B' ) rtv = num;
    return rtv;
}

// convert 16 bit integer to big endian
uint16_t host16BE( uint16_t num )
{
    char order;
    uint16_t rtv;

    order = __Endian();
    if ( order == 'L' )
        rtv = 0x0000;
        rtv = (((rtv >> 8) | (num & 0xff)) << 8) | ((num >> 8) & 0xff);

    if ( order == 'B' ) rtv = num;
    return rtv;
}

int main( int argc, char **argv )
{
    printf( "%u\n", host32BE( 3232235621 ) );
    printf( "%u\n", htonl( 3232235621 ) );
    
    printf( "%u\n", host16BE( 46863 ) );
    printf( "%u\n", htons( 46863 ) );

    printf( "%c\n", __Endian() );
    return 0;
}