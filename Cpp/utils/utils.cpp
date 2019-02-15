

#include <utils.h>

#include <string>
#include <vector>
#include <fstream>


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

} // namespace Utils

