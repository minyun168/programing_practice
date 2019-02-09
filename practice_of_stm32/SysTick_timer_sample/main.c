//

#include <stm32f10x.h>

static _IO uint32_t TimingDelay;
void RCC_Configuration(void);
void Delay(_IO uint32_t nTime);

void LED_Config(void)
{
	GPIO_InitTYpeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO.Init(GPIOB,&GPIO_InitStructure);
}

void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
}

void Delay(_IO uint32_t value)
{
	TimingDelay = value;
	while (TimingDelay != 0);

}

void TimingDelay_Decremnet(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay--;

	}
}

int main(void)
{
	RCC_Configuration();
	LED_Config();
	TimingDelay = 500;  
	SysTick_Config(7200);
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		Delay(500);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		Delay(500);

	}
}