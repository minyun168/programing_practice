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

