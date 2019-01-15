#include <stdio.h>
#include "myblas.h"

// 0 if x matches y
int checkArrays( int N, double *x, double *y ) {
    for( int i = 0; i < N; i++ )
       if( x[i] != y[i] )
          return 1;
    
    return 0;
}

int main( void ) {
    // Test on a small vector of 2x1
    double array1[4] = { 13.0, 13.0, 13.0, 13.0 };
    double array2[4] = { 7.0, 7.0, 7.0, 7.0 };
    double result[4];
    dewvm( 4, array1, array2, result );

    return 0;
}
