/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_PBcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Port_CfgStrType Port_Configuration[PORT_PIN_CONFIG_SET_NUM] = 
{
  /* PinNum   ,PinMode    ,PinDefaultLevelValue ,PinDirection   ,PinInternalAttach   ,PinOutputCurrent*/     
  {Port_Pin_A0 ,Port_PinMode_Dio,Port_PinLevel_Low,Port_PinOutput,Port_PinInternalAttach_Default,Port_PinOutputCurrent_2mA}
};

const uint32 Port_BaseAddress[GPIO_Port_MAX_NUM] = {
    GPIO_Port_A_BASE_ADDRESS 
    ,GPIO_Port_B_BASE_ADDRESS
    ,GPIO_Port_C_BASE_ADDRESS
    ,GPIO_Port_D_BASE_ADDRESS
    ,GPIO_Port_E_BASE_ADDRESS
    ,GPIO_Port_F_BASE_ADDRESS
};
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/