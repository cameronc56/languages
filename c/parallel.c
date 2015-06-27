#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float r1, r2, r3;

	printf("Enter the resistor values r1 and r2: ");
	
	if(scanf("%f %f", &r1, &r2) != 2) {
		printf("Data entered incorrectly.\n");
		exit(0);
	} else {
		if(r1 != 0) {
			if(r2 != 0) {
				r3 = (r1 * r2) / (r1 + r2);
				printf("Total resistance = %f ohms\n", r3);
			} else {
				printf("r2 is a short circuit.\n");
			}
		} else {
			printf("r1 is a short circuit.\n");
		}
	}
	return 0;
}
