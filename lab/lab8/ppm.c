/***************************** 
 *Mac Howe                   * 
 *CPSC2310 002 Fall 2023     * 
 *UserName: Pmhowe           * 
 *Instructor: Dr.Yvon Feaster* 
*****************************/


#include "ppm.h"


void writeHeader(FILE* out, header_t hdr)
{
    fprintf(out, "%s\n%u %u\n%u\n", hdr.type, hdr.width, hdr.height
    , hdr.maxVal);
}

void writePixel(FILE* out, pixel_t color)
{ 
    fwrite(&color.r, sizeof(unsigned char), 1, out);
    fwrite(&color.g, sizeof(unsigned char), 1, out);
    fwrite(&color.b, sizeof(unsigned char), 1, out);
}

// void fillBackground(FILE* out, pixel_t bgColor, int w, int h){
//     for (int y = 0; y < h; y++) {
//         for (int x = 0; x < w; x++) {
//             writePixel(FILE* out, pixel_t bgColor);
//         }
//     }
// }