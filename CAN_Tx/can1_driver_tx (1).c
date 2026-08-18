//////////////////////////////////////////////////////*can1_driver.c*////////////////////////////////////////////////////////////////////

#include <LPC21xx.H>

#include "header.h"

void can1_init(void){

	PINSEL1|=0x40000;//P0.25->RD1

	VPBDIV=1;//PLCK=60MHz

	C1MOD=1;//reset mode

	C1BTR=0x001C001D;//125Kbps baudrate

	AFMR=2;//accept all incoming msgs

	C1MOD=0;//Release reset mode

}
#define RBS (C1GSR&1)

void can1_rx(CAN1 *ptr){

	while(RBS==0);//waiting for msg to receive

	ptr->id=C1RID;

	ptr->dlc=(C1RFS>>16)&0xF;//extract dlc

	ptr->rtr=(C1RFS>>30)&1;//extract rtr

	if(ptr->rtr==0){//if data-frame

		ptr->byteA=C1RDA;//get lower 4bytes data

		ptr->byteB=C1RDB;//get higher ""

	}

	C1CMR=(1<<2);//*Release rxbuf

}

#define TCS ((C1GSR>>3)&1)

void can1_tx(CAN1 v){

	C1TID1=v.id;

	C1TFI1=v.dlc<<16;//Set dlc,rtr=0,ff=0

	if(v.rtr==0){//if data-frame

		C1TDA1=v.byteA;

		C1TDB1=v.byteB;

	}

	else

		C1TFI1|=(1<<30);//rtr=1

	

	C1CMR=0x21;//select Txbuf1 & start Xmission

	while(TCS==0);

}


