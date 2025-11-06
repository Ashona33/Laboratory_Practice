#include "../Inc/lb1_init.h"

void GPIO_Init_Memory(void){
    *(uint32_t*)(0x40023800UL+0x30UL) |= 0x06UL;         //Включение тактирования порта GPIOB и GPIOC

    *(uint32_t*)(0x40020400UL+0x00UL) |= 0x10004001UL;   //Настройка работы 0, 7, 14-го пина GPIOB в режиме вывода сигнала
    *(uint32_t*)(0x40020400UL+0x04UL) |= 0x00UL;         
    *(uint32_t*)(0x40020400UL+0x08UL) |= 0x10004001UL;   //Настройка скорости работы 0, 7, 14-го пина GPIOB на среднюю
    *(uint32_t*)(0x40020400UL+0x18UL) |= 0x40810000UL;
    

    *(uint32_t*)(0x40020800UL+0x08UL) |= 0x100000UL;
    //*(uint32_t*)(0x40020800UL+0x0CUL) |= 0x100000UL;
    //*(uint32_t*)(0x40020800UL+0x18UL) |= 0x4000000UL;
}

void GPIO_Init_Myself_Macros(void){
    RCC_AHB1ENR |= RCC_GPIOB_EN | RCC_GPIOC_EN;

    BIT_SET(GPIOB_MODER, RED_GPIOB14 | BLUE_GPIOB7 | YELLOW_GPIOB0);
    BIT_SET(GPIOB_OTYPER_7_14, RED_GPIOB14_OTYPER | BLUE_GPIOB7_OTYPER);
    BIT_SET(GPIOB_OSPEEDR, RED_GPIOB14 | BLUE_GPIOB7 | YELLOW_GPIOB0);
    BIT_SET(GPIOB_BSRR, GPIOB_RED_RESET | GPIOB_BLUE_RESET | GPIOB_YELLOW_RESET);

    BIT_SET(GPIOC_OSPEEDR, LED_GPIOC10_OUT);
}

void GPIO_Init_CMSIS(void){
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN); //AHB1ENR-ПОЛЕ СТРУКТУРЫ,  RCC_AHB1ENR_GPIOBEN-адрес 

    SET_BIT(GPIOB->MODER, GPIO_MODER_MODE14_0 | GPIO_MODER_MODE7_0 | GPIO_MODER_MODE0_0); // включение красного светодиода, настройка пина PB14 на вывод
    SET_BIT(GPIOB->OTYPER, GPIO_OTYPER_OT7 | GPIO_OTYPER_OT14); //
    SET_BIT(GPIOB->OSPEEDR, GPIO_OSPEEDER_OSPEEDR0_0 | GPIO_OSPEEDER_OSPEEDR7_0 | GPIO_OSPEEDER_OSPEEDR14_0); //
    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR0 | GPIO_BSRR_BR7 | GPIO_BSRR_BR14); //

    SET_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDER_OSPEEDR1_0);
}












//память выделяется последовательно 
//ИО - компилятор должен рассматривать поотдельности, волатад считывает заново, заходит в память, может её читать, менять 