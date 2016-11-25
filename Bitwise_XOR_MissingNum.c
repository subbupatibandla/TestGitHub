#include <stdio.h>

int main()
{
	int a = 10, b = 8;
	
	printf("Before Swap : a %d  b %d\n",a,b);
	
	a = a^b;
	b = a^b;
	a = a^b;
	
	printf("After Swap : a %d  b %d\n",a,b);

	return 0;
}
