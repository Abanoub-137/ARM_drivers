/***********************************************************/
/*** Author  :  Solyma                      ****************/
/*** GPIO_PROGRAM							****************/
/*** Date    : 16/1/2020                    ****************/
/*** Version :  01                          ****************/
/***********************************************************/

#include "A_STD_TYPES.h"
#include "A_BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void GPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8MODE)
{
	switch (copy_u8PORT)
	{
		case GPIOA : 
					if (copy_u8PIN <= 7) // for pins from 0 to 7 we will deal with CRL register
					{
						GPIOA_CRL &= ~ ((0b1111) << (copy_u8PIN *4)); //Reset The Pin (4_bits of the pin) 
						GPIOA_CRL |=   ((copy_u8MODE) << (copy_u8PIN *4)); //setting the pin(4_bits) as its wanted mode
					}
					else if ((copy_u8PIN > 7) && (copy_u8PIN <= 15)) //for pins from 8 to 15
					{
						copy_u8PIN = copy_u8PIN - 8;
						GPIOA_CRH &= ~ ((0b1111) << (copy_u8PIN *4)); //Reset The Pin (4_bits of the pin) 
						GPIOA_CRH |=   ((copy_u8MODE) << (copy_u8PIN *4)); //setting the pin(4_bits) as its wanted mode
						
					}
					break;
		case GPIOB :
					if (copy_u8PIN <= 7) // for pins from 0 to 7 we will deal with CRL register
					{
						GPIOB_CRL &= ~ ((0b1111) << (copy_u8PIN *4)); //Reset The Pin (4_bits of the pin) 
						GPIOB_CRL |=   ((copy_u8MODE) << (copy_u8PIN *4)); //setting the pin(4_bits) as its wanted mode
					}
					else if ((copy_u8PIN > 7) && (copy_u8PIN <= 15)) //for pins from 8 to 15
					{
						copy_u8PIN = copy_u8PIN - 8;
						GPIOB_CRH &= ~ ((0b1111) << (copy_u8PIN *4)); //Reset The Pin (4_bits of the pin) 
						GPIOB_CRH |=   ((copy_u8MODE) << (copy_u8PIN *4)); //setting the pin(4_bits) as its wanted mode
						
					}
					break;
		case GPIOC :  // you can use only 13,14,15 for port C
		            if (copy_u8PIN <= 7) // for pins from 0 to 7 we will deal with CRL register
					{
						GPIOC_CRL &= ~ ((0b1111) << (copy_u8PIN *4)); //Reset The Pin (4_bits of the pin) 
						GPIOC_CRL |=   ((copy_u8MODE) << (copy_u8PIN *4)); //setting the pin(4_bits) as its wanted mode
					}
					else if ((copy_u8PIN > 7) && (copy_u8PIN <= 15)) //for pins from 8 to 15
					{
						copy_u8PIN = copy_u8PIN - 8;
						GPIOC_CRH &= ~ ((0b1111) << (copy_u8PIN *4)); //Reset The Pin (4_bits of the pin) 
						GPIOC_CRH |=   ((copy_u8MODE) << (copy_u8PIN *4)); //setting the pin(4_bits) as its wanted mode
						
					}
					break;
		default: break;
	}
	
}

void GPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8VALUE)
{
	switch(copy_u8PORT)
	{
		case GPIOA :
		            if (copy_u8VALUE == GPIO_HIGH) 
					{
						SET_BIT(GPIOA_ODR,copy_u8PIN);
					}
					else if (copy_u8VALUE == GPIO_LOW) 
					{
						CLR_BIT(GPIOA_ODR,copy_u8PIN);
						
					}
					break;
					
		case GPIOB :
					if (copy_u8VALUE == GPIO_HIGH) 
					{
						SET_BIT(GPIOB_ODR,copy_u8PIN);
					}
					else if (copy_u8VALUE == GPIO_LOW) 
					{
						CLR_BIT(GPIOB_ODR,copy_u8PIN);
						
					}
					break;
		case GPIOC :
					if (copy_u8VALUE == GPIO_HIGH) 
					{
						SET_BIT(GPIOC_ODR,copy_u8PIN);
					}
					else if (copy_u8VALUE == GPIO_LOW) 
					{
						CLR_BIT(GPIOC_ODR,copy_u8PIN);
						
					}
					break;
		default: break;			
	}
}

u8   GPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN )
{
	u8 LOC_u8Result = 0;
	switch (copy_u8PORT)
	{
		case GPIOA :
					LOC_u8Result = GET_BIT(GPIOA_IDR,copy_u8PIN);
					break;
		case GPIOB :
					LOC_u8Result = GET_BIT(GPIOB_IDR,copy_u8PIN);
					break;
		case GPIOC :
					LOC_u8Result = GET_BIT(GPIOC_IDR,copy_u8PIN);
					break;
	    default : break;
		
	}
	return LOC_u8Result;
}

//(4) 
void GPIO_voidSetBit(u8 copy_u8PORT , u8 copy_u8PIN )
{
	
	switch (copy_u8PORT)
	{
		case GPIOA : 
					if ( (PIN0 <=copy_u8PIN) && (copy_u8PIN <= PIN15))
					{
						GPIOA_BSRR = 1 << copy_u8PIN;
					}
					break;
					
		case GPIOB : if ( (PIN0 <=copy_u8PIN) && (copy_u8PIN <= PIN15))
					{
						GPIOB_BSRR = 1 << copy_u8PIN;
					}
					break;
		case GPIOC : 
					 if ( (PIN0 <=copy_u8PIN) && (copy_u8PIN <= PIN15))
					{
						GPIOC_BSRR = 1 << copy_u8PIN;
					}
					break;
		default : break;			
	}
	
}
//(5) 
void GPIO_voidResetBit(u8 copy_u8PORT , u8 copy_u8PIN )
{
	
	switch (copy_u8PORT)
	{
		case GPIOA : 
					if ( (PIN0 <=copy_u8PIN) && (copy_u8PIN <= PIN15))
					{
						GPIOA_BRR = 1 << copy_u8PIN;
					}
					break;
					
		case GPIOB : if ( (PIN0 <=copy_u8PIN) && (copy_u8PIN <= PIN15))
					{
						GPIOB_BRR = 1 << copy_u8PIN;
					}
					break;
		case GPIOC : 
					 if ( (PIN0 <=copy_u8PIN) && (copy_u8PIN <= PIN15))
					{
						GPIOC_BRR = 1 << copy_u8PIN;
					}
					break;
		default : break;			
	}
	
}