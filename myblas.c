// DEWVM - Double precision element-wise vector multiplication
// Carries out x * y, where x and y are two vectors of size N. This is an element-wise 
// operation. Steps through an array and multiplies each element together.
int dewvm( int N, double *x, double *y, double *result ) {
    for( int i = 0; i < N; i++ )
        result[i] = x[i] * y[i];

    return 0;
}

// DGEMV - Double precision generalized matrix time vector
// Carries out A * x + y, where A is an N * N matrix, and x and y are N * 1 vectors. 
int dgemv( int N, double *A, double *x, double *y, double *result ) {
    for( int i = 0; i < N; i++ ) {
        // First term
        double c = 0;
        for( int j = 0; j < N; j++ )
            c += A[i + j*N] * x[i];

        // Second term, place directly in *result
        result[i] = c + y[i];
    }

    return 0;
}
