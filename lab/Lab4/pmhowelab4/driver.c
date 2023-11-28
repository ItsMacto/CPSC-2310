/***************************** 
 *Mac Howe                   * 
 *CPSC2310 Fall 2023         * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#include "functions.h"


int main(int argc, char** argv)
{
    printf("cheking command line arguments\n");

    if (argc < 2)
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did not open\n"); 
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);

    int total = calculateVal(mat, size);
    printf("Total = %d\n", total);

    return 0;
}
