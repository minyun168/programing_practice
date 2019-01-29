//GPIO_InitTypeDef
typedef struct 
{
	uint16_t GPIO_Pin;
	GPIOSpeed_TypeDef GPIO_Speed;
	GPIOMode_TypeDef GPIO_Mode;

}GPIO_InitTypeDef;


typedef enum
{
	GPIO_Speed_10MHz = 1,
	GPIO_Speed_2MHz,
	GPIO_Speed_50MHz,

}GPIOSpeed_TypeDef;


typedef enum
{
	GPIO_Mode_AIN = 0x0, //analog input
	GPIO_Mode_IN_FLOATING = 0x04, //float input
	GPIO_Mode_IPD = 0x28, // with IPD
	GPIO_Mode_IPU = 0x48, //with IPU
	GPIO_Mode_Out_OD = 0x14, //open drain output
	GPIO_Mode_Out_PP = 0x10, //Push-pull output
	GPIO_Mode_AF_OD = 0x1C, //with reuse function of open drain output
	GPIO_Mode_AF_PP = 0x18, //with reuse function of push-pull output
}GPIOMode_TypeDef;