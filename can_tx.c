/////////////////////////////*main2.c(tx)*////////////////////////////////////////////////////////////////////
#define sw ((IOPIN0>>14)&1)
#define sw1 ((IOPIN0>>15)&1)
#include<lpc21xx.h>
#include "header.h"
CAN1 v1;
int main(){
can1_init();
v1.id=0x123;
v1.dlc=8;
v1.rtr=0;
while(1){
		if(sw==0)
		{
		while(sw==0);
		v1.byteA=0x02;
		can1_tx(v1);
		}
		if(sw1==0)
		{
		while(sw==0);
		v1.byteA=0x01;
		can1_tx(v1);
		}
}

}











