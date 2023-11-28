#include <stdio.h>
#include <stdlib.h>

int main()
{
	int r = 3, c = 4, i, j, count;

	int **arr = (int **)malloc(r * sizeof(int *));
	for (i=0; i<r; i++)
	{
		arr[i] = (int *)malloc(c * sizeof(int));
	}
	
	// Note that arr[i][j] is same as *(*(arr+i)+j)
	/*FYI:  I find this code very hard to read. While not necessary, I tend
	 *to use {} - since there is only one line of code it is not necessary to use
	 *{ }*/
	count = 0;
	for (i = 0; i < r; i++)
	for (j = 0; j < c; j++)
		arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
	}
/* Code to free the dynamically allocated memory must first free the rows then 
 *the pointer that points to the row. */
	for(i = 0; i < r; i++)
	{
		free(arr[i]);
	}
	free(arr);

return 0;
}
