/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "ppm.h"


typedef struct Point
{
    int x, y;
} point_t;

typedef struct Circle
{
    point_t center;
    int radius;
    pixel_t color;
} circle_t;

typedef struct Triangle{
    point_t p1, p2, p3;
    pixel_t color;
} triangle_t;

typedef struct Quadrilateral{
    point_t p1, p2, p3, p4;
    pixel_t color;
} quadrilateral_t;


typedef struct Shape {
    union {
        circle_t cir;
        triangle_t tri;
        quadrilateral_t qua;
    } shape;
    char type; 
} shape_t;


// Read in the information from the input file that describes the shape 
shape_t* readInfo(FILE *in, header_t *hdr, int *numShapes);

// Functions to check if a point is inside the given shape
int isHitCir(circle_t c, point_t p);
int isHitTri(triangle_t t, point_t p);
int isHitQua(quadrilateral_t q, point_t p);


// General function to draw any shape
void drawShape(FILE *out, shape_t *shapes, header_t hdr, int numShapes);

#endif