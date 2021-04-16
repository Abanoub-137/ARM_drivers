
#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_


#define MNVIC_NO_SUB_PRIORITY 0

/////////////////////////
#define MNVIC_PEND_SV        -6
#define MNVIC_SYSTICK        -5
////////////////////////////
#define MNVIC_SV_CALL        -4
/////////////////////////
#define MNVIC_MEMORY_MANAGE  -3
#define MNVIC_BUS_FAULT      -2
#define MNVIC_USAGE_FAULT    -1
/////////////////////////

//GROUP 3
//Priority =  Copy_u8SubPriority | ( Copy_u8GroupPriority << ( (Copy_u8GroupLevels - 0x05FA0300) / 256 ) ) ;

//u8 Priority   = ( Copy_u8SubPriority | (Copy_u8GroupPriority << 4) )  ;
// 0x100 Hex  ---> 256 Decimal
#define MNVIC_GROUP_4_SUB_0     0x05FA0300//0 bit for sub & 4 bit For group   << 0
#define MNVIC_GROUP_3_SUB_1     0x05FA0400//1 bit for sub & 3 bit For group   << 1
#define MNVIC_GROUP_2_SUB_2     0x05FA0500//2 bit for sub & 2 bit For group   << 2
#define MNVIC_GROUP_1_SUB_3     0x05FA0600//3 bit for sub & 1 bit For group   << 3
#define MNVIC_GROUP_0_SUB_4     0x05FA0700//4 bit for sub & 0 bit For group   << 4

////////////////////////

//#define For Interrupt ID =  POsition In Vector Table
#define 	 MNVIC_WWDG             0

#define 	 MNVIC_EXTI0            6
#define 	 MNVIC_EXTI1            7
#define 	 MNVIC_EXTI2            8
#define		 MNVIC_EXTI3			9
#define		 MNVIC_EXTI4			10
#define		 MNVIC_EXTI9_5			23
#define		 MNVIC_EXTI15_10	    40

#define      MNVIC_DMA              11

#define      MNVIC_USART1           37
/////////////////////////

void MNVIC_voidInit              (void);

void MNVIC_voidEnablePeripheral  ( u8 Copy_u8INTID );

void MNVIC_voidDisablePeripheral ( u8 Copy_u8INTID );

void MNVIC_voidSetPending        ( u8 Copy_u8INTID );

void MNVIC_voidClearPending      ( u8 Copy_u8INTID );

u8   MNVIC_u8GetActive           ( u8 Copy_u8INTID );

void MNVIC_voidSetPriority( s8 Copy_u8PeripheralID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u8GroupLevels );


#endif /* MNVIC_INTERFACE_H_ */
