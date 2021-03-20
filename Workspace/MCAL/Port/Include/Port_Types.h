/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_Types.h
 *       Module:  Port 
 *
 *  Description:  DIO Driver  
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


typedef uint8 Port_PinModeType;
typedef uint8 Port_StatusType;

typedef enum
{
  Port_A,
  Port_B,
  Port_C,
  Port_D,
  Port_E,
  Port_F
}Port_PortType;

typedef enum
{
  Port_Pin_A0 = 0,
  Port_Pin_A1,
  Port_Pin_A2,
  Port_Pin_A3,
  Port_Pin_A4,
  Port_Pin_A5,
  Port_Pin_A6,
  Port_Pin_A7,
  Port_Pin_B0,
  Port_Pin_B1,
  Port_Pin_B2,
  Port_Pin_B3,
  Port_Pin_B4,
  Port_Pin_B5,
  Port_Pin_B6,
  Port_Pin_B7,
  Port_Pin_C0,
  Port_Pin_C1,
  Port_Pin_C2,
  Port_Pin_C3,
  Port_Pin_C4,
  Port_Pin_C5,
  Port_Pin_C6,
  Port_Pin_C7,
  Port_Pin_D0,
  Port_Pin_D1,
  Port_Pin_D2,
  Port_Pin_D3,
  Port_Pin_D4,
  Port_Pin_D5,
  Port_Pin_D6,
  Port_Pin_D7,
  Port_Pin_E0,
  Port_Pin_E1,
  Port_Pin_E2,
  Port_Pin_E3,
  Port_Pin_E4,
  Port_Pin_E5,
  Port_Pin_F0 = 40,
  Port_Pin_F1,
  Port_Pin_F2,
  Port_Pin_F3,
  Port_Pin_F4
}Port_PinType;


typedef enum 
{
  Port_PinLevel_Low,
  Port_PinLevel_High,
  Port_PinLevel_NA                /*Must be chosen for Input Pin*/	
}Port_PinLevelValueType;

typedef enum 
{
   Port_PinInput,
   Port_PinOutput
}Port_PinDirectionType;


typedef enum 
{
    Port_PinInternalAttach_OpenDrain,  /*Must be choosen when the Pin is Output*/
    Port_PinInternalAttach_PullUpRes,
    Port_PinInternalAttach_PullDownRes,
    Port_PinInternalAttach_Default      /*Must be choosen when the Pin is Output*/
}Port_PinInternalAttachType;

typedef enum
{
	Port_PinOutputCurrent_2mA = 0,
	Port_PinOutputCurrent_4mA,
	Port_PinOutputCurrent_8mA,
  Port_PinOutputCurrent_Default /*Must be choosen when the Pin is Input*/
}Port_PinOutputCurrentType;

typedef struct
{
	  Port_PinType                   Port_PinNum                ;
    Port_PinModeType               Port_PinMode               ;
    Port_PinLevelValueType         Port_PinDefaultLevelValue  ;
    Port_PinDirectionType          Port_PinDirection          ;
    Port_PinInternalAttachType     Port_PinInternalAttach     ;
    Port_PinOutputCurrentType      Port_PinOutputCurrent      ;
}Port_CfgStrType;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/