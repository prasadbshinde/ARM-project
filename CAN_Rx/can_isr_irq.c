//////////////////////////////////////////////ISr(rx)/////////////////////////////////////////////////////////////////////
#include<lpc21xx.h>
extern int flag;
void config_can0(void)__irq{
unsigned long int icr =C1ICR;
if(icr & 0X01){
C1CMR=(1<<2);
//C1ICR=1;
}	 
//uart0_tx("rec rec....\r\n");
flag=1;
VICVectAddr=0;
}

void config_handler_can0(void){


C1IER=1;
VICIntEnable=1<<26;
VICIntSelect=0;
VICVectCntl0=26 | 1<<5;
VICVectAddr0=(unsigned int)config_can0;
}
