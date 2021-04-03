/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Adc_HW.h
 *       Module:  Adc 
 *
 *  Description:  Adc Driver  
 *  
 *********************************************************************************************************************/
#ifndef ADC_HW_H
#define ADC_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define ADC0_BASE_ADDRESS           ((uint32)0x40038000)
#define ADC1_BASE_ADDRESS           ((uint32)0x40039000)

#define REG_ADCACTSS_OFFSET           ((uint32)0x000)       /*ADC Active Sample Sequencer*/
#define REG_ADCRIS_OFFSET             ((uint32)0x004)       /*ADC Raw Interrupt Status*/
#define REG_ADCIM_OFFSET              ((uint32)0x008)       /*ADC Interrupt Mask*/
#define REG_ADCISC_OFFSET             ((uint32)0x00C)       /*ADC Interrupt Status and Clear                    */
#define REG_ADCOSTAT_OFFSET           ((uint32)0x010)       /*ADC Overflow Status                               */
#define REG_ADCEMUX_OFFSET            ((uint32)0x014)       /*ADC Event Multiplexer Select                      */
#define REG_ADCUSTAT_OFFSET           ((uint32)0x018)       /*ADC Underflow Status                              */
#define REG_ADCTSSEL_OFFSET           ((uint32)0x01C)       /*ADC Trigger Source Select                         */
#define REG_ADCSSPRI_OFFSET           ((uint32)0x020)       /*ADC Sample Sequencer Priority                     */
#define REG_ADCSPC_OFFSET             ((uint32)0x024)       /*ADC Sample Phase Control                          */
#define REG_ADCPSSI_OFFSET            ((uint32)0x028)       /*ADC Processor Sample Sequence Initiate            */
#define REG_ADCSAC_OFFSET             ((uint32)0x030)       /*ADC Sample Averaging Control                      */
#define REG_ADCDCISC_OFFSET           ((uint32)0x034)       /*ADC Digital Comparator Interrupt Status and Clear */
#define REG_ADCCTL_OFFSET             ((uint32)0x038)       /*ADC Control                                       */
#define REG_ADCSSMUX0_OFFSET          ((uint32)0x040)       /*ADC Sample Sequence Input Multiplexer Select 0    */
#define REG_ADCSSCTL0_OFFSET          ((uint32)0x044)       /*ADC Sample Sequence Control 0                     */
#define REG_ADCSSFIFO0_OFFSET         ((uint32)0x048)       /*ADC Sample Sequence Result FIFO 0                 */
#define REG_ADCSSFSTAT0_OFFSET        ((uint32)0x04C)       /*ADC Sample Sequence FIFO 0 Status                 */
#define REG_ADCSSOP0_OFFSET           ((uint32)0x050)       /*ADC Sample Sequence 0 Operation                   */
#define REG_ADCSSDC0_OFFSET           ((uint32)0x054)       /*ADC Sample Sequence 0 Digital Comparator Select   */
#define REG_ADCSSMUX1_OFFSET          ((uint32)0x060)       /*ADC Sample Sequence Input Multiplexer Select 1    */
#define REG_ADCSSCTL1_OFFSET          ((uint32)0x064)       /*ADC Sample Sequence Control 1                     */
#define REG_ADCSSFIFO1_OFFSET         ((uint32)0x068)       /*ADC Sample Sequence Result FIFO 1                 */
#define REG_ADCSSFSTAT1_OFFSET        ((uint32)0x06C)       /*ADC Sample Sequence FIFO 1 Status                 */
#define REG_ADCSSOP1_OFFSET           ((uint32)0x070)       /*ADC Sample Sequence 1 Operation                   */
#define REG_ADCSSDC1_OFFSET           ((uint32)0x074)       /*ADC Sample Sequence 1 Digital Comparator Select   */
#define REG_ADCSSMUX2_OFFSET          ((uint32)0x080)       /*ADC Sample Sequence Input Multiplexer Select 2    */
#define REG_ADCSSCTL2_OFFSET          ((uint32)0x084)       /*ADC Sample Sequence Control 2                     */
#define REG_ADCSSFIFO2_OFFSET         ((uint32)0x088)       /*ADC Sample Sequence Result FIFO 2                 */
#define REG_ADCSSFSTAT2_OFFSET        ((uint32)0x08C)       /*ADC Sample Sequence FIFO 2 Status                 */
#define REG_ADCSSOP2_OFFSET           ((uint32)0x090)       /*ADC Sample Sequence 2 Operation                   */
#define REG_ADCSSDC2_OFFSET           ((uint32)0x094)       /*ADC Sample Sequence 2 Digital Comparator Select   */
#define REG_ADCSSMUX3_OFFSET          ((uint32)0x0A0)       /*ADC Sample Sequence Input Multiplexer Select 3    */
#define REG_ADCSSCTL3_OFFSET          ((uint32)0x0A4)       /*ADC Sample Sequence Control 3                     */
#define REG_ADCSSFIFO3_OFFSET         ((uint32)0x0A8)       /*ADC Sample Sequence Result FIFO 3                 */
#define REG_ADCSSFSTAT3_OFFSET        ((uint32)0x0AC)       /*ADC Sample Sequence FIFO 3 Status                 */
#define REG_ADCSSOP3_OFFSET           ((uint32)0x0B0)       /*ADC Sample Sequence 3 Operation                   */
#define REG_ADCSSDC3_OFFSET           ((uint32)0x0B4)       /*ADC Sample Sequence 3 Digital Comparator Select   */
#define REG_ADCDCRIC_OFFSET           ((uint32)0xD00)       /*ADC Digital Comparator Reset Initial Conditions   */
#define REG_ADCDCCTL0_OFFSET          ((uint32)0xE00)       /*ADC Digital Comparator Control 0                  */
#define REG_ADCDCCTL1_OFFSET          ((uint32)0xE04)       /*ADC Digital Comparator Control 1                  */
#define REG_ADCDCCTL2_OFFSET          ((uint32)0xE08)       /*ADC Digital Comparator Control 2                  */
#define REG_ADCDCCTL3_OFFSET          ((uint32)0xE0C)       /*ADC Digital Comparator Control 3                  */
#define REG_ADCDCCTL4_OFFSET          ((uint32)0xE10)       /*ADC Digital Comparator Control 4                  */
#define REG_ADCDCCTL5_OFFSET          ((uint32)0xE14)       /*ADC Digital Comparator Control 5                  */
#define REG_ADCDCCTL6_OFFSET          ((uint32)0xE18)       /*ADC Digital Comparator Control 6                  */
#define REG_ADCDCCTL7_OFFSET          ((uint32)0xE1C)       /*ADC Digital Comparator Control 7                  */
#define REG_ADCDCCMP0_OFFSET          ((uint32)0xE40)       /*ADC Digital Comparator Range 0                    */
#define REG_ADCDCCMP1_OFFSET          ((uint32)0xE44)       /*ADC Digital Comparator Range 1                    */
#define REG_ADCDCCMP2_OFFSET          ((uint32)0xE48)       /*ADC Digital Comparator Range 2                    */
#define REG_ADCDCCMP3_OFFSET          ((uint32)0xE4C)       /*ADC Digital Comparator Range 3                    */
#define REG_ADCDCCMP4_OFFSET          ((uint32)0xE50)       /*ADC Digital Comparator Range 4                    */
#define REG_ADCDCCMP5_OFFSET          ((uint32)0xE54)       /*ADC Digital Comparator Range 5                    */
#define REG_ADCDCCMP6_OFFSET          ((uint32)0xE58)       /*ADC Digital Comparator Range 6                    */
#define REG_ADCDCCMP7_OFFSET          ((uint32)0xE5C)       /*ADC Digital Comparator Range 7                    */
#define REG_ADCPP_OFFSET              ((uint32)0xFC0)       /*ADC Peripheral Properties                         */
#define REG_ADCPC_OFFSET              ((uint32)0xFC4)       /*ADC Peripheral Configuration                      */
#define REG_ADCCC_OFFSET              ((uint32)0xFC8)       /*ADC Clock Configuration                           */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define REG_ADCACTSS_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCACTSS_OFFSET    )))
#define REG_ADCRIS_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_ADCRIS_OFFSET      )))
#define REG_ADCIM_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_ADCIM_OFFSET       )))
#define REG_ADCISC_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_ADCISC_OFFSET      )))
#define REG_ADCOSTAT_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCOSTAT_OFFSET    )))
#define REG_ADCEMUX_ADDR(BaseAddress)          ((uint32)((BaseAddress) + (REG_ADCEMUX_OFFSET     )))
#define REG_ADCUSTAT_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCUSTAT_OFFSET    )))
#define REG_ADCTSSEL_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCTSSEL_OFFSET    )))
#define REG_ADCSSPRI_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSPRI_OFFSET    )))
#define REG_ADCSPC_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_ADCSPC_OFFSET      )))
#define REG_ADCPSSI_ADDR(BaseAddress)          ((uint32)((BaseAddress) + (REG_ADCPSSI_OFFSET     )))
#define REG_ADCSAC_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_ADCSAC_OFFSET      )))
#define REG_ADCDCISC_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCDCISC_OFFSET    )))
#define REG_ADCCTL_ADDR(BaseAddress)           ((uint32)((BaseAddress) + (REG_ADCCTL_OFFSET      )))
#define REG_ADCSSMUX0_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSMUX0_OFFSET   )))
#define REG_ADCSSCTL0_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSCTL0_OFFSET   )))
#define REG_ADCSSFIFO0_ADDR(BaseAddress)       ((uint32)((BaseAddress) + (REG_ADCSSFIFO0_OFFSET  )))
#define REG_ADCSSFSTAT0_ADDR(BaseAddress)      ((uint32)((BaseAddress) + (REG_ADCSSFSTAT0_OFFSET )))
#define REG_ADCSSOP0_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSOP0_OFFSET    )))
#define REG_ADCSSDC0_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSDC0_OFFSET    )))
#define REG_ADCSSMUX1_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSMUX1_OFFSET   )))
#define REG_ADCSSCTL1_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSCTL1_OFFSET   )))
#define REG_ADCSSFIFO1_ADDR(BaseAddress)       ((uint32)((BaseAddress) + (REG_ADCSSFIFO1_OFFSET  )))
#define REG_ADCSSFSTAT1_ADDR(BaseAddress)      ((uint32)((BaseAddress) + (REG_ADCSSFSTAT1_OFFSET )))
#define REG_ADCSSOP1_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSOP1_OFFSET    )))
#define REG_ADCSSDC1_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSDC1_OFFSET    )))
#define REG_ADCSSMUX2_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSMUX2_OFFSET   )))
#define REG_ADCSSCTL2_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSCTL2_OFFSET   )))
#define REG_ADCSSFIFO2_ADDR(BaseAddress)       ((uint32)((BaseAddress) + (REG_ADCSSFIFO2_OFFSET  )))
#define REG_ADCSSFSTAT2_ADDR(BaseAddress)      ((uint32)((BaseAddress) + (REG_ADCSSFSTAT2_OFFSET )))
#define REG_ADCSSOP2_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSOP2_OFFSET    )))
#define REG_ADCSSDC2_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSDC2_OFFSET    )))
#define REG_ADCSSMUX3_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSMUX3_OFFSET   )))
#define REG_ADCSSCTL3_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCSSCTL3_OFFSET   )))
#define REG_ADCSSFIFO3_ADDR(BaseAddress)       ((uint32)((BaseAddress) + (REG_ADCSSFIFO3_OFFSET  )))
#define REG_ADCSSFSTAT3_ADDR(BaseAddress)      ((uint32)((BaseAddress) + (REG_ADCSSFSTAT3_OFFSET )))
#define REG_ADCSSOP3_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSOP3_OFFSET    )))
#define REG_ADCSSDC3_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCSSDC3_OFFSET    )))
#define REG_ADCDCRIC_ADDR(BaseAddress)         ((uint32)((BaseAddress) + (REG_ADCDCRIC_OFFSET    )))
#define REG_ADCDCCTL0_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL0_OFFSET   )))
#define REG_ADCDCCTL1_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL1_OFFSET   )))
#define REG_ADCDCCTL2_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL2_OFFSET   )))
#define REG_ADCDCCTL3_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL3_OFFSET   )))
#define REG_ADCDCCTL4_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL4_OFFSET   )))
#define REG_ADCDCCTL5_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL5_OFFSET   )))
#define REG_ADCDCCTL6_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL6_OFFSET   )))
#define REG_ADCDCCTL7_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCTL7_OFFSET   )))
#define REG_ADCDCCMP0_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP0_OFFSET   )))
#define REG_ADCDCCMP1_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP1_OFFSET   )))
#define REG_ADCDCCMP2_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP2_OFFSET   )))
#define REG_ADCDCCMP3_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP3_OFFSET   )))
#define REG_ADCDCCMP4_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP4_OFFSET   )))
#define REG_ADCDCCMP5_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP5_OFFSET   )))
#define REG_ADCDCCMP6_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP6_OFFSET   )))
#define REG_ADCDCCMP7_ADDR(BaseAddress)        ((uint32)((BaseAddress) + (REG_ADCDCCMP7_OFFSET   )))
#define REG_ADCPP_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_ADCPP_OFFSET       )))
#define REG_ADCPC_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_ADCPC_OFFSET       )))
#define REG_ADCCC_ADDR(BaseAddress)            ((uint32)((BaseAddress) + (REG_ADCCC_OFFSET       )))

#define ADC_WRITE_REG(RegWriteAddr,RegWriteValue)  ((*((volatile uint32*)RegWriteAddr)) |= (RegWriteValue))


/*ADCACTSS Register*/
#define ADCACTSS_ASEN0_BIT_SHIFT         0U
#define ADCACTSS_ASEN1_BIT_SHIFT         1U
#define ADCACTSS_ASEN2_BIT_SHIFT         2U
#define ADCACTSS_ASEN3_BIT_SHIFT         3U
/*ADC Event Multiplexer Select (ADCEMUX)*/
#define ADCEMUX_EM0_BIT_SHIFT            0U   /*SS0 Trigger Select*/
#define ADCEMUX_EM1_BIT_SHIFT            4U   /*SS1 Trigger Select*/
#define ADCEMUX_EM2_BIT_SHIFT            8U   /*SS2 Trigger Select*/
#define ADCEMUX_EM3_BIT_SHIFT            12U  /*SS3 Trigger Select*/

#define SS0_SAMPLE_NUM                   8U
#define SS1_SAMPLE_NUM                   4U
#define SS2_SAMPLE_NUM                   4U
#define SS3_SAMPLE_NUM                   1U
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