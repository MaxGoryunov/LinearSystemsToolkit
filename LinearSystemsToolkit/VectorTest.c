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

int main() {
	vectorAllTests();
}