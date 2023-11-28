/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#include "functions.h"

int main(int argc, char * argv[])
{ 
    // Checking for the correct number of command line arguments
    assert(argc == 3); 

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");
    assert(inputFile && outputFile); 

    node_t *head = NULL;

    createList(inputFile, &head);
    printList(outputFile, head);
    deleteList(&head);

    fclose(inputFile);
    fclose(outputFile);


    return 0;
}
