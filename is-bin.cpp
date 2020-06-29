#include <iostream>

bool is_bin( std::string num ) {
    if ( num.empty() ) {
        goto bad;
    }
    for ( std::string::iterator it = num.begin() ; it != num.end() ; it++ ) {
        if ( *it != '0' && *it != '1' ) {
            goto bad;
        }
    }
    return true;
    bad:
        return false;
}

int main( int argc, char **argv ) {
    if ( !is_bin( "0101011b11" ) ) {
        std::cout << "1 - Invalid bit string!\n" << "\n";
    }
    if ( !is_bin( "010101111" ) ) {
        std::cout << "2 - Invalid bit string!\n" << "\n";
    }
    return 0;
}