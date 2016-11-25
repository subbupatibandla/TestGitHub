#include <stdio.h>

int main()
{
	int x = 0x1234;
	int a;
	
	a = x&0x00FF;
	a = a<<8;
	x = x&0xFF00;
	x = x>>8;
	x = x|a;
	printf("Before Swap Bytes: %x\n",x);
	x = (x<<8) | (x>>8);
	printf("After Swap Bytes: %02x\n",x);
	
	return 0;
}
