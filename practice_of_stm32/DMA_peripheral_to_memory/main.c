#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_dma.h"
#include <stdio.h>

void RCC_Configuration(void);
void GPIO_Configuration(void);
void DMA_Configuration(void);
void USART_Configuration(void);
int fputc(int ch, FILE *f);

uint8_t SrcBuf[12]="xxxxxxxxxxx";
{
	uint8_t flag=1;
	RCC_Configuration();
	GPIO_Configuration();
	USART_Config();
	DMA_Configuration();

	USART_ClearFlag(USART1,USART_FLAG_TC);
	USART_DMACmd(USART1,USART_DMAReq_Rx,ENABLE);
	DMA_Cmd(DMA1_Channel4,ENABLE);

	while(flag)
	{
		if(strstr(SrcBuf,"LED"))
		{
			printf(SrcBuf);
			flag = 0;
		}
	}
}


