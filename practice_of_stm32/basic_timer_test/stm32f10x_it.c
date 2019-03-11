void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET) //if have interrupt
	{
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5))); //if pin PB_5 is 1, make it be 0; if pin PB_5 is 0, make it be 1. 
		TIM_ClearITPendingBit(TIM7,TIM_FLAG_Update); //function "TIM_ClearITPendingBit": clear interrupt flag "TIM_FLAG_Update"
	}
}