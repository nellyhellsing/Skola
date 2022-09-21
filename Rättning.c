#include <stdio.h>

static inline void assign(int* x, int* y)
{
	*x = 5; 
	*y = 3;
	return;
}

static inline void print(const int x, const int y)
{
	printf("x = %d\n", x);
	printf("y = %d\n", y);
	return;
}

int main(void)
{
	int x = 0, y = 0;
	assign(&x, &y); 
	print(x, y);
	return 0;
}
