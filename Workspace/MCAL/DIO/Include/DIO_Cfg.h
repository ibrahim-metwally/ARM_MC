/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO_CFG.h
 *       Module:  DIO 
 *
 *  Description:  DIO Driver  
 *  
 *********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define DioCfg_DioChannel_1_Bit          6U
#define DioCfg_DioChannel_4_Bit          7U
#define DioCfg_DioChannel_5_Bit          4U
#define DioCfg_DioChannel_6_Bit          3U
#define DioCfg_DioChannel_7_Bit          2U
#define DioCfg_DioChannel_8_Bit          1U
#define DioCfg_DioChannel_9_Bit          0U
#define DioCfg_DioChannel_10_Bit         7U
#define DioCfg_DioChannel_13_Bit         7U
#define DioCfg_DioChannel_14_Bit         6U
#define DioCfg_DioChannel_15_Bit         5U
#define DioCfg_DioChannel_16_Bit         4U
#define DioCfg_DioChannel_17_Bit         0U
#define DioCfg_DioChannel_18_Bit         1U
#define DioCfg_DioChannel_19_Bit         2U
#define DioCfg_DioChannel_20_Bit         3U
#define DioCfg_DioChannel_21_Bit         4U
#define DioCfg_DioChannel_22_Bit         5U
#define DioCfg_DioChannel_23_Bit         6U
#define DioCfg_DioChannel_24_Bit         7U
#define DioCfg_DioChannel_28_Bit         0U
#define DioCfg_DioChannel_29_Bit         1U
#define DioCfg_DioChannel_30_Bit         2U
#define DioCfg_DioChannel_31_Bit         3U
#define DioCfg_DioChannel_43_Bit         4U
#define DioCfg_DioChannel_44_Bit         5U
#define DioCfg_DioChannel_45_Bit         0U
#define DioCfg_DioChannel_46_Bit         1U
#define DioCfg_DioChannel_47_Bit         2U
#define DioCfg_DioChannel_48_Bit         3U
#define DioCfg_DioChannel_49_Bit         3U
#define DioCfg_DioChannel_50_Bit         2U
#define DioCfg_DioChannel_51_Bit         1U
#define DioCfg_DioChannel_52_Bit         0U
#define DioCfg_DioChannel_53_Bit         6U
#define DioCfg_DioChannel_57_Bit         5U
#define DioCfg_DioChannel_58_Bit         4U
#define DioCfg_DioChannel_59_Bit         4U
#define DioCfg_DioChannel_60_Bit         5U
#define DioCfg_DioChannel_61_Bit         0U
#define DioCfg_DioChannel_62_Bit         1U
#define DioCfg_DioChannel_63_Bit         2U
#define DioCfg_DioChannel_64_Bit         3U

#define DIO_MAX_CHANNEL  43U
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Dio_PortChannel Dio_PortChannelCfg[DIO_MAX_CHANNEL];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/