#include <stdio.h>
#include<Stdint.h>
#include<stdbool.h>


typedef struct  {
	bool val;
	uint8_t mask;
	uint16_t curCount;
	uint16_t prevCount;
} buttonParser_8;


typedef struct  {
	bool val;
	uint16_t mask;
	uint16_t curCount;
	uint16_t prevCount;
} buttonParser_16;

void init_8();
void init_16();
void checkButton_8(uint8_t buttonVal);
void checkButton_16(uint16_t buttonVal);


buttonParser_8 button8[8] = {
		{0,0b00000001, 0, 0},
		{0,0b00000010, 0, 0},
		{0,0b00000100, 0, 0},
		{0,0b00001000, 0, 0},
		{0,0b00010000, 0, 0},
		{0,0b00100000, 0, 0},
		{0,0b01000000, 0, 0},
		{0,0b10000000, 0, 0}
};

buttonParser_16 button16[16] = {
		{0,0b0000000000000001, 0, 0},
		{0,0b0000000000000010, 0, 0},
		{0,0b0000000000000100, 0, 0},
		{0,0b0000000000001000, 0, 0},
		{0,0b0000000000010000, 0, 0},
		{0,0b0000000000100000, 0, 0},
		{0,0b0000000001000000, 0, 0},
		{0,0b0000000010000000, 0, 0},
		{0,0b0000000100000000, 0, 0},
		{0,0b0000001000000000, 0, 0},
		{0,0b0000010000000000, 0, 0},
		{0,0b0000100000000000, 0, 0},
		{0,0b0001000000000000, 0, 0},
		{0,0b0010000000000000, 0, 0},
		{0,0b0100000000000000, 0, 0},
		{0,0b1000000000000000, 0, 0}
};

uint16_t Reg ;
int main(void)
{

	Reg = 0;
	setbuf(stdout, NULL);

	init_8();
	init_16();
	while(1) {
		printf("Simulate button press by pressing the button :");
		scanf("%u", &Reg);
		printf("\nValue entered=%d\n",(uint8_t)Reg);
		checkButton_8((uint8_t)Reg);
		printf("checking uint16..\n");
		checkButton_16(Reg);
	}
	return 0;
}


void init_8()
{
	int i;
	for(i=0; i< sizeof(button8)/sizeof(buttonParser_8); i++) {
		button8[i].prevCount = button8[i].curCount;
	}
	printf("Structure button8 is initialized..\n");


}

void init_16()
{
	int i;
	for(i=0; i< sizeof(button16)/sizeof(buttonParser_16); i++) {
		button16[i].prevCount = button16[i].curCount;
	}
	printf("Structure button16 is initialized..\n");
}


void checkButton_8(uint8_t buttonVal)
{
	int i;
	for(i=0; i< sizeof(button8)/sizeof(buttonParser_8); i++) {
		button8[i].val = (uint8_t)buttonVal & button8[i].mask;
		if(button8[i].val) {
			button8[i].curCount++;
			button8[i].val = 0;
		}

		if(button8[i].curCount > button8[i].prevCount) {
			printf("Button[%d] Pressed, prevCount=%d, curCount=%d\n",i,
					button8[i].prevCount, button8[i].curCount);
			button8[i].prevCount = button8[i].curCount;
		}
	}

}


void checkButton_16(uint16_t buttonVal)
{
	int i;
	for(i=0; i< sizeof(button16)/sizeof(buttonParser_16); i++) {
		button16[i].val = buttonVal & button16[i].mask;
		if(button16[i].val) {
			button16[i].curCount++;
			button16[i].val = 0;
		}

		if(button16[i].curCount > button16[i].prevCount) {
			printf("Button[%d] Pressed, prevCount=%d, curCount=%d\n",i,
					button16[i].prevCount, button16[i].curCount);
			button16[i].prevCount = button16[i].curCount;
		}
	}

}
