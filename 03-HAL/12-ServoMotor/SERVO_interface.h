/************************************************************************/
/*	Author		:	Abanoub Kamal                                       */
/* 	Version		:	V01													*/
/*	Date		: 	26 June 2021	 									*/
/************************************************************************/


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_


#define TIM4_CHANNEL_1			0
#define TIM4_CHANNEL_2			1
#define TIM4_CHANNEL_3			2
#define TIM4_CHANNEL_4			3

/***************************************************************************
 * 						HardWare connection
 *
 * 	TIM4 No remap (
 * 					SERVO_CHANNEL_1  -----> TIM4_CHANNEL_1 ( PB6 ),
 * 					SERVO_CHANNEL_2  -----> TIM4_CHANNEL_2 ( PB7 ),
 * 					SERVO_CHANNEL_3  -----> TIM4_CHANNEL_3 ( PB8 ),
 * 					SERVO_CHANNEL_4  -----> TIM4_CHANNEL_4 ( PB9 )
 */


/* Macros */
#define SERVO_CHANNEL_1				TIM4_CHANNEL_1
#define SERVO_CHANNEL_2 			TIM4_CHANNEL_2
#define SERVO_CHANNEL_3 			TIM4_CHANNEL_3
#define SERVO_CHANNEL_4 			TIM4_CHANNEL_4

/***********************************************************************
 * Description: # this function use TIM4 to generate PWM on its channels (we can use 4 Channels)
 * 					to control on servomotor angele
 *				# TIM4 No remap (TIM4_CH1/PB6, TIM4_CH2/PB7, TIM4_CH3/PB8, TIM4_CH4/PB9)
 *
 * Inputs     :	Copy_u8Angle				value		: 0 ~ 180
 *
 * 				Copy_u8Channel				options		: SERVO_CHANNEL_1
 * 														  SERVO_CHANNEL_2
 * 														  SERVO_CHANNEL_3
 * 														  SERVO_CHANNEL_4
 * return     :	void
 * scope      :	public
 **********************************************************************/
void HSERVO_viodSetServoAngle(u8 Copy_u8Angle , u8 Copy_u8Channel );


#endif /* SERVOMOTOR_INTERFACE_H_ */
