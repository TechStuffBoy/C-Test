#include <stdio.h>

int s;
char ch;
float f;
int main(void)
{
	ch= -100;
	s = ch;
	f=s;
	printf("Value of f=%f\n",f);
	f = *(float *)&s;
	printf("Hello,world\n");
	printf("Value of c=%d\n",ch);
	printf("Value of f=%f\n",f);
	return 0;
}
