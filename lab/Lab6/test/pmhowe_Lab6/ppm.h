/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#ifndef PPM_H
#define PPM_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Pixel
{
    unsigned char r, g, b;
}pixel_t;

typedef struct Header
{
    char type[3];
    unsigned int width;
    unsigned int height;
    unsigned int maxVal;
}header_t;


// writes the header information to the output file
void writeHeader(FILE* out, header_t hdr);


// writes pixel information to the output file 
void writePixel(FILE* out,  pixel_t color);

#endif // !PPM_H
