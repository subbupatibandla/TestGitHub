#include<stdio.h>

int* inc(int val)
{
  int a = val;
  a++;
  return &a;
}

int* dec(int val)
{
  int a = val;
  a = 25;
  printf("Adress in dec: %u",&a);
  return &a;
}


int main(void)
{
    int a = 10;
	printf("Address of a is %u\n",&a);
    int *val = inc(a);
    printf("Address Returned : %u\n",val);
    dec(a);

    printf("\n Incremented value is equal to [%d] \n", *val);

    return 0;
}
