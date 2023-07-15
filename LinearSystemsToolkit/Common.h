#pragma once

#include <stdio.h>

#define SafeMalloc(size) safeMalloc(size, __LINE__)

/**
* @brief a non-null pointer.
* 
* Checks if the passed pointer is NULL. If it is, reports a null-pointer at a
* specified line, otherwise returns the pointer.
* 
* @param ptr pointer to check
* @param line line for reporting
* 
* @return checked pointer
*/
void* notNull(void* ptr, int line);

/**
* @brief performs safe malloc operation
* 
* Performs malloc of specified size of memory and returns its pointer if malloc
* was successful.
* 
* @param size size of memory for allocation
* @param line line for reporting if malloc failed
* 
* @return created pointer
*/
void* safeMalloc(size_t size, int line);