#ifndef INCLUDED_UTILS
#define INCLUDED_UTILS


#include <string>
#include <vector>


namespace Utils
{



    std::vector< std::string > ReadFile( std::string filename ) ;
    

    std::vector< int > SplitIntString( std::string line ) ;



} // namespace Utils




#endif  // INCLUDED_UTILS
