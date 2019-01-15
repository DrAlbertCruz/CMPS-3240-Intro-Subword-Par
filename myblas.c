// DEWVM - Double precision element-wise vector multiplication
// Carries out x * y, where x and y are two vectors of size N. This is an element-wise 
// operation. Steps through an array and multiplies each element together.
int dewvm( int N, double *x, double *y, double *result ) {
    for( int i = 0; i < N; i++ )
        result[i] = x[i] * y[i];

    return 0;
}

