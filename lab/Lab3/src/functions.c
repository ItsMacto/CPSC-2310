/*************************
 *Mac HOwe
 *CPSC 2311 002
 *pmhowe@clemnson.edu
 *************************/

#include "functions.h"
#include <string.h> 


void numSentences(FILE* in, FILE* out)
{
    int count = 0;
    // end of sentence flag for repeated characters 
    int endSentence = 0;
    char c;
    // Loop through the input file by chars until the end of file is reached
    while((c = fgetc(in)) != EOF){
        if (c == '.' || c == '!' || c == '?') {
            if (endSentence != 1){
                // Increment the sentence count
                count++;
            }
            // Set the end of sentence flag
            endSentence = 1;
        }
        else{
            // Reset the end of sentence flag
            endSentence = 0;
        }
    }
    // Print the total number of sentences to the output file
    fprintf(out, "Total number of sentences: %d\n", count);
}

void numWords(FILE* in, FILE* out)
{
    // Move the file pointer to the beginning of the input file
    fseek(in, 0, SEEK_SET);

    int count = 0;
    int endWord = 0;
    char c;
    // Loop through the input file by chars until the end of file is reached
    while ((c = fgetc(in)) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            // If the end of word flag is not set
            if (endWord != 1){
                // Increment the word count
                count++;
            }
            // Set the end of word flag
            endWord = 1;
        }
        else{
            endWord = 0;
            printf("%c",c);
        }
    }
    // Print the total number of words to the output file
    fprintf(out, "Total number of words: %d\n", count);
}