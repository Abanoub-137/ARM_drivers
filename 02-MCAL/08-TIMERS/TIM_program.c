/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	4 April 2021										*/
/************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM_interface.h"
#include "TIM_private.h"
#include "TIM_config.h"



void MTIM2_voidSetBusyWaitMs(u32 Copy_u32MsNumber)
{
	u32 Copy_u32Count;
	/* configer the timer */
	TIM2->PSC = 800-1; 	// prescaler=800 at AHP=8MHz and so APB1=8MHz --> TIM_CLK=10KHZ & T=100us
	TIM2->ARR = 10-1 ;
	/* enable timer 2 */
	TIM2->CNT = 0;
	TIM2->CR1 = 0x1;
	
	/* wait for the timer flag is set */
	for(Copy_u32Count=0 ; Copy_u32Count<Copy_u32MsNumber ; Copy_u32Count++)
	{
		while(! GET_BIT(TIM2->SR , 0) );
		/* clear the flag */
		CLR_BIT(TIM2->SR , 0);
	}
	/* disable the timer */
	TIM2->CR1 = 0;
}    


void MTIM2_voidSetBusyWaitUs(u32 Copy_u32UsNumber)
{
	u32 Copy_u32Count;
	/* configer the timer */
	TIM2->PSC = 8-1; 	// prescaler=8 at AHP=8MHz and so APB1=8MHz --> TIM_CLK=8MHZ & T=1us
	TIM2->ARR = Copy_u32UsNumber-1;    //
	/* enable timer 2 */
	TIM2->CNT = 0;
	TIM2->CR1 = 0x1;
	
	/* wait for the timer flag is set */
	//for(Copy_u32Count=0 ; Copy_u32Count<Copy_u32UsNumber ; Copy_u32Count++)
	{
		while(! GET_BIT(TIM2->SR , 0) );
		/* clear the flag */
		CLR_BIT(TIM2->SR , 0);
	}
	/* disable the timer */
	TIM2->CR1 = 0;
}










void MTIM_voidInit(void)
{

}

void MTIM6_voidSetBusyWait(u32 Copy_32Ticks )
{

}

void MTIM_voidSetIntervalSingle(u32 Copy_32Ticks , void (*Copy_ptr)(void) )
{

}

void MTIM_voidStopInterval(void)
{

}

u32 MTIM_u32GetElapsedTime(void)
{

}

u32 MTIM_u32GetRemainingTime(void)
{

}

u16 MTIM_u16CountEvents(void)
{

}









