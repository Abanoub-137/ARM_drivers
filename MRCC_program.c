
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MRCC_private.h"
#include "MRCC_config.h"

error_status MRCC_enumInitSysClock(void){

	error_status LOC_enumState  = OK ;
	u16          LOC_u32TimeOut = 0  ;

	#if     MRCC_CLOCK_TYPE == MRCC_HSE_CRYSTAL

		/* BIT 1:0 in CFGR reg -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		MRCC -> CFGR = 0x00000001;

		/* Bit 16 in CR reg -> Enable The HSE Clock */
		/* Enable HSE with no bypass */
		MRCC -> CR   = 0x00010000; 

		/* Bit 17 in CR reg -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( MRCC -> CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{ 
			LOC_u32TimeOut++ ; 

			if( LOC_u32TimeOut >= 10000 ){

				/*TimeOut*/ 
				LOC_enumState  = NOK ;
				break                ;

			}
		}

	#elif   MRCC_CLOCK_TYPE == MRCC_HSE_RC

		/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
		/* HSE Clock Disabled */
		MRCC -> CR   = 0x00000001;
		MRCC -> CFGR = 0x00000000;

		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		MRCC -> CFGR = 0x00000001;

		/* BIT 18 in CR reg -> To Select HSE BYPASS */
		/* HSEBYPASS Clock Enable */
		/* Enable HSE with bypass */
		MRCC -> CR   = 0x00050000;

		/* Bit 17 in CR reg -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( MRCC -> CR , 17 ) ) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{ 
			LOC_u32TimeOut++ ; 

			if( LOC_u32TimeOut >= 10000 ){

				/*TimeOut*/ 
				LOC_enumState  = NOK ;
				break                ;

			}
		}

	#elif   MRCC_CLOCK_TYPE == MRCC_HSI
	
		/* BIT 1:0 in CFGR reg -> Choose Between HSI OR HSE OR PLL */
		/* HSI Selected As A System Clock */
		MRCC -> CFGR = 0x00000000;

		/* Bit 0 in CR reg -> Enable The HSI Clock */
		/* Enable HSI + Trimming = 0 */
		MRCC -> CR   = 0x00000081; 

		/* Bit 1 in CR reg -> Checking While The HSI Clock Is Stable Or Not */
		while( ( ( GET_BIT( MRCC -> CR , 1 ) ) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{ 
			LOC_u32TimeOut++ ; 

			if( LOC_u32TimeOut >= 10000 ){

				/*TimeOut*/ 
				LOC_enumState  = NOK ;
				break                ;

			}
		}
	
	#elif   MRCC_CLOCK_TYPE == MRCC_PLL
	
		/* Startup Code Enables PLL With Multiplication Factor = 9 To Work With 72MHZ So We Will Switch
		   To Other Clock Source To Allow Us Edit PLL Configuration Because We Can not Do Any Thing While
		   Is Enable */
		MRCC -> CFGR = 0x00000000;
		MRCC -> CR   = 0x00000001;

		/* BIT 1:0 in CFGR reg -> Choose Between HSI OR HSE OR PLL */
		/* PLL Selected As A System Clock */

		MRCC -> CFGR = 0x00000002;

		/* Choosing The Multiplication Factor For PLL */
		#if   ( MRCC_PLL_MUL_VAL >= PLL_MUL_BY_2 ) && ( MRCC_PLL_MUL_VAL <= PLL_MUL_BY_16 )

			MRCC -> CFGR &= ~( ( 0b1111 )         << 18 ) ;
			MRCC -> CFGR |=  ( MRCC_PLL_MUL_VAL ) << 18   ;

		#else

			#warning "Wrong Multiplication Factor For PLL"

		#endif


		#if   MRCC_PLL_INPUT == MRCC_PLL_IN_HSI_DIV_2

			/* BIT 16 in CFGR reg -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSI Divided By 2 */
			CLR_BIT( MRCC -> CFGR , 16 );

		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE_DIV_2

			/* Bit 16 in CR reg -> Enable The HSE Clock */
			SET_BIT( MRCC -> CR   , 16 );

			/* BIT 16 in CFGR reg -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( MRCC -> CFGR , 16 );

			/* BIT 17 in CFGR reg -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Divided By Two */
			SET_BIT( MRCC->CFGR , 17 );

		#elif MRCC_PLL_INPUT == MRCC_PLL_IN_HSE

			/* Bit 16 in CR reg -> Enable The HSE Clock */
			SET_BIT( MRCC -> CR   , 16 );

			/* BIT 16 in CFGR reg -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT( MRCC -> CFGR , 16 );

			/* BIT 17 in CFGR ref -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Not Divided */
			CLR_BIT( MRCC -> CFGR , 17 );

		#else

			#warning "Wrong PLL Clock Configuration"

		#endif

		/* Enable PLL Clock */
		SET_BIT( MRCC->CR , 24 );

		/* Wait Until PLL Ready Flag Set */
		while( ( ( GET_BIT( MRCC->CR , 25 ) ) == 0 ) && ( LOC_u32TimeOut < 10000 ) )
		{ 
	
			LOC_u32TimeOut++; 

			if( LOC_u32TimeOut >= 10000 ){

				/*TimeOut*/ 
				LOC_enumState  = NOK ;
				break                ;

			}

		}
	
	#else

		#error "You chosed Wrong Clock type"

	#endif
	
	#if    MRCC_CS_SYS == MRCC_ENABLE_CS
		/*Enable Clock Security System*/
		SET_BIT( MRCC->CR , 19 );	

	#elif  MRCC_CS_SYS == MRCC_DISABLE_CS
		/*Disable Clock Security System*/
		CLR_BIT( MRCC->CR , 19 );

	#else

		#warning "Wrong Clock Security System Configuration Choice "

	#endif

	return LOC_enumState ;

}

error_status MRCC_enumEnablePerClock  ( u8 Copy_u8BusId , u8 Copy_u8PerId ){

	error_status LOC_enumState = OK ;

	if (Copy_u8PerId <= 31)
	{
		switch (Copy_u8BusId)
		{
			/* Enable The Peripheral That Exist in AHB Bus */
			case     MRCC_AHB  : SET_BIT( MRCC -> AHBENR  , Copy_u8PerId );   break;
			/* Enable The Peripheral That Exist in APB1 Bus */
			case     MRCC_APB1 : SET_BIT( MRCC -> APB1ENR , Copy_u8PerId );   break;
			/* Disable The Peripheral That Exist in APB2 Bus */
			case     MRCC_APB2 : SET_BIT( MRCC -> APB2ENR , Copy_u8PerId );   break;
			/* If The User Passing Wrong BusId The Function Will Return An Error Status  */
			default            : LOC_enumState = NOK                      ;   break;
		}
	}

	else
	{
		/* Return Error */
		LOC_enumState = NOK ;
	}

	return LOC_enumState ;

}

error_status MRCC_enumDisablePerClock ( u8 Copy_u8BusId , u8 Copy_u8PerId ){

	error_status LOC_enumState = OK ;

	if (Copy_u8PerId <= 31)
	{
		switch ( Copy_u8BusId )
		{
			/* Disable The Peripheral That Exist in AHB Bus */
			case     MRCC_AHB  : CLR_BIT( MRCC -> AHBENR  , Copy_u8PerId );   break;
			/* Disable The Peripheral That Exist in APB1 Bus */
			case     MRCC_APB1 : CLR_BIT( MRCC -> APB1ENR , Copy_u8PerId );   break;
			/* Disable The Peripheral That Exist in APB2 Bus */
			case     MRCC_APB2 : CLR_BIT( MRCC -> APB2ENR , Copy_u8PerId );   break;
			/* If The User Passing Wrong BusId The Function Will Return An Error Status  */
			default            : LOC_enumState = NOK                      ;   break;
		}
	}

	else
	{
		/* Return Error */
		LOC_enumState = NOK ;
	}

	return LOC_enumState ;

}
