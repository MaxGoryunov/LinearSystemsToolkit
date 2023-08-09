#include <assert.h>
#include "Vector.h"

/**
* vectorSum can produce a sum of two vectors.
*/
void sumsTwoVectors() {
	int size = 3;
	Vector* left = vectorCreate(size);
	Vector* right = vectorCreate(size);
	Vector* sum = vectorCreate(size);
	for (int i = 0; i < size; ++i) {
		left->data[i] = i;
		right->data[i] = i * 2;
		sum->data[i] = i * 3;
	}
	assert(1 == vectorEqual(vectorSum(left, right), sum));
}

void vectorAllTests() {
	sumsTwoVectors();
}

/**
* @todo #1:45m/DEV The issue does not specify the required code coverage for
*  this feature, this is why I decided that it is enough to just create
*  functions listed in the issue. It is important to add some tests to check
*  that the remaining functions also work as intended.
*/

int main() {
	vectorAllTests();
}