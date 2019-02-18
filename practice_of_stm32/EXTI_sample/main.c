//

#include <stm32f10x.h>
#include <stm32f10x_exti.h>
#include <stm32f10x_rcc.h>
#include <misc.h>

void RCC_Configuration(void);
void GPIO_Configuration(void);
void NVIC_Configuration(void);
void Delay(_IO uint32_t nCount);
void Key_scan(void);

unsigned char _it0 = 0,num = 0;

int main (void)
{
	unsigned char b = 0;
	RCC_Configuration();
	NVIC_Configuration();
	GPIO_Configuration();

	while(1)          
	{
		Key_scan;
		if (num==2 && b==0)    
		{
			GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			b=1;  // The effection of variable "b" is for changing the state of LED when we pressing the Key next time. Not for LED LOOP.Because when the function "Key_Scan" is executed next time,"num=0".
  
		}
		else if (num==2 && b==1)
		{
			GPIO_SetBits(GPIOB,GPIO_Pin_5);
			b=0;
			
		}


	}
}


void Key_Scan(void)
{
	num=0;
	if (_it0==2)
	{
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)==0)
		{
  			Delay(0xffff);  // Delay for shaking accidently
  			if (GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)==0)
  			{
  				while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)==0); //empty "while loop", when pressing the button
  				num=2; //when release the button
		}
	}
	_it0=0;
}


void Delay(_IO uint32_t nCount)
{
	for(;nCount!=0;nCount--);

}


void RCC_Configuration(void)
{
	SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE); //AFIO is multiplexing clock, when some IO is for multiplexing use.
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

}


void GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

}


void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);
	EXTI_InitStructure.EXTI_Line = EXTI_Line2;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_InitStructrue.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
}