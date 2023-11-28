#ifndef PPMUTIL_H
#define PPMUTIL_H


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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

// Reads the PPM header from the given file.
void readHeader(FILE*, header_t*);

// Reads pixel data from the given file based on header information.
pixel_t* readPixels(FILE*, header_t);

// Writes the PPM header to the given file.
void writeHeader(FILE*, header_t);

// Writes pixel data to the given file.
void writePixels(FILE*, pixel_t*, header_t);

// Facilitates reading both the header and pixel data from a file.
pixel_t* read(FILE*, header_t*);

// Facilitates writing both the header and pixel data to a file.
void write(FILE*, header_t, pixel_t*);

// Allocates memory for the pixel data based on header information.
pixel_t* allocatePixMemory(header_t);

// Frees the allocated memory for the pixel data.
void freeMemory(pixel_t*);

// Skips over comments in the PPM header.
void ckComment(FILE*);


#endif