#include <assert.h>
#include "Vector.h"

/**
* vectorSum can produce a sum of two vectors.
*/
void sumsTwoVectors() {
	int size      = 3;
	Vector* left  = vectorCreate(size);
	Vector* right = vectorCreate(size);
	Vector* sum   = vectorCreate(size);
	for (int i = 0; i < size; ++i) {
		left->data[i]  = i;
		right->data[i] = i * 2;
		sum->data[i]   = i * 3;
	}
	assert(1 == vectorEqual(vectorSum(left, right), sum));
}
/**
 * @todo #12:30m/DEV There is no operation for freeing the memory when the
 *  vector is no longer needed. There must be a function which takes a 
 *  vector and frees memory reserved for it. This behaviour in tests must
 *  be checked by special methods which detect memory leakages.
*/

/**
 * vectorDiff returns a difference of two vectors.
*/
void calculatesDiffOfTwoVectors() {
	int size      = 3;
	Vector* left  = vectorCreate(size);
	Vector* right = vectorCreate(size);
	Vector* diff  = vectorCreate(size);
	for (int i = 0; i < size; ++i) {
		left->data[i]  = i + 4;
		right->data[i] = i + 1;
		diff->data[i]  = 3;
	}
	assert(1 == vectorEqual(vectorDiff(left, right), diff));
}

/**
 * secondNorm calculates vector's second norm.
*/
void calculatesSecondNorm() {
	Vector* vec  = vectorCreate(3);
	vec->data[0] = 3;
	vec->data[1] = 4;
	vec->data[2] = 12;
	assert(13 == secondNorm(vec));
}

/**
 * vectorScale scales given vector by some factor.
*/
void scalesGivenVectorBySomeFactor() {
	int size     = 3;
	Vector* vec  = vectorCreate(size);
	vec->data[0] = 1;
	vec->data[1] = 2;
	vec->data[2] = 3;
	Vector* res  = vectorCreate(size);
	res->data[0] = 3;
	res->data[1] = 6;
	res->data[2] = 9;
	assert(1 == vectorEqual(vectorScale(vec, 3), res));
}

/**
 * linspace creates a linearly spaced vector.
*/
void linspaceCreatesLinearlySpacedVector() {
	Vector* vec = vectorCreate(3);
	vec->data[0] = 0;
	vec->data[1] = 0.5;
	vec->data[2] = 1;
	assert(1 == vectorEqual(vec, linspace(0, 1, 3)));
}

/**
 * scalarMultiplication correctly multiplies two vectors.
*/
void scalarMultiplicationCorrectlyMultipliesTwoVectors() {
	int size     = 2;
	Vector* row  = vectorCreate(size);
	row->data[0] = 1;
	row->data[1] = 2;
	Vector* col  = vectorCreate(size);
	col->data[0] = 3;
	col->data[0] = 4;
	assert(1 * 3 + 2 * 4 == scalarMultiplication(row, col));
}

/**
 * vectorEqual returns true for equal vectors.
*/
void vectorEqualReturnsTrueForEqualVectors() {
	int size       = 2;
	Vector* left   = vectorCreate(size);
	left->data[0]  = 2;
	left->data[1]  = 3;
	Vector* right  = vectorCreate(size);
	right->data[0] = 2;
	right->data[1] = 3;
	assert(1 == vectorEqual(left, right));
}

/**
 * vectorEqual returns false for vectors which are not equal.
*/
void vectorEqualReturnsFalseForUnequalVectors() {
	int size       = 2;
	Vector* left   = vectorCreate(size);
	left->data[0]  = 1;
	left->data[1]  = 2;
	Vector* right  = vectorCreate(size);
	right->data[0] = 1;
	right->data[1] = 3;
	assert(0 == vectorEqual(left, right));
}

/**
 * vectorEqual returns true for pointers to the same vector.
*/
void vectorEqualReturnsTrueForPointersToTheSameVector() {
	int size      = 3;
	Vector* left  = vectorCreate(size);
	left->data[0] = 2;
	left->data[1] = 3;
	left->data[2] = 4;
	Vector* right = left;
	assert(1 == vectorEqual(left, right));
}

void vectorAllTests() {
	sumsTwoVectors();
}

/**
 * @todo #12:45min/DEV Tests for Common.c were not written in this PR because
 *  the issue only mentions Vector tests. However, functionality in Common.c
 *  also needs to be covered by tests to ensure correctness.
*/
/**
 * @todo #12:30m/DEV There will probably be other test files, not only Vector
 *  tests. Vector tests have to be reorganized so that all tests can be run
 *  using one command, meaning that all tests are built as a single app.
*/
int main() {
	vectorAllTests();
}