

#include <utils.h>

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace Utils
{

    std::vector< std::string > ReadFile( const std::string & filename ,
                                               int           reserve  )
    {
        std::ifstream file( filename ) ;

        std::vector< std::string > output ;
        if( reserve != 0 )
            output.reserve( reserve ) ;

        std::string lineBuffer ;

        while( std::getline( file, lineBuffer ) )
        {
            output.push_back( lineBuffer ) ;
        }

        return output ;
    }



    std::vector< int > SplitIntString( const std::string & line )
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

