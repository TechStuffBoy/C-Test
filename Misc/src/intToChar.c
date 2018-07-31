/*
 * intToChar.c
 *
 *  Created on: 31-Jul-2018
 *      Author: CPSG-WB-4
 */


#include <stdio.h>
#include<string.h>

int main(void)
{
	int i;
	i = 34567;
	char s[11];
	sprintf(s,"%ld", i);
	printf("String = %s\n",s);

	//Add 0x to the HEX number
	char buffer[20];
	snprintf(buffer, sizeof(buffer), "0x%X", i);
	printf("String = %s\n",buffer);
	return 0;
}
