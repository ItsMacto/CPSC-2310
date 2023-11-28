/*****************************
 *Mac Howe                   *
 *CPSC2310 002 Fall 2023     *
 *UserName: Pmhowe           *
 *Instructor: Dr.Yvon Feaster*
 *****************************/

#include "shape.h"

shape_t* readInfo(FILE *in, header_t *hdr, int *numShapes)
{
    char shapeType[4];

    fscanf(in, "%s %u %u %u", hdr->type, &hdr->width, &hdr->height,
           &hdr->maxVal);
    fscanf(in, "%d", numShapes);

    shape_t *shapes = (shape_t *)malloc(*numShapes * sizeof(shape_t));

    for (int i = 0; i < *numShapes; i++)
    {
        fscanf(in, "%s", shapeType);
        if (strncmp(shapeType, "Cir", 3) == 0) {
            shapes[i].type = 'C';
            fscanf(in, "%d %d %d", &shapes[i].shape.cir.center.x,
                &shapes[i].shape.cir.center.y, &shapes[i].shape.cir.radius);
            fscanf(in, "%hhu %hhu %hhu", &shapes[i].shape.cir.color.r, 
                &shapes[i].shape.cir.color.g, &shapes[i].shape.cir.color.b);
        }

        else if (strncmp(shapeType, "Tri", 3) == 0) {

            shapes[i].type = 'T';
            fscanf(in, "%d %d", &shapes[i].shape.tri.p1.x, 
                &shapes[i].shape.tri.p1.y);
            fscanf(in, "%d %d", &shapes[i].shape.tri.p2.x, 
                &shapes[i].shape.tri.p2.y);
            fscanf(in, "%d %d", &shapes[i].shape.tri.p3.x,
                &shapes[i].shape.tri.p3.y);
            fscanf(in, "%hhu %hhu %hhu", &shapes[i].shape.tri.color.r, 
                &shapes[i].shape.tri.color.g, &shapes[i].shape.tri.color.b);
        } else if (strncmp(shapeType, "Qua", 3) == 0) {

            shapes[i].type = 'Q';
            fscanf(in, "%d %d", &shapes[i].shape.qua.p1.x, &shapes[i].shape.qua.p1.y);
            fscanf(in, "%d %d", &shapes[i].shape.qua.p2.x, &shapes[i].shape.qua.p2.y);
            fscanf(in, "%d %d", &shapes[i].shape.qua.p3.x, &shapes[i].shape.qua.p3.y);
            fscanf(in, "%d %d", &shapes[i].shape.qua.p4.x, &shapes[i].shape.qua.p4.y);
            fscanf(in, "%hhu %hhu %hhu", &shapes[i].shape.qua.color.r,
                &shapes[i].shape.qua.color.g, &shapes[i].shape.qua.color.b);
        } else {
        fprintf(stderr, "Unknown shape type: %s\n", shapeType);
        free(shapes);
        exit(1);
    }
    }
    if(!feof(in)){
        fscanf(in, "%hhu %hhu %hhu", &hdr->backgroundColor.r,
            &hdr->backgroundColor.g, &hdr->backgroundColor.b);
    }
    else{
        hdr->backgroundColor.r = 255;
        hdr->backgroundColor.g = 255;
        hdr->backgroundColor.b = 255;
    }

    return shapes;
}

int isHitCir(circle_t c, point_t p)
{
    // if it is within the circle
    int dx = p.x - c.center.x;
    int dy = p.y - c.center.y;
    return (dx * dx + dy * dy) <= (c.radius * c.radius);
}

int isHitTri(triangle_t t, point_t p)
{
    double x1 = t.p1.x, y1 = t.p1.y;
    double x2 = t.p2.x, y2 = t.p2.y;
    double x3 = t.p3.x, y3 = t.p3.y;

    double denominator = ((y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3));

    if  (denominator == 0) return 0;

    double a = ((y2 - y3) * (p.x - x3) + (x3 - x2) * (p.y - y3)) /
               denominator ;
    double b = ((y3 - y1) * (p.x - x3) + (x1 - x3) * (p.y - y3)) /
               denominator ;


    return (a >= 0 && a <= 1 && b >= 0 && b <= 1 && (a + b) <= 1);
}

int isHitQua(quadrilateral_t q, point_t p)
{
    triangle_t t1 = {q.p1, q.p2, q.p3, q.color};
    triangle_t t2 = {q.p1, q.p3, q.p4, q.color};

    return isHitTri(t1, p) || isHitTri(t2, p);
}

void drawShape(FILE *out, shape_t *shapes, header_t hdr, int numShapes)
{
    

    
    for (int y = 0; y < hdr.height; y++)
    {
        for (int x = 0; x < hdr.width; x++)
        {
            point_t currentPt = {x, y};
            pixel_t curentPx = hdr.backgroundColor;
            for (int i = 0; i < numShapes; i++){
                switch (shapes[i].type)
                {
                case 'C':
                    if (isHitCir(shapes[i].shape.cir, currentPt )){
                        curentPx = shapes[i].shape.cir.color;
                    }
                    break;
                case 'T':
                    if (isHitTri(shapes[i].shape.tri, currentPt )){
                        curentPx = shapes[i].shape.tri.color;
                    }
                    break;
                case 'Q':
                    if (isHitQua(shapes[i].shape.qua, currentPt )){
                        curentPx = shapes[i].shape.qua.color;
                    }
                    break;
                default:
                    break;
                }
            }
            
            writePixel(out, curentPx);
            
        }
    }
}