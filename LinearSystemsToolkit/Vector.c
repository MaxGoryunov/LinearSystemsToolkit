#include <math.h>
#include "Vector.h"
#include "Common.h"

Vector* vectorCreate(int n) {
	Vector* v = SafeMalloc(sizeof(Vector));
	v->data = SafeMalloc(sizeof(double) * n);
	v->n = n;
	for (int i = 0; i < n; ++i) {
		v->data[i] = 0;
	}
	return v;
}

Vector* vectorSum(Vector* left, Vector* right) {
	Vector* v = vectorCreate(left->n);
	for (int i = 0; i < v->n; ++i) {
		v->data[i] = left->data[i] + right->data[i];
	}
	return v;
}

Vector* vectorDiff(Vector* left, Vector* right) {
	Vector* v = vectorCreate(left->n);
	for (int i = 0; i < v->n; ++i) {
		v->data[i] = left->data[i] - right->data[i];
	}
	return v;
}

double secondNorm(Vector* v) {
	double sum = 0;
	for (int i = 0; i < v->n; ++i) {
		sum += v->data[i] * v->data[i];
	}
	return sqrt(sum);
}

Vector* vectorScale(Vector* v, double num) {
	Vector* vv = vectorCreate(v->n);
	for (int i = 0; i < vv->n; ++i) {
		vv->data[i] = v->data[i] * num;
	}
	return vv;
}

Vector* linspace(double start, double end, int n) {
	Vector* x = vectorCreate(n);
	for (int i = 0; i < n; i++) {
		x->data[i] = start + (end - start) / (n - 1) * i;
	}
	return x;
}

double scalarMultiplication(Vector* row, Vector* col) {
	double sum = 0;
	for (int i = 0; i < row->n; ++i) {
		sum += row->data[i] * col->data[i];
	}
	return sum;
}

char vectorDataEqual(Vector* left, Vector* right) {
	char equal = 1;
	for (int i = 0; i < left->n; ++i) {
		if (left->data[i] != right->data[i]) {
			equal = 0;
			break;
		}
	}
	return equal;
}

char vectorEqual(Vector* left, Vector* right) {
	return (left->n == right->n) && vectorDataEqual(left, right);
}