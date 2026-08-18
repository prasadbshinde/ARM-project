/////////////////////////////////////////////////////////////adc_driver/////////////////////////////////////////////////////
#include<lpc21xx.h>
//int result;
void adc_init()
{
PINSEL1|=0X15400000;
ADCR=0X00200400;
}
int adc_read(int chn)
{
int result=0;
ADCR |= 1<<chn;
ADCR|=1<<24;
while(((ADDR>>31)&1)==0);
ADCR^=1<<24;
ADCR^=1<<chn;
result=(ADDR>>6)&0X3FF;
//uart0_tx_integer(result);
//uart0_tx_string("\r\n");
return result;
}


