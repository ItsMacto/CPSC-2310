/*************************
 *Mac Howe
 *CPSC 2311 002
 *pmhowe@clemnson.edu
 *************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>  
/*
Parameters: in - file pointer to the input file
            out - file pointer to the output file
Return: Void nothing is returned
This function will count the sentences in the file provided then write it to 
the output file
*/
void numSentences(FILE* in, FILE* out);
/*
Parameters: in - file pointer to the input file
            out - file pointer to the output file
Return: Void nothing is returned
This function will count the words in the file provided then write it to 
the output file
*/
void numWords(FILE* in, FILE* out);


#endif // !FUNCTIONS_H
