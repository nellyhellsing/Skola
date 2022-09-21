#include <stdio.h>

 assign(int* num, const int size)
{
	 for (int i = 0; i < size; i++)
     {
		num[i] = size - 1 - i;
	 }
	 return 0;
}

print(const int* num, const int size)
{
	printf("Number of elements: 10\n");
	printf("---------------------------------------------------------------\n");
	
	for(int i = 0; i < size; i++)
	{
		printf("%d\n", num[i]);
	}
	printf("---------------------------------------------------------------\n");
}

int main(void)
{
	int num[10];
	assign(num, 10);
	print(num, 10);
	return 0;
}
