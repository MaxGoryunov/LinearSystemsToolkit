#include <limits.h>
#include <assert.h>
#include <malloc.h>
#include "CommonTest.h"
#include "Common.h"

int arch() {
    return CHAR_BIT * sizeof(void*);
}

/**
 * safeMalloc can return allocated memory of correct size.
*/
void safeMallocReturnsAllocatedMemoryOfCorrectSize() {
    void* ptr = SafeMalloc(16);
    int expected = (arch() == 64) ? sizeof(double) : sizeof(int);
    assert(expected == sizeof(ptr));
    free(ptr);
}

void commonAllTests() {
    safeMallocReturnsAllocatedMemoryOfCorrectSize();
}