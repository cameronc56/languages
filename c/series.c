#include <stdio.h>

int main(void) {
	float v1, r1, r2, i, v2;
	printf("Enter Voltage v1: ");
	scanf("%f", &v1);
	printf("Enter Resistance r1: ");
	scanf("%f", &r1);
	printf("Enter Resistance r2: ");
  	scanf("%f", &r2);

	i = v1 / (r1 + r2);
	v2 = i * r2;

	printf("Current: %f\nv2: %f\n", i, v2);
	return 0;
}
