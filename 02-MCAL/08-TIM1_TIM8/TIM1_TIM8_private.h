/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	4 April 2021										*/
/************************************************************************/
#ifndef TIM1_TIM8_PRIVATE_H
#define TIM1_TIM8_PRIVATE_H


/* Base address of TIM1 = 0x40012C00 */
/* Base address of TIM8 = 0x40013400 */
typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RCR;
	volatile u32 CCR1;
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 BDTR;
	volatile u32 DCR;
	volatile u32 DMAR;
}TIMER_t;

/* Pointer to struct of Register of TIMER 1 */
#define TIM1    ( (TIMER_t *)0x40012C00 )
/* Pointer to struct of Register of TIMER 8 */
#define TIM8    ( (TIMER_t *)0x40013400 )


#endif