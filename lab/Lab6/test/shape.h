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

// read in the information from the input file that describes the circle 
void readInfo(FILE*, header_t*, circle_t*);

// will return true if the point is within the circle 
int isHitCir(circle_t, point_t);

// will loop through the image and change the pixels to the background or the 
// circle color  
void makeCircle(FILE* out, circle_t* cir, int w, int h);

#endif