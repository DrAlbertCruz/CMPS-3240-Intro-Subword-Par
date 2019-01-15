// DEWMV - Double precision element-wise vector multiplication
// Carries out x * y, where x and y are two vectors of size N. This is an element-wise 
// operation.
void dewvm( int N, double *x, double *y, double *result );

// DGEMV - Double precision generalized matrix time vector
// Carries out A * x + y, where A is an N * N matrix, and x and y are N * 1 vectors. 
void dgemv( int N, double *A, double *x, double *y, double *result );

