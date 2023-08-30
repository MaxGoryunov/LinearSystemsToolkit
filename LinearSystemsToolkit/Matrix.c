#include <malloc.h>
#include "Matrix.h"

Matrix* matrixCreate(int n) {
    Matrix* M = malloc(sizeof(Matrix));
    M->n = n;
    double** A = malloc(n * sizeof(double*) + n * n * sizeof(double));
	char* p = A;
	p += n * sizeof(double*);
	for (int i = 0; i < n; i++) {
		A[i] = p + i * n * sizeof(double);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i][j] = 0;
		}
	}
	M->data = A;
	return M;
}

void matrixDestroy(Matrix* M) {
	free(M->data);
	free(M);
}

Matrix* matrixIdentity(int n) {
    Matrix* M = matrixCreate(n);
    for (int i = 0; i < n; ++i) {
        M->data[i][i] = 1;
    }
    return M;
}

