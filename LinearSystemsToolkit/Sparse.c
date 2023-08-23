#include <malloc.h>
#include "Sparse.h"
#include "Common.h"

Element* elementCreate(double data, int col) {
	Element* e = SafeMalloc(sizeof(Element));
	e->data = data;
	e->col = col;
	e->next = NULL;
	return e;
}

void elementDestroy(Element* e) {
	if (e != NULL) {
		elementDestroy(e->next);
		free(e);
	}
}

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

Element* copiedRow(Element* row) {
	if (row == NULL) {
		return NULL;
	}
	Element* cur = row;
	Element* head = elementCreate(cur->data, cur->col);
	Element* tail = head;
	cur = cur->next;
	while (cur != NULL) {
		tail->next = cur;
		tail = tail->next;
		cur = cur->next;
	}
	return head;
}

Sparse* subtractedRows(Element* left, Element* right) {
	Element* head = NULL;
	Element* first = left;
	Element* second = right;
	if (first == NULL && second == NULL) {
		return head;
	}
	else if (first == NULL && second != NULL) {
		return copiedRow(second);
	}
	else if (first != NULL && second == NULL) {
		return copiedRow(first);
	}
	if (first->col < second->col) {
		head = elementCreate(first->data, first->col);
		first = first->next;
	}
	else if (second->col < first->col) {
		head = elementCreate(second->data, second->col);
		second = second->next;
	}
	else {
		head = elementCreate(
			first->data - second->data,
			first->col
		);
		first = first->next;
		second = second->next;
	}
	Element* tail = head;
	while (first != NULL && second != NULL) {
		if (first->col < second->col) {
			tail->next = elementCreate(first->data, first->col);
			tail = tail->next;
			first = first->next;
		}
		else if (second->col < first->col) {
			tail->next = elementCreate(second->data, second->col);
			tail = tail->next;
			second = second->next;
		}
		else {
			tail->next = elementCreate(
				first->data - second->data,
				first->col
			);
			tail = tail->next;
			first = first->next;
			second = second->next;
		}
		if (head == NULL && tail != NULL) {
			head = tail;
		}
	}
	if (first != NULL) {
		tail->next = first;
	}
	else {
		tail->next = second;
	}
	return head;
}

Sparse* sparseDiff(Sparse* left, Sparse* right) {
    Sparse* R = sparseCreate(left->n);
	for (int i = 0; i < R->n; ++i) {
		R->rows[i] = subtractedRows(left->rows[i], right->rows[i]);
	}
	return R;
}

/**
 * @todo #13:30m/DEV sparseSum is supposed to work similar to sparseDiff, but
 *  with addition instead of subtraction. It is outside of the goals of this
 *  PR to optimize written code and remove all duplication, so creating an
 *  implementation for sparseSum should be done in a separate PR.
*/

/**
 * @todo #13:60m/DEV All remaining functions from issue #13 starting from
 *  sparseScale and on are supposed to be implemented in a separate PR because
 *  this PR is already large enough.
*/