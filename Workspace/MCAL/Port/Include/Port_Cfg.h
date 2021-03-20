/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_CFG.h
 *       Module:  Port 
 *
 *  Description:  Port Driver  
 *  
 *********************************************************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H
#include "Port_Types.h"
#include "Port_HW.h"
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PortConfigSet                        (&Port_Configuration[0])
#define PORT_PIN_CONFIG_SET_NUM               1U


#define Port_PinMode_Dio                     0U
#define Port_PinMode_Alt                     1U
#define Port_PinMode_ANALOG                  2U

#define PortPinMode_U0Rx_PA0                 1U
#define PortPinMode_CAN1Rx_PA0               8U
#define PortPinMode_U0Tx_PA1                 1U
#define PortPinMode_CAN1Tx_PA1               8U
#define PortPinMode_SSI0Clk_PA2              2U
#define PortPinMode_SSI0Fss_PA3              2U
#define PortPinMode_SSI0Rx_PA4               2U
#define PortPinMode_SSI0Tx_PA5               2U
#define PortPinMode_I2C1SCL_PA6              3U
#define PortPinMode_M1PWM2_PA6               5U
#define PortPinMode_I2C1SDA_PA7              3U
#define PortPinMode_M1PWM3_PA7               5U
#define PortPinMode_U1Rx_PB0                 1U
#define PortPinMode_T2CCP0_PB0               7U
#define PortPinMode_U1Tx_PB1                 1U
#define PortPinMode_T2CCP1_PB1               7U
#define PortPinMode_I2C0SCL_PB2              3U
#define PortPinMode_T3CCP0_PB2               7U
#define PortPinMode_I2C0SDA_PB3              3U
#define PortPinMode_T3CCP1_PB3               7U
#define PortPinMode_SSI2Clk_PB4              2U
#define PortPinMode_M0PWM2_PB4               4U
#define PortPinMode_T1CCP0_PB4               7U
#define PortPinMode_CAN0Rx_PB4               8U
#define PortPinMode_SSI2Fss_PB5              2U
#define PortPinMode_M0PWM3_PB5               4U
#define PortPinMode_T1CCP1_PB5               7U
#define PortPinMode_CAN0Tx_PB5               8U
#define PortPinMode_SSI2Rx_PB6               2U
#define PortPinMode_M0PWM0_PB6               4U
#define PortPinMode_T0CCP0_PB6               7U
#define PortPinMode_SSI2Tx_PB7               2U
#define PortPinMode_M0PWM1_PB7               4U
#define PortPinMode_T0CCP1_PB7               7U
#define PortPinMode_TCK SWCLK_PC0            1U
#define PortPinMode_T4CCP0_PC0               7U
#define PortPinMode_TMS SWDIO_PC1            1U
#define PortPinMode_T4CCP1_PC1               7U
#define PortPinMode_TDI_PC2                  1U
#define PortPinMode_T5CCP0_PC2               7U
#define PortPinMode_TDO SWO_PC3              1U
#define PortPinMode_T5CCP1_PC3               7U
#define PortPinMode_U4Rx_PC4                 1U
#define PortPinMode_U1Rx_PC4                 2U
#define PortPinMode_M0PWM6_PC4               4U
#define PortPinMode_IDX1_PC4                 6U
#define PortPinMode_WT0CCP0_PC4              7U
#define PortPinMode_U1RTS_PC4                8U
#define PortPinMode_U4Tx_PC5                 1U
#define PortPinMode_U1Tx_PC5                 2U
#define PortPinMode_M0PWM7_PC5               4U
#define PortPinMode_PhA1_PC5                 6U
#define PortPinMode_WT0CCP1_PC5              7U
#define PortPinMode_U1CTS_PC5                8U
#define PortPinMode_U3Rx_PC6                 1U
#define PortPinMode_PhB1_PC6                 6U
#define PortPinMode_WT1CCP0_PC6              7U
#define PortPinMode_USB0EPEN_PC6             8U
#define PortPinMode_U3Tx_PC7                 1U
#define PortPinMode_WT1CCP1_PC7              7U
#define PortPinMode_USB0PFLT_PC7             8U
#define PortPinMode_SSI3Clk_PD0              1U
#define PortPinMode_SSI1Clk_PD0              2U
#define PortPinMode_I2C3SCL_PD0              3U
#define PortPinMode_M0PWM6_PD0               4U
#define PortPinMode_M1PWM0_PD0               5U
#define PortPinMode_WT2CCP0_PD0              7U
#define PortPinMode_SSI3Fss_PD1              1U
#define PortPinMode_SSI1Fss_PD1              2U
#define PortPinMode_I2C3SDA_PD1              3U
#define PortPinMode_M0PWM7_PD1               4U
#define PortPinMode_M1PWM1_PD1               5U
#define PortPinMode_WT2CCP1_PD1              7U
#define PortPinMode_SSI3Rx_PD2               1U
#define PortPinMode_SSI1Rx_PD2               2U
#define PortPinMode_M0FAULT0_PD2             4U
#define PortPinMode_WT3CCP0_PD2              7U
#define PortPinMode_USB0EPEN_PD2             8U
#define PortPinMode_SSI3Tx_PD3               1U
#define PortPinMode_SSI1Tx_PD3               2U
#define PortPinMode_IDX0_PD3                 6U
#define PortPinMode_WT3CCP1_PD3              7U
#define PortPinMode_USB0PFLT_PD3             8U
#define PortPinMode_U6Rx_PD4                 1U
#define PortPinMode_WT4CCP0_PD4              7U
#define PortPinMode_U6Tx_PD5                 1U
#define PortPinMode_WT4CCP1_PD5              7U
#define PortPinMode_U2Rx_PD6                 1U
#define PortPinMode_M0FAULT0_PD6             4U
#define PortPinMode_PhA0_PD6                 6U
#define PortPinMode_WT5CCP0_PD6              7U
#define PortPinMode_U2Tx_PD7                 1U
#define PortPinMode_PhB0_PD7                 6U
#define PortPinMode_WT5CCP1_PD7              7U
#define PortPinMode_NMI_PD7                  8U
#define PortPinMode_U7Rx_PE0                 1U
#define PortPinMode_U7Tx_PE1                 1U
#define PortPinMode_U5Rx_PE4                 1U
#define PortPinMode_I2C2SCL_PE4              3U
#define PortPinMode_M0PWM4_PE4               4U
#define PortPinMode_M1PWM2_PE4               5U
#define PortPinMode_CAN0Rx_PE4               8U
#define PortPinMode_U5Tx_PE5                 1U
#define PortPinMode_I2C2SDA_PE5              3U
#define PortPinMode_M0PWM5_PE5               4U
#define PortPinMode_M1PWM3_PE5               5U
#define PortPinMode_CAN0Tx_PE5               8U
#define PortPinMode_U1RTS_PF0                1U
#define PortPinMode_SSI1Rx_PF0               2U
#define PortPinMode_CAN0Rx_PF0               3U
#define PortPinMode_M1PWM4_PF0               5U
#define PortPinMode_PhA0_PF0                 6U
#define PortPinMode_T0CCP0_PF0               7U
#define PortPinMode_NMI_PF0                  8U
#define PortPinMode_C0o_PF0                  9U
#define PortPinMode_U1CTS_PF1                1U
#define PortPinMode_SSI1Tx_PF1               2U
#define PortPinMode_M1PWM5_PF1               5U
#define PortPinMode_PhB0_PF1                 6U
#define PortPinMode_T0CCP1_PF1               7U
#define PortPinMode_C1o_PF1                  9U
#define PortPinMode_TRD1_PF1                 14U
#define PortPinMode_SSI1Clk_PF2              2U
#define PortPinMode_M0FAULT0_PF2             4U
#define PortPinMode_M1PWM6_PF2               5U
#define PortPinMode_T1CCP0_PF2               7U
#define PortPinMode_TRD0_PF2                 14U
#define PortPinMode_SSI1Fss_PF3              2U
#define PortPinMode_CAN0Tx_PF3               3U
#define PortPinMode_M1PWM7_PF3               5U
#define PortPinMode_T1CCP1_PF3               7U
#define PortPinMode_TRCLK_PF3                14U

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Port_CfgStrType Port_Configuration[PORT_PIN_CONFIG_SET_NUM];
extern const uint32 Port_BaseAddress[GPIO_Port_MAX_NUM];
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/