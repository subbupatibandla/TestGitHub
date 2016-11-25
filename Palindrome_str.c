#include <stdio.h>

int checkPalindrome(char *s)
{
	char temp[10];
	int i =0;
	
	int len = strlen(s);
	
	while(i != len)
	{
		temp[i] = s[len-1-i];
		i = i+1;
	}
	temp[len] = '\0';
	
	printf("After Reverse %s\n",temp);
	
	if (!strcmp(temp,s))
		return 1;
	else
		return 0;

}


int main()
{
	char s[10];
	
	printf("Enter string to be validated:\n");
	gets(s);
	
	if (checkPalindrome(s))
		printf("Given string is palindrome\n");
	else
		printf("Given string is not palindrome\n");
		

	getchar();

	return 0;
}
