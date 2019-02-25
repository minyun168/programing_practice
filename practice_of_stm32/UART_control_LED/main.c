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
		if (strstr(CmdBuffer,"LEDON"))  // strstr: if "LEDON" in CmdBuffer, return address (as true). This function in "string.h"
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_5);
			memset(CmdBuffer,10,0);  //Set CmdBuffer to 0
		}
		if (strstr(CmdBuffer,"LEDOFF"))
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			memset(CmdBuffer,10,0);
		}
	}

}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
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
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
}


void USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx; //Set USART work in receive mode
	USART_Init(USART1,&USART_InitStructure);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE); //Open USART1 to receiving the interrupt
	USART_Cmd(USART1,ENABLE);

}


void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}


 