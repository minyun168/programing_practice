void TIM3_IRQHandler(void)
{
	uint16_t reloadvalue;
	if(TIM_GetITStatus(TIM3,TIM_IT_cc1)!=RESET)
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_CC1);//clear interrupt flag "TIM_IT_CC1"
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5)));//if pin PB_5 is 1, make it be 0; if pin PB_5 is 0, make it be 1. 
		reloadvalue = TIM_GetCapture1(TIM3);
		TIM_SetCompare1(TIM3,reloadvalue+200); //P75 <<crazy stm32>>

	}
}