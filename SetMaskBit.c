#include <stdio.h>

//Take 19 bit and set 5 bit with opposite value if it is 1 -> 0 or 0->1
int main()
{
	int i = 12;
	int readbit = 19;
	int setbit = 5;
	int rdval = 0;
	
	rdval = i&(1<(readbit-1));
	printf("Readbit is %d\n",rdval);
	
	i = i | ((1<<4) & ~rdval);
	printf("After set bit i: %d",i);	
	
	return 0;
}
