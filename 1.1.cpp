#include "stm32f10x.h"

void delay_ms(uint32_t ms) {
    for(uint32_t i = 0; i < ms * 8000; i++) {
        __NOP();
    }
}

void GPIO_Config(void) {
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

  
    GPIO_InitTypeDef gpioOut;
    gpioOut.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3;
    gpioOut.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioOut.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOA, &gpioOut);

  
    GPIO_ResetBits(GPIOA, GPIO_Pin_2 | GPIO_Pin_3);
}

int main(void) {
    GPIO_Config();

    while (1) {
   
        GPIOA->ODR ^= (GPIO_Pin_2 | GPIO_Pin_3);

        delay_ms(1000); 
    }
}