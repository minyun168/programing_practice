#include "stm32f10x.h"
#include "stm32f10x_tim.h"
#include "stm32f10x_rcc.h"
#include "misc.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void TIM_Configuration(void);
int main(void)
{
	RCC_Configuration();
	GPIO_Configuration():
	TIM_Configuration();
	while(1)
	{

	}
}

void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB2Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

}

void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);
}

void TIM_Configuration(void)
{
	TIM_TimeBaseInitTypeDef TIM_TIMBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_TimeBaseStructure.TIM_Prescaler = 3600-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseStructure.TIM_Period = 200;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure); 

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;

	TIM_OCInitStructure.TIM_Pulse = 20;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_ForcedOC1Config(TIM3,TIM_ForcedAction_Active);
	TIM_Cmd(TIM3,ENABLE);
	TIM_CtrlPWMOutputs(TIM3,ENABLE);
	
}