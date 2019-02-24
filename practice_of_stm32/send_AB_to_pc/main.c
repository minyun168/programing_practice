// This Program will have the outcome: Display char "AB" in the pc

#include "stm32f10x.h"
#include "stm22f10x_usart.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART_Config(void);

int main()
{
	RCC_Configuration();
	GPIO_Configuration();
	USART_Config();
	USART_ClearFlag(USART1,USART_FLAG_TC);
	USART_SendData(USART1,'A');
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
	USART_SendData(USART1,'B');
	while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);

}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //USART1_TX
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //USART1_RX
	GPIO_InitStructure.GPIO_Mode = GPIO_MOde_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

}


void USART_Config(void) //the configuration detail you can see: UART_USART_configuration.c
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No; //Verification bit is None
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_Cmd(USART1,ENABLE);
	
}

