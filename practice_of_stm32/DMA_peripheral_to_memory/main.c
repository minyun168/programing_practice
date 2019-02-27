//Pc use "serial debugging assistant" send "LED" to development board; when development board receive the data, transfer it to buffer, the main loop will scan whether receive the data, if have receive, send the data to serial port

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
	uint8_t flag=1; //flag is for loop
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


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_INitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE); // DMA1 shoud use AHB clock

}


void USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	UsART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = UsSART_WordLength_8b;
	USART_InitStructure.USART_StopBits = UsART_StopBits_1;
	UsARt_InitStructure.USART_Parity = USSART_Parity_No;
	USART_InitStructure.USART_HardwareFlowcontrol = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_Cmd(USART1,ENABLE);

}


void DMA_Configuration(void)
{
	
}