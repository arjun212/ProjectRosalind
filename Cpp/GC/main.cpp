#include <iostream>
#include <cmath>
#include <iomanip>

#include "utils.h"

namespace
{
    const std::string NULL_MARKER = "XXXX" ;
    const int         EPOCH_LIMIT = 0.001  ;

    std::string getMarker( const std::string & markerLine  )
    {
        std::string::const_iterator start = markerLine.end() - 4 ;
        std::string::const_iterator end   = markerLine.end() ;
        return std::string( start, end ) ;
    }

    double computeGc( const std::string & dna )
    {
        if( dna.empty() )
        {
            return -1 ;
        }

        int gcCount = 0 ;

        for( char c : dna )
        {
            if( c == 'G' || c == 'C' )
                ++gcCount ;
        }

        return ( gcCount * 100.0 ) / dna.length() ;
    }

    void propagateHighestGc( const std::string & marker          ,
                             const std::string & currentBuffer   ,
                                   double      & highestGC       ,
                                   std::string & highestGCMarker )
    {
        double currentGc = computeGc( currentBuffer ) ;
        double epoch     =  currentGc - highestGC     ;
        if( epoch > EPOCH_LIMIT )
        {
            highestGC       = currentGc ;
            highestGCMarker = marker    ;
        }
    }

}

int main()
{

    std::vector< std::string > lines( Utils::ReadFile( "./data" ) ) ;

    std::string currentGcMarker = NULL_MARKER ;
    std::string buffer          = ""          ;

    double      highestGC       = -1          ;
    std::string highestGCMarker = NULL_MARKER ;

    // for( const std::string & line : lines ) is the same
    for( std::vector< std::string >::const_iterator it = lines.cbegin() ,
                                                    et = lines.cend()   ; it != et ; ++it )
    {
        const std::string & line = *it;

        std::size_t pos = line.find( '>' ) ;

        if( pos != std::string::npos ) 
        {
            currentGcMarker = getMarker( line ) ;
            propagateHighestGc( currentGcMarker, buffer, highestGC, highestGCMarker ) ;
            
            buffer = "" ;
        }
        else
        {
            buffer += line ;
        }

    }

    propagateHighestGc( currentGcMarker, buffer, highestGC, highestGCMarker ) ;

    std::cout << "Rosalind_" << highestGCMarker << "\n" << highestGC << "\n" ;


    return 0 ;
}
