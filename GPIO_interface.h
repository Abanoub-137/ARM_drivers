/***********************************************************/
/*** Author  :  Solyma                      ****************/
/*** GPIO_INTERFACE							****************/
/*** Date    : 16/1/2020                    ****************/
/*** Version :  01                          ****************/
/***********************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH  1
#define GPIO_LOW  0

#define GPIOA  0
#define GPIOB  1
#define GPIOC  2

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7 
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15





/* At First we will express the pin for its mode and CNF too*/
//for the the output of 10 MHz
#define OUTPUT_SPEED_10MHZ_PP     0b0001 //Push Pull
#define OUTPUT_SPEED_10MHZ_OD     0b0101 //Open Drain
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001 //Alternative function Push Pull
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101 //Alternative function Open Drain

//for the the output of 2 MHz
#define OUTPUT_SPEED_2MHZ_PP     0b0010
#define OUTPUT_SPEED_2MHZ_OD     0b0110
#define OUTPUT_SPEED_2MHZ_AFPP   0b1010
#define OUTPUT_SPEED_2MHZ_AFOD   0b1110

//for the the output of 50 MHz
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111

/* Second we will express the pins as Input*/
#define INPUT_ANALOG           0b0000
#define INPUT_FLOATING         0b0100
#define INPUT_Pull_UP_DOWN     0b1000  //Pulled Up Or Down
//Input 0b1100 Not Allowed

//(1)
void GPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE);
//(2)
void GPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8VALUE);
//(3)
u8 GPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN );

//(4)this function is used for Setting a bit (Corresponding ODRx Register )
void GPIO_voidSetBit(u8 copy_u8PORT , u8 copy_u8PIN ); //Using BSRR(BitSetResetRegister) 

//(5)
void GPIO_voidResetBit(u8 copy_u8PORT , u8 copy_u8PIN );//Using RBR(BitSetResetRegister)


//locking mode of pin
void GPIO_voidLockPinMode(u8 copy_u8PORT ,u8 copy_u8PIN);//Port configuration lock register (GPIOx_LCKR)




#endif