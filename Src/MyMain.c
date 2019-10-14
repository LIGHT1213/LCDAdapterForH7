#include "MyMain.h"
extern uint32_t ImgIn[38400];
void MyMain()
{
	//printf("1");
	//ShwoImg(ImgTran(ImgIn));
	while(1)
	{
		Lcd_Clear(RED);
	}

}
uint16_t ImgTran(uint32_t img[38400])
{
	uint16_t TempPic[76800];
	int t=0;
	for(int i=0;i<=38400;i++)
	{
		TempPic[t]=img[i]>>16;
		TempPic[t+1]=img[i];
		t+=2;
	}
	return TempPic[76800];
}
void ShwoImg(uint16_t img[76800])
{
	for(int w=0;w<=240;w++)
	{
		for(int l=0;l<=320;l++)
		{
			Lcd_WriteData_16Bit(img[w+l]);
		}
	}
}
void HAL_UART_RxCpltCallback (UART_HandleTypeDef * huart)
{
	if(huart->Instance == UART4)
	{
		HAL_UART_Receive_DMA(&huart4,ImgIn,38400);
		Lcd_Clear(RED);
	}
}

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

int fputc(int ch,__FILE *f)
{
    uint8_t temp[1]={ch};
    HAL_UART_Transmit(&huart4,temp,1,10);
		return ch;
}


PUTCHAR_PROTOTYPE
{
	HAL_UART_Transmit(&huart4,(uint8_t*)&ch,1,10);
	return ch;
}
