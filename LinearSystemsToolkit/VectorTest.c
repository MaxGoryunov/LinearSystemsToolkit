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
	Vector* vec = vectorCreate(3);
	vec->data[0] = 3;
	vec->data[1] = 4;
	vec->data[2] = 12;
	assert(13 == secondNorm(vec));
}

/**
 * vectorScale scales given vector by some factor.
*/


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