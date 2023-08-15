#pragma once

/**
 * @brief Element struct.
 * 
 * It is a matrix element.
*/
typedef struct Element {
	double data;          // value
	int col;              // column
	struct Element* next; // next element
} Element;

/**
 * @brief Sparse matrix.
 * 
 * Sparse matrix is a matrix in which the number of elements is relatively
 * small compared to its overall size.
*/
typedef struct Sparse {
	int n;                 // size
	struct Element** rows; // rows
} Sparse;