#include <stdio.h>

int main()
{
    int i = 5;
    int j = 6;
    int k = 7;
    int *intPtr1 = &i;
    int *intPtr2 = &j;
    int **Ptr2Ptr = &intPtr1;

    printf("Address of i: %p\n", &i);
    printf("Address of j: %p\n", &j);
    printf("Address of k: %p\n", &k);
    printf("value of intPtr1: %p\n", intPtr1);
    printf("value of intPtr2: %p\n", intPtr2);
    printf("Address of intPtr1: %p\n", &intPtr1);
    printf("Address of intPtr2: %p\n", &intPtr2);
    printf("Address of Ptr2Ptr: %p\n", &Ptr2Ptr);
    printf("value of Ptr2Ptr: %p\n", Ptr2Ptr);
    printf("Now changing the value of the pointer that Ptr2Ptr is pointing.\n");
    *Ptr2Ptr = intPtr2;
    printf("What is the value of what Ptr2Ptr is pointer at: %p\n",intPtr1 );
    printf("Now changing the value of the pointer that Ptr2Ptr is pointing.\n");
    *Ptr2Ptr = &k;
    printf("What is the value of what Ptr2Ptr is pointer at: %p\n",intPtr1 );

    return 0;
}

/*Address of i: 0x7ff7bcea0298
Address of j: 0x7ff7bcea0294
Address of k: 0x7ff7bcea0290
value of intPtr1: 0x7ff7bcea0298
value of intPtr2: 0x7ff7bcea0294
Address of intPtr1: 0x7ff7bcea0288
Address of intPtr2: 0x7ff7bcea0280
Address of Ptr2Ptr: 0x7ff7bcea0278
value of Ptr2Ptr: 0x7ff7bcea0288
Now changing the value of the pointer that Ptr2Ptr is pointing.
What is the value of what Ptr2Ptr is pointer at: 0x7ff7bcea0294
Now changing the value of the pointer that Ptr2Ptr is pointing.
What is the value of what Ptr2Ptr is pointer at: 0x7ff7bcea0290
*/