/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Ibrahim Metwally
 *       Module:  MCU 
 *
 *  Description:  MCU Driver  
 *  
 *********************************************************************************************************************/
#ifndef MCU_CFG_H
#define MCU_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "MCU_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define MCU_CLOCK_CFG_SET_0        0U
#define MCU_CLOCK_CFG_SET_1        1U
#define MCU_CLOCK_CONFIG_SET       2U

#define MCU_DRIVER_CFG              (&MCU_Configuration[MCU_CLOCK_CFG_SET_0])

/*REG RCC   Bits 5:4 OSCSRC*/
#define MCU_MAIN_OSC               0U           /*Main Oscillator*/
#define MCU_PI_OSC                 1U           /*Precision Internal Oscillator*/
#define MCU_PI_OSC_DIV_4           2U           /*Precision Internal Oscillator*/
#define MCU_LFI_OSC                3U           /*Precision internal oscillator /4*/
/*REG RCC2   6:4 OSCSRC2*/
#define MCU_HIBER_OSC              7U         /*32.768-kHz external oscillator*/
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define DEVISOR_1        1U
#define DEVISOR_2        2U
#define DEVISOR_3        3U
#define DEVISOR_4        4U
#define DEVISOR_5        5U
#define DEVISOR_6        6U
#define DEVISOR_7        7U
#define DEVISOR_8        8U
#define DEVISOR_9        9U
#define DEVISOR_10       10U
#define DEVISOR_11       11U
#define DEVISOR_12       12U
#define DEVISOR_13       13U
#define DEVISOR_14       14U
#define DEVISOR_15       15U
#define DEVISOR_16       16U


/*crystal value attached to the main oscillator*/
#define MAIN_OSC_FREQ_4          ((uint8)0x06)       /* 4 MHz Crystal Frequency (MHz) Not Using the PLL         */
#define MAIN_OSC_FREQ_4_096      ((uint8)0x07)       /* 4.096 MHz Crystal Frequency (MHz) Not Using the PLL     */
#define MAIN_OSC_FREQ_4_9152     ((uint8)0x08)       /* 4.9152 MHz Crystal Frequency (MHz) Not Using the PLL    */
#define MAIN_OSC_FREQ_5          ((uint8)0x09)       /* 5 MHz (USB)            */
#define MAIN_OSC_FREQ_5_12       ((uint8)0x0A)       /* 5.12 MHz               */
#define MAIN_OSC_FREQ_6          ((uint8)0x0B)       /* 6 MHz (USB)            */
#define MAIN_OSC_FREQ_6_144      ((uint8)0x0C)       /* 6.144 MHz              */
#define MAIN_OSC_FREQ_7_3728     ((uint8)0x0D)       /* 7.3728 MHz             */
#define MAIN_OSC_FREQ_8          ((uint8)0x0E)       /* 8 MHz (USB)            */
#define MAIN_OSC_FREQ_8_192      ((uint8)0x0F)       /* 8.192 MHz              */
#define MAIN_OSC_FREQ_10         ((uint8)0x10)       /* 10.0 MHz (USB)         */
#define MAIN_OSC_FREQ_12         ((uint8)0x11)       /* 12.0 MHz (USB)         */
#define MAIN_OSC_FREQ_12_288     ((uint8)0x12)       /* 12.288 MHz             */
#define MAIN_OSC_FREQ_13_56      ((uint8)0x13)       /* 13.56 MHz              */
#define MAIN_OSC_FREQ_14_31818   ((uint8)0x14)       /* 14.31818 MHz           */
#define MAIN_OSC_FREQ_16         ((uint8)0x15)       /* 16.0 MHz (USB)         */
#define MAIN_OSC_FREQ_16_384     ((uint8)0x16)       /* 16.384 MHz             */
#define MAIN_OSC_FREQ_18         ((uint8)0x17)       /* 18.0 MHz (USB)         */
#define MAIN_OSC_FREQ_20         ((uint8)0x18)       /* 20.0 MHz (USB)         */
#define MAIN_OSC_FREQ_24         ((uint8)0x19)       /* 24.0 MHz (USB)         */
#define MAIN_OSC_FREQ_25         ((uint8)0x1A)       /* 25.0 MHz (USB)         */

#define MCU_MAIN_OSC_FREQ        MAIN_OSC_FREQ_8

#define MCU_CLOCK_GATES_MAX               ((uint8)49)
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Mcu_ConfigType MCU_Configuration[MCU_CLOCK_CONFIG_SET];
 
extern const uint16 Mcu_ActivatedClockGates[MCU_CLOCK_GATES_MAX]; 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: MCU_Cfg.h
 *********************************************************************************************************************/