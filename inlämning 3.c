#include <stdio.h>

int main(void)
{
	int num1 = -3;
	int* ptr1 = &num1;

	*ptr1 = 4;
	printf("num1 = %d\n", num1);

	return 0;
}
