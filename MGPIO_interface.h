

#ifndef MGPIO_INTERFACE_H_
#define MGPIO_INTERFACE_H_


#define MGPIO_u8_PORTA	0
#define MGPIO_u8_PORTB	1
#define MGPIO_u8_PORTC	2

#define MGPIO_INPUT_ANLOG               0b0000
#define MGPIO_INPUT_FLOATING            0b0100
#define MGPIO_INPUT_PULLUP_PULLDOWN     0b1000

//For Speed 10
#define MGPIO_OUTPUT_SPEED_10MHZ_PP     0b0001
#define MGPIO_OUTPUT_SPEED_10MHZ_OD     0b0101
#define MGPIO_OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define MGPIO_OUTPUT_SPEED_10MHZ_AFOD   0b1101

//For Speed 2
#define MGPIO_OUTPUT_SPEED_2MHZ_PP      0b0010
#define MGPIO_OUTPUT_SPEED_2MHZ_OD      0b0110
#define MGPIO_OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define MGPIO_OUTPUT_SPEED_2MHZ_AFOD    0b1110

//For Speed 2
#define MGPIO_OUTPUT_SPEED_50MHZ_PP     0b0011
#define MGPIO_OUTPUT_SPEED_50MHZ_OD     0b0111
#define MGPIO_OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define MGPIO_OUTPUT_SPEED_50MHZ_AFOD   0b1111

#define MGPIO_u8_PIN0		0
#define MGPIO_u8_PIN1		1
#define MGPIO_u8_PIN2		2
#define MGPIO_u8_PIN3		3
#define MGPIO_u8_PIN4		4
#define MGPIO_u8_PIN5		5
#define MGPIO_u8_PIN6		6
#define MGPIO_u8_PIN7		7
#define MGPIO_u8_PIN8		8
#define MGPIO_u8_PIN9		9
#define MGPIO_u8_PIN10		10
#define MGPIO_u8_PIN11		11
#define MGPIO_u8_PIN12		12
#define MGPIO_u8_PIN13		13
#define MGPIO_u8_PIN14		14
#define MGPIO_u8_PIN15		15

#define MGPIO_u8_HIGH	1
#define MGPIO_u8_LOW	0

#define MGPIO_u8_LOW_PORT_VALUE      0xFF
#define MGPIO_u16_HIGH_PORT_VALUE    0xFF00


error_status MGPIO_enumSetPinValue   ( u8 Copy_u8Port , u8 Copy_u8Pin      , u8    Copy_u8Value );

error_status MGPIO_enumGetPinValue   ( u8 Copy_u8Port , u8 Copy_u8Pin      , u8  * Copy_ptrData );

error_status MGPIO_enumSetPortValue  ( u8 Copy_u8Port , u8 Copy_u8Position , u16   Copy_u8Value );
error_status MGPIO_enumGetPortValue  ( u8 Copy_u8Port , u8 Copy_u8Position , u16 * Copy_ptrData );


#endif /* MGPIO_INTERFACE_H_ */
