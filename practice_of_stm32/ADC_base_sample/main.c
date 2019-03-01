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


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure); //If we use USART, we should use "StructInit".
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE); //USART1
	RCC_AHBPeriphClockCmd(RCC_AHB2Periph_DMA1,ENABLE); //ADC1 should use DMA1
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE); //ADC1
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
}