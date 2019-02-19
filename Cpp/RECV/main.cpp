#include <iostream>
#include <unordered_map>
#include <sstream>

#include "utils.h"


static std::unordered_map< char, char > REVERSE( { { 'A', 'T' } ,
                                                   { 'T', 'A' } ,
                                                   { 'C', 'G' } ,
                                                   { 'G', 'C' } } ) ;

int main()
{

    std::vector< std::string > lines( Utils::ReadFile( "./data" ) ) ;

    std::string line = lines.at( 0 ) ;


    std::stringstream ss ;

    for( std::string::reverse_iterator it = line.rbegin() ,
                                       et = line.rend()   ; it != et ; ++it )
    {
        ss << REVERSE[ *it ] ;
    }

    std::cout << ss.str() << "\n" ;

    return 0 ;
}
