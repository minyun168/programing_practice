#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "misc.h"
#include <string.h>

void RCC_Confguration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void USART_Config(void);

unsigned char CmdBuffer[10];


int main(void)
{
	RCC_Configuration();
	GPIO_Configuration();
	USART_Config();
	NVIC_Configuration();
	memset(CmdBuffeer,10,0);
	while(1)
	{
		if (strstr(CmdBuffer,"LEDON"))
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_5);
			memset(CmdBuffer,10,0);
		}
		if (strstr(CmdBuffer,"LEDOFF"))
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			memset(CmdBuffer,10,0);
		}
	}

}
