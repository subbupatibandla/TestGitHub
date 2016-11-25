#include <stdio.h>
int main()
{
    unsigned char arr[2] = {0x00, 0x01};
    unsigned short int x = *(unsigned short int *) arr;
    printf("%d", x);
    getchar();
    return 0;
}
