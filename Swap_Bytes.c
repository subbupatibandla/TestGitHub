#include <stdio.h>

union st {
	int i;
	char a[4];
};

int main()
{
	union st obj;
	char b[5];
	
	obj.i = 0x12345678;
	b[0] = obj.a[3];
	b[1] = obj.a[2];
	b[2] = obj.a[1];
	b[3] = obj.a[0];
	b[4] = '\0';
	
	printf("Before %x %x\n",obj.i,obj.a[0]);
	strncpy(obj.a,b,4);
	
	printf("After %x %x\n",obj.i,obj.a[0]);
	
	return 0;
}
