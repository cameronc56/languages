#include <stdio.h>

int main(void) {
	//char arr[] = "Hello World";
	//printf("%s\n", arr);
	//printf("%p\n", &arr);

	int i = 5;  //32 bits in stack memory allocated
				//identifier i created and assigned to memory address of 5
				
	int j = i;  //32 bits (4 bytes) in stack memory allocated
				//identifier i created and assigned to memory address of value of i

	printf("%d\n", i);
	printf("%p\n", &i);
	
	printf("%d\n", j);
	printf("%p\n", &j);
	
	return 0;
}
