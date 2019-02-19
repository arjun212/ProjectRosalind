#include <iostream>
#include <map>
#include <iomanip>

#include "utils.h"

namespace
{
/*
 * HD + HT = 100% Dominant trait visible
 * HD + HR = 100% Dominant trait visible
 * HT + HR = 50% Dominant trait visible
 */
    double DTVisibleProb( const std::string & picks )
    {
        if( picks == "HD_HD" )
            return 1.0  ;
        if( picks == "HD_HT" )
            return 1.0  ;
        if( picks == "HD_HR" )
            return 1.0  ;
        if( picks == "HT_HD" )
            return 1.0  ;
        if( picks == "HT_HT" )
            return 0.75 ;
        if( picks == "HT_HR" )
            return 0.5  ;
        if( picks == "HR_HD" )
            return 1.0  ;
        if( picks == "HR_HT" )
            return 0.5  ;
        if( picks == "HR_HR" )
            return 0.0  ;
        return 0.0 ;
    }

    struct Population
    {
        int HD ; // Homozygous Dominant
        int HT ; // Heterozygous
        int HR ; // Homozygous Recessive

        void grabHD(){ --HD ; }
        void grabHT(){ --HT ; }
        void grabHR(){ --HR ; }
        void grab( const std::string & type )
        {
            if( type == "HD" )
                grabHD() ;
            if( type == "HR" )
                grabHR() ;
            if( type == "HT" )
                grabHT() ;
        }

        double probHD()
        {
            return ( HD > 0 ) ? ( HD * 1.0 ) / ( HD + HT + HR ) : 0 ;
        }

        double probHT()
        {
            return ( HT > 0 ) ? ( HT * 1.0 ) / ( HD + HT + HR ) : 0 ;
        }

        double probHR()
        {
            return ( HR > 0 ) ? ( HR * 1.0 ) / ( HD + HT + HR ) : 0 ;
        }

        double prob( const std::string & type )
        {
            if( type == "HD" )
                return probHD() ;
            if( type == "HR" )
                return probHR() ;
            if( type == "HT" )
                return probHT() ;

            return 0;
        }

    } ;
} // namespace

int main()
{
    
    std::string line( Utils::ReadFile( "./data" ).at( 0 ) ) ;
    std::vector< int > nums( Utils::SplitIntString( line ) ) ;

    const Population pop{ nums.at( 0 ) ,   // Homozygous Dominant 
                          nums.at( 1 ) ,   // Heterozygous 
                          nums.at( 2 ) } ; // Homozygous Recessive


    // Here we are going to simulate building a probability tree

    std::map< std::string, double > probTree ;

    for( const std::string & type1 : { "HD", "HT", "HR" } )
    {
        Population firstRemoval = pop ;
        double firstProb = firstRemoval.prob( type1 ) ;
        firstRemoval.grab( type1 ) ;

        for( const std::string & type2 : { "HD", "HT", "HR" } )
        {
            Population secondRemoval = firstRemoval ;
            double secondProb = secondRemoval.prob( type2 ) ;
            secondRemoval.grab( type2 ) ;

            std::stringstream ss ;
            ss << type1 << "_" << type2 ;
            probTree[ ss.str() ] = firstProb * secondProb ;
        }
    }

    double sum = 0 ;
    for( std::map< std::string, double >::const_iterator it = probTree.cbegin(),
                                                         et = probTree.cend()  ;
                                                         it != et ;
                                                         ++it )
    {
        sum += DTVisibleProb( it->first ) * it->second ;  
    }

    std::cout << sum << "\n" ;

    return 0 ;
}
