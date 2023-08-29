#pragma once

#include "Vector.h"

/**
 * @brief A matrix of regular values.
 * 
 * This struct represents a square matrix.
*/
typedef struct Matrix {
	double** data; // matrix values
	int      n;    // matrix size
} Matrix;

/**
 * @brief Initialize a matrix.
 * 
 * @param n The size of the matrix.
 * 
 * @return A pointer to the matrix.
*/
Matrix* matrixCreate(int n);

/**
 * @brief Free a matrix.
 * 
 * @param A The matrix to free.
*/
void matrixDestroy(Matrix* A);

/**
 * @brief Create an identity matrix.
 * 
 * @param n The size of the matrix.
 * 
 * @return A pointer to the matrix.
*/
Matrix* matrixIdentity(int n);

/**
 * @brief Read a matrix from a file.
 * 
 * @param name The name of the file.
 * @param n    The size of the matrix.
 * 
 * @return A pointer to the matrix.
*/
Matrix* matrixReadFromFile(const char* name, int n);

/**
 * @brief Print a matrix to console.
 * 
 * @param A The matrix to print.
*/
void matrixPrint(Matrix* A);

/**
 * @brief Sums two matrices.
 * 
 * @param left  Left term.
 * @param right Right term.
 * 
 * @return The sum.
*/
Matrix* matrixSum(Matrix* left, Matrix* right);

/**
 * @brief Subtracts two matrices.
 * 
 * @param left  Left term.
 * @param right Right term.
 * 
 * @return The difference.
*/
Matrix* matrixDiff(Matrix* left, Matrix* right);

/**
 * @brief Scales a matrix by some factor.
 * 
 * @param A   The matrix to scale.
 * @param num The factor by which the matrix is scaled.
 * 
 * @return The scaled matrix.
*/
Matrix* matrixScale(Matrix* A, double num);

/**
 * @brief Multiplies a matrix by a vector.
 * 
 * Matrix and vector dimensions must match. The result of such multiplication 
 * is b = A * vec.
 * 
 * @param A   The matrix to multiply.
 * @param vec The vector to multiply.
 * 
 * @return A vector containing the product.
*/
Vector* matrixMultiplyByVector(Matrix* A, Vector* vec);

/**
 * @brief Multiplies two matrices.
 * 
 * @param left  The left term.
 * @param right The right term.
 * 
 * @return The product of the two matrices' multiplication.
*/
Matrix* matrixMultiply(Matrix* left, Matrix* right);

/**
 * @brief Creates a normalized orthogonal matrix.
 * 
 * Orthogonal matrix is calculated according to the formula:
 * Q = I - 2 * w * w' / (w' * w), where
 * I is an identity matrix,
 * w is a given vector seed
 * 
 * @param seed The seed vector.
 * 
 * @return A normalized orthogonal matrix.
*/
Matrix* matrixOrthogonal(Vector* seed);

/**
 * @brief Creates a diagonal matrix from a vector.
 * 
 * @param diag Vector containing the diagonal elements.
 * 
 * @return A diagonal matrix.
*/
Matrix* matrixDiagonal(Vector* diag);