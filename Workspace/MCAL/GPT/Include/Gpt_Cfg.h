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
/**/
#define GPT_MAX_CONFIG_CHANNEL    1U
/*GPT Channels*/
#define GPT_CHANNEL_1        ((Gpt_ChannelType)0)
#define GPT_CHANNEL_2        ((Gpt_ChannelType)1)
#define GPT_CHANNEL_3        ((Gpt_ChannelType)2)
#define GPT_CHANNEL_4        ((Gpt_ChannelType)3)
#define GPT_CHANNEL_5        ((Gpt_ChannelType)4)
#define GPT_CHANNEL_6        ((Gpt_ChannelType)5)
#define GPT_CHANNEL_7        ((Gpt_ChannelType)6)
#define GPT_CHANNEL_8        ((Gpt_ChannelType)7)
#define GPT_CHANNEL_9        ((Gpt_ChannelType)8)
#define GPT_CHANNEL_10       ((Gpt_ChannelType)9)
#define GPT_CHANNEL_11       ((Gpt_ChannelType)10)
#define GPT_CHANNEL_12       ((Gpt_ChannelType)11)
/**/
#define GPT_CHANNEL_1_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_2_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_3_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_4_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_5_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_6_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_7_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_8_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_9_TICK_FREQ       ((Gpt_ValueType)16)
#define GPT_CHANNEL_10_TICK_FREQ      ((Gpt_ValueType)16)  
#define GPT_CHANNEL_11_TICK_FREQ      ((Gpt_ValueType)16)  
#define GPT_CHANNEL_12_TICK_FREQ      ((Gpt_ValueType)16)  
/**/
#define GPT_CHANNEL_1_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_2_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_3_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_4_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_5_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_6_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_7_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_8_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_9_MAX_TICK       ((Gpt_ValueType)0xFFFFFFFF)
#define GPT_CHANNEL_10_MAX_TICK      ((Gpt_ValueType)0xFFFFFFFF)  
#define GPT_CHANNEL_11_MAX_TICK      ((Gpt_ValueType)0xFFFFFFFF)  
#define GPT_CHANNEL_12_MAX_TICK      ((Gpt_ValueType)0xFFFFFFFF)  
/*Channel Mode*/
#define GPT_CH_MODE_ONESHOT      1U
#define GPT_CH_MODE_CONTINUOUS   2U
/*Timer Status*/
#define GPT_CH_NOT_STARTED       0U
#define GPT_CH_RUNNING           1U
#define GPT_CH_STOPPED           2U
#define GPT_CH_EXPIRED           3U
/*GPT Notification Status*/
#define GPT_CH_NOTIFY_DISABLE    0U
#define GPT_CH_NOTIFY_ENABLE     1U
/**/
extern const Gpt_ChannelConfigType Gpt_ChannelConfiguration[GPT_MAX_CONFIG_CHANNEL];
/**/
extern Gpt_ChannelRamDataType Gpt_ChannelRamData[GPT_MAX_CONFIG_CHANNEL];
/**/
extern const Gpt_ConfigType Gpt_Configuration[GPT_MAX_CONFIG_CHANNEL];
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/