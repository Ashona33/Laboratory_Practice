#ifndef INIT_H
#define INIT_H

#include <stm32f4xx.h>
#include <stm32f429xx.h>

#define RCC_AHB1ENR (*(uint32_t*)(0x40023800UL + 0x30UL))
#define RCC_GPIOB_EN 0x02UL
#define RCC_GPIOC_EN 0x04UL

#define BUTTON1_GPIOC5   0x00UL
#define BUTTON2_GPIOC6   0x00UL
#define BUTTON3_GPIOC7   0x00UL

#define RED_GPIOB14      0x10000000UL
#define BLUE_GPIOB7      0x4000UL
#define YELLOW_GPIOB0    0x01UL
#define NEW_GPIOB1       0x02UL

#endif