#ifndef INIT_H
#define INIT_H

#include <stm32f4xx.h>
#include <stm32f429xx.h>

#define RCC_AHB1ENR (*(uint32_t*)(0x40023800UL + 0x30UL))
#define RCC_GPIOB_EN 0x02UL
#define RCC_GPIOC_EN 0x04UL

#define GPIOB_MODER (*(uint32_t*)(0x40020400UL + 0x00UL))
#define GPIOB_OSPEEDR (*(uint32_t*)(0x40020400UL + 0x08UL))
#define GPIOB_BSRR (*(uint32_t*)(0x40020400UL + 0x18UL))
#define GPIOB_OTYPER_7_14 (*(uint32_t*)(0x40020400UL + 0x04UL))

#define GPIOC_MODER (*(uint32_t*)(0x40020800UL + 0x00UL))
#define GPIOC_OSPEEDR (*(uint32_t*)(0x40020800UL + 0x08UL))
#define GPIOC_BSRR (*(uint32_t*)(0x40020800UL + 0x18UL))
#define GPIOC_IDR (*(uint32_t*)(0x40020800UL + 0x10UL))


#define BUTTON1_GPIOC5          0x00UL
#define BUTTON2_GPIOC6          0x00UL
#define BUTTON3_GPIOC1          0x00UL
#define LED_GPIOC1              0x04UL

#define RED_GPIOB14             0x10000000UL
#define RED_GPIOB14_OTYPER      0x4000UL
#define BLUE_GPIOB7             0x4000UL
#define BLUE_GPIOB7_OTYPER      0x80UL
#define YELLOW_GPIOB0           0x01UL

#define GPIOB_RED_SET           0x4000UL
#define GPIOB_BLUE_SET          0x80UL
#define GPIOB_YELLOW_SET        0x01UL

#define GPIOB_RED_RESET         0x40000000UL
#define GPIOB_BLUE_RESET        0x800000UL
#define GPIOB_YELLOW_RESET      0x10000UL

#define GPIOC_LED_SET           0x20000UL
#define GPIOC_LED_RESET         0x20000UL


void GPIO_Init_Memory(void);
void GPIO_Init_Myself_Macros(void);
void GPIO_Init_CMSIS(void);  //gpio порты включаются с помощью библиотеки смсис


#endif