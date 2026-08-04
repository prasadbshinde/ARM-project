#include <lpc21xx.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

#define SPEED_THRESHOLD        150
#define VOLTAGE_THRESHOLD      2.2
#define ENGINE_TEMP_THRESHOLD  80

CAN1 v1;
int flag;

void read_sensors(float *voltage, int *speed, int *temp);

int main()
{
    float voltage;
    int speed, temp;
    int fault;
    char s[50];

    can1_init();
    adc_init();
    uart0_init(9600);
    config_handler_can0();

    IODIR0 = 1<<7;
    IOSET0 = 1<<7;

    while(1)
    {
        fault = 0;

        if(flag)
        {
            uart0_tx_string("rec....\r\n");
            flag = 0;

            if(C1RDA == 0x01)
                uart0_tx_string("Object detected, brakes applied\r\n");

            else if(C1RDA == 0x02)
                uart0_tx_string("Crash detected\r\n");

            else if(C1RDA == 0x03)
                uart0_tx_string("Door is open\r\n");

            else if(C1RDA == 0x04)
                uart0_tx_string("Door is closed\r\n");
        }

        /* Read all sensors */
        read_sensors(&voltage, &speed, &temp);

        sprintf(s,"S:%d km/hr V:%.2f V T:%d\r\n",
                speed, voltage, temp);
        uart0_tx_string(s);

        if(temp >= ENGINE_TEMP_THRESHOLD)
        {
            uart0_tx_string("Temperature High: ");
            uart0_integer(temp);
            uart0_tx_string("\r\n");
            fault = 1;
        }

        if(voltage < VOLTAGE_THRESHOLD)
        {
            sprintf(s,"Low Voltage: %.2f V\r\n", voltage);
            uart0_tx_string(s);
            fault = 1;
        }

        if(speed > SPEED_THRESHOLD)
        {
            sprintf(s,"Overspeed: %d km/hr\r\n", speed);
            uart0_tx_string(s);
            fault = 1;
        }

        if(fault)
            IOCLR0 = 1<<7;      // LED ON
        else
            IOSET0 = 1<<7;      // LED OFF

        delay_ms(4000);
    }
}

void read_sensors(float *voltage, int *speed, int *temp)
{
    *voltage = adc_read(0);
    *voltage = (*voltage / 1023.0) * 3.3;
    *voltage = *voltage * 5.0;

    delay_ms(20);

    *speed = adc_read(1);
    *speed = (*speed * 180) / 1023;

    delay_ms(20);

    *temp = adc_read(2);
    *temp = (*temp * 330) / 1023;
}