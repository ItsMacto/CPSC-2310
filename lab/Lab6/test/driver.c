/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ppm.h"
#include "shape.h"

int main(int argc, char* argv[])
{
    FILE *inFile = fopen(argv[1], "r");
    assert(inFile != NULL);
    FILE *outFile = fopen(argv[2], "wb");
    assert(outFile != NULL);


    header_t hdr;
    circle_t cir;

    readInfo(inFile, &hdr, &cir);

    writeHeader(outFile, hdr);


    makeCircle(outFile, &cir, hdr.width, hdr.height);


    fclose(inFile);
    fclose(outFile);

    return 0;
}
