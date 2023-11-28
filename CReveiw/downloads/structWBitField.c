#include <stdio.h> 
#include <stdlib.h>

// Space optimized representation of the date 
typedef struct date { 	
	// d has value between 1 and 31, so 5 bits 
	// are sufficient (5 bit unsigned int = 0 - 31)
	unsigned int d : 5; 
	// m has value between 1 and 12, so 4 bits 
	// are sufficient (4 bit unsigned int = 0 - 15)
	
	//this forces the compiler to store the m in a separate 4 block of memory
	//unsigned int : 0;
	unsigned int m : 4; 
	/*This is the largest data size, 4 bytes, so the memory set aside will be in  
	 *4 byte blocks*/
	unsigned int y; 
}date_t; 

int main() 
{ 
	printf("Size of date is %lu bytes\n", sizeof(struct date)); 
	date_t dt = { 31, 12, 2020}; 
	printf("Date is %d/%d/%d\n", dt.d, dt.m, dt.y); 
	return 0; 
}

/*The size of struct is 8 bytes rather than 12 bytes, saving 4 bytes of memory*/
