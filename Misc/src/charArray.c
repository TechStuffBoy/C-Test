//
//#include <stdio.h>
//#include <conio.h>
//#include<string.h>
//
//#define NO_OF_BOTS 2
//#define NO_OF_BUTTONS 4
//#define	PIFACE	NO_OF_BUTTONS+200
//
//char* processVarArray[NO_OF_BOTS][NO_OF_BUTTONS];
//int main(void)
//{
//	int i;
//	int j;
//	int a = 5;
//	int b = 0;
//	char processVarBuf[50];
//	char processVar[] = { "pProcessImageOut_l->CN%d_Uint8_Array_In_Var_%d"};
//	char array[50];
//
//	printf("PIFACE=%d\n",PIFACE);
//
//	for(i=0;i<NO_OF_BOTS;i++) {
//		for(j=0;j<NO_OF_BUTTONS;j++) {
//			sprintf(processVarBuf, processVar, i+1,j+1);
//			//printf("%s\n",processVarBuf);
//			processVarArray[i][j]= processVarBuf;
//			strcpy(array,processVarArray[0][0]);
////			printf("Val in processVarArray[%d][%d]=%s\n",i,j,processVarArray[i][j]);
//			if(strcmp(processVarBuf,processVarArray[i][j])) {
////				printf("True\n");
//			} else
////				printf("false\n");
//			memset(processVarBuf, 0, sizeof processVarBuf);
//		}
//	}
//
//	if( (a-5) && b)
//		printf("Condition Satisfied\n");
//	else
//		printf("Condition Not Satisfied\n");
//
//	return 0;
//}
//
//
//
//
//
