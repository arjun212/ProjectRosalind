

#include <utils.h>

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace Utils
{

    std::vector< std::string > ReadFile( std::string filename )
    {
        std::ifstream file( filename ) ;

        std::vector< std::string > output ;

        std::string lineBuffer ;

        while( std::getline( file, lineBuffer ) )
        {
            output.push_back( lineBuffer ) ;
        }

        return output ;
    }



    std::vector< int > SplitIntString( std::string line )
    {
        std::istringstream iss ( line ) ;

        std::vector< int > result ;

        int n ;
        while( iss >> n )
        {
            result.push_back( n ) ;
        }

        return result ;
    }


} // namespace Utils

