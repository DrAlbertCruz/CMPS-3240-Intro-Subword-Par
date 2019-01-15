#include <stdio.h>
#include "myblas.h"

#define LENGTH 4

// 0 if x matches y
int checkArrays( int N, double *x, double *y ) {
    for( int i = 0; i < N; i++ )
       if( x[i] != y[i] )
          return 1;
    
    return 0;
}

int main( void ) {
    // Test on a small vector of 2x1
    double array1[LENGTH] = { 1.0, 2.0, 3.0, 4.0 };
    double array2[LENGTH] = { 1.0, 2.0, 3.0, 4.0 };
    double result[LENGTH];
    dewvm( LENGTH, array1, array2, result );

    double correctResult[LENGTH] = { 1.0, 4.0, 9.0, 16.0 };

    if( !checkArrays( LENGTH, result, correctResult ) )
       printf( "Works fine!\n" );
    else
       printf( "Does not work.\n" ); 

    return 0;
}
