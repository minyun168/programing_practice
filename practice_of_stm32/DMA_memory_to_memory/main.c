//Transfer data from "Hello DMA" to "DMA Hello" in memory

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_dma.h"
#include "stdio.h"


void RCC_Configuration(void);
void GPIO_Configuration(void);
void DMA_Configuration(void);
void USART_Configuration(void);
int fputc(int ch,FILE *f);

uint8_t SrcBuf[10]="Hello DMA"; //uint8_t: unsigned char
uint8_t DstBuf[10]="DMA Hello";

int main(void)
{
	RCC_Configuration();
	GPIO_Configuration();
	USART_Configuration();
	DMA_Configuration();

	USART_ClearFlag(USART1,USART_FLAG_TC); //Sending data: firstly clear USART_FLAG_TC; receiving data: firstly check whether USART_IT_RXNE is RESET
	printf("Befor the DMA transfer:\n");
	printf("DstBuf:%s\n",DstBuf);

	DMA_Cmd(DMA1_Channel1,ENABLE); // Enabling the DMA, and transfer data

	printf("After the DMA transfer:\n");
	printf("DstBuf:%s\n",DstBuf);

}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(&GPIO_InitStructure);
}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_AHBPeriohClockCmd(RCC_APB2Periph_DMA1,ENABLE); //Hrer is DMA clock, so we should use "AHB" 

}


void USART_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1,&USART_InitStructure); 
	USART_Cmd(USART1,ENABLE);
}


int fputc(int ch,FILE *f)
{
	if (ch=='\n')
	{
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
		USART_SendData(USART1,'\r');
	}
	while (USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET);
	USART_SendData(USART1,ch);

	return ch;

}


void DMA_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(DMA1_Channel1); //Set register the default value
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)SrcBuf; //Though the test is memory to memory, we should define an address as "peripheral address". (Here is the data transfer source address)
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)DstBuf; //Memory address(Here is data transfer Destination address)
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC; //*Define peripheral address as source(Here is from SrcBuf to DstBuf);when we need to define peripheral as destination,use"DMA_DIR_PeripheralDST"
	DMA_InitStructure.DMA_BufferSize = 10; //The length of data transfer(here is "Hello DMA")
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Enable; 
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable; // Set data pointer automatic add
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte; // Set data transfer unit
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal; //set mode as normal or loop
	DMA_InitStructure.DMA_Priority = DMA_Priority_High; 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Enable; //Set the mode is memory to memory; when we transfer data from peripheral to memory, we should use "DMA_M2M_Disable"
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);
}