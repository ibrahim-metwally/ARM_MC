/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Types.h
 *       Module:  Gpt 
 *
 *  Description:  Gpt Driver  
 *  
 *********************************************************************************************************************/
#ifndef Gpt_TYPES_H
#define Gpt_TYPES_H

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
typedef uint8 Gpt_StatusType;

typedef void (*tfvoidCbkFunc) (void);

typedef uint8 Gpt_ChannelType    ;
typedef uint32 Gpt_ValueType     ;
typedef uint8 Gpt_ModeType       ;
typedef uint8 Gpt_PredefTimerType;
typedef uint8 Gpt_TimerStatusType;
/**/
typedef struct
{
  Gpt_ChannelType GptChannelId;
  uint8 GptGptChannelTickFrequency;
  uint64 GptChannelTickValueMax;
  Gpt_ModeType ChannelMode;
  tfvoidCbkFunc GptNotification;
}Gpt_ChannelConfigType;
/**/
typedef struct
{
  Gpt_TimerStatusType GptTimerStatus;
  boolean NotifyStatus;
}Gpt_ChannelRamDataType;
/**/
typedef struct
{
   Gpt_ChannelConfigType* Gpt_ChannelConfig;
   Gpt_ChannelRamDataType* Gpt_ChannelRamDataType;
}Gpt_ConfigType;
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