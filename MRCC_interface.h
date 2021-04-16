
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


#define MRCC_AHB       0 
#define MRCC_APB1      1
#define MRCC_APB2      2

/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For APB1 Bus               */
/*                              0-DMA1                                */
/*                              1-DMA2                                */
/*                              2-SRAM                                */
/*                              3-FLITF                               */
/*                              4-CRC                                 */
/*                              5-FSMC                                */
/*                              6-SDIO                                */
/*                                                                    */
/**********************************************************************/


#define    MRCC_DMA1         0
#define    MRCC_DMA2         1
#define    MRCC_SRAM         2
#define    MRCC_FLITF        4
#define    MRCC_CRC          6
#define    MRCC_FSMC         8
#define    MRCC_SDIO         10



/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For APB2 Bus               */
/*                              0-AFIO                                */
/*                              1-RESERVED                            */
/*                              2-GPIOA                               */
/*                              3-GPIOB                               */
/*                              4-GPIOC                               */
/*                              5-GPIOD                               */
/*                              6-GPIOE                               */
/*                              7-GPIOF                               */
/*                              8-GPIOG                               */
/*                              9-ADC1                                */
/*                              10-ADC2                               */
/*                              11-TIM1                               */
/*                              12-SPI1                               */
/*                              13-TIM8                               */
/*                              14-USART1                             */
/*                              15-ADC3                               */
/*                              16-RESERVED                           */
/*                              17-RESERVED                           */
/*                              18-RESERVED                           */
/*                              19-TIM9                               */
/*                              20-TIM10                              */
/*                              21-TIM11                              */
/*                                                                    */
/**********************************************************************/




#define    MRCC_AFIO         0
#define    MRCC_GPIOA        2
#define    MRCC_GPIOB        3
#define    MRCC_GPIOC        4
#define    MRCC_GPIOD        5
#define    MRCC_GPIOE        6
#define    MRCC_GPIOF        7
#define    MRCC_GPIOG        8
#define    MRCC_ADC1         9
#define    MRCC_ADC2         10
#define    MRCC_TIM1         11
#define    MRCC_SPI1         12
#define    MRCC_TIM8         13
#define    MRCC_USART1       14
#define    MRCC_ADC3         15
#define    MRCC_TIM9         19
#define    MRCC_TIM10        20
#define    MRCC_TIM11        21



/**********************************************************************/
/*                                                                    */
/*                 Peripheral Clock Enable For APB1 Bus               */
/*                              0-TIM2                                */
/*                              1-TIM3                                */
/*                              2-TIM4                                */
/*                              3-TIM5                                */
/*                              4-TIM6                                */
/*                              5-TIM7                                */
/*                              6-TIM12                               */
/*                              7-TIM13                               */
/*                              8-TIM14                               */
/*                              9-RESERVED                            */
/*                              10-RESERVED                           */
/*                              11-WWDG                               */
/*                              12-RESERVED                           */
/*                              13-RESERVED                           */
/*                              14-SPI2                               */
/*                              15-SPI3                               */
/*                              16-RESERVED                           */
/*                              17-USART2                             */
/*                              18-USART3                             */
/*                              19-UART4                              */
/*                              20-UART5                              */
/*                              21-I2C1                               */
/*                              22-I2C2                               */
/*                              23-USB                                */
/*                              24-RESERVED                           */
/*                              25-CAN                                */
/*                              26-RESERVED                           */
/*                              27-BKP                                */
/*                              28-PWR                                */
/*                              29-DAC                                */
/*                                                                    */
/**********************************************************************/




#define    MRCC_TIM2         0
#define    MRCC_TIM3         1
#define    MRCC_TIM4         2
#define    MRCC_TIM5         3
#define    MRCC_TIM6         4
#define    MRCC_TIM7         5
#define    MRCC_TIM12        6
#define    MRCC_TIM13        7
#define    MRCC_TIM14        8
#define    MRCC_WWDG         11
#define    MRCC_SPI2         14
#define    MRCC_SPI3         15
#define    MRCC_USART2       17
#define    MRCC_USART3       18
#define    MRCC_UART4        19
#define    MRCC_UART5        20
#define    MRCC_I2C1         21
#define    MRCC_I2C2         22
#define    MRCC_USB          23
#define    MRCC_CAN          25
#define    MRCC_BKP          27
#define    MRCC_PWR          28
#define    MRCC_DAC          29


error_status MRCC_enumInitSysClock    ( void );
error_status MRCC_enumEnablePerClock  ( u8 Copy_u8BusId , u8 Copy_u8PerId );
error_status MRCC_enumDisablePerClock ( u8 Copy_u8BusId , u8 Copy_u8PerId );


#endif
