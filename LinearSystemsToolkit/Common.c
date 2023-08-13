#include <malloc.h>
#include <stdlib.h>
#include "Common.h"

void* notNull(void* ptr, int line) {
	if (ptr == NULL) {
		printf("Null pointer at %i\n", line);
		exit(1);
	}
	return ptr;
}

void* safeMalloc(size_t size, int line) {
	return notNull(malloc(size), line);
}