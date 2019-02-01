//Led Loop of control pin PC7

#include <stm32f10x.h>

void Delay(_IO uint32_t nCount);
void LED_Init(void);

void Delay(unsigned int nCount)
{
	for(;nCount!=0;nCount--);
}

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_Structure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO,ENABLE);
	GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Structure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Structure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOC,&GPIO_Structure);
	
}

int main(void)
{
	SystemInit();
	LED_Init();
	while(1)
	{
		GPIO_SetBits(GPIOC,GPIO_Pin_7);
		Delay(0x8FFFF);
		GPIO_ResetBits(GPIOC,GPIO_Pin7);
		Delay(0x8FFFF);
	}
}