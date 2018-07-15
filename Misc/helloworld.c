/*

#include <stdio.h>
#include <conio.h>
#include <string.h>

#define NO_OF_BOTS 2
#define NO_OF_BUTTONS 4
//char processVarBuf[50];
void KK_Input_Event_Counter();
int main() {
	int i=0,j=0;
//	char processVar[] = { "pProcessImageOut_l->CN%d_Uint8_Array_In_Var_%d"};
//	sprintf(processVarBuf, processVar, i+1,j+1);

	KK_Input_Event_Counter();
}


void KK_Input_Event_Counter() {

	int i;
	int j;
	char processVarBuf[50];
	char processVar[] = { "pProcessImageOut_l->CN%d_Uint8_Array_In_Var_%d"};
	char *processVarArray[NO_OF_BOTS][NO_OF_BUTTONS];

	printf("Size of array=%d\n",sizeof(processVarArray));

	for(i=0;i<NO_OF_BOTS;i++) {
		for(j=0;j<NO_OF_BUTTONS;j++) {
			sprintf(processVarBuf, processVar, i+1,j+1);
			printf("%s\n",processVarBuf);
			processVarArray[i][j][0]= &processVarBuf;
			memset(processVarBuf, 0, sizeof processVarBuf);
		}
	}

}
*/
