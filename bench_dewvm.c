#include <stdio.h>
#include <stdlib.h>
#include "myblas.h"

#define LENGTH 100000000

int main( void ) {
    /* This function tests the dewvm() function by carrying it out on an arbitrarily large 
     * vector. It only does this one so you will need some shell scripting to repeat this binary
     * a few times to get a good estimate with $time. 
     */
    double *array1 = (double *) malloc( sizeof(double) * LENGTH );
    double *array2 = (double *) malloc( sizeof(double) * LENGTH );
    double *array3 = (double *) malloc( sizeof(double) * LENGTH );
    
    dewvm( LENGTH, array1, array2, array3 );

    free( array1 );
    free( array2 );
    free( array3 );
    return 0;
}
