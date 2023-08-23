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

void sparsePrint(Sparse *A) {
    for (int i = 0; i < A->n; ++i) {
		Element* cur = A->rows[i];
		for (int j = 0; j < A->n; ++j) {
			if (cur != NULL && cur->col == j) {
				printf("%.15f ", cur->data);
				cur = cur->next;
			}
			else {
				printf("%.15f ", 0);
			}
		}
		printf("\n");
	}
}
/**
 * @todo #13:30m/DEV There must be a possibility to specify printed numbers' 
 *  format. Function 'sparsePrint' always prints numbers with 15-digit
 *  precision.
*/

