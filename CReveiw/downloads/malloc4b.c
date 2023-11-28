 #include<stdio.h>
#include<stdlib.h>
const int rows = 3;
const int cols = 4;
int main()
{
	int count=1;

	int i = 0,j = 0;
	/*This calculates the amount of memory needed for the Pointers of the 2D 
	 *allocation.*/
    int header = rows * sizeof(int*);
	/*This calculates the amount of memory needed for the data that will be 
	 *stored. */
    int data = rows * cols * sizeof(int);	
	/*dynamically allocate enough memory for both the pointers and the data*/
    int** rowptr = (int**)malloc(header + data);	
	/*Create a pointer that will point to the beginning of where the memory for 
	 *the data will reside. rowptr is pointing to the beginnin of the allocated 
	 *memory. There are 3 pointers so this will be 24 bytes (3*8)from the 
	 *begining of (rowptr) the allocated memory.*/
	int* buffer = (int*)(rowptr + rows);
	printf("Value of Buffer (the address where it points) %p\n", buffer);
	
	/*This loop will point each of the pointers to the place in memory that the
	 *data is stored.  */
	for(i = 0; i < rows; i++)
	{
		rowptr[i] = (buffer + (i * cols));
		printf("%p points to %p\n", &rowptr[i], rowptr[i]);
		//printf("%p\n", rowptr[i]);
			
	}
	//give them value
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			rowptr[i][j] = count++; 
		}
	}
	//print the values 
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%d ", rowptr[i][j]);
		}
		printf("\n");
	}

	
	free(rowptr);

	return 0;
}
