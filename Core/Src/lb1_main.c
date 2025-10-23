//#include <stdint.h>
#include "../Inc/lb1_init.h"
#include "stdbool.h"

int main(void){
    bool flag = 0;
    GPIO_Init_Memory();

    while(1){
        //SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR_14 + GPIO_BSRR_BR_7 + GPIO_BSRR_BR_0);
        if (BIT_READ(GPIOC_IDR, BUTTON1_GPIOC8)){ 
            BIT_SET(GPIOB_BSRR, GPIOB_RED_SET); 
            BIT_SET(GPIOC_MODER, BUTTON3_GPIOC10_OUT);
            flag = 0;
        }
        else { BIT_SET(GPIOB_BSRR, GPIOB_RED_RESET); }

        if (BIT_READ(GPIOC_IDR, BUTTON2_GPIOC9)){ 
            BIT_SET(GPIOB_BSRR, GPIOB_BLUE_SET); 
            BIT_SET(GPIOC_MODER, LED_GPIOC10_OUT);
            flag = 1;
        }
        else { BIT_SET(GPIOB_BSRR, GPIOB_BLUE_RESET); }

        if (!flag){
            if (BIT_READ(GPIOC_IDR, BUTTON3_GPIOC10)){ 
                BIT_SET(GPIOB_BSRR, GPIOB_YELLOW_SET); 
            }
            else { BIT_SET(GPIOB_BSRR, GPIOB_YELLOW_RESET); }
            BIT_SET(GPIOC_BSRR, GPIOC_LED_RESET);
        }

        if (flag){
            BIT_SET(GPIOC_BSRR, GPIOC_LED_SET);
        }
    }
}
