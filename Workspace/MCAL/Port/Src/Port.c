/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_HW.h"
#include "Port.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define PORT_NOT_INITIALIZED          0
#define PORT_INITIALIZED              1
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Port_CfgStrType* Port_CfgPtr = NULL_PTR;
static Port_StatusType Port_Status = PORT_NOT_INITIALIZED;

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
void Port_Init(const Port_CfgStrType * ConfigPtr)
{
    uint8 Idx = 0;
    uint8 PortNum = 0;
    uint8 PinPos = 0;
    uint32 PortBaseAddress = 0;
    Port_PinType                   Port_PinNum                ;
    Port_PinModeType               Port_PinMode               ;
    Port_PinLevelValueType         Port_PinDefaultLevelValue  ;
    Port_PinDirectionType          Port_PinDirection          ;
    Port_PinInternalAttachType     Port_PinInternalAttach     ;
    Port_PinOutputCurrentType      Port_PinOutputCurrent      ;
    uint32 *PortRegPtr = NULL_PTR;

   if(ConfigPtr != NULL_PTR)
   {
     Port_CfgPtr = ConfigPtr;
     for (Idx = 0; Idx < PORT_PIN_CONFIG_SET_NUM;Idx++)
     {
        Port_PinNum               = Port_CfgPtr[Idx].Port_PinNum               ;
        Port_PinMode              = Port_CfgPtr[Idx].Port_PinMode              ;
        Port_PinDefaultLevelValue = Port_CfgPtr[Idx].Port_PinDefaultLevelValue ;
        Port_PinDirection         = Port_CfgPtr[Idx].Port_PinDirection         ;
        Port_PinInternalAttach    = Port_CfgPtr[Idx].Port_PinInternalAttach    ;
        Port_PinOutputCurrent     = Port_CfgPtr[Idx].Port_PinOutputCurrent     ;

        PortNum = Port_PinNum / 8 ;
        PinPos = Port_PinNum % 8 ;
        PortBaseAddress = Port_BaseAddress[PortNum];
        if((Port_PinNum == Port_Pin_D7) || (Port_PinNum == Port_Pin_F0))
        {
          /*Unlock*/
       /*GPIO Lock (GPIOLOCK)*/
         PortRegPtr = GPIO_LOCK(PortBaseAddress);
         *PortRegPtr = GPIOLOCK_REG_UNLOCK;
       /*GPIO Commit (GPIOCR)*/
         PortRegPtr = GPIO_CR(PortBaseAddress);
         *PortRegPtr |= (uint32)(((uint8)0x01) << PinPos);
        }
        else
        {
           /**/
        }
        /*2. Set the direction of the GPIO port pins by programming the GPIODIR register.*/
        PortRegPtr = GPIO_DIR(PortBaseAddress);
        *PortRegPtr |= (uint32)(((uint8)Port_PinDirection) << PinPos);
        /*3. Configure the GPIOAFSEL register to program each bit as a GPIO or alternate pin.*/
        PortRegPtr = GPIO_AFSEL(PortBaseAddress);
        if(Port_PinMode == Port_PinMode_Dio)
        {
           *PortRegPtr |= (uint32)(((uint8)Port_PinMode_Dio) << PinPos);
        }
        else
        {
          PortRegPtr = (uint32)(((uint8)Port_PinMode_Alt) << PinPos);
          /*GPIO Port Control (GPIOPCTL)*/
          PortRegPtr = GPIO_PCTL(PortBaseAddress);
          *PortRegPtr |= (uint32)(((uint32)Port_PinMode) << (PinPos * PMC_BIT_NUM));
        }
        /*4. Set the drive strength for each of the pins through the GPIODR2R, GPIODR4R, and GPIODR8R registers.*/
     if(Port_PinOutputCurrent != Port_PinOutputCurrent_Default)
     {
        PortRegPtr = GPIO_DRIVE_SELECT(PortBaseAddress,(Port_PinOutputCurrent * 4));
        *PortRegPtr |= (uint32)(((uint8)0x01) << PinPos);
     }
     else
     {
       /**/
     }
      /* 5. pull-up, pull-down, open drain - GPIOPUR, GPIOPDR, GPIOODR register */
       if(Port_PinInternalAttach != Port_PinInternalAttach_Default)
       {
        PortRegPtr = GPIO_INTERNAL_ATTACH(PortBaseAddress,(Port_PinInternalAttach * 4));
        *PortRegPtr |= (uint32)(((uint8)0x01) << PinPos);
       }
       else
       {
         /**/
       }
       /*6. digital function GPIODEN register , analog function GPIOAMSEL register.*/
       if(Port_PinMode == Port_PinMode_Dio)
       {
         PortRegPtr = GPIO_DEN(PortBaseAddress);
         *PortRegPtr |= (uint32)(((uint8)0x01) << PinPos);
       }
       else if(Port_PinMode == Port_PinMode_ANALOG)
       {
         PortRegPtr = GPIO_AMSEL(PortBaseAddress);
         *PortRegPtr |= (uint32)(((uint8)0x01) << PinPos);
       }
       else
       {
          /**/
       }

     if((Port_PinNum == Port_Pin_D7) || (Port_PinNum == Port_Pin_F0))
        {
          /*Lock*/
          /*GPIO Commit (GPIOCR)*/
         PortRegPtr = GPIO_CR(PortBaseAddress);
         *PortRegPtr |= (uint32)(((uint8)0x00) << PinPos);
          /*GPIO Lock (GPIOLOCK)*/
         PortRegPtr = GPIO_LOCK(PortBaseAddress);
         *PortRegPtr = (uint32)0;
        }
        else
        {
           /**/
        }
     }
     Port_Status = PORT_INITIALIZED;
   }
   else
   {
      /**/
   }
}

