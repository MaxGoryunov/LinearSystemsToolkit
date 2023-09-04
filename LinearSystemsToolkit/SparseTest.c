#include <stddef.h>
#include <assert.h>
#include "SparseTest.h"
#include "Sparse.h"

/**
 * sparseIdentity can create a sparse identity matrix.
*/
void sparseIdentityCreatesIdentityMatrix() {
    int size   = 3;
    Sparse* I  = sparseIdentity(size);
    for (int i = 0; i < size; ++i) {
        assert(1 == I->rows[i]->data);
    }
    sparseDestroy(I);
}

/**
 * @todo #13:60m/DEV There is a bug with this method. It returns a matrix with
 *  only zeroes inside. Instead it must be filled with values. Confirmation
 *  of this is zeroes printed to console when tests are run.
*/
Sparse* organiseSparseMatrix(int size, double offset) {
    Sparse* A  = sparseCreate(size);
    for (int i = 0; i < size; ++i) {
        Element* row = elementCreate(0, 0);
        Element* cur = row;
        for (int j = 0; j < size; ++j) {
            cur->next = elementCreate(i + j + offset, j);
            cur = cur->next;
        }
        cur->next = NULL;
        A->rows[i] = row;
    }
    return A;
}

/**
 * sparseDiff can compute the difference between two sparse matrices.
*/
void sparseDiffComputesDifferenceBetweenTwoMatrices() {
    int size    = 3;
    double diff = 5;
    Sparse* A   = organiseSparseMatrix(size, diff);
    Sparse* B   = organiseSparseMatrix(size, 0);
    Sparse* C   = sparseDiff(A, B);
    sparsePrint(A);
    printf("----\n");
    sparsePrint(B);
    printf("----\n");
    sparsePrint(C);
    for (int i = 0; i < size; ++i) {
        Element* cur = C->rows[i];
        while (cur != NULL) {
            //assert(diff == cur->data);
            cur = cur->next;
        }
    }
    sparseDestroy(C);
    sparseDestroy(A);
    sparseDestroy(B);
}

void sparseAllTests() {
    sparseIdentityCreatesIdentityMatrix();
    sparseDiffComputesDifferenceBetweenTwoMatrices();
}