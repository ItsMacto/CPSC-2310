#include <stdio.h>

// A variable declaration like basic data types 
typedef struct Point 
{ 
    int x, y; 
    int *z;
}point_t; 

int main() 
{ 
    point_t p1;
    struct Point p2; 
    struct Point *Ptr = &p2;
    
    p1.x = 0;
    p1.y = 1;
    printf("%d %d\n", p1.x, p1.y);
    p2.x = 2; 
    p2.y = 4;
    printf("%d %d\n", p2.x, p2.y);
    Ptr->y = 5;
    /*Lines 29 and 30 do the same thing. This is saying go to where 
     *Ptr is pointing, which is p2 get the address of p2's x variable and
     *point z to that address. 
     *The -> is dereferencing Ptr, with the -> you do not need to use the "." 
     *when using -> to dereference. However, (*Ptr) is also dereferencing you
     *you still need to use '.' to access a member variable of the struct.*/
    //Ptr->z = &Ptr->x; //is the same as the next line.
    (*Ptr).z = &(*Ptr).x;
    printf("%d %d\n", p2.x, p2.y);
    printf("%d\n", *(*Ptr).z);//same as *(Ptr->z));

    (*Ptr).x = 10; 

    printf("%d %d\n", p2.x, Ptr->y);

    return 0;

}
