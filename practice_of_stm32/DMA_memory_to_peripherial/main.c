//Function: send "Send by DMA" to peripheral by using  DMA

#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stm32f1x_dma.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void DMA_Configuration(void);
void USART_Config(void);

uint8_t SrcBuf[12] = "Send by DMA";

int main(void)
{
	RCC_Configuration();
	GPIO_Configuration();
	USART_Configuration();
	DMA_Configuration();

	USART_ClearFlag(USART1,USART_FLAG_TC);
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE); //USART can send DMA request
	DMA_Cmd(DMA1_Channel4,ENABLE);  
}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriohClockCmd(RCC_APB2Periph_DMA1,ENABLE);

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


void DMA_Configuration(void)
{
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_PeripheralBaseAddr = (uint32_t)&USART1->DR; // transfer destination
	DMA_InitStructure.DMA_MemoryBaseAddr = (uint32_t)SrcBuf; //transfer source
	DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralDST; 
	DMA_InitStructure.DMA_BufferSize = 11;
	DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable; //Peripherial address is same, because UART1 register address is const. So address needn't automatic add.
	DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_Mode = DMA_Mode_Normal; //once using "normal",again using "DMA_Mode_Circular"
	DMA_InitStructure.DMA_Priority = DMA_Priority_High; 
	DMA_InitStructure.DMA_M2M = DMA_M2M_Disable; //Not memory to memory, so need to "disable"

	DMA_Init(DMAl_Channel4,&DMA_InitStructure);

}