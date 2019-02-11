#include "stm32f10x_it.h"
#include "stm32f10x_exti.h"
#include "stm32f10x_rcc.h"
#include "misc.h"

extern unsigned char _it0;

void EXTI2_IRQHandler(void)
{
	if (EXTI_GetITStatus(EXTI_Line2)!=RESET)
	{
		_it0=2;
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
}