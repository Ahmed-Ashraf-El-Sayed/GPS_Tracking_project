#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
void init(){  // Activation for all ports used for LCD & Red LED
SYSCTL_RCGCGPIO_R=0x23;   //Activate clocks for Port A , B ,F
while ((SYSCTL_PRGPIO_R&0x23)==0){}  //delay
//Activation for Port F
GPIO_PORTF_LOCK_R=0x4C4F434B;
GPIO_PORTF_CR_R =0x1F;
GPIO_PORTF_AFSEL_R=0;
GPIO_PORTF_PCTL_R=0;
GPIO_PORTF_AMSEL_R=0;
GPIO_PORTF_DIR_R=0x0E;
GPIO_PORTF_DEN_R=0x1F;
GPIO_PORTF_PUR_R=0x11;
//Activation for Port A
GPIO_PORTA_LOCK_R=0x4C4F434B;
GPIO_PORTA_CR_R =0xFF;
GPIO_PORTA_AMSEL_R &=~ 0xFF;
GPIO_PORTA_AFSEL_R &=~ 0xE0;
GPIO_PORTA_DEN_R |= 0xE0;
GPIO_PORTA_PCTL_R &= ~0xFFF00000;
GPIO_PORTA_DIR_R |= 0XE0;       //pins 5,6,7 are output
  //Activation for Port B
GPIO_PORTB_LOCK_R=0x4C4F434B;
GPIO_PORTB_CR_R =0xFF;    
GPIO_PORTB_AMSEL_R &= ~0xFF;
GPIO_PORTB_AFSEL_R &= ~0xFF;
GPIO_PORTB_DEN_R |= 0xFF;
GPIO_PORTB_PCTL_R &= ~0xFFFFFFFF;
GPIO_PORTB_DIR_R |= 0XFF;       // all pins are output
}
