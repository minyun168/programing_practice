//Transfer data from "Hello DMA" to "DMA Hello"

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