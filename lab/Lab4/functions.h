/***************************** 
 *Mac Howe                   * 
 *CPSC2310 Fall 2023         * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

// Parameters: fp - File pointer from which the matrix should be read.
//             size - Pointer to an integer where the size of the matrix will 
//                    be stored.
//Return:A pointer to the matrix read from the file.
//This function reads a matrix from the given file and returns it.
int** readFile(FILE* fp, int *size);

// Parameters: mat - The matrix to be printed.
//             num - Size of the matrix.

// This function prints the given matrix.
void printMatrix (int** mat, int num);

// Parameters: mat - The matrix whose values are to be summed.
//             size - Size of the matrix.
// Return:     The calculated sum.
// This function calculates the sum of all values in the matrix except those 
// on the left and right diagonals.
int calculateVal(int** mat, int size);

// Parameters: size - Size of the matrix.
//             row - Row index of the element.
//             col - Column index of the element.
//  Return:    True if the element is on the right diagonal, False otherwise.
// This function checks if a given element is part of the right diagonal of a 
// matrix.
bool isRightDiagonal(int size, int row, int col);

// Parameters: row - Row index of the element.
//             col - Column index of the element.
// Return:     True if the element is on the left diagonal, False otherwise.
// This function checks if a given element is part of the left diagonal of a
//  matrix.
bool isLeftDiagonal(int row, int col);

#endif // !FUNCTIONS_H
