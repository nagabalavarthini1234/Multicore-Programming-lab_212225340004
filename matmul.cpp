#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    float A[2][2] = {{1,2},{3,4}};
    float b[] = {8,10};
    float c[2];

    int i, j;

    // Parallel matrix-vector multiplication A * b
    #pragma omp parallel for private(j)
    for (i = 0; i < 2; i++) {
        c[i] = 0;
        for (j = 0; j < 2; j++) {
            c[i] += A[i][j] * b[j];
        }
    }

    // Print result
    for (i = 0; i < 2; i++) {
        cout << "c[" << i << "] = " << c[i] << endl;
    }

    return 0;
}
