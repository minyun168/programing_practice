// A function just like "prinf" in C language and we can use the function to repeat the test of "send AB to pc"

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stdarg.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART_Config(void);
void Uart_SendByte(int data);
void Uart_SendString(char *pt);
void Uart_Printf(const char *fmt,...);


int main(void)
{
	RCC_Configuration();
	GPIO_Configuration();
	USART_Config(void);
	USART_ClearFlag(USART1,USART_FLAG_TC);
	Uart_Printf("Welcome to my world !\n");	
	Uart_Printf("website:%s\n","www.airkissface.top");
	Uart_Printf("temperature=%d\n",13);

}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStruccture.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Initstructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

}


void RC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

}


void USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_Cmd(USART1,ENABLE);

}




void Uart_SendByte(int data)
{
	if (data=='\n')
	{
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
		USART_SendData(USART1,'\r'); //在串口调试助手中使用的换行符是"\r",故遇到"\n"需要转换
	}
	while (USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESER);
	USART_SendData(USART1,data);

}


void Uart_SendString(char *pt)
{
	char *dst=pt;
	while(dst<pt+strlen(pt))
	{
		Uart_SendByte(*dst++);
	}
}


void Uart_Printf(const char *fmt,...)
{
	va_list ap;
	char string[50];

	va_start(ap,fmt);
	vsprintf(string,fmt,ap);
	va_end(ap);
	Uart_SendString(string);
}


