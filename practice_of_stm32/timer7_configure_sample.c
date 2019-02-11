// The configure sample of timer_7

TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_TimeBaseStructure.TIM_Prescaler = 36000-1;
TIM_TimeBaseStructure.TIM_ClockDivision = i0;
TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
TIM_TimeBaseStructure.TIM_Period = 1000;
