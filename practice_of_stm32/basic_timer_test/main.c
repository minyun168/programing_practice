#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "misc.h"

void RCC_Configuration(void);
void GPIO_Configuretion(void);
void NVIC_Configuretion(void);
void TIM_Configuration(void);

int main(void)
{
	RCC_Configuration;
	GPIO_Configuration;
	TIM_Configuration;
	NVIC_Configuration;
	while(1)
	{

	}
}

