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
    int numShapes;


    shape_t *shapes = readInfo(inFile, &hdr, &numShapes);

    writeHeader(outFile, hdr);
    

    drawShape(outFile, shapes, hdr, numShapes);

    free(shapes);

    fclose(inFile);
    fclose(outFile);

    return 0;
}
