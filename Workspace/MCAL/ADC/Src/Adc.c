/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Adc.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Adc_HW.h"
#include "Adc.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define ADC_NOT_INITIALIZED          0U
#define ADC_INITIALIZED              1U
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Adc_ConfigType* Adc_CfgPtr = NULL_PTR;
static Adc_StatusType Adc_Status = ADC_NOT_INITIALIZED;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
void Adc_Init ( const Adc_ConfigType * ConfigPtr )
{
  Adc_ValueGroupType AdcGroupId                  ;
  uint8 CahnnelNum                               ;
  Adc_ChannelType AdcChannelId                   ;
  Adc_GroupPriorityType AdcGroupPriority         ;
  Adc_TriggerSourceType AdcGroupTriggSrc         ;
  Adc_GroupConvModeType AdcGroupConversionMode   ;
  tfvoidCbkFunc AdcNotification                  ;
  Adc_StreamBufferModeType AdcStreamingBufferMode;
  Adc_StreamNumSampleType AdcStreamingNumSamples ;

  uint8 ChannelIdx = 0;
  uint8 GroupIdx = 0;

  if (ConfigPtr != NULL_PTR)
  {
    Adc_CfgPtr = ConfigPtr;

   for (GroupIdx = 0; GroupIdx < ADC_CFG_ADC_GROUP_MAX; GroupIdx++)
   {
       Adc_CfgPtr->Adc_ChannelGroupRamData[GroupIdx].Adc_GroupStatus = ADC_IDLE;
       Adc_CfgPtr->Adc_ChannelGroupRamData[GroupIdx].Adc_NotifyStatus = NOTIFY_DISABLE;

       AdcGroupId             = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcGroupId            ;
       CahnnelNum             = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].CahnnelNum            ;
       AdcChannelId           = Adc_CfgPtr->AdcChannelId[ChannelIdx]                          ;
       AdcGroupPriority       = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcGroupPriority      ;
       AdcGroupTriggSrc       = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcGroupTriggSrc      ;
       AdcGroupConversionMode = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcGroupConversionMode;
       AdcNotification        = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcNotification       ;
       AdcStreamingBufferMode = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcStreamingBufferMode;
       AdcStreamingNumSamples = Adc_CfgPtr->Adc_GroupConfig[ChannelIdx].AdcStreamingNumSamples;

/*1-Disable the sample sequencer by clearing the corresponding ASENn bit in the ADCACTSS register */
      ADC_WRITE_REG(REG_ADCACTSS_ADDR(GroupIdx),(uint32)(((uint32)0x00) << ADCACTSS_ASEN0_BIT_SHIFT));
      ADC_WRITE_REG(REG_ADCACTSS_ADDR(GroupIdx),(uint32)(((uint32)0x00) << ADCACTSS_ASEN1_BIT_SHIFT));
      ADC_WRITE_REG(REG_ADCACTSS_ADDR(GroupIdx),(uint32)(((uint32)0x00) << ADCACTSS_ASEN2_BIT_SHIFT));
      ADC_WRITE_REG(REG_ADCACTSS_ADDR(GroupIdx),(uint32)(((uint32)0x00) << ADCACTSS_ASEN3_BIT_SHIFT));
/*2-Configure the trigger event for the sample sequencer in the ADCEMUX register*/
      ADC_WRITE_REG(REG_ADCEMUX_ADDR(GroupIdx),(uint32)(((uint32)ADC_CONV_MODE_ONESHOT) << ADCEMUX_EM0_BIT_SHIFT));
      ADC_WRITE_REG(REG_ADCEMUX_ADDR(GroupIdx),(uint32)(((uint32)ADC_CONV_MODE_ONESHOT) << ADCEMUX_EM1_BIT_SHIFT));
      ADC_WRITE_REG(REG_ADCEMUX_ADDR(GroupIdx),(uint32)(((uint32)ADC_CONV_MODE_ONESHOT) << ADCEMUX_EM2_BIT_SHIFT));
      ADC_WRITE_REG(REG_ADCEMUX_ADDR(GroupIdx),(uint32)(((uint32)ADC_CONV_MODE_ONESHOT) << ADCEMUX_EM3_BIT_SHIFT));
      
      for (ChannelIdx = 0; ChannelIdx < CahnnelNum; ChannelIdx++)
      {

      }

      
   }

    Adc_Status = ADC_INITIALIZED;
  }
  else
  {
     Adc_Status = ADC_NOT_INITIALIZED;
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
Std_ReturnType Adc_SetupResultBuffer ( Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
void Adc_StartGroupConversion ( Adc_GroupType Group )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
void Adc_StopGroupConversion ( Adc_GroupType Group )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
Std_ReturnType Adc_ReadGroup ( Adc_GroupType Group, Adc_ValueGroupType *DataBufferPtr)
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
Adc_StatusType Adc_GetGroupStatus ( Adc_GroupType Group )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
Adc_StreamNumSampleType Adc_GetStreamLastPointer ( Adc_GroupType Group,Adc_ValueGroupType ** PtrToSamplePtr )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
void Adc_EnableGroupNotification ( Adc_GroupType Group )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/******************************************************************************
* \Syntax          :  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   :  
*                                                                   
*******************************************************************************/
void Adc_DisableGroupNotification ( Adc_GroupType Group )
{
  if(Adc_Status == ADC_INITIALIZED)
  {

  }
  else
  {
     /**/
  }
}
/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/