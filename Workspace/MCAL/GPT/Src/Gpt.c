/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt_HW.h"
#include "Gpt.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define Gpt_NOT_INITIALIZED          0
#define Gpt_INITIALIZED              1

#define TIMER_A_DISABLED             0U
#define TIMER_A_ENABLED              1U
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Gpt_ConfigType* Gpt_CfgPtr = NULL_PTR;
static const Gpt_ChannelConfigType* Gpt_ChannelConfigPtr = NULL_PTR;
Gpt_ChannelRamDataType *Gpt_ChannelRamDataPtr;

static Gpt_StatusType Gpt_Status = Gpt_NOT_INITIALIZED;
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
void Gpt_Init (const Gpt_ConfigType * ConfigPtr)
{
  uint8 GptChannelIdx = 0;
  uint32 BaseAddress = 0;
  uint32 RegAddress = 0;
  uint32 *RegPtr = NULL_PTR;
  Gpt_ChannelType GptChannelId;
  Gpt_ValueType GptGptChannelTickFrequency;
  Gpt_ValueType GptChannelTickValueMax;
  Gpt_ModeType ChannelMode;

    if((ConfigPtr != NULL_PTR) || 
    (ConfigPtr->Gpt_ChannelConfig != NULL_PTR) ||
     (ConfigPtr->Gpt_ChannelRamDataType != NULL_PTR))
    {
      Gpt_CfgPtr = ConfigPtr;
      Gpt_ChannelConfigPtr = ConfigPtr->Gpt_ChannelConfig;
      Gpt_ChannelRamDataPtr = ConfigPtr->Gpt_ChannelRamDataType;
                       /*One-Shot/Periodic Timer Mode*/
      for (GptChannelIdx = 0;GptChannelIdx < GPT_MAX_CONFIG_CHANNEL;GptChannelIdx++)
      {
        GptChannelId = Gpt_ChannelConfigPtr[GptChannelIdx].GptChannelId;
        GptGptChannelTickFrequency = Gpt_ChannelConfigPtr[GptChannelIdx].GptGptChannelTickFrequency;
        GptChannelTickValueMax = Gpt_ChannelConfigPtr[GptChannelIdx].GptChannelTickValueMax;
        ChannelMode = Gpt_ChannelConfigPtr[GptChannelIdx].ChannelMode;
        BaseAddress = Gpt_RegBaseAddress[GptChannelIdx];
/*1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes*/
        RegAddress = BaseAddress + REG_GPTMCTL_OFFSET;
        RegPtr = RegAddress;
        *RegPtr |= (uint32)TIMER_A_DISABLED;
 /*2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x0000.0000*/       
        RegAddress = BaseAddress + REG_GPTMCFG_OFFSET;
        RegPtr = RegAddress;
        *RegPtr |= (uint32)0x00000000;
/*3. Configure the TnMR field in the GPTM Timer n Mode Register (GPTMTnMR)*/    
        RegAddress = BaseAddress + REG_GPTMTAMR_OFFSET;
        RegPtr = RegAddress;
        *RegPtr |= (uint32)ChannelMode;
/*4. configure interrupt, and count up or down.*/
        /*GPTM Timer A Count Direction*/
        *RegPtr |= (uint32)(((uint32)GPTM_COUNT_UP) << GPTM_TACDIR_BIT_IDX);
        /*Disable Interrupt*/
        *RegPtr |= (uint32)(((uint32)0) << GPTM_TAMIE_BIT_IDX);
        /**/
        RegAddress = BaseAddress + REG_GPTMIMR_OFFSET;
        RegPtr = RegAddress;
        *RegPtr |= (uint32)(((uint32)0) << GPTM_IMR_TATOIM_BIT_IDX);
        *RegPtr |= (uint32)(((uint32)0) << GPTM_IMR_TBTOIM_BIT_IDX);
        /*Bit Mode Selection GPTM Configuration (GPTMCFG)*/
        RegAddress = BaseAddress + REG_GPTMCFG_OFFSET;
        RegPtr = RegAddress;
         if(GptChannelTickValueMax <= 0xFFFF)                       /*16*/
         {
           *RegPtr |= (uint32)GPT_16_32_Bit_Timer_Select_16;
         }
         else if(GptChannelTickValueMax <= 0xFFFFFFFF)              /*32*/
         {
           if(GptChannelId < 6)
           {
             *RegPtr |= (uint32)GPT_16_32_Bit_Timer_Select_32;
           }
           else
           {
             *RegPtr |= (uint32)GPT_32_64_Bit_Timer_Select_32;
           }
         }
         else if(GptChannelTickValueMax <= 0xFFFFFFFFFFFFFFFF)      /*64*/
         {
            *RegPtr |= (uint32)GPT_32_64_Bit_Timer_Select_64;
         }
         else
         {
           /**/
         }
      }
      Gpt_Status = Gpt_INITIALIZED;
    }
    else
    {
       Gpt_Status = Gpt_NOT_INITIALIZED;
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
void Gpt_DisableNotification ( Gpt_ChannelType Channel )
{
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
void Gpt_EnableNotification ( Gpt_ChannelType Channel )
{
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
void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
  uint32 BaseAddress = 0;
  uint32 RegAddress = 0;
  uint32 *RegPtr = NULL_PTR;
  Gpt_ChannelType GptChannelId;
  Gpt_ValueType GptGptChannelTickFrequency;
  Gpt_ValueType GptChannelTickValueMax;
  Gpt_ModeType ChannelMode;

  if(Gpt_Status == Gpt_INITIALIZED)
  {
     GptChannelTickValueMax = Gpt_ChannelConfigPtr[Channel].GptChannelTickValueMax;
     GptGptChannelTickFrequency = Gpt_ChannelConfigPtr[Channel].GptGptChannelTickFrequency;
     GptChannelTickValueMax = Gpt_ChannelConfigPtr[Channel].GptChannelTickValueMax;
    if((Gpt_ChannelRamDataPtr[Channel].GptTimerStatus != GPT_CH_RUNNING) &&
            (Value <= GptChannelTickValueMax))
    {
      BaseAddress = Gpt_RegBaseAddress[Channel];
      RegAddress = BaseAddress + REG_GPTMTAILR_OFFSET;
      RegPtr = RegAddress;

    }
    else
    {
      /*DET Error*/
    }
  }
  else
  {
     /*DET Error*/
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
void Gpt_StopTimer ( Gpt_ChannelType Channel )
{
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
Gpt_ValueType Gpt_GetTimeElapsed ( Gpt_ChannelType Channel )
{
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
Gpt_ValueType Gpt_GetTimeRemaining ( Gpt_ChannelType Channel )
{
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
Std_ReturnType Gpt_GetPredefTimerValue ( Gpt_PredefTimerType PredefTimer ,uint32* TimeValuePtr )
{
}
/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/