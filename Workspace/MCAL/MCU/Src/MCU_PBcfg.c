/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  MCUPBcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MCU_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************Clock Gates*******************************/
 /*byte 1 is the LSB in Reg offset (0x600), Byte 0 Bit idx in each Reg*/                  /*Reg Offset*/
#define MCU_RCGCWD_0                       ((uint16)0x0000)                                  /*0x600*/
#define MCU_RCGCWD_1                       ((uint16)0x0001)                                  /*0x600*/
#define MCU_RCGCTIMER_0                    ((uint16)0x0400)                                  /*0x604*/
#define MCU_RCGCTIMER_1                    ((uint16)0x0401)                                  /*0x604*/
#define MCU_RCGCTIMER_2                    ((uint16)0x0402)                                  /*0x604*/
#define MCU_RCGCTIMER_3                    ((uint16)0x0403)                                  /*0x604*/
#define MCU_RCGCTIMER_4                    ((uint16)0x0404)                                  /*0x604*/
#define MCU_RCGCTIMER_5                    ((uint16)0x0405)                                  /*0x604*/
#define MCU_RCGCGPIO_A                     ((uint16)0x0800)                                  /*0x608*/
#define MCU_RCGCGPIO_B                     ((uint16)0x0801)                                  /*0x608*/
#define MCU_RCGCGPIO_C                     ((uint16)0x0802)                                  /*0x608*/
#define MCU_RCGCGPIO_D                     ((uint16)0x0803)                                  /*0x608*/
#define MCU_RCGCGPIO_E                     ((uint16)0x0804)                                  /*0x608*/
#define MCU_RCGCGPIO_F                     ((uint16)0x0805)                                  /*0x608*/
#define MCU_RCGCDMA                        ((uint16)0x0C00)                                  /*0x60C*/
#define MCU_RCGCHIB                        ((uint16)0x1400)                                  /*0x614*/
#define MCU_RCGCUART_0                     ((uint16)0x1800)                                  /*0x618*/
#define MCU_RCGCUART_1                     ((uint16)0x1801)                                  /*0x618*/
#define MCU_RCGCUART_2                     ((uint16)0x1802)                                  /*0x618*/
#define MCU_RCGCUART_3                     ((uint16)0x1803)                                  /*0x618*/
#define MCU_RCGCUART_4                     ((uint16)0x1804)                                  /*0x618*/
#define MCU_RCGCUART_5                     ((uint16)0x1805)                                  /*0x618*/
#define MCU_RCGCUART_6                     ((uint16)0x1806)                                  /*0x618*/
#define MCU_RCGCUART_7                     ((uint16)0x1807)                                  /*0x618*/
#define MCU_RCGCSSI_0                      ((uint16)0x1C00)                                  /*0x61C*/
#define MCU_RCGCSSI_1                      ((uint16)0x1C01)                                  /*0x61C*/
#define MCU_RCGCSSI_2                      ((uint16)0x1C02)                                  /*0x61C*/
#define MCU_RCGCSSI_3                      ((uint16)0x1C03)                                  /*0x61C*/
#define MCU_RCGCI2C_0                      ((uint16)0x2000)                                  /*0x620*/
#define MCU_RCGCI2C_1                      ((uint16)0x2001)                                  /*0x620*/
#define MCU_RCGCI2C_2                      ((uint16)0x2002)                                  /*0x620*/
#define MCU_RCGCI2C_3                      ((uint16)0x2003)                                  /*0x620*/
#define MCU_RCGCUSB                        ((uint16)0x2800)                                  /*0x628*/
#define MCU_RCGCCAN_0                      ((uint16)0x3400)                                  /*0x634*/
#define MCU_RCGCCAN_1                      ((uint16)0x3401)                                  /*0x634*/
#define MCU_RCGCADC_0                      ((uint16)0x3800)                                  /*0x638*/
#define MCU_RCGCADC_1                      ((uint16)0x3801)                                  /*0x638*/
#define MCU_RCGCACMP                       ((uint16)0x3c00)                                  /*0x63c*/
#define MCU_RCGCPWM_0                      ((uint16)0x4000)                                  /*0x640*/
#define MCU_RCGCPWM_1                      ((uint16)0x4001)                                  /*0x640*/
#define MCU_RCGCQEI_0                      ((uint16)0x4400)                                  /*0x644*/
#define MCU_RCGCQEI_1                      ((uint16)0x4401)                                  /*0x644*/
#define MCU_RCGCEEPROM                     ((uint16)0x5800)                                  /*0x658*/
#define MCU_RCGCWTIMER_0                   ((uint16)0x5C00)                                  /*0x65C*/
#define MCU_RCGCWTIMER_1                   ((uint16)0x5C01)                                  /*0x65C*/
#define MCU_RCGCWTIMER_2                   ((uint16)0x5C02)                                  /*0x65C*/
#define MCU_RCGCWTIMER_3                   ((uint16)0x5C03)                                  /*0x65C*/
#define MCU_RCGCWTIMER_4                   ((uint16)0x5C04)                                  /*0x65C*/
#define MCU_RCGCWTIMER_5                   ((uint16)0x5C05)                                  /*0x65C*/
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Mcu_ConfigType MCU_Configuration[MCU_CLOCK_CONFIG_SET] = 
{
    /* ClockSource   PLL        Freq  */
    {MCU_MAIN_OSC , FALSE , 4}
    ,{MCU_MAIN_OSC, TRUE  , 50} /*50MHZ*/
};

