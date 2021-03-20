/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port_HW.h
 *       Module:  Port 
 *
 *  Description:  Port Driver  
 *  
 *********************************************************************************************************************/
#ifndef PORT_HW_H
#define PORT_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define GPIO_Port_A_BASE_ADDRESS        ((uint32)0x40058000)
#define GPIO_Port_B_BASE_ADDRESS        ((uint32)0x40059000)
#define GPIO_Port_C_BASE_ADDRESS        ((uint32)0x4005A000)
#define GPIO_Port_D_BASE_ADDRESS        ((uint32)0x4005B000)
#define GPIO_Port_E_BASE_ADDRESS        ((uint32)0x4005C000)
#define GPIO_Port_F_BASE_ADDRESS        ((uint32)0x4005D000)

#define GPIO_Port_MAX_NUM                 6U

#define GPIODATA_OFFSET                   ((uint32)0x000) 
#define GPIODIR_OFFSET                    ((uint32)0x400) 
#define GPIOIS_OFFSET                     ((uint32)0x404) 
#define GPIOIBE_OFFSET                    ((uint32)0x408) 
#define GPIOIEV_OFFSET                    ((uint32)0x40C) 
#define GPIOIM_OFFSET                     ((uint32)0x410) 
#define GPIORIS_OFFSET                    ((uint32)0x414) 
#define GPIOMIS_OFFSET                    ((uint32)0x418) 
#define GPIOICR_OFFSET                    ((uint32)0x41C) 
#define GPIOAFSEL_OFFSET                  ((uint32)0x420) 
#define GPIODR2R_OFFSET                   ((uint32)0x500) 
#define GPIODR4R_OFFSET                   ((uint32)0x504) 
#define GPIODR8R_OFFSET                   ((uint32)0x508) 
#define GPIOODR_OFFSET                    ((uint32)0x50C) 
#define GPIOPUR_OFFSET                    ((uint32)0x510) 
#define GPIOPDR_OFFSET                    ((uint32)0x514) 
#define GPIOSLR_OFFSET                    ((uint32)0x518) 
#define GPIODEN_OFFSET                    ((uint32)0x51C) 
#define GPIOLOCK_OFFSET                   ((uint32)0x520) 
#define GPIOCR_OFFSET                     ((uint32)0x524) 
#define GPIOAMSEL_OFFSET                  ((uint32)0x528) 
#define GPIOPCTL_OFFSET                   ((uint32)0x52C) 
#define GPIOADCCTL_OFFSET                 ((uint32)0x530) 
#define GPIODMACTL_OFFSET                 ((uint32)0x534) 


#define GPIO_DATA(BaseAddress)                ((BaseAddress) + (GPIODATA_OFFSET  ))     /*GPIO Data                      */
#define GPIO_DIR(BaseAddress)                 ((BaseAddress) + (GPIODIR_OFFSET   ))     /*GPIO Direction                 */
#define GPIO_IS(BaseAddress)                  ((BaseAddress) + (GPIOIS_OFFSET    ))     /*GPIO Interrupt Sense           */
#define GPIO_IBE(BaseAddress)                 ((BaseAddress) + (GPIOIBE_OFFSET   ))     /*GPIO Interrupt Both Edges      */
#define GPIO_IEV(BaseAddress)                 ((BaseAddress) + (GPIOIEV_OFFSET   ))     /*GPIO Interrupt Event           */
#define GPIO_IM(BaseAddress)                  ((BaseAddress) + (GPIOIM_OFFSET    ))     /*GPIO Interrupt Mask            */
#define GPIO_RIS(BaseAddress)                 ((BaseAddress) + (GPIORIS_OFFSET   ))     /*GPIO Raw Interrupt Status      */
#define GPIO_MIS(BaseAddress)                 ((BaseAddress) + (GPIOMIS_OFFSET   ))     /*GPIO Masked Interrupt Status   */
#define GPIO_ICR(BaseAddress)                 ((BaseAddress) + (GPIOICR_OFFSET   ))     /*GPIO Interrupt Clear           */
#define GPIO_AFSEL(BaseAddress)               ((BaseAddress) + (GPIOAFSEL_OFFSET ))     /*GPIO Alternate Function Select */
#define GPIO_DR2R(BaseAddress)                ((BaseAddress) + (GPIODR2R_OFFSET  ))     /*GPIO 2-mA Drive Select         */
#define GPIO_DR4R(BaseAddress)                ((BaseAddress) + (GPIODR4R_OFFSET  ))     /*GPIO 4-mA Drive Select         */
#define GPIO_DR8R(BaseAddress)                ((BaseAddress) + (GPIODR8R_OFFSET  ))     /*GPIO 8-mA Drive Select         */
#define GPIO_ODR(BaseAddress)                 ((BaseAddress) + (GPIOODR_OFFSET   ))     /*GPIO Open Drain Select         */
#define GPIO_PUR(BaseAddress)                 ((BaseAddress) + (GPIOPUR_OFFSET   ))     /*GPIO Pull-Up Select            */
#define GPIO_PDR(BaseAddress)                 ((BaseAddress) + (GPIOPDR_OFFSET   ))     /*GPIO Pull-Down Select          */
#define GPIO_SLR(BaseAddress)                 ((BaseAddress) + (GPIOSLR_OFFSET   ))     /*GPIO Slew Rate Control Select  */
#define GPIO_DEN(BaseAddress)                 ((BaseAddress) + (GPIODEN_OFFSET   ))     /*GPIO Digital Enable            */
#define GPIO_LOCK(BaseAddress)                ((BaseAddress) + (GPIOLOCK_OFFSET  ))     /*GPIO Lock                      */
#define GPIO_CR(BaseAddress)                  ((BaseAddress) + (GPIOCR_OFFSET    ))     /*GPIO Commit                    */
#define GPIO_AMSEL(BaseAddress)               ((BaseAddress) + (GPIOAMSEL_OFFSET ))     /*GPIO Analog Mode Select        */
#define GPIO_PCTL(BaseAddress)                ((BaseAddress) + (GPIOPCTL_OFFSET  ))     /*GPIO Port Control              */
#define GPIO_ADCCTL(BaseAddress)              ((BaseAddress) + (GPIOADCCTL_OFFSET))     /*GPIO ADC Control               */
#define GPIO_DMACTL(BaseAddress)              ((BaseAddress) + (GPIODMACTL_OFFSET))     /*GPIO DMA Control               */

#define PMC_BIT_NUM   4U

#define GPIOLOCK_REG_UNLOCK                  ((uint32)0x4C4F434B)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define GPIO_DRIVE_SELECT(BaseAddress,Offset)           ((BaseAddress) + (GPIODR2R_OFFSET + (Offset)))

#define GPIO_INTERNAL_ATTACH(BaseAddress,Offset)        ((BaseAddress) + (GPIOODR_OFFSET + (Offset)))     

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

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