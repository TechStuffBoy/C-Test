
#include <stdio.h>
#include <conio.h>
#include<string.h>

#define NO_OF_BOTS 2
#define NO_OF_BUTTONS 4
#define	PIFACE	NO_OF_BUTTONS+200

char* processVarArray[NO_OF_BOTS][NO_OF_BUTTONS];
int main(void)
{
	int i;
	int j;
	char processVarBuf[50];
	char processVar[] = { "pProcessImageOut_l->CN%d_Uint8_Array_In_Var_%d"};

	printf("PIFACE=%d\n",PIFACE);

	for(i=0;i<NO_OF_BOTS;i++) {
		for(j=0;j<NO_OF_BUTTONS;j++) {
			sprintf(processVarBuf, processVar, i+1,j+1);
			//printf("%s\n",processVarBuf);
			processVarArray[i][j]= processVarBuf;
			printf("Val in processVarArray[%d][%d]=%s\n",i,j,processVarArray[i][j]);
			memset(processVarBuf, 0, sizeof processVarBuf);
		}
	}

	return 0;
}





