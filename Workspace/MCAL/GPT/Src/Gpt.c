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
  boolean IsTimerConcatUsed = FALSE;

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
        /*Check Prescaler Usage*/
        if(GptGptChannelTickFrequency < DEFAULT_CH_FREQ)
        {
          if(Gpt_ChannelRamDataPtr[GptChannelId].TimerCountDirection == GPTM_COUNT_UP)
          {
            Gpt_ChannelRamDataPtr[GptChannelId].PrescalerType = GPT_TIMER_EXTENSION;
          }
          else   /*GPTM_COUNT_DOWN*/
          {
            Gpt_ChannelRamDataPtr[GptChannelId].PrescalerType = GPT_TRUE_PRESCALER;
          }
        }
/*1. Ensure the timer is disabled (the TnEN bit in the GPTMCTL register is cleared) before making any changes*/
        RegAddress = BaseAddress + REG_GPTMCTL_OFFSET;
        RegPtr = RegAddress;
        *RegPtr |= (uint32)TIMER_A_DISABLED;
/*2. Write the GPTM Configuration Register (GPTMCFG) with a value of 0x00000000*/       
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
             *RegPtr |= (uint32)GPT_16_32_Bit_Timer_Select_32;      /*Timer B concatenated*/
             Gpt_ChannelRamDataPtr[GptChannelId].TimerConcatenation = TRUE;
           }
           else
           {
             *RegPtr |= (uint32)GPT_32_64_Bit_Timer_Select_32;
           }
         }
         else if(GptChannelTickValueMax <= 0xFFFFFFFFFFFFFFFF)      /*64*/
         {
            *RegPtr |= (uint32)GPT_32_64_Bit_Timer_Select_64;       /*Timer B concatenated*/
            Gpt_ChannelRamDataPtr[GptChannelId].TimerConcatenation = TRUE;
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
    uint32 BaseAddress = 0;

  BaseAddress = Gpt_RegBaseAddress[Channel];

  Gpt_ChannelRamDataPtr[Channel].NotifyStatus = FALSE;
  /*GPTM Timer A Time-Out Interrupt Mask*/
   GPT_WRITE_REG(GPTMIMR_REG_ADDR(BaseAddress),(uint32)(((uint32)0x00) << GPTM_IMR_TATOIM_BIT_IDX));   
   if(Gpt_ChannelRamDataPtr[Channel].TimerConcatenation == TRUE)
   { 
      /*GPTM Timer B Time-Out Interrupt Mask*/
      GPT_WRITE_REG(GPTMIMR_REG_ADDR(BaseAddress),(uint32)(((uint32)0x00) << GPTM_IMR_TBTOIM_BIT_IDX));  
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
void Gpt_EnableNotification ( Gpt_ChannelType Channel )
{
  uint32 BaseAddress = 0;

  BaseAddress = Gpt_RegBaseAddress[Channel];

  Gpt_ChannelRamDataPtr[Channel].NotifyStatus = TRUE;
  /*GPTM Timer A Time-Out Interrupt Mask*/
   GPT_WRITE_REG(GPTMIMR_REG_ADDR(BaseAddress),(uint32)(((uint32)0x01) << GPTM_IMR_TATOIM_BIT_IDX));   
   if(Gpt_ChannelRamDataPtr[Channel].TimerConcatenation == TRUE)
   { 
      /*GPTM Timer B Time-Out Interrupt Mask*/
      GPT_WRITE_REG(GPTMIMR_REG_ADDR(BaseAddress),(uint32)(((uint32)0x01) << GPTM_IMR_TBTOIM_BIT_IDX));  
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
void Gpt_StartTimer ( Gpt_ChannelType Channel, Gpt_ValueType Value )
{
  uint32 BaseAddress = 0;
  uint32 RegAddress = 0;
  uint32 *RegPtr = NULL_PTR;
  Gpt_ChannelType GptChannelId;
  Gpt_ValueType GptGptChannelTickFrequency;
  Gpt_ValueType GptChannelTickValueMax;
  Gpt_ModeType ChannelMode;
  Gpt_ValueType RegValue = 0;

  if(Gpt_Status == Gpt_INITIALIZED)
  {
     GptChannelTickValueMax = Gpt_ChannelConfigPtr[Channel].GptChannelTickValueMax;
     GptGptChannelTickFrequency = Gpt_ChannelConfigPtr[Channel].GptGptChannelTickFrequency;
     GptChannelTickValueMax = Gpt_ChannelConfigPtr[Channel].GptChannelTickValueMax;
 /*5. Load the start value into the GPTM Timer n Interval Load Register (GPTMTnILR)*/     
    if((Gpt_ChannelRamDataPtr[Channel].GptTimerStatus != GPT_CH_RUNNING) &&
            (Value <= GptChannelTickValueMax))
    {
      if(Gpt_ChannelRamDataPtr[Channel].PrescalerType == GPT_TRUE_PRESCALER)
      {
        RegValue = (uint64)(Value * (DEFAULT_CH_FREQ / GptGptChannelTickFrequency));
      }
      else if(Gpt_ChannelRamDataPtr[Channel].PrescalerType == GPT_TIMER_EXTENSION)
      {
        RegValue = (uint64)(Value << (DEFAULT_CH_FREQ / GptGptChannelTickFrequency));
      }
      else   /*GPT_NO_PRESCALER*/
      {
         /**/
      }
      BaseAddress = Gpt_RegBaseAddress[Channel];
      GPT_WRITE_REG(GPTMTAILR_REG_ADDR(BaseAddress),(uint32)RegValue);            /*Timer A Load*/
      if(GptChannelTickValueMax > 0xFFFFFFFF)  /*32 Bit*/
      {
        GPT_WRITE_REG(GPTMTBILR_REG_ADDR(BaseAddress),(uint32)(RegValue >> 32));  /*Timer B Load*/
      }
    }
    else
    {
      /*DET Error*/
    }
 /*6. If interrupts are required,set GPTM Interrupt Mask Register (GPTMIMR)*/
    if(Gpt_ChannelRamDataPtr[Channel].NotifyStatus == TRUE)
    {
      /*GPTM Timer A Time-Out Interrupt Mask*/
      GPT_WRITE_REG(GPTMIMR_REG_ADDR(BaseAddress),(uint32)(((uint32)0x01) << GPTM_IMR_TATOIM_BIT_IDX));   
      if(Gpt_ChannelRamDataPtr[GptChannelId].TimerConcatenation == TRUE)
      { 
        /*GPTM Timer B Time-Out Interrupt Mask*/
        GPT_WRITE_REG(GPTMIMR_REG_ADDR(BaseAddress),(uint32)(((uint32)0x01) << GPTM_IMR_TBTOIM_BIT_IDX));  
      }                                                            
    } 
 /*7. Set the TnEN bit in the GPTMCTL register to enable the timer and start counting*/
     GPT_WRITE_REG(GPTMCTL_REG_ADDR(BaseAddress),(uint32)(((uint32)0x01) << GPTM_TAEN_BIT_IDX)); 

     Gpt_ChannelRamDataPtr[Channel].GptTimerStatus = GPT_CH_RUNNING; 
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
void Gpt_StopTimer ( Gpt_ChannelType Channel )
{
  uint32 BaseAddress = 0;
  if(Gpt_Status == Gpt_INITIALIZED)
  {
    BaseAddress = Gpt_RegBaseAddress[Channel];
    if(Gpt_ChannelRamDataPtr[Channel].GptTimerStatus == GPT_CH_RUNNING)
    {
      GPT_WRITE_REG(GPTMCTL_REG_ADDR(BaseAddress),(uint32)(((uint32)0x00) << GPTM_TAEN_BIT_IDX));  
      Gpt_ChannelRamDataPtr[Channel].GptTimerStatus = GPT_CH_STOPPED;
    }
    else
    {
    /**/
    }
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
/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/