#include<stdio.h>
#include<stdlib.h>
#define R 3
#define C 4

int main()
{
	int **arr;
	int count = 0,i,j;
	/*This line allocates the memory for the pointers hint: sizeof(int*)* R*/
	arr = (int **)malloc(sizeof(int *) * R);
	/*This line of code allocates space for all of the data.  Subscript 0 will
	 *point to this block of memory.*/
	arr[0] = (int *)malloc(sizeof(int) * C * R);

	/*This for loop points the remaining pointers to the appropriate place in 
	 *memory. */
	for(i = 1; i < R; i++)
		arr[i] = (arr[i-1] + C);
		//arr[i] = (*arr + (C * i));
	/*This loop initializes the data. */
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count
		}
	}
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			printf("%3d ", arr[i][j]);
		}
		printf("\n");
	}

	free(arr[0]);
	free(arr);

	return 0;
}
