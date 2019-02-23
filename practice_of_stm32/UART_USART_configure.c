USART_InitTypeDef USART_InitStructure;
USART_InitStructure.USART_BaudRate = 115200;  //BaudRate is 115200
USART_InitStructure.USART_WordLength = USART_WordLength_8b; //Data bits is 8 bit
USART_InitStructure.USART_StopBits = USART_StopBits_1; //Stop bit is 1
USART_InitStructure.USART_Partity = USART_Parity_No; //Verification bit is None
USART_InitStructure.USART_HardWareFlowControl = USART_HardWareFlowControl_None; //Harwareflow control is None;
USART_InitStructure.USART_Mode = USART_Mode_Tx;
USAT_Init(USART1,&USART_InitStructure);
