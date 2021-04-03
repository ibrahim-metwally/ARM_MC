/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Adc_Types.h
 *       Module:  Adc 
 *
 *  Description:  Adc Driver  
 *  
 *********************************************************************************************************************/
#ifndef ADC_TYPES_H
#define ADC_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef void (*tfvoidCbkFunc) (void);

typedef uint8 Adc_GroupType           ;
typedef uint8 Adc_ChannelType         ;
typedef uint16 Adc_ValueGroupType     ;
typedef uint8 Adc_StatusType          ;
typedef uint8 Adc_StreamNumSampleType ;
typedef uint8 Adc_TriggerSourceType   ;
typedef uint8 Adc_GroupConvModeType   ;
typedef uint8 Adc_GroupPriorityType   ;
typedef uint8 Adc_GroupDefType        ;
typedef uint8 Adc_StreamBufferModeType;

#define ADC_GROUP0_CHANNEL_0       ((uint8)0x00)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_1       ((uint8)0x01)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_2       ((uint8)0x02)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_3       ((uint8)0x03)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_4       ((uint8)0x04)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_5       ((uint8)0x05)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_6       ((uint8)0x06)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_7       ((uint8)0x07)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_8       ((uint8)0x08)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_9       ((uint8)0x09)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_10      ((uint8)0x0A)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP0_CHANNEL_11      ((uint8)0x0B)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_0       ((uint8)0x10)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_1       ((uint8)0x11)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_2       ((uint8)0x12)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_3       ((uint8)0x13)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_4       ((uint8)0x14)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_5       ((uint8)0x15)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_6       ((uint8)0x16)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_7       ((uint8)0x17)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_8       ((uint8)0x18)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_9       ((uint8)0x19)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_10      ((uint8)0x1A)     /*MSB ->Group ID - LSB ->Channel ID*/
#define ADC_GROUP1_CHANNEL_11      ((uint8)0x1B)     /*MSB ->Group ID - LSB ->Channel ID*/

typedef enum
{
  ADC_IDLE = 0,
  ADC_BUSY
}Adc_GroupStatusType;


typedef struct
{
  Adc_ValueGroupType AdcGroupId                  ;
  uint8 CahnnelNum                               ;
  Adc_GroupPriorityType AdcGroupPriority         ;
  Adc_TriggerSourceType AdcGroupTriggSrc         ;
  Adc_GroupConvModeType AdcGroupConversionMode   ;
  tfvoidCbkFunc AdcNotification                  ;
  Adc_StreamBufferModeType AdcStreamingBufferMode;
  Adc_StreamNumSampleType AdcStreamingNumSamples ;
}Adc_GroupConfigType;

typedef struct
{
   Adc_GroupStatusType Adc_GroupStatus;
   uint8 Adc_NotifyStatus             ;
}Adc_ChannelGroupRamDataType;

typedef struct
{
  Adc_GroupConfigType* Adc_GroupConfig                ;
  Adc_ChannelType* AdcChannelId                       ;
  Adc_ChannelGroupRamDataType* Adc_ChannelGroupRamData;
}Adc_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/