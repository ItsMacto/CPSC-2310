/*************************
 *Mac Howe
 *CPSC 2311 002
 *pmhowe@clemnson.edu
 *************************/

#include <assert.h>
#include "./src/functions.h"


int main(int argc, char* argv[])
{
    // Open the input file in read mode and 
    // check if the input file was opened successfully
    FILE *inFile = fopen(argv[1], "r");
    assert(inFile != NULL && "Error opening input file");

    // Open the output file in read mode and 
    // check if the output file was opened successfully
	FILE *outFile = fopen(argv[2], "w");
    assert(outFile != NULL && "Error opening output file");

    // Function to count the number of sentences in the input file
    numSentences(inFile, outFile);

    //Function to count the number of words in the input file
    numWords(inFile, outFile);

    // Close the files
    fclose(inFile);
    fclose(outFile);


    return 0;
}
