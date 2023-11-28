#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main()
{
    FILE* in = fopen("input.txt", "r");
    //add code to check file opened successfully 
    if(in == NULL)
    {
        fprintf(stderr, "The file did not open!! Exiting program!!\n");
        exit(-1);
    }
    //assert(in != NULL);
    //Add file with a number in it. 
    int num;

    fscanf(in, "%d", &num);
    printf("%d\n", num);

    return 0;
}