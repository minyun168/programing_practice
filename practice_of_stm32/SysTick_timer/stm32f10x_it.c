#include "stm32f10x_it.h"   //here is .h  not .c
extern void TimingDelay_Decrement(void);
void SysTick_Handler(void)
{
	TimingDelay_Decrement();
}