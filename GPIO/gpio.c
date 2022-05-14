/*******************************************************************************
 *                               Includes                                      *
 *******************************************************************************/
#include"gpio.h"
#include<avr/io.h>
#include"common_macros.h"

/*******************************************************************************
 *                               Global Variabls                               *
 *******************************************************************************/
/*******************************************************************************
 *                               Function Difinitions                           *
 *******************************************************************************/
/*
 * [Function name]: Setup Pin direction.
 * [Description] :
 *	Setup the direction of the required pin input/output.
 * 	If the input port number or pin number are not correct, The function will not handle the request.
 * [Args]:
 *	[In]:
 *		1.port number. 2.pin number. 3.pin direction.
 *	[Out]: null. 
 *		
 *	[Return]: void.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction)
{
	if(port_num>NUM_OF_PORTS||pin_num>NUM_OF_PIN_PER_PORT)
	{
		/*The user entered invalid port number or pin number*/
		/*Do nothing*/
	}
	else
	{	/*Setup pin direction*/
		switch(port_num)
		{
			case PORTA_ID:
				if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRA,pin_num);
				}
				else if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRA,pin_num);
				}
			break;

			case PORTB_ID:
				if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRB,pin_num);
				}
				else if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRB,pin_num);
				}
			break;

			case PORTC_ID:
				if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRC,pin_num);
				}
				else if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRC,pin_num);
				}
			break;

			case PORTD_ID:
				if(direction==PIN_OUTPUT)
				{
					SET_BIT(DDRD,pin_num);
				}
				else if(direction==PIN_INPUT)
				{
					CLEAR_BIT(DDRD,pin_num);
				}
			break;
		}
	}
}

/*
 * [Function Name]: Write on pin.
 * [Description]:
 * 	Write the value Logic High or Logic Low on the required pin.
 * 	If the input port number or pin number are not correct, The function will not handle the request.
 * 	If the pin is input, this function will enable/disable the internal pull-up resistor.
 *[Args]
 *	[IN]:	1.Port Number. 2.Pin Number. 3. Value.
 *	[Out]:void.
 *	[Returns]:void
 *
 */
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value)
{
	if(port_num>NUM_OF_PORTS||pin_num>NUM_OF_PIN_PER_PORT)
	{
		/*Invalid port number or pin number*/
		/*Do nothing*/
	}
	else
	{
		switch(port_num)
		{
			case PORTA_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTA,pin_num);
				}
				else if(value == LOGIC_LOW)
				{
					CLEAR_BIT(PORTA,pin_num);
				}
			break;

			case PORTB_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTB,pin_num);
				}
				else if(value == LOGIC_LOW)
				{
					CLEAR_BIT(PORTB,pin_num);
				}
			break;

			case PORTC_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTC,pin_num);
				}
				else if(value == LOGIC_LOW)
				{
					CLEAR_BIT(PORTC,pin_num);
				}
			break;

			case PORTD_ID:
				if(value == LOGIC_HIGH)
				{
					SET_BIT(PORTD,pin_num);
				}
				else if(value == LOGIC_LOW)
				{
					CLEAR_BIT(PORTD,pin_num);
				}
			break;


		}
	}
}

/*
 *[Function Name]: readPin. 
 *
 *[Description] :
 * 	Read and return the value for the required pin, it should be Logic High or Logic Low.
 * 	If the input port number or pin number are not correct, The function will return Logic Low.
 *
 *[Args]:
 *	[in]:	1. port number.	2.pin number.
 * 	[out]:void
 *	[returns]:uint8_pinValue.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	if(port_num>NUM_OF_PORTS||pin_num>NUM_OF_PIN_PER_PORT)
	{
		/*Invalid pin number or port number*/
		/*Do Nothing*/
	}
	else
	{
		uint8 GPIO_pinValue=-1;
		switch(port_num)
		{
			case PORTA_ID:
				if(BIT_IS_SET(PINA,pin_num))
				{
					GPIO_pinValue=1;
				}
				else
				{
					GPIO_pinValue=0;
				}
			break;

			case PORTB_ID:
				if(BIT_IS_SET(PINB,pin_num))
				{
					GPIO_pinValue=1;
				}
				else
				{
					GPIO_pinValue=0;
				}
			break;

			case PORTC_ID:
				if(BIT_IS_SET(PINC,pin_num))
				{
					GPIO_pinValue=1;
				}
				else
				{
					GPIO_pinValue=0;
				}
			break;

			case PORTD_ID:
				if(BIT_IS_SET(PINC,pin_num))
				{
					GPIO_pinValue=1;
				}
				else
				{
					GPIO_pinValue=0;
				}
			break;
		}
		return GPIO_pinValue;
	}
	return 0;
}


/*
 *[Function Name]: setupPortDirection
 *[Description] :
 * Setup the direction of the required port all pins input/output.
 * If the direction value is PORT_INPUT all pins in this port should be input pins.
 * If the direction value is PORT_OUTPUT all pins in this port should be output pins.
 * If the input port number is not correct, The function will not handle the request.
 *[Args]:
 *	[in]:	1. Port Number. 2.Direction.
 *	[out]:null.
 *	[returns]:void
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction)
{
	if(port_num>NUM_OF_PORTS)
	{
		/*Invalid pin number or port number*/
		/*Do Nothing*/
	}
	else
	{
		switch(port_num)
		{
			case PORTA_ID:
				DDRA=direction;
			break;

			case PORTB_ID:
				DDRB=direction;
			break;

			case PORTC_ID:
				DDRC=direction;
			break;

			case PORTD_ID:
				DDRD=direction;
			break;
		}
	}
}

/*
 *[Function Name]: writePort.
 *[Description] :
 * Write the value on the required port.
 * If any pin in the port is output pin the value will be written.
 * If any pin in the port is input pin this will activate/deactivate the internal pull-up resistor.
 * If the input port number is not correct, The function will not handle the request.
 *
 *[Args]:
 *	[in]: 1. Port number. 2. Value.
 *	[out]:null
 *	[returns]:void
 */
void GPIO_writePort(uint8 port_num, uint8 value)
{
	if(port_num>NUM_OF_PORTS)
	{
		/*Invalid pin number or port number*/
		/*Do Nothing*/
	}
	else
	{
		switch(port_num)
		{
			case PORTA_ID:
				PORTA=value;
			break;

			case PORTB_ID:
				PORTB=value;
			break;

			case PORTC_ID:
				PORTC=value;
			break;

			case PORTD_ID:
				PORTD=value;
			break;
		}
	}
}

/*
 *[Function Name]: readPort.
 *[Description] :
 * Read and return the value of the required port.
 * If the input port number is not correct, The function will return ZERO value.
 *[Args]:
 *	[in]: port number.
 *	[out]: null.
 *	[returns]: void.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	if(port_num>NUM_OF_PORTS)
	{
		/*Invalid pin number or port number*/
		/*Do Nothing*/
	}
	else
	{
		switch(port_num)
		{
			case PORTA_ID:
				return PINA;
			break;

			case PORTB_ID:
				return PINB;
			break;

			case PORTC_ID:
				return PINC;
			break;

			case PORTD_ID:
				return PIND;
			break;
		}
	}
	return 0;
}
