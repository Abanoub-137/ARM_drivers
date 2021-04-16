

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MGPIO_private.h"
#include "MGPIO_config.h"

error_status MGPIO_enumSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value ){

	error_status LOC_enumStatus = OK ;

	if( ( Copy_u8Port < 3 ) && ( Copy_u8Pin < 16 ) ){

		switch( Copy_u8Port ){

		case MGPIO_u8_PORTA :

			/* Set   The Specified Pin Of GPIOA Passing To This Function To High */
			if      ( Copy_u8Value == MGPIO_u8_HIGH ){ SET_BIT( MGPIOA_ODR , Copy_u8Pin ); }
			/* Clear The Specified Pin Of GPIOA Passing To This Function To LOW */
			else if ( Copy_u8Value == MGPIO_u8_LOW  ){ CLR_BIT( MGPIOA_ODR , Copy_u8Pin ); }

			break;

		case MGPIO_u8_PORTB :

			/* Set   The Specified Pin Of GPIOB Passing To This Function To High */
			if      ( Copy_u8Value == MGPIO_u8_HIGH ){ SET_BIT( MGPIOB_ODR , Copy_u8Pin ); }
			/* Clear The Specified Pin Of GPIOB Passing To This Function To LOW */
			else if ( Copy_u8Value == MGPIO_u8_LOW  ){ CLR_BIT( MGPIOB_ODR , Copy_u8Pin ); }

			break;

		case MGPIO_u8_PORTC :

			/* Set   The Specified Pin Of GPIOC Passing To This Function To High */
			if      ( Copy_u8Value == MGPIO_u8_HIGH ){ SET_BIT( MGPIOC_ODR , Copy_u8Pin ); }
			/* Clear The Specified Pin Of GPIOC Passing To This Function To LOW */
			else if ( Copy_u8Value == MGPIO_u8_LOW  ){ CLR_BIT( MGPIOC_ODR , Copy_u8Pin ); }

			break;

		default            : LOC_enumStatus = NOK ; break ;

		}
	}

	else{ LOC_enumStatus = NOK ; }

	return LOC_enumStatus ;

}


error_status MGPIO_enumGetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 * Copy_ptrData ){

	error_status LOC_enumStatus = OK ;

	if( ( Copy_u8Port < 3 ) && ( Copy_u8Pin < 16 ) ){

		switch(Copy_u8Port){

		/* Reading The Digital Value Of A Specified Pin Passing To This Function */
		case MGPIO_u8_PORTA : *Copy_ptrData  = GET_BIT( MGPIOA_IDR , Copy_u8Pin ); break;

		/* Reading The Digital Value Of A Specified Pin Passing To This Function */
		case MGPIO_u8_PORTB : *Copy_ptrData  = GET_BIT( MGPIOB_IDR , Copy_u8Pin ); break;

		/* Reading The Digital Value Of A Specified Pin Passing To This Function */
		case MGPIO_u8_PORTC : *Copy_ptrData  = GET_BIT( MGPIOC_ODR , Copy_u8Pin ); break;

		default             : LOC_enumStatus = NOK ;                               break;

		}

	}

	else { LOC_enumStatus = NOK ; }


	return LOC_enumStatus ;

}


error_status MGPIO_enumSetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 Copy_u8Value ){

	error_status LOC_enumStatus = OK ;

	if( Copy_u8Port < 3  ){

		switch( Copy_u8Port ){

		case MGPIO_u8_PORTA:

			/* Set   GPIOA LOW PORT With The Specified Value Passing To This Function */
			if      ( Copy_u8Position == MGPIO_u8_LOW  ){ MGPIOA_ODR = (MGPIOA_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
			/* Set   GPIOA HIGH PORT With The Specified Value Passing To This Function */
			else if ( Copy_u8Position == MGPIO_u8_HIGH ){ MGPIOA_ODR = (MGPIOA_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

			break;

		case MGPIO_u8_PORTB:

			/* Set   GPIOB LOW  PORT With The Specified Value Passing To This Function */
			if      ( Copy_u8Position == MGPIO_u8_LOW  ){ MGPIOB_ODR = (MGPIOB_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
			/* Set   GPIOB HIGH PORT With The Specified Value Passing To This Function */
			else if ( Copy_u8Position == MGPIO_u8_HIGH ){ MGPIOB_ODR = (MGPIOB_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

			break;

		case MGPIO_u8_PORTC:

			/* Set   GPIOC LOW PORT With The Specified Value Passing To This Function */
			if      ( Copy_u8Position == MGPIO_u8_LOW  ){ MGPIOC_ODR = (MGPIOC_ODR & 0xFF00 ) | ( (u8)Copy_u8Value ) ; }
			/* Set   GPIOC HIGH PORT With The Specified Value Passing To This Function */
			else if ( Copy_u8Position == MGPIO_u8_HIGH ){ MGPIOC_ODR = (MGPIOC_ODR & 0x00FF ) | (     Copy_u8Value ) ; }

			break;

		default            : LOC_enumStatus = NOK ;

		}

	}

	else { LOC_enumStatus = NOK ; }

	return LOC_enumStatus ;

}

error_status MGPIO_enumGetPortValue( u8 Copy_u8Port , u8 Copy_u8Position , u16 * Copy_ptrData ){

	error_status LOC_enumStatus = OK ;

	if( Copy_u8Port < 3  ){

		switch( Copy_u8Port ){

		case MGPIO_u8_PORTA:

			/* Reading The Digital Value Of A Specified Port Passing To This Function */
			*Copy_ptrData = MGPIOA_IDR;
			if      ( Copy_u8Position == MGPIO_u8_LOW  ){ *Copy_ptrData &= 0x00FF ; }
			else if ( Copy_u8Position == MGPIO_u8_HIGH ){ *Copy_ptrData &= 0xFF00 ; }

			break;

		case MGPIO_u8_PORTB:

			/* Reading The Digital Value Of A Specified Port Passing To This Function */
			*Copy_ptrData = MGPIOB_IDR;
			if      ( Copy_u8Position == MGPIO_u8_LOW  ){ *Copy_ptrData &= 0x00FF ; }
			else if ( Copy_u8Position == MGPIO_u8_HIGH ){ *Copy_ptrData &= 0xFF00 ; }

			break;

		case MGPIO_u8_PORTC:

			/* Reading The Digital Value Of A Specified Port Passing To This Function */
			*Copy_ptrData = MGPIOC_IDR;
			if      ( Copy_u8Position == MGPIO_u8_LOW  ){ *Copy_ptrData &= 0x00FF ; }
			else if ( Copy_u8Position == MGPIO_u8_HIGH ){ *Copy_ptrData &= 0xFF00 ; }

			break;

		default            : LOC_enumStatus = NOK ;

		}

	}

	else { LOC_enumStatus = NOK ; }

	return LOC_enumStatus ;

}
