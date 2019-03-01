#include "stm32f10x.h"
#include "stm32f10x_usart.h"
#include "stdio.h"
#include "stm32f10x_dma.h"
#include "stm32f10x_adc.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void DMA_Configuration(void);
void USART_Config(void);
int fputc(int ch,FILE *f);
void ADC_Configuration(void);
vul6 ADC_ConvertedValue;
static unsigned long ticks;

int main(void)
{
	uint8_t flag = 0;
	uint32_t value = 0;
	RCC_Configuration();
	GPIO_Configuration();
	USART_Config();
	DMA_Configuration();
	ADC_Configuration();
	USART_ClearFlag(USART1,USART_FLAG_TC);
	while(1)
	{
		if(ticks++ >= 900000)
		{
			ticks = 0;
			flag = 1;

		}
		if(flag)
		{
			flag = 0;
			printf("The current AD value = %d\n",ADC_ConvertedValue);
		}
	}
}