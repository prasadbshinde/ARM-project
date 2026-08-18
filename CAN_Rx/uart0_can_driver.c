//////////////////////////////////////////////////////////////////////*uart0_driver*/////////////////////////////////////////////////////////

#include<lpc21xx.h>
#define  RDR ((U0LSR&1))
#define  THRE ((U0LSR>>5)&1)
void uart0_init(unsigned int baud)
{

int pclk,result=0;
PINSEL0 |=5;
VPBDIV==1;
pclk=60000000;
result=pclk/(16*baud);
U0LCR=0X83;
U0DLL=(result&0xff);
U0DLM=((result>>8)&0xff);
U0LCR=0X03;
}

void uart0_tx(unsigned char data)
{
U0THR=data;

while(THRE==0);
}

unsigned char uart0_rx()
{
unsigned int temp;
while(RDR==0);
temp=U0RBR;
return temp;
}

void uart0_tx_string(char*p)
{
while(*p)
{
U0THR=*p;
while(THRE==0);
p++;

}
}


void uart0_rx_string(char*p)
{
int i=0;
int temp=0;
while(1)
{
temp=uart0_rx();
uart0_tx(temp);
if(temp==13)
break;
p[i++]=temp;
}
p[i]=0;
}


void uart0_integer(int num)
{
int a[10],i=0;
if(num<0)
{
num=-num;
uart0_tx('-');
}
if(num==0)
{
uart0_tx(0+48);
return;
}




while(num)
{
a[i++]=num%10;
num=num/10;
}
for(--i;i>=0;i--)
{
uart0_tx(a[i]+48);
}
 }

void uart0_rx_string1(char*p)
{
int i=0;
int temp=0;
while(1)
{
temp=uart0_rx();
uart0_tx(temp);
if(i==13)
break;
p[i++]=temp;
}
p[i]=0;
}