const uint16 Mcu_ActivatedClockGates[MCU_CLOCK_GATES_MAX] = 
{
  MCU_RCGCWD_0
  ,MCU_RCGCWD_1
  ,MCU_RCGCTIMER_0
  ,MCU_RCGCTIMER_1
  ,MCU_RCGCTIMER_2
  ,MCU_RCGCTIMER_3
  ,MCU_RCGCTIMER_4
  ,MCU_RCGCTIMER_5
  ,MCU_RCGCGPIO_A
  ,MCU_RCGCGPIO_B
  ,MCU_RCGCGPIO_C
  ,MCU_RCGCGPIO_D
  ,MCU_RCGCGPIO_E
  ,MCU_RCGCGPIO_F
  ,MCU_RCGCDMA
  ,MCU_RCGCHIB
  ,MCU_RCGCUART_0
  ,MCU_RCGCUART_1
  ,MCU_RCGCUART_2
  ,MCU_RCGCUART_3
  ,MCU_RCGCUART_4
  ,MCU_RCGCUART_5
  ,MCU_RCGCUART_6
  ,MCU_RCGCUART_7
  ,MCU_RCGCSSI_0
  ,MCU_RCGCSSI_1
  ,MCU_RCGCSSI_2
  ,MCU_RCGCSSI_3
  ,MCU_RCGCI2C_0
  ,MCU_RCGCI2C_1
  ,MCU_RCGCI2C_2
  ,MCU_RCGCI2C_3
  ,MCU_RCGCUSB
  ,MCU_RCGCCAN_0
  ,MCU_RCGCCAN_1
  ,MCU_RCGCADC_0
  ,MCU_RCGCADC_1
  ,MCU_RCGCACMP
  ,MCU_RCGCPWM_0
  ,MCU_RCGCPWM_1
  ,MCU_RCGCQEI_0
  ,MCU_RCGCQEI_1
  ,MCU_RCGCEEPROM
  ,MCU_RCGCWTIMER_0
  ,MCU_RCGCWTIMER_1
  ,MCU_RCGCWTIMER_2
  ,MCU_RCGCWTIMER_3
  ,MCU_RCGCWTIMER_4
  ,MCU_RCGCWTIMER_5
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


/**********************************************************************************************************************
 *  END OF FILE: MCU_PBcfg.c
 *********************************************************************************************************************/