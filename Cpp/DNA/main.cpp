#include <iostream>
#include <cmath>
#include <iomanip>

#include "utils.h"

enum CHAR_INDEX
{
    A     = 0 ,
    C     = 1 ,
    G     = 2 ,
    T     = 3 ,
    COUNT
} ;



int main()
{
    std::vector< std::string > test( Utils::ReadFile( "./data" ) ) ;
    
    std::string DNA = test.at( 0 ) ;

    std::array< int, COUNT > result = { 0, 0, 0, 0 } ;

    for( char c : DNA )
    {
        switch( c )
        {
            case 'A' : ++result[ A ] ; break ;
            case 'C' : ++result[ C ] ; break ;
            case 'G' : ++result[ G ] ; break ;
            case 'T' : ++result[ T ] ; break ;
        }

    }
    
    for( int count : result )
        std::cout << count << " " ;
    
    std::cout << "\n" ;

	return 0;
}
