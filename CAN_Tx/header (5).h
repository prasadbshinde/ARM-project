typedef unsigned char u8;

typedef signed char s8;

typedef unsigned int u32;

typedef signed int s32;


extern void uart0_init(u32 baud);

extern void uart0_tx(u8 data);

extern u8 uart0_rx(void);

extern void uart0_tx_string(s8 *ptr);

extern void uart0_tx_integer(s32 num);

extern void uart0_tx_float(float num);


extern void lcd_init(void);

extern void lcd_cmd(u8 cmd);

extern void lcd_data(u8 data);

extern void lcd_string(s8 *ptr);

extern void delay_ms(u32 ms);


extern void adc_init(void);

extern u32 adc_read(u8 ch_num);


extern void config_eint0(void);

extern void config_vic_for_eint0(void);


extern void config_vic_for_uart0(void);


extern void i2c_init(void);

extern void i2c_send(u8 sa,u8 mr,u8 data);

extern u8 i2c_read(u8 sa,u8 mr);


typedef struct CAN1_MSG{

	u32 id;

	u32 byteA;

	u32 byteB;

	u8 rtr;

	u8 dlc;

	u8 ff;

}CAN1;


extern void can1_tx(CAN1 v);

extern void can1_init(void);




