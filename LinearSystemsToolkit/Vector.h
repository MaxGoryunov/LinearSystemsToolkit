#pragma once

/**
* @brief vector struct
* 
* It is used as a representation of a mathematics vector.
*/
typedef struct Vector {
	double* data; // vector values
	int n; // vector dimension
} Vector;

/**
* @brief create a new vector
* 
* @param n vector dimension
* 
* @return created vector
*/
Vector* vectorCreate(int n);

/**
* @brief sum of two vectors
* 
* @param left left vector sum operand
* @param right right vector sum operand
* 
* @return sum of two vectors
*/
Vector* vectorSum(Vector* left, Vector* right);

/**
* @brief vector difference
* 
* @param left left term
* @param right right term
* 
* @return vector difference
*/
Vector* vectorDiff(Vector* left, Vector* right);

/**
* @brief second vector norm
* 
* @param v vector for which the second norm is calculated
* 
* @return second norm of specified vector
*/
double secondNorm(Vector* v);

/**
* @brief vector and number multiplication
* 
* @param v vector
* @param num number by which the vector is multiplied
* 
* @return scaled vector
*/
Vector* vectorScale(Vector* v, double num);

/**
* @brief linearly spaced vector
* 
* @param start first vector value
* @param end last vector value
* @param n vector dimension
* 
* @return created linearly spaced vector
*/
Vector* linspace(double start, double end, int n);

/**
* @brief scalar multiplication of two vectors
* 
* @param row row vector or v1^T
* @param col second vector
* 
* @return scalar multiplication
*/
double scalarMultiplication(Vector* row, Vector* col);