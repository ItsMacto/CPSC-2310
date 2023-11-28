#include "ppmUtil.h"

void writeHeader(FILE *image, header_t head)
{
    fprintf(image, "%s\n%u %u\n%u\n", head.type, head.width, head.height
    , head.maxVal);
}
void writePixels(FILE *image, pixel_t *p, header_t head)
{
    fwrite(p, sizeof(pixel_t), head.width * head.height, image);
}

pixel_t *readPixels(FILE *image, header_t head)
{
    pixel_t *pixels = allocatePixMemory(head);
    fread(pixels, sizeof(pixel_t), head.width * head.height, image);
    return pixels;
}

pixel_t *read(FILE *in, header_t *head)
{
    readHeader(in, head);
    return readPixels(in, *head);
}
void write(FILE *image, header_t head, pixel_t *pix)
{
    writeHeader(image, head);
    writePixels(image, pix, head);
}

pixel_t *allocatePixMemory(header_t h)
{
    return malloc(h.width * h.height * sizeof(pixel_t));
}

void ckComment(FILE *in)
{
    char ch;
    do
    {
        ch = getc(in);
        if (ch == '#')
        {
            while (ch != '\n' && ch != EOF)
            {
                ch = getc(in);
            }
        }
    } while (isspace(ch) || ch == '#');
    ungetc(ch, in);
}

void readHeader(FILE *in, header_t *hdr)
{
    fscanf(in, "%2s", hdr->type);
    ckComment(in);
    fscanf(in, "%u", &hdr->width);
    ckComment(in);
    fscanf(in, "%u", &hdr->height);
    ckComment(in);
    fscanf(in, "%u", &hdr->maxVal);
    ckComment(in);
}

void freeMemory(pixel_t *pix)
{
    free(pix);
}

