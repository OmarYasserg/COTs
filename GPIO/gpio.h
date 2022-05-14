#ifndef GPIO_H
#define GPIO_H


/*******************************************************************************
 *                                INCLUES                                       *
 *******************************************************************************/
/*Include common header files*/
#include "std_types.h"
#include "common_macros.h"


/*******************************************************************************
 *                    DIFINITIONS & STATIC CONFIGURATIONS                      *
 *******************************************************************************/
#define NUM_OF_PORTS        4
#define NUM_OF_PIN_PER_PORT 8


/*******************************************************************************
 *                       	Type Declaration			                      *
 *******************************************************************************/
/* --------------------------------------------------------------------------------------------
[Enum Name]:gpio pins.
[Enum Description]:
This enum is responsible for maintaining information about the available pins
--------------------------------------------------------------------------------------------*/
enum {PIN0_ID,PIN1_ID,PIN2_ID,PIN3_ID,PIN4_ID,PIN5_ID,PIN6_ID,PIN7_ID};

/* --------------------------------------------------------------------------------------------
[Enum Name]:gpio ports.
[Enum Description]:
This enum is responsible for maintaining information about the available ports
--------------------------------------------------------------------------------------------*/
enum {PORTA_ID,PORTB_ID, PORTC_ID,PORTD_ID};

/* --------------------------------------------------------------------------------------------
[Enum Name]:Pin direction type.
[Enum Description]:
This enum is responsible for maintaining information about the port direction type
--------------------------------------------------------------------------------------------*/
typedef enum {
	PORT_INPUT,PORT_OUTPUT=0xff 
}GPIO_portDirectionType;

/* --------------------------------------------------------------------------------------------
[Enum Name]:Pin direction type.
[Enum Description]:
This enum is responsible for maintaining information about the pin direction type
--------------------------------------------------------------------------------------------*/
typedef enum {
	PIN_INPUT,PIN_OUTPUT
}GPIO_pinDirectionType;


/*******************************************************************************
 *                        	FUNCTIONS LIKE MACTOS	 	                       *
 *******************************************************************************/

/*******************************************************************************
 *                       PUBLIC FUNCTION DECLARATIONS	                       *
 *******************************************************************************/
/*
 * Description :
 * Setup the direction of the required pin input/output.
 * If the input port number or pin number are not correct, The function will not handle the request.
 */
void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num, GPIO_PinDirectionType direction);

/*
 *Description:
 * Write the value of the pin for specific port.
 * If the input port number or the pin number are not correct, the function won't handle the request.
 */ 
void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value);

/*
 *Description:
 *Read the pin value for specific port.
 *If the port number or the pin number are not correct, the function won't handle the request.
 */
uint8 GPIO_readPin(uint8 port_num, uint8 pin_num);

/*
 *Description:
 *Setup the direction of the port (OUT_DIRECTION or INPUT_DIRECTION).
 *If the port number is not correct the function won't handle the request.
 */
void GPIO_setupPortDirection(uint8 port_num, uint8 direction);

/*
 *Description:
 *Write a specific value on the whole port.	
 *If the port number is not correct the function won't handle the request.
 */
void GPIO_writePort(uint8 port_num, uint8 value);

/*
 *Description:
 *Read the value of specific port.
 * If the port number is not correct the function won't handle the request.
 */
uint8 GPIO_readPort(uint8 port_num);

#endif