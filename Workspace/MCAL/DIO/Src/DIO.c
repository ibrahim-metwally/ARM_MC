/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"
#include "DIO_Cfg.h"
#include "DIO.h"
#include "DIO_HW.h"
#include "BitOperations.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
 Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
 {
     uint32 *PortRegPtr = NULL_PTR;
     uint32 PortBaseAddress = 0;
     uint8 PortNum = 0;
     uint8 ChannelOffset = 0;
     Dio_LevelType Level = 0;

     if(ChannelId < DIO_MAX_CHANNEL)
     {
       PortNum = Dio_PortChannelCfg[ChannelId].PortIdx;
       ChannelOffset = Dio_PortChannelCfg[ChannelId].PinIdx;
       PortBaseAddress = Port_BaseAddress[PortNum];
       PortRegPtr = (uint32*)GPIO_DATA(PortBaseAddress);
       PortRegPtr = (uint32*)GET_PERIPH_ALIAS_REG_ADDRESS(ChannelOffset,PortRegPtr);
       Level = (uint8)*PortRegPtr;
     }
     else
     {
       /**/
     }
    return Level;
 }
 void Dio_WriteChannel (Dio_ChannelType ChannelId , Dio_LevelType Level)
 {
     uint32 *PortRegPtr = NULL_PTR;
     uint32 PortBaseAddress = 0;
     uint8 PortNum = 0;
     uint8 ChannelOffset = 0;

     if(ChannelId < DIO_MAX_CHANNEL)
     {
       PortNum = Dio_PortChannelCfg[ChannelId].PortIdx;
       ChannelOffset = Dio_PortChannelCfg[ChannelId].PinIdx;
       PortBaseAddress = Port_BaseAddress[PortNum];
       PortRegPtr = (uint32*)GPIO_DATA(PortBaseAddress);
       PortRegPtr = (uint32*)GET_PERIPH_ALIAS_REG_ADDRESS(ChannelOffset,PortRegPtr);
       *PortRegPtr = (uint32)Level;
     }
     else
     {
       /**/
     }
 }
 Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
 {
     uint32 *PortRegPtr = NULL_PTR;
     uint32 PortBaseAddress = 0;
     Dio_PortLevelType Level = 0;

    if(PortId < DioCfg_Max_DioPort)
     {
       PortBaseAddress = Port_BaseAddress[PortId];
       PortRegPtr = (uint32*)GPIO_DATA(PortBaseAddress);
       PortRegPtr = (uint32*)(PortRegPtr + GPIODATA_PORT_MASK_OFFSET);
       Level = (Dio_PortLevelType)*PortRegPtr;
     }
     else
     {
       /**/
     }
    return Level;
 }
 void Dio_WritePort (Dio_PortType PortId , Dio_PortLevelType Level)
 {
     uint32 *PortRegPtr = NULL_PTR;
     uint32 PortBaseAddress = 0;

    if(PortId < DioCfg_Max_DioPort)
     {
       PortBaseAddress = Port_BaseAddress[PortId];
       PortRegPtr = (uint32*)GPIO_DATA(PortBaseAddress);
       PortRegPtr = (uint32*)(PortRegPtr + GPIODATA_PORT_MASK_OFFSET);
       *PortRegPtr = (uint32)Level;
     }
     else
     {
       /**/
     }
 }
 Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId)
 {
     Dio_LevelType Level;

     Level = Dio_ReadChannel(ChannelId);
     Level = (Level == STD_HIGH) ? STD_LOW : STD_HIGH;
     Dio_WriteChannel(ChannelId,Level);
     
     return Level;
 }
/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/