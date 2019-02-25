#include "stm32f10x_it.h"
#include "stm32f10x_usart.h"

unsigned char Buffer[10];
extern unsigned char CmdBuffer[10];
unsigned char RxCounter = 0;

void USART1_IRQHandler(void)
{
	unsigned int i = 0;
	if (USART_GetITStatus(USART1,USART_IT_RXNE)!=RESET)
	{
		Buffer[RxCounter++] = USART_ReceiveData(USART1);
		if ((Buffer[RxCounter-2]==0x0d)&&(Buffer[RxCounter-1]==0x0a)) //When we send command to stm32, it will end with command "Enter"; "Enter" Key includes carriage return(ASCII is 0x0d) and wrap(ASCII is 0x0a)
		{                                                             //"&" and "&&" is different,"&&" is Logic 
			for (i=0;i<RxCounter;i++)
			{
				CmdBuffer[i] = Buffer[i];

			}
			CmdBuffer[RxCounter]=0; //?
			RxCounter = 0;
		}
	}
}