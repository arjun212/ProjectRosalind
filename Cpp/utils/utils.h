#ifndef INCLUDED_UTILS
#define INCLUDED_UTILS


#include <string>
#include <vector>


namespace Utils
{



    std::vector< std::string > ReadFile( const std::string & filename     ,
                                               int           reserve  = 0 ) ;
    

    std::vector< int > SplitIntString( const std::string & line ) ;



} // namespace Utils




#endif  // INCLUDED_UTILS
