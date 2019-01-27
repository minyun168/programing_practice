GPIO_InitTypeDef GPIO_Structure;
GPIO_Structure.GPIO_Pin = GPIO_Pin_5;

GPIO_Structure.GPIO_Mode = GPIO_Mode_Out_PP;
GPIO_Init(GPIOB,&GPIO_Structure);

GPIO_SetBits(GPIOB,GPIO_Pin_5);
GPIO_ResetBits(GPIOB,GPIO_Pin_5);