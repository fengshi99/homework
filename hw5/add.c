#include <stdio.h>
#include <stdlib.h>

int main()
{

	char s[] = "123456";
	printf("&s = %p \n",&s);
	printf("&s[0] = %p \n ",&s[0]);
	printf("s[0] = %p \n",s[0]);
	return 0;
}
