/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt_Cfg.h
 *       Module:  Gpt 
 *
 *  Description:  Gpt Driver  
 *  
 *********************************************************************************************************************/
#ifndef Gpt_CFG_H
#define Gpt_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define Gpt_STANDARAD_INT    0U
#define Gpt_NMI_INT          1U

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
/*GPT Channels*/
#define GPT_CONFIG_CHANNEL_1        ((Gpt_ChannelType)0)
#define GPT_CONFIG_CHANNEL_2        ((Gpt_ChannelType)1)
#define GPT_CONFIG_CHANNEL_3        ((Gpt_ChannelType)2)
#define GPT_CONFIG_CHANNEL_4        ((Gpt_ChannelType)3)
#define GPT_CONFIG_CHANNEL_5        ((Gpt_ChannelType)4)
#define GPT_CONFIG_CHANNEL_6        ((Gpt_ChannelType)5)
#define GPT_CONFIG_CHANNEL_7        ((Gpt_ChannelType)6)
#define GPT_CONFIG_CHANNEL_8        ((Gpt_ChannelType)7)
#define GPT_CONFIG_CHANNEL_9        ((Gpt_ChannelType)8)
#define GPT_CONFIG_CHANNEL_10       ((Gpt_ChannelType)9)
#define GPT_CONFIG_CHANNEL_11       ((Gpt_ChannelType)10)
#define GPT_CONFIG_CHANNEL_12       ((Gpt_ChannelType)11)
/*Channel Mode*/
#define GPT_CH_MODE_CONTINUOUS   0U
#define GPT_CH_MODE_ONESHOT      1U
/*Timer Status*/
#define GPT_CH_NOT_STARTED   0U
#define GPT_CH_RUNNING       1U
#define GPT_CH_STOPPED       2U
#define GPT_CH_EXPIRED       3U
/*GPT Notification Status*/
#define GPT_CH_NOTIFY_DISABLE   0U
#define GPT_CH_NOTIFY_ENABLE    1U
/**/
extern const Gpt_ChannelConfigType Gpt_ChannelConfiguration[];
/**/
extern Gpt_ChannelRamDataType Gpt_ChannelRamData[];
/**/
extern const Gpt_ConfigType Gpt_Configuration[];
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/