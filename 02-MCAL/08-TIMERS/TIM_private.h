/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	4 April 2021										*/
/************************************************************************/
#ifndef TIM_PRIVATE_H
#define TIM_PRIVATE_H


#define TRUE	1
#define FALSE 	0
#define STK_SINGLE_INTERVAL		0
#define STK_PERIODIC_INTERVAL	1


typedef struct
{
	volatile u32 CR1;
	volatile u32 CR2;    // reserved in TIM10-11-13-14
	volatile u32 SMCR;   // this register reserved in TIM6-TIM7 (basic timers)
	volatile u32 DIER; 
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;  // reserved in TIM10-11-13-14
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	
	/* all nest regester not exist in TIM6-TIM7 (basic timers) */
	volatile u32 RCR;    // // this register reserved in TIM2-TIM5 & TIM10-11-13-14 (general perpose) 
	volatile u32 CCR1;
	volatile u32 CCR2;   // reserved in TIM10-11-13-14
	volatile u32 CCR3;   // reserved in TIM10-11-13-14
	volatile u32 CCR4;   // reserved in TIM10-11-13-14
	volatile u32 BDTR;   // // this register reserved in TIM2-TIM5 & TIM10-11-13-14 (general perpose)
	volatile u32 DCR;    // reserved in TIM10-11-13-14
	volatile u32 DMAR;   // reserved in TIM10-11-13-14
}TIMER_t;



/*************************************************************************/
/*					    	general perpose TIMERS						 */
/*************************************************************************/
/* Base address of TIM2 = 0x40000000 */		// APB1
/* Base address of TIM3 = 0x40000400 */		// APB1
/* Base address of TIM4 = 0x40000800 */		// APB1
/* Base address of TIM5 = 0x40000C00 */		// APB1

/* Pointer to struct of Register of TIMER 2 */
#define TIM2    ( (TIMER_t *)0x40000000 )
/* Pointer to struct of Register of TIMER 3 */
#define TIM3    ( (TIMER_t *)0x40000400 )
/* Pointer to struct of Register of TIMER 4 */
#define TIM4    ( (TIMER_t *)0x40000800 )
/* Pointer to struct of Register of TIMER 5 */
#define TIM5    ( (TIMER_t *)0x40000C00 )


/*************************************************************************/
/*							advanced TIMER								 */
/*************************************************************************/
/* Base address of TIM1 = 0x40012C00 */		// APB2

/* Pointer to struct of Register of TIMER 1 */
#define TIM1    ( (TIMER_t *)0x40012C00 )


#endif
