/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Adc_PBcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Adc_Cfg.h"
#include "Adc_HW.h"
#include "Adc_Cbk.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
Adc_ChannelGroupRamDataType Adc_ChannelGroupRamData[ADC_CFG_ADC_GROUP_MAX];

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Adc_GroupConfigType Adc_GroupConfig[ADC_CFG_ADC_GROUP_MAX] = 
{
   {  
      ADC_CFG_ADC_GROUP_0        , /* AdcGroupId            */
      ADC_CFG_GROUP0_CHANNEL_NUM , /*CahnnelNum*/
      ADC_SS_PRI_0               , /* AdcGroupPriority      */
      ADC_TRIGG_SRC_SW           , /* AdcGroupTriggSrc      */
      ADC_CONV_MODE_ONESHOT      , /* AdcGroupConversionMode*/
      &vidAdcGroup0Notify        , /* AdcNotification       */
      ADC_STREAM_BUFFER_LINEAR   , /* AdcStreamingBufferMode*/
      1                            /* AdcStreamingNumSamples*/
    }
    ,{  
      ADC_CFG_ADC_GROUP_1        , /* AdcGroupId            */
      ADC_CFG_GROUP0_CHANNEL_NUM , /*CahnnelNum*/
      ADC_SS_PRI_1               , /* AdcGroupPriority      */
      ADC_TRIGG_SRC_SW           , /* AdcGroupTriggSrc      */
      ADC_CONV_MODE_ONESHOT      , /* AdcGroupConversionMode*/
      &vidAdcGroup1Notify        , /* AdcNotification       */
      ADC_STREAM_BUFFER_LINEAR   , /* AdcStreamingBufferMode*/
      1                            /* AdcStreamingNumSamples*/
    }
};
/*Constrain Group 0 channels shall be listed then Group 1 channels*/
const Adc_ChannelType AdcChannelCfg [ADC_CFG_CHANNEL_MAX] =      
{
  ADC_GROUP0_CHANNEL_0   
  ,ADC_GROUP1_CHANNEL_0  
};

const Adc_ConfigType Adc_Configuration[] = 
{
 &Adc_GroupConfig[0]
 ,&AdcChannelCfg[0]
 ,&Adc_ChannelGroupRamData[0]
};

/*********************************************************************************************************************/
/*  END OF FILE:                                                                                              */
/*********************************************************************************************************************/