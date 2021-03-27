/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdg_HW.h
 *       Module:  Gpt 
 *
 *  Description:  Gpt Driver  
 *  
 *********************************************************************************************************************/
#ifndef Gpt_HW_H
#define Gpt_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*Registeres Base Address*/
#define GPT_CH_1_BASE_ADDR      ((uint32)0x40030000)     /*GPT_16_32_bit_Timer_0_Base     */
#define GPT_CH_2_BASE_ADDR      ((uint32)0x40031000)     /*GPT_16_32_bit_Timer_1_Base     */
#define GPT_CH_3_BASE_ADDR      ((uint32)0x40032000)     /*GPT_16_32_bit_Timer_2_Base     */
#define GPT_CH_4_BASE_ADDR      ((uint32)0x40033000)     /*GPT_16_32_bit_Timer_3_Base     */
#define GPT_CH_5_BASE_ADDR      ((uint32)0x40034000)     /*GPT_16_32_bit_Timer_4_Base     */
#define GPT_CH_6_BASE_ADDR      ((uint32)0x40035000)     /*GPT_16_32_bit_Timer_5_Base     */
#define GPT_CH_7_BASE_ADDR      ((uint32)0x40036000)     /*GPT_32_64_bit_Wide_Timer_0_Base*/
#define GPT_CH_8_BASE_ADDR      ((uint32)0x40037000)     /*GPT_32_64_bit_Wide_Timer_1_Base*/
#define GPT_CH_9_BASE_ADDR      ((uint32)0x4004C000)     /*GPT_32_64_bit_Wide_Timer_2_Base*/
#define GPT_CH_10_BASE_ADDR     ((uint32)0x4004D000)     /*GPT_32_64_bit_Wide_Timer_3_Base*/
#define GPT_CH_11_BASE_ADDR     ((uint32)0x4004E000)     /*GPT_32_64_bit_Wide_Timer_4_Base*/
#define GPT_CH_12_BASE_ADDR     ((uint32)0x4004F000)     /*GPT_32_64_bit_Wide_Timer_5_Base*/
/*Timers Register Map*/
#define REG_GPTMCFG_OFFSET                     ((uint32)0x000)        /*GPTM Configuration             */
#define REG_GPTMTAMR_OFFSET                    ((uint32)0x004)        /*GPTM Timer A Mode              */
#define REG_GPTMTBMR_OFFSET                    ((uint32)0x008)        /*GPTM Timer B Mode              */
#define REG_GPTMCTL_OFFSET                     ((uint32)0x00C)        /*GPTM Control                   */
#define REG_GPTMSYNC_OFFSET                    ((uint32)0x010)        /*GPTM Synchronize               */
#define REG_GPTMIMR_OFFSET                     ((uint32)0x018)        /*GPTM Interrupt Mask            */
#define REG_GPTMRIS_OFFSET                     ((uint32)0x01C)        /*GPTM Raw Interrupt Status      */
#define REG_GPTMMIS_OFFSET                     ((uint32)0x020)        /*GPTM Masked Interrupt Status   */
#define REG_GPTMICR_OFFSET                     ((uint32)0x024)        /*GPTM Interrupt Clear           */
#define REG_GPTMTAILR_OFFSET                   ((uint32)0x028)        /*GPTM Timer A Interval Load     */
#define REG_GPTMTBILR_OFFSET                   ((uint32)0x02C)        /*GPTM Timer B Interval Load     */
#define REG_GPTMTAMATCHR_OFFSET                ((uint32)0x030)        /*GPTM Timer A Match             */
#define REG_GPTMTBMATCHR_OFFSET                ((uint32)0x034)        /*GPTM Timer B Match             */
#define REG_GPTMTAPR_OFFSET                    ((uint32)0x038)        /*GPTM Timer A Prescale          */
#define REG_GPTMTBPR_OFFSET                    ((uint32)0x03C)        /*GPTM Timer B Prescale          */
#define REG_GPTMTAPMR_OFFSET                   ((uint32)0x040)        /*GPTM TimerA Prescale Match     */
#define REG_GPTMTBPMR_OFFSET                   ((uint32)0x044)        /*GPTM TimerB Prescale Match     */
#define REG_GPTMTAR_OFFSET                     ((uint32)0x048)        /*GPTM Timer A                   */
#define REG_GPTMTBR_OFFSET                     ((uint32)0x04C)        /*GPTM Timer B                   */
#define REG_GPTMTAV_OFFSET                     ((uint32)0x050)        /*GPTM Timer A Value             */
#define REG_GPTMTBV_OFFSET                     ((uint32)0x054)        /*GPTM Timer B Value             */
#define REG_GPTMRTCPD_OFFSET                   ((uint32)0x058)        /*GPTM RTC Predivide             */
#define REG_GPTMTAPS_OFFSET                    ((uint32)0x05C)        /*GPTM Timer A Prescale Snapshot */
#define REG_GPTMTBPS_OFFSET                    ((uint32)0x060)        /*GPTM Timer B Prescale Snapshot */
#define REG_GPTMTAPV_OFFSET                    ((uint32)0x064)        /*GPTM Timer A Prescale Value    */
#define REG_GPTMTBPV_OFFSET                    ((uint32)0x068)        /*GPTM Timer B Prescale Value    */
#define REG_GPTMPP_OFFSET                      ((uint32)0xFC0)        /*GPTM Peripheral Properties     */
/**/
#define GPTMCFG_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMCFG_OFFSET     )))
#define GPTMTAMR_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTAMR_OFFSET    )))
#define GPTMTBMR_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTBMR_OFFSET    )))
#define GPTMCTL_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMCTL_OFFSET     )))
#define GPTMSYNC_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMSYNC_OFFSET    )))
#define GPTMIMR_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMIMR_OFFSET     )))
#define GPTMRIS_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMRIS_OFFSET     )))
#define GPTMMIS_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMMIS_OFFSET     )))
#define GPTMICR_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMICR_OFFSET     )))
#define GPTMTAILR_REG_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_GPTMTAILR_OFFSET   )))
#define GPTMTBILR_REG_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_GPTMTBILR_OFFSET   )))
#define GPTMTAMATCHR_REG_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_GPTMTAMATCHR_OFFSET)))
#define GPTMTBMATCHR_REG_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_GPTMTBMATCHR_OFFSET)))
#define GPTMTAPR_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTAPR_OFFSET    )))
#define GPTMTBPR_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTBPR_OFFSET    )))
#define GPTMTAPMR_REG_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_GPTMTAPMR_OFFSET   )))
#define GPTMTBPMR_REG_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_GPTMTBPMR_OFFSET   )))
#define GPTMTAR_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMTAR_OFFSET     )))
#define GPTMTBR_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMTBR_OFFSET     )))
#define GPTMTAV_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMTAV_OFFSET     )))
#define GPTMTBV_REG_ADDR(BaseAddress)             ((uint32)((BaseAddress) + (REG_GPTMTBV_OFFSET     )))
#define GPTMRTCPD_REG_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_GPTMRTCPD_OFFSET   )))
#define GPTMTAPS_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTAPS_OFFSET    )))
#define GPTMTBPS_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTBPS_OFFSET    )))
#define GPTMTAPV_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTAPV_OFFSET    )))
#define GPTMTBPV_REG_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_GPTMTBPV_OFFSET    )))
#define GPTMPP_REG_ADDR(BaseAddress)              ((uint32)((BaseAddress) + (REG_GPTMPP_OFFSET      )))
													 
