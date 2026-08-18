/////////////////////////////*main2.c(tx)*////////////////////////////////////////////////////////////////////
#include <lpc21xx.h>
#include "header.h"

#define VIB_SENSOR ((IOPIN0 >> 14) & 1)
#define IR_SENSOR  ((IOPIN0 >> 15) & 1)

CAN1 v1;

int main(void)
{
    PINSEL0 &= ~((3<<28) | (3<<30));
    IODIR0 &= ~((1<<14) | (1<<15));

    can1_init();

    v1.id = 0x123;
    v1.dlc = 8;
    v1.rtr = 0;

    while(1)
    {
        if(VIB_SENSOR == 0)
        {
            while(VIB_SENSOR == 0);
            v1.byteA = 0x02;
            can1_tx(v1);
        }

        if(IR_SENSOR == 0)
        {
            while(IR_SENSOR == 0);
            v1.byteA = 0x01;
            can1_tx(v1);
        }
    }
}
