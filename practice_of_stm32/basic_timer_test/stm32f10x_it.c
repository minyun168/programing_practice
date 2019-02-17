void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)==SET)
	{
		GPIO_WriteBit(GPIOB,GPIO_Pin_5,(BitAction)(1-GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_5)));
		TIM_ClearITPendingBit(TIM7,TIM_FLAG_Update);
	}
}