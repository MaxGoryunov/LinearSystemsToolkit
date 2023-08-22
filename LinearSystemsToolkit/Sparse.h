#pragma once

#include "Vector.h"

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

/**
 * @brief Creates a sparse matrix.
 * 
 * @param n matrix size
 * 
 * @return created sparse matrix
*/
Sparse* sparseCreate(int n);

/**
 * @brief Removes given sparse matrix from memory.
 * 
 * @param sparse matrix to be removed
*/
void sparseDestroy(Sparse* A);

/**
 * @brief Creates an identity matrix.
 * 
 * Identity matrix is a matrix with 1s(ones) on its primary diagonal and
 * zeroes in all remaining positions.
 * 
 * @param n matrix size
 * 
 * @return created identity matrix
*/
Sparse* sparseIdentity(int n);

/**
 * @brief Reads sparse matrix from file.
 * 
 * All elements must be present in a file. Only non-zero elements will be
 * stored in memory, maintaining a sparse structure.
 * 
 * @param name file name
 * @param n    matrix size
 * 
 * @return created matrix
*/
Sparse* sparseFromFile(char* name, int n);

/**
 * @todo #13:30m/DEV Now there is only one way of reading matrix from a file.
 * It must also be possible to specify matrix size in the file from which it
 * is being read.
*/
/**
 * @todo #13:60m/DEV When reading a matrix from file even zero elements must
 * be specified. It must be possible to create a sparse matrix only from non-
 * zero elements specified in a file.
*/

/**
 * @brief Prints a sparse matrix to console.
 * 
 * @param A sparse matrix to be printed
*/
void sparsePrint(Sparse* A);

/**
 * @brief Adds two matrices together.
 * 
 * @param left  left term
 * @param right right term
 * 
 * @return matrix sum
*/
Sparse* sparseSum(Sparse* left, Sparse* right);

/**
 * @brief Subtracts one sparse matrix from another.
 * 
 * @param left  left term
 * @param right right term
 * 
 * @return matrix difference
*/
Sparse* sparseDiff(Sparse* left, Sparse* right);

/**
 * @brief Scales a sparse matrix by a given factor.
 * 
 * @param A   sparse matrix
 * @param num factor for scaling
 * 
 * @return sparse matrix multiplied by a number
*/
Sparse* sparseScale(Sparse* A, double num);

/**
 * @brief Multiplies a sparse matrix by a given vector.
 * 
 * @param A sparse matrix
 * @param b some vector
 * 
 * @return vector as a result of a matrix multiplied by vector
*/
Vector* sparseMultiplyByVector(Sparse* A, Vector* b);

/**
 * @brief Multiplies two sparse matrices.
 * 
 * @param left  left term of matrix multiplication
 * @param right right term of matrix multiplication
 * 
 * @return a matrix C which is equal to left * right
*/
Sparse* sparseMultiply(Sparse* left, Sparse* right);

/**
 * @brief Creates a normalized orthogonal matrix from a given vector seed.
 * 
 * Orthogonal matrix is calculated according to the formula:
 * Q = I - 2 * w * w' / (w' * w), where
 * I is an identity matrix,
 * w is a given seed - vertical vector
 * 
 * @param seed vector seed
 * 
 * @return a normalized orthogonal matrix
*/
Sparse* sparseOrthogonalFromSeed(Vector* seed);

/**
 * @brief Creates a diagonal sparse matrix from a vector of given values.
 * 
 * Created matrix's dimension is equal to that of given vector, all elements
 * except those on the primary diagonal. Elements on the primary diagonal are
 * equal to vector elements and appear in the same order.
 * 
 * @param diag vector with values to be put into matrix's primary diagonal
 * 
 * @return a diagonal matrix
*/
Sparse* sparseDiagonalFromVector(Vector* diag);