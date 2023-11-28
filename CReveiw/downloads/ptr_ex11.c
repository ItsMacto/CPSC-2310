
#include<stdio.h>
void f(int *paa, int *pbb)
{
  printf("inside f ; p is pointing to this address %p\n", paa);
  printf("inside f ; q is pointing to this address %p\n", pbb);
  paa = pbb; 
  printf("inside f and after p = q ; p is pointing to this address %p\n", p);
  *p = 2;
}

int main()
{
  int a = 0, b = 1;
  int *pa = &a;
  int *pb = &b;
  printf("Before calling f - pa is pointing to this address %p\n", pa);
  
  f(pa, pb);
  printf("After calling f - pa is pointing to this address %p\n", pa);
  printf("%d %d and %d %d\n", a, b, *pa, *pb);

  
  return 0;
}

/*What is the output of the above?





*/
