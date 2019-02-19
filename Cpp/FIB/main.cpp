#include <iostream>
#include <cmath>
#include <iomanip>

#include "utils.h"


int main()
{

    std::vector< int > nums( Utils::SplitIntString( Utils::ReadFile( "./data" ).at( 0 ) ) ) ;

    int n = nums.at( 0 ) ; // Number of iterations to run for
    int k = nums.at( 1 ) ; // Size of litter produced by each iteration


    int Fn1 = 1 ;
    int Fn2 = 1 ;

    // First two iterations are defined to start with
    // one rabbit pair, so remove them from the number
    // we must iterate over.
    n -= 2 ;


    int Fn = 1 ;

    for( ; n > 0 ; --n )
    {
        Fn  = ( Fn1 * k ) + Fn2 ;
        Fn1 = Fn2               ;
        Fn2 = Fn                ;

    }


    std::cout << Fn << "\n" ;

    return 0 ;
}
