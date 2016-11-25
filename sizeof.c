#include <stdio.h>

struct std {
	int data;
	float item;
};

int main()
{
	void *p;
	struct std obj;
	
	p = &obj;
	
	printf("Adress %u %u\n",p,&obj+1);
	
	printf("actual size %d size of structure is %d\n",sizeof(obj),((char*)(&obj + 1)-(char*)&obj));
	printf("size of type is %d\n",((int*)0+1));
	
	return 1;	
}
