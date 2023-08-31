#include <assert.h>
#include "CommonTest.h"
#include "Common.h"

/**
 * safeMalloc can return allocated memory of correct size.
*/
void safeMallocReturnsAllocatedMemoryOfCorrectSize() {
    size_t size = 16;
    assert(sizeof(int) == sizeof(SafeMalloc(size)));
}

void commonAllTests() {
    safeMallocReturnsAllocatedMemoryOfCorrectSize();
}