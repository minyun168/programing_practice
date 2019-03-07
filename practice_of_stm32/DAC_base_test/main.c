//DAC_base_test: DAC module produce analog voltage, and print it by DAC_output_channel_1(PA4)

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_dac.h"
#include "stdio.h"

void RCC_Configuration(void);
void NVIC_Configuration(void);
void GPIO_Configuration(void);
void USART_Configuration(void);
void DAC_Configuration(void);
void DAC_Output(u16 value);

int fputc(int ch, FILE *f);

int main(void)
{
	RCC_Configuration();
	GPIO_Configuration();
	USART_Config();
	USART_ClearFlag(USART1,USART_FLAG_TC);
	DAC_Configuration();
	DAC_Output(1500);

}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure)

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4; //DAC output channel_1 is pin PA4
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_4);
}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeripheralClockCmd(RCC_APB2Peripheral_GPIOA,ENABLE);
	RCC_APB2PeripheralClockCmd(RCC_APB2Peripheral_USART1,ENABLE);
	RCC_APB2PeripheralClockCmd(RCC_APB2Peripheral_DAC,ENABLE);

}


void USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_USART_Mode = USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure);
	USART_Cmd(USART1,ENABLE);
	
}

