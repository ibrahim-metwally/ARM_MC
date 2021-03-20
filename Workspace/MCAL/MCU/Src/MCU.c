/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  MCU.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Mcu_Hw.h"
#include "MCU_Cfg.h"
#include "MCU.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
#define MCU_PLL_OUTPUT_DIV2          200U

#define MCU_PLL_MAX_OUTPUT           80U /*80 MHZ*/
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Mcu_ConfigType* MCU_CfgPtr = NULL_PTR;
static Mcu_StatusType Mcu_Status = MCU_NOT_INITIALIZED;
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
* \Syntax          : void Mcu_Init (const Mcu_ConfigType * ConfigPtr)    
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Mcu_ConfigType                           
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                   
*******************************************************************************/
void Mcu_Init (const Mcu_ConfigType * ConfigPtr)
{
    if(ConfigPtr != NULL_PTR)
    {
      MCU_CfgPtr = ConfigPtr;
      Mcu_Status = MCU_INITIALIZED;
    }
    else
    {
        /**/
    }
}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_InitClock (Mcu_ClockType ClockSetting)  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting                           
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType
*                                                                   
*******************************************************************************/
Std_ReturnType Mcu_InitClock (Mcu_ClockType ClockSetting)
{
    Std_ReturnType ReturnStatus = E_NOT_OK;
    uint32 RccRegValue = 0;
    uint8 ClockSource = 0;
    uint8 CrystalValue = 0;
    boolean IsPllUsed = FALSE;
    uint8 SYSDIV = 0;
    uint16 RequiredFreq = 0;
    uint32 RIS_RegVal = 0;
    
    uint8 PLLLRIS = 0;
    uint8 GateIdx = 0;
    uint32 RegOffset = 0;
    uint32 * RegAddress = NULL_PTR;
    uint8 BitPostion = 0;

    if(Mcu_Status == MCU_INITIALIZED)
	{
    ClockSource = MCU_CfgPtr[ClockSetting].u8ClockSource;
    IsPllUsed = MCU_CfgPtr[ClockSetting].bPllUsage;
    RequiredFreq = MCU_CfgPtr[ClockSetting].Frequency;

      /*1. Bypass the PLL and system clock divider by setting the BYPASS bit and clearing the USESYS bit in the RCC register,*/
        /*PLL BYPASS */
     RCC_REGISTER |= (uint32)(((uint32)(0x01))  <<  RCC_BYPASS_BIT_SHIFT);
        /*Enable System Clock Divider*/
     RCC_REGISTER |= (uint32)(((uint32)(0x00)) << RCC_USESYSDIV_BIT_SHIFT );

     /*2. Select the crystal value (XTAL) and oscillator source (OSCSRC), and clear the PWRDN bit in RCC/RCC2.*/
      /*Main OSC Frequency*/
     CrystalValue = MCU_MAIN_OSC_FREQ;
     /*Crystal Frequency */
     RCC_REGISTER |= (uint32)(((uint32)CrystalValue)  <<  RCC_XTAL_BIT_SHIFT);
       /*Main Oscillator Enable/Disable*/
     RCC_REGISTER |= (uint32)(((uint32)MAIN_OSC_ENABLE) << RCC_MOSCDIS_BIT_SHIFT);
     /*PLL Power Down*/
     RCC_REGISTER |= (uint32)(((uint32)(0x00))  <<  RCC_PWRDN_BIT_SHIFT );
     /*3. Select the desired system divider (SYSDIV) in RCC/RCC2 and set the USESYS bit in RCC.*/
      /*Calculate Sys DIV*/
     SYSDIV = (MCU_PLL_OUTPUT_DIV2 / RequiredFreq) - 1;
     /*write SYSDIV*/
     RCC_REGISTER |= (uint32)(((uint32)(SYSDIV)) << RCC_SYSDIV_BIT_SHIFT );
      /*Enable System Clock Divider*/
     RCC_REGISTER |= (uint32)(((uint32)(0x01)) << RCC_USESYSDIV_BIT_SHIFT );
   /*4. Wait for the PLL to lock by polling the PLLLRIS bit in the Raw Interrupt Status (RIS) register.*/
   while (PLLLRIS == 0)
   {
     RIS_RegVal = RIS_REGSITER;
     PLLLRIS = (uint8)(((uint32)0x01) & (RIS_RegVal >> PLLLRIS_BIT));
   }
   /*5. Enable use of the PLL by clearing the BYPASS bit in RCC/RCC2.*/
    /*PLL BYPASS */
    RCC_REGISTER |= (uint32)(((uint32)(0x00))  <<  RCC_BYPASS_BIT_SHIFT);
    ReturnStatus = E_OK;
  }
  else
  {
    ReturnStatus = E_NOT_OK;
  }
 return ReturnStatus;
}
/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus (void) 
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType
*                                                                   
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus (void)
{
  return (Mcu_PllStatusType)(((uint32)0x01) & ((uint32)PLL_STATUS_REGISTER));
}
/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_DistributePllClock (void)  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType
*                                                                   
*******************************************************************************/
Std_ReturnType Mcu_DistributePllClock (void)
{
    Std_ReturnType ReturnValue = E_NOT_OK;
    boolean IsPllUsed = FALSE;
    uint32 RccRegValue = 0;

    IsPllUsed = MCU_CfgPtr[MCU_CLOCK_CFG_SET_0].bPllUsage;
      /* PLL */
    if(IsPllUsed == TRUE)
    {
       /*PLL BYPASS */
       RCC_REGISTER |= (uint32)(((uint32)(0x00)) << RCC_BYPASS_BIT_SHIFT);
       ReturnValue = E_OK;
    }
    else
    {
       ReturnValue = E_NOT_OK;
    }

 return ReturnValue;
}
/******************************************************************************
* \Syntax          : Mcu_RawResetType Mcu_GetResetRawValue (void)  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : Mcu_RawResetType
*                                                                   
*******************************************************************************/
Mcu_RawResetType Mcu_GetResetRawValue (void)
{
 return (Mcu_RawResetType)RESC_REGISTER;
}
/******************************************************************************
* \Syntax          : void Mcu_PerformReset (void)  
* \Description     :                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : void
*                                                                   
*******************************************************************************/
void Mcu_PerformReset (void)
{
  APINT_REG  = APINT_REG_VECTKEY | ((uint32)(((uint32)0x01) << APINT_SYSRESREQ_BIT_IDX));
}

/*********************************************************************************************************************/
/*  END OF FILE: MCU.c                                                                                               */
/*********************************************************************************************************************/
