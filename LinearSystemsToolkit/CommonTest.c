#include <assert.h>
#include "CommonTest.h"
#include "Common.h"

void safeMallocReturnsAllocatedMemoryOfCorrectSize() {
    size_t size = 16;
    assert(size == sizeof(SafeMalloc(size)));
}