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
#include "Wdg_HW.h"
#include "Wdg.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define WDG_NOT_INITIALIZED          0
#define WDG_INITIALIZED              1
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Wdg_ConfigType* Wdg_CfgPtr = NULL_PTR;
static Wdg_StatusType Wdg_Status = WDG_NOT_INITIALIZED;
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
void Wdg_Init (const Wdg_ConfigType * ConfigPtr)
{
  uint32 WdtCtrlRegister = 0;
  boolean WriteEnable = FALSE;
    if(ConfigPtr != NULL_PTR)
    {
      Wdg_CfgPtr = ConfigPtr;

      /*************Watchdog Lock (WDTLOCK)*************/
      /*Unlock WDT Registers*/
      WDT0_LOCK_REGESTER = WDTLOCK_UNLOCKED_VALUE;
      /*Check Write Complete Complete Bit*/
      while (WriteEnable == FALSE)
      {
        WriteEnable = (boolean)(WDT0_CTL_REGESTER >> WRC_SHIFT_VALUE);
      }
      /************Watchdog Load (WDTLOAD)******************/
       /*Initial Time Out*/
       WDT0_LOAD_REGESTER = (uint32)(Wdg_CfgPtr->WdgInitialTimeout);
     /*Check Write Complete Complete Bit*/
      while (WriteEnable == FALSE)
      {
        WriteEnable = (boolean)(WDT0_CTL_REGESTER >> WRC_SHIFT_VALUE);
      }
      /*************Watchdog Control (WDTCTL)*************/
      /*Enable WDT Interrupt*/
       WdtCtrlRegister = 0x01 << INTEN_SHIFT_VALUE;
       /*Reset Enable/Disable*/
       WdtCtrlRegister |= (uint32)(((uint32)(Wdg_CfgPtr->ResetEnable)) << RESEN_SHIFT_VALUE);
       /*Interrupt Type*/
       WdtCtrlRegister |= (uint32)(((uint32)(Wdg_CfgPtr->InterruptType)) << INTTYPE_SHIFT_VALUE);
       /*Write Watchdog Control (WDTCTL),*/
       WDT0_CTL_REGESTER = WdtCtrlRegister;
      /*************Watchdog Lock (WDTLOCK)*************/
      /*Check Write Complete Complete Bit*/
      while (WriteEnable == FALSE)
      {
        WriteEnable = (boolean)(WDT0_CTL_REGESTER >> WRC_SHIFT_VALUE);
      }
      /*lock WDT Registers*/
      WDT0_LOCK_REGESTER = 0;
      Wdg_Status = WDG_INITIALIZED;
    }
    else
    {
       Wdg_Status = WDG_NOT_INITIALIZED;
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
void Wdg_SetTriggerCondition (uint16 timeout)
{
  uint32 TickValue = 0;
  boolean WriteEnable = FALSE;

  if(Wdg_Status == WDG_INITIALIZED)
  {
    if(timeout <= WDG_MAX_TIME_OUT)
    {
       /*PIOSC 16 MHZ ->>>> 62.5 nSec*/

       /*1 Tick ->>>> 62.5 nSec*/
       /*10 Ticks ->>>>> 625 nSec*/
       /*x Ticks  ->>>> timeout(ms)* 1000000*/
       TickValue = (uint32)((timeout * ((uint32)10000000)) / ((uint32)625));

      /*************Watchdog Lock (WDTLOCK)*************/
      /*Unlock WDT Registers*/
      WDT0_LOCK_REGESTER = WDTLOCK_UNLOCKED_VALUE;
      /*Check Write Complete Complete Bit*/
      while (WriteEnable == FALSE)
      {
        WriteEnable = (boolean)(WDT0_CTL_REGESTER >> WRC_SHIFT_VALUE);
      }
      /************Watchdog Load (WDTLOAD)******************/
       WDT0_LOAD_REGESTER = TickValue;
      /*************Watchdog Lock (WDTLOCK)*************/
      /*Check Write Complete Complete Bit*/
      while (WriteEnable == FALSE)
      {
        WriteEnable = (boolean)(WDT0_CTL_REGESTER >> WRC_SHIFT_VALUE);
      }
      /*lock WDT Registers*/
      WDT0_LOCK_REGESTER = 0;
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
/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/