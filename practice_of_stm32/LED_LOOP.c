#include "stm32f10x.h"

#define Led1_On() GPIO_SetBits(GPIOB,GPIO_Pin_5)
#define Led1_Off() GPIO_ResetBits(GPIOB,GPIO_Pin_5)

#define Led2_On() GPIO_SetBits(GPIOD,GPIO_Pin_6)
#define Led2_Off() GPIO_ResetBits(GPIOD,GPIO_Pin_6)

#define Led3_On() GPIO_SetBits(GPIOD,GPIO_Pin_3)
#define Led3_Off() GPIO_ResetBits(GPIOD,GPIO_Pin_3)

void LED_Init(void);
void Delay(_IO uint32_t nCount);

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	GPIO_Structure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_pp;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_Structure);

	GPIO_Structure.GPIO_Pin = GPIO_Pin_6;
	GPIO_Structure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOD, &GPIO_Structure);
}

int main(void)
{
	SystemInit();  //system clock setting in stm32
	LED_Init();
	while(1)
	{
		Led1_On();Led2_Off();Led3_Off();
		Delay(0x8FFFF);
		Led1_Off();Led2_On();Led3_Off();
		Delay(0x8FFFF);
		Led1_Off();Led2_Off();Led3_On();
		Delay(0x8FFFF);


	}
}


void Delay(unsigned int nCount)
{
	for(;nCount!=0;nCount--);
}