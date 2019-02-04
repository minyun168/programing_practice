//

#include <stm32f10x.h>
#include <stm32f10x_exti.h>
#include <stm32f10x_rcc.h>
#include <misc.h>

void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void Delay(_IO uint32_t nCount);
void Key_scan(void);

unsigned char _it0 = 0,num = 0;

int main (void)
{
	unsigned char b = 0;
	RCC_Configuration();
	NVIC_Configuration();
	GPIO_Configuration();

	while(1)
	{
		Key_scan;
		if (num==2 && b==0)
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			b=1;

		}
		else if (num==2 && b==1)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_5);
			b=0;
			
		}


	}
}