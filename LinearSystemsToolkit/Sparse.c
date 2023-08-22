#include <malloc.h>
#include "Sparse.h"
#include "Common.h"

Sparse* sparseCreate(int n) {
    Sparse* S = SafeMalloc(sizeof(Sparse));
	S->n = n;
	S->rows = SafeMalloc(n * sizeof(Element*));
	for (int i = 0; i < n; ++i) {
		S->rows[i] = NULL;
	}
	return S;
}

void sparseDestroy(Sparse* A) {
    for (int i = 0; i < A->n; ++i) {
        free(A->rows[i]);
    }
    free(A);
}

Sparse *sparseIdentity(int n)
{
    Sparse* S = sparseCreate(n);
	for (int i = 0; i < n; ++i) {
		S->rows[i] = elementCreate(1, i);
	}
	return S;
}
