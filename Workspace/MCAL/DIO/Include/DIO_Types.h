/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_Types.h
 *       Module:  DIO 
 *
 *  Description:  DIO Driver  
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

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
typedef uint8 Dio_ChannelType  ;
typedef uint8 Dio_PortType     ;
typedef uint8 Dio_LevelType    ;
typedef uint8 Dio_PortLevelType;

typedef struct
{
  uint8 PortIdx;
  uint8 PinIdx;
}Dio_PortChannel;

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