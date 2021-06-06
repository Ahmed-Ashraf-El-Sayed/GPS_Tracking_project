#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
void SystemInit(){}	
unsigned int x;
unsigned char led_out;
void init(){ // activation for port F only
	SYSCTL_RCGCGPIO_R |= 0x20;
	while ((SYSCTL_PRGPIO_R&0x20)==0){};
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x02;
	GPIO_PORTF_DIR_R |= 0x02;
	GPIO_PORTF_DEN_R |= 0x02;
	GPIO_PORTF_AMSEL_R &= ~0x02;
	GPIO_PORTF_AFSEL_R &= ~0x02;
	GPIO_PORTF_PCTL_R &= ~0x000000F0;
	}	
void RED_LED_output (unsigned char data){
GPIO_PORTF_DATA_R |= data;
}
int main(){
init();	 // activation for port F only
while(1){	
x = 100; // dummy data
if ( x >= 100){
 RED_LED_output(led_out);
 led_out = 0x02;
}
 else led_out = 0x00;
}
}
