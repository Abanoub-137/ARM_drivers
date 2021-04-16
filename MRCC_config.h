
#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_


/* Options:    MRCC_HSE_CRYSTAL
               MRCC_HSE_RC
               MRCC_HSI
               MRCC_PLL			   */

#define MRCC_CLOCK_TYPE 	MRCC_HSE_CRYSTAL

/* Options:    MRCC_PLL_IN_HSI_DIV_2
               MRCC_PLL_IN_HSE_DIV_2
			   MRCC_PLL_IN_HSE      */
			   
/* Note: Select value only if you have PLL as input clock source */

#if MRCC_CLOCK_TYPE == MRCC_PLL

	#define MRCC_PLL_INPUT	 MRCC_PLL_IN_HSE

#endif

/* PLL Options:  */

/* Note: Select value only if you have PLL as input clock source */

#if MRCC_CLOCK_TYPE == MRCC_PLL

	#define MRCC_PLL_MUL_VAL   PLL_MUL_BY_9
	
#endif

/* Options:    MRCC_ENABLE_CS
               MRCC_DISABLE_CS      */

#define MRCC_CS_SYS   MRCC_DISABLE_CS



#endif
