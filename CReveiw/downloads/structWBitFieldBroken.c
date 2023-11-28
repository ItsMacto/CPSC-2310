#include <stdio.h>
struct date {
	unsigned d : 5;
	unsigned m : 4;
	int y; 
}; 

int main() 
{ 
	struct date dt = { 31, 12, 2020 }; 
	printf("Date is %d/%d/%d\n", dt.d, dt.m, dt.y); 
	return 0; 
}
