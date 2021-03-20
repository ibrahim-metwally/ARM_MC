/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdg_HW.h
 *       Module:  WDG 
 *
 *  Description:  WDG Driver  
 *  
 *********************************************************************************************************************/
#ifndef WDG_HW_H
#define WDG_HW_H

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
#define WDT0_BASE_ADDRESS      ((uint32)0x40000000)
#define WDT1_BASE_ADDRESS      ((uint32)0x40001000)

#define WDT0_LOAD_REG_OFFSET                    ((uint32)0x000)
#define WDT0_VALUE_REG_OFFSET                   ((uint32)0x004)
#define WDT0_CTL_REG_OFFSET                     ((uint32)0x008)
#define WDT0_ICR_REG_OFFSET                     ((uint32)0x00C)
#define WDT0_RIS_REG_OFFSET                     ((uint32)0x010)
#define WDT0_MIS_REG_OFFSET                     ((uint32)0x014)
#define WDT0_TEST_REG_OFFSET                    ((uint32)0x418)
#define WDT0_LOCK_REG_OFFSET                    ((uint32)0xC00)

#define WDT0_LOAD_REGESTER           *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_LOAD_REG_OFFSET ))
#define WDT0_VALUE_REGESTER          *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_VALUE_REG_OFFSET))
#define WDT0_CTL_REGESTER            *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_CTL_REG_OFFSET  ))
#define WDT0_ICR_REGESTER            *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_ICR_REG_OFFSET  ))
#define WDT0_RIS_REGESTER            *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_RIS_REG_OFFSET  ))
#define WDT0_MIS_REGESTER            *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_MIS_REG_OFFSET  ))
#define WDT0_TEST_REGESTER           *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_TEST_REG_OFFSET ))
#define WDT0_LOCK_REGESTER           *((volatile uint32*)(WDT0_BASE_ADDRESS +  WDT0_LOCK_REG_OFFSET ))


#define WDTLOCK_UNLOCKED_VALUE       ((uint32)0x1ACCE551)
/*********************** Watchdog Control (WDTCTL) *********************/
#define INTEN_BIT_POSTION           0U
#define RESEN_BIT_POSTION           1U
#define INTTYPE_BIT_POSTION         2U
#define WRC_BIT_POSTION             31U

#define INTEN_BIT_LEN               1U
#define RESEN_BIT_LEN               1U
#define INTTYPE_BIT_LEN             1U
#define WRC_BIT_LEN                 1U

#define INTEN_SHIFT_VALUE            (INTEN_BIT_POSTION   - INTEN_BIT_LEN   + 1)
#define RESEN_SHIFT_VALUE            (RESEN_BIT_POSTION   - RESEN_BIT_LEN   + 1)
#define INTTYPE_SHIFT_VALUE          (INTTYPE_BIT_POSTION - INTTYPE_BIT_LEN + 1)
#define WRC_SHIFT_VALUE              (WRC_BIT_POSTION     - WRC_BIT_LEN     + 1)

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