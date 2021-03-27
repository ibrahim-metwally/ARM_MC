/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  Gpt 
 *
 *  Description:  Gpt Driver  
 *  
 *********************************************************************************************************************/
#ifndef Gpt_H
#define Gpt_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*Configuration Set Handle*/
#define GptConfigSet             (&Gpt_ChannelConfiguration[0])
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern void Gpt_Init (const Gpt_ConfigType * ConfigPtr);
extern void Gpt_DisableNotification ( Gpt_ChannelType Channel );
extern void Gpt_EnableNotification ( Gpt_ChannelType Channel );
extern void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value );
extern void Gpt_StopTimer ( Gpt_ChannelType Channel );
extern Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel );
extern Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel );
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/