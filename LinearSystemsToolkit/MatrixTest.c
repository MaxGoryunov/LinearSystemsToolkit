#include <assert.h>
#include "MatrixTest.h"
#include "Matrix.h"

/**
 * matrixIdentity can return an identity matrix.
*/
void matrixIdentityReturnsIdentityMatrix() {
    int size  = 3;
    Matrix* A = matrixIdentity(size);
    for (int i = 0; i < size; ++i) {
        assert(1 == A->data[i][i]);
    }
    matrixDestroy(A);
}

/**
 * matrixSum can return the sum of two matrices.
*/
void matrixSumSumsTwoMatrices() {
    int size  = 3;
    Matrix* A = matrixCreate(size);
    Matrix* B = matrixCreate(size);
    Matrix* S = matrixCreate(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A->data[i][j] = i;
            B->data[i][j] = j;
            S->data[i][j] = i + j;
        }
    }
    assert(1 == matrixEqual(matrixSum(A, B), S));
    matrixDestroy(A);
    matrixDestroy(B);
    matrixDestroy(S);
}

/**
 * matrixDiff can compute the difference of two matrices.
*/
void matrixDiffComputesDifferenceOfTwoMatrices() {
    int size  = 3;
    Matrix* A = matrixCreate(size);
    Matrix* B = matrixCreate(size);
    Matrix* D = matrixCreate(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A->data[i][j] = i + j;
            B->data[i][j] = j;
            D->data[i][j] = i;
        }
    }
    assert(1 == matrixEqual(matrixDiff(A, B), D));
    matrixDestroy(A);
    matrixDestroy(B);
    matrixDestroy(D);
}

/**
 * matrixScale can scale a matrix by some factor.
*/
void matrixScaleScalesMatrixBySomeFactor() {
    int size  = 3;
    double factor = 3;
    Matrix* A = matrixCreate(size);
    Matrix* S = matrixCreate(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            A->data[i][j] = i + j;
            S->data[i][j] = (i + j) * factor;
        }
    }
    assert(1 == matrixEqual(matrixScale(A, factor), S));
    matrixDestroy(A);
    matrixDestroy(S);
}

void matrixAllTests() {
    matrixIdentityReturnsIdentityMatrix();
    matrixSumSumsTwoMatrices();
}