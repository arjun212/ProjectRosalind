#include <iostream>
#include <cmath>
#include <iomanip>

#include "utils.h"


int main()
{

    std::vector< std::string > lines( Utils::ReadFile( "./data" ) ) ;

    std::string line = lines.at( 0 ) ;


    std::stringstream ss ;

    for( char c : line )
    {
        if( c == 'T' )
            ss << 'U' ;
        else
            ss << c ;
    }

    std::cout << ss.str() << "\n" ;

    return 0 ;
}
