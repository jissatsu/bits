#include <stdio.h>
#include <iostream>

short numeq( int n1, int n2 ) {
    return (n1 ^ n2);
}

int main( int argc, char **argv ) {
    printf( "%s\n", numeq(10, 10) == 0 ? "true" : "false" );
    return 0;
}