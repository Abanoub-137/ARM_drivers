/************************************************************************************/
/*	Author		:	Abanoub Kamal                                       			*/
/* 	Version		:	V01																*/
/*	Date		: 	4 April 2021													*/
/* 	Notes		:	# we use TIM2 for busy wait as timer 6 is 32 bits counter
					# TIM2 & TIM5 is 32 bits counter
					# our calculation is depend on AHB CLK =8MHz and so APB CLK = 8MHz
					# */
/************************************************************************************/
#ifndef TIM_INTERFACE_H
#define TIM_INTERFACE_H



/***********************************************************************
 * Description: synchronous function.
 *				stuck the processor for time equal number of ms.
 *
 * Inputs     :	Copy_u32MsNumber		range		: 1 ~ (2^32)
 *										description : number of ms
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM2_voidSetBusyWaitMs(u32 Copy_u32MsNumber);

/***********************************************************************
 * Description: synchronous function.
 *				stuck the processor for time equal number of us.
 *
 * Inputs     :	Copy_u32UsNumber		range		: 1 ~ (2^32)
 *										description : number of us
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM2_voidSetBusyWaitUs(u32 Copy_u32UsNumber);















/***********************************************************************
 * Description: Apply clock choice from configuration file 
 *				Disable systick interrupt
 *				Disable systick 	
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM_voidInit(void);


/***********************************************************************
 * Description: synchronous function.
 *				stuck the processor for time equal number of ticks 
 *				entered multibly time of one tick.
 *
 * Inputs     :	Copy_32Ticks			range		: 0 ~ (2^24 -1)
 *										description : number of ticks
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM_voidSetBusyWait(u32 Copy_32Ticks );

/***********************************************************************
 * Description: Asynchronous function.
 *				this function take function name to excute it after a time
 *				interval equal (tick time * time of one tick)
 *
 * Inputs     :	Copy_32Ticks				range		: 0 ~ (2^24 -1)
 *											description : number of ticks 
 *				
 * 				void (*Copy_ptr)(void)		value	: function name  
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM_voidSetIntervalSingle(u32 Copy_32Ticks , void (*Copy_ptr)(void) );

/***********************************************************************
 * Description: Asynchronous function.
 *				this function take function name to excute it after a time
 *				interval equal (tick time * time of one tick) and repeat it periodicaly
 *
 * Inputs     :	Copy_32Ticks				range		: 0 ~ (2^24 -1)
 *											description : number of ticks 
 *				
 * 				void (*Copy_ptr)(void)		value	: function name 
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM_voidSetIntervalPeriodic(u32 Copy_32Ticks , void (*Copy_ptr)(void) );

/***********************************************************************
 * Description: this function to stop the timer (SysTick)  
 *				and lock its interrupt
 *				
 * Inputs     :	void
 * return     :	void
 * scope      :	public
 **********************************************************************/
void MTIM_voidStopInterval(void);

/***********************************************************************
 * Description: to fined the time consumed since the timer start counting 
 *				
 * Inputs     :	void
 * return     :	u32
 * scope      :	public
 **********************************************************************/
u32 MTIM_u32GetElapsedTime(void);

/***********************************************************************
 * Description: to find the time remaining till the timer firing interrupt  
 *				and do something
 *				
 * Inputs     :	void
 * return     :	u32
 * scope      :	public
 **********************************************************************/
u32 MTIM_u32GetRemainingTime(void); 



#endif
