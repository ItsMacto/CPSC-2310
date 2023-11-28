/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#include "shape.h"


void readInfo(FILE* in, header_t* hdr, circle_t* cir)
{
    fscanf(in, "%s %u %u %u", hdr->type, &hdr->width, &hdr->height,
     &hdr->maxVal);
    fscanf(in, "%d %d %d", &cir->center.x, &cir->center.y, &cir->radius);
    fscanf(in, "%hhu %hhu %hhu", &cir->color.r, &cir->color.g, &cir->color.b);
}

void makeCircle (FILE* out, circle_t* cir, int w, int h)
{
    // set background to white
    pixel_t backgroundC = {255, 255, 255}; 


    // each pixel in the image 
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            point_t currentPt = {x, y};
            if (isHitCir(*cir, currentPt))
                writePixel(out, cir->color);
            else
                writePixel(out, backgroundC);
        }
    }
}


int isHitCir(circle_t c, point_t p)
{
    // if it is within the circle 
    int dx = p.x - c.center.x;
    int dy = p.y - c.center.y;
    return (dx * dx + dy * dy) <= (c.radius * c.radius);
}
