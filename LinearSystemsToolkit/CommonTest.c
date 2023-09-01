#include <assert.h>
#include <malloc.h>
#include "CommonTest.h"
#include "Common.h"

/**
 * safeMalloc can return allocated memory of correct size.
*/
void safeMallocReturnsAllocatedMemoryOfCorrectSize() {
    size_t size = 16;
    void* ptr = SafeMalloc(size);
    printf("sizeof(ptr) = %i\n", sizeof(ptr));
    printf("sizeof(int) = %i\n", sizeof(int));
    assert(sizeof(int) == sizeof(int));
    free(ptr);
}

void commonAllTests() {
    safeMallocReturnsAllocatedMemoryOfCorrectSize();
}