// A sample of ADC configure

// Set Pin_0 as ADC external input Pin
GPIO_InitTypeDef GPIO_InitStructure;
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
GPIO_Init(GPIOC,&GPIO_InitStructure);


// DMA channel configure
DMA_InitTypeDef DMA_InitStructure;
DMA_DeInit(DMA1_Channel1);

DMA_InitStructure.DMA_PerpheralBaseAddr = (uint32_t)&ADC1->DR;
DMA_InitStructure.DMA_MeomorBaseAddr = (u32)&AC_ConvertedValue;
DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralSRC;
DMA_InitStructure.DMA_BufferSize = 1;
DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
DMA_InitStructure.DMA_MemoryDataSize - DMA_MemoryDataSize_HalfWord;
DMA_InitStructure.DMA_Mode = DMA_Mode_Circular;
DMA_InitStructure.DMA_Priority = DMA_Priority_High;
DMA_InitStructure.DMA_M2M = DMA_M2M_Disable;

DMA_Init(DMA1_Channel1,&DMA_InitStructure);

DMA_Cmd(DMA1_Channel1,ENABLE);
