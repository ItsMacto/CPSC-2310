// C program to demonstrate that size_t or
// any unsigned int type should be used
// carefully when used in a loop.
#include<stdio.h>

#define N 10

int main()
{
	size_t i = 0;
	int a[N];

	for(i = 0; i < N; ++i)
	{
		a[i] = i; 
	}
	
		
	// But reverse cycles are tricky for unsigned
	// types as they can lead to infinite loops.
	// size_t says the value of n will not be negative there for this will 
	// cause an infinate loop. 
	for (i = N-1; i >= 0; --i) /*change to for(i = N-1; i <= N; --i)*/
    {
        printf("%d ", a[i]);
    }
		
}