void Port_EnableJTAG(void)
 {
   uint32 *PortRegPtr = NULL_PTR;
   uint8 Idx = 0;
      /********************Unlock****************************/
       /*GPIO Lock (GPIOLOCK)*/
         PortRegPtr = GPIO_LOCK(GPIO_Port_C_BASE_ADDRESS);
         *PortRegPtr = GPIOLOCK_REG_UNLOCK;
       /*GPIO Commit (GPIOCR)*/
         PortRegPtr = GPIO_CR(GPIO_Port_C_BASE_ADDRESS);
       /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint8)0x01) << Idx);
       }
      /*******************Enable JTAG***************************/

       PortRegPtr = GPIO_AFSEL(GPIO_Port_C_BASE_ADDRESS);
       /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint8)1) << Idx);
       }
      /*GPIO Port Control (GPIOPCTL)*/
      PortRegPtr = GPIO_PCTL(GPIO_Port_C_BASE_ADDRESS);
      /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint32)1) << (Idx * PMC_BIT_NUM));
       }
       /*GPIO_DEN*/
      PortRegPtr = GPIO_DEN(GPIO_Port_C_BASE_ADDRESS);
      /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint32)1) << Idx);
       }

      /**********************Lock*******************************/
      /*GPIO Commit (GPIOCR)*/
      PortRegPtr = GPIO_CR(GPIO_Port_C_BASE_ADDRESS);
      for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint8)0x00) << Idx);
       }
      /*GPIO Lock (GPIOLOCK)*/
      PortRegPtr = GPIO_LOCK(GPIO_Port_C_BASE_ADDRESS);
      *PortRegPtr = (uint32)0;
 }

void Port_DisableJTAG(void)
{
   uint32 *PortRegPtr = NULL_PTR;
   uint8 Idx = 0;
      /********************Unlock****************************/
       /*GPIO Lock (GPIOLOCK)*/
         PortRegPtr = GPIO_LOCK(GPIO_Port_C_BASE_ADDRESS);
         *PortRegPtr = GPIOLOCK_REG_UNLOCK;
       /*GPIO Commit (GPIOCR)*/
         PortRegPtr = GPIO_CR(GPIO_Port_C_BASE_ADDRESS);
       /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint8)0x01) << Idx);
       }
      /*******************Enable GPIO***************************/
       PortRegPtr = GPIO_AFSEL(GPIO_Port_C_BASE_ADDRESS);
       /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint8)Port_PinMode_Dio) << Idx);
       }
      /*GPIO Port Control (GPIOPCTL)*/
      PortRegPtr = GPIO_PCTL(GPIO_Port_C_BASE_ADDRESS);
      /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint32)0) << (Idx * PMC_BIT_NUM));
       }
       /*GPIO_DEN*/
      PortRegPtr = GPIO_DEN(GPIO_Port_C_BASE_ADDRESS);
      /*PC[3:0]*/
       for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint32)1) << Idx);
       }
      /**********************Lock*******************************/
      /*GPIO Commit (GPIOCR)*/
      PortRegPtr = GPIO_CR(GPIO_Port_C_BASE_ADDRESS);
      for (Idx = 0; Idx < 4;Idx++)
       {
         *PortRegPtr |= (uint32)(((uint8)0x00) << Idx);
       }
      /*GPIO Lock (GPIOLOCK)*/
      PortRegPtr = GPIO_LOCK(GPIO_Port_C_BASE_ADDRESS);
      *PortRegPtr = (uint32)0;
}
/*********************************************************************************************************************/
/*  END OF FILE:                                                                                                */
/*********************************************************************************************************************/