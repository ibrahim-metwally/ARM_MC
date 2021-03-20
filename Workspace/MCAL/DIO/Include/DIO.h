/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO 
 *
 *  Description:  DIO Driver  
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "DIO_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DioCfg_DioChannel_1                         0U
#define DioCfg_DioChannel_4                         1U
#define DioCfg_DioChannel_5                         2U
#define DioCfg_DioChannel_6                         3U
#define DioCfg_DioChannel_7                         4U
#define DioCfg_DioChannel_8                         5U
#define DioCfg_DioChannel_9                         6U
#define DioCfg_DioChannel_10                        7U
#define DioCfg_DioChannel_13                        8U
#define DioCfg_DioChannel_14                        9U
#define DioCfg_DioChannel_15                        10U
#define DioCfg_DioChannel_16                        11U
#define DioCfg_DioChannel_17                        12U
#define DioCfg_DioChannel_18                        13U
#define DioCfg_DioChannel_19                        14U
#define DioCfg_DioChannel_20                        15U
#define DioCfg_DioChannel_21                        16U
#define DioCfg_DioChannel_22                        17U
#define DioCfg_DioChannel_23                        18U
#define DioCfg_DioChannel_24                        19U
#define DioCfg_DioChannel_28                        20U
#define DioCfg_DioChannel_29                        21U
#define DioCfg_DioChannel_30                        22U
#define DioCfg_DioChannel_31                        23U
#define DioCfg_DioChannel_43                        24U
#define DioCfg_DioChannel_44                        25U
#define DioCfg_DioChannel_45                        26U
#define DioCfg_DioChannel_46                        27U
#define DioCfg_DioChannel_47                        28U
#define DioCfg_DioChannel_48                        29U
#define DioCfg_DioChannel_49                        30U
#define DioCfg_DioChannel_50                        31U
#define DioCfg_DioChannel_51                        32U
#define DioCfg_DioChannel_52                        33U
#define DioCfg_DioChannel_53                        34U
#define DioCfg_DioChannel_57                        35U
#define DioCfg_DioChannel_58                        36U
#define DioCfg_DioChannel_59                        37U
#define DioCfg_DioChannel_60                        38U
#define DioCfg_DioChannel_61                        39U
#define DioCfg_DioChannel_62                        40U
#define DioCfg_DioChannel_63                        41U
#define DioCfg_DioChannel_64                        42U


#define DioCfg_DioPort_A                  0U
#define DioCfg_DioPort_B                  1U
#define DioCfg_DioPort_C                  2U
#define DioCfg_DioPort_D                  3U
#define DioCfg_DioPort_E                  4U
#define DioCfg_DioPort_F                  5U

#define DioCfg_Max_DioPort                6U
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
extern void Dio_WriteChannel (Dio_ChannelType ChannelId , Dio_LevelType Level);
extern Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);
extern void Dio_WritePort (Dio_PortType PortId , Dio_PortLevelType Level);
extern Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId);

#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/