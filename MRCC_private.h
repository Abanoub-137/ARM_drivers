
#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

#define MRCC_BASE_ADDRESS 0x40021000

typedef struct{
	
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
	
}RCC_type;

#define MRCC ( ( volatile RCC_type * ) MRCC_BASE_ADDRESS )

/* Clock Types */

#define MRCC_HSE_CRYSTAL 		0
#define MRCC_HSE_RC				1			
#define MRCC_HSI				2	
#define MRCC_PLL				3

/* PLL Options */

#define MRCC_PLL_IN_HSI_DIV_2   0
#define MRCC_PLL_IN_HSE_DIV_2   1
#define MRCC_PLL_IN_HSE         2

#define MRCC_DISABLE_CS         0
#define MRCC_ENABLE_CS          1

#define PLL_MUL_BY_2	0
#define PLL_MUL_BY_3	1
#define PLL_MUL_BY_4	2
#define PLL_MUL_BY_5	3
#define PLL_MUL_BY_6	4
#define PLL_MUL_BY_7	5
#define PLL_MUL_BY_8	6
#define PLL_MUL_BY_9	7
#define PLL_MUL_BY_10	8
#define PLL_MUL_BY_11	9
#define PLL_MUL_BY_12	10
#define PLL_MUL_BY_13	11
#define PLL_MUL_BY_14	12
#define PLL_MUL_BY_15	13
#define PLL_MUL_BY_16	14



#endif