#define GPT_WRITE_REG(RegWriteAddr,RegWriteValue)  ((*((volatile uint32*)RegWriteAddr)) |= (RegWriteValue))

#define GPTM_COUNT_DOWN  0U
#define GPTM_COUNT_UP    1U
/**********GPTM Control (GPTMCTL)************/
#define GPTM_TAEN_BIT_IDX  0U    /*GPTM Timer A Enable*/
/**********GPTM Timer A Mode (GPTMTAMR)******/
#define GPTM_TAMR_BIT_IDX     0U     /*GPTM Timer A Mode*/
#define GPTM_TACDIR_BIT_IDX   4U     /*GPTM Timer A Count Direction*/
#define GPTM_TAMIE_BIT_IDX   5U     /*GPTM Timer A Match Interrupt Enable*/
/**********GPTM Interrupt Mask (GPTMIMR)******/
#define GPTM_IMR_TATOIM_BIT_IDX    0U /*GPTM Timer A Time-Out Interrupt Mask*/
#define GPTM_IMR_TBTOIM_BIT_IDX    8U /*GPTM Timer B Time-Out Interrupt Mask*/
/**********GPTM Configuration (GPTMCFG)*******/
#define GPT_16_32_Bit_Timer_Select_16   4U
#define GPT_16_32_Bit_Timer_Select_32   0U
#define GPT_32_64_Bit_Timer_Select_32   4U
#define GPT_32_64_Bit_Timer_Select_64   0U
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const uint32 Gpt_RegBaseAddress [];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE
 *********************************************************************************************************************/