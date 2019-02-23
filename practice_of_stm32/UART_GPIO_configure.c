// This is a example of UART GPIO configuration 

GPIO_InitTypeDef GPIO_InitStructure;
GPIO_StructInit(&GPIO_InitStructure);
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA9 pin is for USART1_TX
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP; // Multiplexing push-pull output
GPIO_Init(GPIOA,&GPIO_InitStructure);

GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //PA10 pin is for USART1_RX
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; //Multiplexing open drain input
GPIO_Init(GPIOA,&GPIO_InitStructure);

