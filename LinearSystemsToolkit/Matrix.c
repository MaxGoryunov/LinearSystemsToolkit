#include <malloc.h>
#include <stdio.h>
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

Matrix* matrixReadFromFile(const char* name, int n) {
    FILE* f = fopen(name, "r");
    Matrix* A = matrixCreate(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(f, "%lf", &(A->data[i][j]));
        }
    }
    fclose(f);
    return A;
}

void matrixPrint(Matrix* M) {
    for (int i = 0; i < M->n; ++i) {
        for (int j = 0; j < M->n; ++j) {
            printf("%lf ", M->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* matrixSum(Matrix* left, Matrix* right) {
	Matrix* S = matrixCreate(left->n);
	for (int i = 0; i < left->n; ++i) {
		for (int j = 0; j < right->n; ++j) {
			S->data[i][j] = left->data[i][j] + right->data[i][j];
		}
	}
	return S;
}

Matrix* matrixDiff(Matrix* left, Matrix* right) {
	Matrix* D = matrixCreate(left->n);
	for (int i = 0; i < left->n; ++i) {
		for (int j = 0; j < right->n; ++j) {
			D->data[i][j] = left->data[i][j] - right->data[i][j];
		}
	}
	return D;
}

Matrix* matrixScale(Matrix* A, double num) {
	Matrix* S = matrixCreate(A->n);
	for (int i = 0; i < A->n; ++i) {
		for (int j = 0; j < A->n; ++j) {
			S->data[i][j] = A->data[i][j] * num;
		}
	}
	return S;
}

int matrixEqual(Matrix* left, Matrix* right) {
	if (left->n != right->n) {
		return 0;
	}
	for (int i = 0; i < left->n; ++i) {
		for (int j = 0; j < left->n; ++j) {
			if (left->data[i][j] != right->data[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}