//#include "app.h"
//
//#include <oplk/oplk.h>
//#include <oplk/debugstr.h>
//#include <eventlog/eventlog.h>
//
//#include <stddef.h>
//#include <stdio.h>
//#include <wiringPi.h>
//#include <stdlib.h>
//#include <stdint.h>
//
//
//#define OK_INPUT 23
//#define REJECT_INPUT 24
//#define SINGER_INPUT 25
//#define POWERTABLE_INPUT 26
//
//#define OK_OUTPUT 21
//#define REJECT_OUTPUT 4
//#define SINGER_OUTPUT 15
//#define POWERTABLE_OUTPUT 16
//
//#define false 0
//#define true 1
//
//
//
//typedef struct
//{
//	UINT8		digitalIn[4];
//} PI_IN;
//
//typedef struct
//{
//	UINT8    digitalOut[4];
//} PI_OUT;
//
////KK Pin Definitions
//UINT8 Input_Pins[4] = {OK_INPUT,REJECT_INPUT,SINGER_INPUT,POWERTABLE_INPUT};
//UINT8 Output_Pins[4] = {OK_OUTPUT,REJECT_OUTPUT,SINGER_OUTPUT,POWERTABLE_OUTPUT};
//
////------------------------------------------------------------------------------
//// local vars
////------------------------------------------------------------------------------
///* process image */
//static PI_IN*           pProcessImageIn_l;
//static const PI_OUT*    pProcessImageOut_l;
//
///* application variables */
//static UINT8            digitalIn_l;            // 8 bit digital input
//static UINT8            digitalOut_l;           // 8 bit digital output
//
//
////------------------------------------------------------------------------------
//// local function prototypes
////------------------------------------------------------------------------------
//static tOplkError   initProcessImage(void);
//
//
//
//
//tOplkError initApp(void)
//{
//	tOplkError  ret;
//	int i;
//	ret = initProcessImage();
//	wiringPiSetup ();
//	//KK INPUT Pin Configuration
//	for(i=0;i<4;i++) {
//		pinMode (Input_Pins[i], INPUT);
//	}
//
//	for(i=0;i<4;i++) {
//		pinMode (Output_Pins[i], OUTPUT);
//	}
//
//	//ByDefault all Outputs should be off
//	for(i=0;i<4;i++) {
//		digitalWrite(Output_Pins[i], true);
//	}
//
//	return ret;
//}
//
//
//void shutdownApp(void)
//{
//	oplk_freeProcessImage();
//}
//
//
//tOplkError processSync(void)
//{
//	tOplkError  ret = kErrorOk;
//	int i;
//	int j;
//
//	if (oplk_waitSyncEvent(100000) != kErrorOk)
//		return ret;
//
//	ret = oplk_exchangeProcessImageOut();
//	if (ret != kErrorOk)
//		return ret;
//
//
//	//Handling Inputs
//	for(i=0;i<4;i++) {
//		if( digitalRead(Input_Pins[i] == 0) {
//			pProcessImageIn_l->digitalIn[i] = 1;
//			printf("Transmitted Input_Pins[%d] Val=%d to Master\n",i,pProcessImageIn_l->digitalIn[i]);
//		} else {
//			pProcessImageIn_l->digitalIn[i] = 0;
//			printf("Transmitted Input_Pins[%d] Val=%d to Master\n",i,pProcessImageIn_l->digitalIn[i]);
//		}
//	}
//
//	ret = oplk_exchangeProcessImageIn();
//	return ret;
//}
//
//void setupInputs(void)
//{
//	digitalIn_l = 1;
//}
//
//
//void increaseInputs(void)
//{
//	if (digitalIn_l == 128)
//		digitalIn_l = 1;
//	else
//		digitalIn_l = digitalIn_l << 1;
//
//	printf("\b \b");
//	printInputs();
//}
//
//
//void decreaseInputs(void)
//{
//	if (digitalIn_l == 1)
//		digitalIn_l = 128;
//	else
//		digitalIn_l = digitalIn_l >> 1;
//
//	printf("\b \b");
//	printInputs();
//}
//
//
//void printOutputs(void)
//{
//	int i;
//
//	printf("\b \b");
//	printf("Digital outputs: ");
//	for (i = 0; i < 8; i++)
//	{
//		if (((digitalOut_l >> i) & 1) == 1)
//			printf("*");
//		else
//			printf("-");
//	}
//	printf("\n");
//}
//
//
//void printInputs(void)
//{
//	int i;
//
//	printf("Digital inputs: ");
//	for (i = 0; i < 8; i++)
//	{
//		if (((digitalIn_l >> i) & 1) == 1)
//			printf("*");
//		else
//			printf("-");
//	}
//	printf("\n");
//}
//
//
//static tOplkError initProcessImage(void)
//{
//	tOplkError  ret = kErrorOk;
//	UINT        varEntries;
//	tObdSize    obdSize;
//
//	/* Allocate process image */
//	printf("Initializing process image...\n");
//	printf("Size of process image: Input = %lu Output = %lu \n",
//			(ULONG)sizeof(PI_IN),
//			(ULONG)sizeof(PI_OUT));
//	eventlog_printMessage(kEventlogLevelInfo,
//			kEventlogCategoryGeneric,
//			"Allocating process image: Input:%lu Output:%lu",
//			(ULONG)sizeof(PI_IN),
//			(ULONG)sizeof(PI_OUT));
//
//	ret = oplk_allocProcessImage(sizeof(PI_IN), sizeof(PI_OUT));
//	if (ret != kErrorOk)
//		return ret;
//
//	pProcessImageIn_l = (PI_IN*)oplk_getProcessImageIn();
//	pProcessImageOut_l = (const PI_OUT*)oplk_getProcessImageOut();
//
//	/* link process variables used by CN to object dictionary */
//	fprintf(stderr, "Linking process image vars:\n");
//
//
//	obdSize = sizeof(pProcessImageIn_l->digitalIn[0]);
//	varEntries = 4;
//	ret = oplk_linkProcessImageObject(0x2200,
//			0x01,
//			offsetof(PI_IN, digitalIn),
//			FALSE,
//			obdSize,
//			&varEntries);
//	//ret = oplk_linkProcessImageObject(0x2000, 0x01, offsetof(PI_IN, aAnalogInput), FALSE, obdSize, &varEntries);
//
//	if (ret != kErrorOk)
//	{
//		fprintf(stderr,
//				"Linking process vars failed with \"%s\" (0x%04x)\n",
//				debugstr_getRetValStr(ret),
//				ret);
//		return ret;
//	}
//
//	obdSize = sizeof(pProcessImageOut_l->digitalOut[0]);
//	varEntries = 4;
//	ret = oplk_linkProcessImageObject(0x3200,
//			0x01,
//			offsetof(PI_OUT, digitalOut),
//			TRUE,
//			obdSize,
//			&varEntries);
//	//ret = oplk_linkProcessImageObject(0x3000, 0x01, offsetof(PI_OUT, aAnalogOutput), TRUE, obdSize, &varEntries);
//	if (ret != kErrorOk)
//	{
//		fprintf(stderr,
//				"Linking process vars failed with \"%s\" (0x%04x)\n",
//				debugstr_getRetValStr(ret),
//				ret);
//		return ret;
//	}
//
//	fprintf(stderr, "Linking process vars... ok\n\n");
//
//	return kErrorOk;
//}
//
//
