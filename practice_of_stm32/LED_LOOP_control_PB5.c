//Led loop's sample of control pin PB5 

#include "stm32f10x.h"

void LED_Init(void);
void Delay(_IO uint32_t nCount);

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_Structure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Structure);

}

int main(void)
{
	SystemInit();
	LED_Init();

	while (1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		Delay(0x8FFFF);
		GPIO_ResetBits(GPIOB,GPIO_pin_5);
		Delay(0x8FFFF);

	}

	void Delay(unsigned int nCount)
	{
		for(;nCount!=0;nCount--);
	}
}