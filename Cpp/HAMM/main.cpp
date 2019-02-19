#include <iostream>
#include <cmath>
#include <iomanip>

#include "utils.h"

namespace
{
    typedef std::string::const_iterator StringCit ;
}


int main()
{
    std::vector< std::string > lines( Utils::ReadFile( "./data" ) ) ;

    std::string line1 = lines.at( 0 ) ;
    std::string line2 = lines.at( 1 ) ;

    StringCit it1 = line1.cbegin() ;
    StringCit it2 = line2.cbegin() ;
    StringCit et1 = line1.cend()   ;
    StringCit et2 = line2.cend()   ;

    int HAMMScore = 0 ;

    for( ; it1 != et1 && it2 != et2 ; ++it1, ++it2 )
    {
        if( *it1 != *it2 )
            ++HAMMScore ;
    }

    std::cout << HAMMScore << "\n" ;

    return 0 ;
}
