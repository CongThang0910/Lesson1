#include "stm32f10x.h"

void delay_ms(int ms) {
    for (int i = 0; i < ms * 8000; i++) {
        __asm("NOP");  
    }
}

int main(void) {
    
    RCC->APB2ENR |= (1<<2);   

    
    GPIOA->CRL &= ~(0xF << (0*4));  
    GPIOA->CRL |=  (0x8 << (0*4));  
    GPIOA->ODR |= (1<<0);           

    
    GPIOA->CRL &= ~(0xF << (2*4));  
    GPIOA->CRL |=  (0x2 << (2*4));  

    while(1) {
        
        if(!(GPIOA->IDR & (1<<0))) {
            
            GPIOA->ODR ^= (1<<2);
            delay_ms(200);
        }
    }
}