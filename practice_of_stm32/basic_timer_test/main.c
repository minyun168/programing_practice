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

void Rcc_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);

}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}

void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCMD = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}

void TIM_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 3600-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 1000;
	TIM_TimeBaseStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM7,&TIM_TimeBaseStructure);

	TIM_UpdateRequestConfig(TIM7,TIM_UpdateSource_Regular);
	TIM_Cmd(TIM7,ENABLE);
	TIM_ITConfig(TIM7,TIM_IT_Update,ENABLE);
}