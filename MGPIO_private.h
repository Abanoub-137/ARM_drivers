
#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_

#define MGPIOA_IDR *((volatile u32 *)( 0x40010800 + 0x08 ) )
#define MGPIOA_ODR *((volatile u32 *)( 0x40010800 + 0x0C ) )


#define MGPIOB_IDR *((volatile u32 *)( 0x40010C00 + 0x08 ) )
#define MGPIOB_ODR *((volatile u32 *)( 0x40010C00 + 0x0C ) )


#define MGPIOC_IDR *((volatile u32 *)( 0x40011000 + 0x08 ) )
#define MGPIOC_ODR *((volatile u32 *)( 0x40011000 + 0x0C ) )

#endif /* MGPIO_PRIVATE_H_ */
