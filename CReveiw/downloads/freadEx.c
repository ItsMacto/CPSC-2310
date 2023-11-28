#include <stdio.h>
#include <stdlib.h>
 
//Maximum size of the array
#define MAX_SIZE  32
 
int main()
{
    //file pointer
    FILE *fp = NULL;
    char readFileData[MAX_SIZE] = {0};
 
    //open the file
    fp = fopen("test.txt", "r");
    if(fp == NULL)
    {
        printf("Error in opening the file\n");
        exit(1);
    }
 
    // This only reads 5 out of the 9 characters from file Why???
    fread(readFileData,sizeof(char),9, fp);
 
    //Display read data to stdout (standard out)
    //prototype for puts: int puts(const char *str);
    //There is also a fputs - fputs(const *char, FILE*)
    puts(readFileData);
    puts("Now is the time for all good men come to the aid of their country.");

    //close the file
    fclose(fp);
 
    printf("Read file successfully\n");
 
    return 0;
}