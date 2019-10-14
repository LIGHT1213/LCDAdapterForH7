#ifndef MYMAIN_H
#define MYMAIN_H
#include <gui.h>
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "KeyPad.h"

void MyMain();
uint16_t ImgTran(uint32_t img[38400]);
void ShwoImg(uint16_t img[76800]);
uint32_t ImgIn[38400];
#endif
