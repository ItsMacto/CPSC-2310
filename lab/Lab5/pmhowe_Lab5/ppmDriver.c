#include "ppmUtil.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input ppm file> <output ppm file>\n"
        , argv[0]);
        return 1;
    }

    FILE *inFp = fopen(argv[1], "rb");
    FILE *outFp = fopen(argv[2], "wb");

    if (!inFp || !outFp)
    {
        perror("Error opening file");
        return 1;
    }

    header_t header;
    pixel_t *pixels = read(inFp, &header);

    write(outFp, header, pixels);

    freeMemory(pixels);
    fclose(inFp);
    fclose(outFp);

    return 0;
}
