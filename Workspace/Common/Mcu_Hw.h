
#ifndef MCU_HW_REG_H
#define MCU_HW_REG_H

#include "Std_Types.h"

#define CORE_PERIP_BASE_ADDRESS          ((uint32)0xE000E000)

#define APINT_REG_Offset                ((uint32)0xD0C)

#define APINT_REG                       *((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + APINT_REG_Offset))

#define APINT_REG_VECTKEY                ((uint32)0x05FA0000)

#define APINT_SYSRESREQ_BIT_IDX          2U

#define INTCTRL_REG_Offset               ((uint32)0xD04)

#define INTCTRL_REG                      *((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + INTCTRL_REG_Offset))

#define REG_4_INT_SET_ENABLE_OFFSET    ((uint32)0x100)           /*Interrupt 0-31 */
#define REG_5_INT_SET_ENABLE_OFFSET    ((uint32)0x104)           /*Interrupt 32-63*/ 
#define REG_6_INT_SET_ENABLE_OFFSET    ((uint32)0x108)           /*Interrupt 64-95*/
#define REG_7_INT_SET_ENABLE_OFFSET    ((uint32)0x10C)           /*Interrupt 96-127*/
#define REG_8_INT_SET_ENABLE_OFFSET    ((uint32)0x110)           /*Interrupt 96-127*/

#define REG_4_INT_SET_ENABLE    ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REG_4_INT_SET_ENABLE_OFFSET))
#define REG_5_INT_SET_ENABLE    ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REG_5_INT_SET_ENABLE_OFFSET))
#define REG_6_INT_SET_ENABLE    ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REG_6_INT_SET_ENABLE_OFFSET))
#define REG_7_INT_SET_ENABLE    ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REG_7_INT_SET_ENABLE_OFFSET))
#define REG_8_INT_SET_ENABLE    ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REG_8_INT_SET_ENABLE_OFFSET))

#define REGISTER_SIZE                  ((uint32)32)   /*32 Bits*/

#define REGISTER_MSB_IDX               ((uint32)31)   

#define REG_4_MSB_NUM               ((uint32)31)   
#define REG_5_MSB_NUM               ((uint32)63)   
#define REG_6_MSB_NUM               ((uint32)95)   
#define REG_7_MSB_NUM               ((uint32)127)   
 

#define REGISTER_29_PRI0_OFFSET       ((uint32)0x400)
#define REGISTER_30_PRI1_OFFSET       ((uint32)0x404)
#define REGISTER_31_PRI2_OFFSET       ((uint32)0x408)
#define REGISTER_32_PRI3_OFFSET       ((uint32)0x40C)
#define REGISTER_33_PRI4_OFFSET       ((uint32)0x410)
#define REGISTER_34_PRI5_OFFSET       ((uint32)0x414)
#define REGISTER_35_PRI6_OFFSET       ((uint32)0x418)
#define REGISTER_36_PRI7_OFFSET       ((uint32)0x41C)
#define REGISTER_37_PRI8_OFFSET       ((uint32)0x420)
#define REGISTER_38_PRI9_OFFSET       ((uint32)0x424)
#define REGISTER_39_PRI10_OFFSET      ((uint32)0x428)
#define REGISTER_40_PRI11_OFFSET      ((uint32)0x42C)
#define REGISTER_41_PRI12_OFFSET      ((uint32)0x430)
#define REGISTER_42_PRI13_OFFSET      ((uint32)0x434)
#define REGISTER_43_PRI14_OFFSET      ((uint32)0x438)
#define REGISTER_44_PRI15_OFFSET      ((uint32)0x43C)
#define REGISTER_45_PRI16_OFFSET      ((uint32)0x440)
#define REGISTER_46_PRI17_OFFSET      ((uint32)0x444)
#define REGISTER_47_PRI18_OFFSET      ((uint32)0x448)
#define REGISTER_48_PRI19_OFFSET      ((uint32)0x44C)
#define REGISTER_49_PRI20_OFFSET      ((uint32)0x450)
#define REGISTER_50_PRI21_OFFSET      ((uint32)0x454)
#define REGISTER_51_PRI22_OFFSET      ((uint32)0x458)
#define REGISTER_52_PRI23_OFFSET      ((uint32)0x45C)
#define REGISTER_53_PRI24_OFFSET      ((uint32)0x460)
#define REGISTER_54_PRI25_OFFSET      ((uint32)0x464)
#define REGISTER_55_PRI26_OFFSET      ((uint32)0x468)
#define REGISTER_56_PRI27_OFFSET      ((uint32)0x46C)
#define REGISTER_57_PRI28_OFFSET      ((uint32)0x470)
#define REGISTER_58_PRI29_OFFSET      ((uint32)0x474)
#define REGISTER_59_PRI30_OFFSET      ((uint32)0x478)
#define REGISTER_60_PRI31_OFFSET      ((uint32)0x47C)
#define REGISTER_61_PRI32_OFFSET      ((uint32)0x480)
#define REGISTER_62_PRI33_OFFSET      ((uint32)0x484)
#define REGISTER_63_PRI34_OFFSET      ((uint32)0x488)
 

#define REGISTER_29_PRI0            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_29_PRI0_OFFSET  ))
#define REGISTER_30_PRI1            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_30_PRI1_OFFSET  ))
#define REGISTER_31_PRI2            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_31_PRI2_OFFSET  ))
#define REGISTER_32_PRI3            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_32_PRI3_OFFSET  ))
#define REGISTER_33_PRI4            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_33_PRI4_OFFSET  ))
#define REGISTER_34_PRI5            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_34_PRI5_OFFSET  ))
#define REGISTER_35_PRI6            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_35_PRI6_OFFSET  ))
#define REGISTER_36_PRI7            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_36_PRI7_OFFSET  ))
#define REGISTER_37_PRI8            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_37_PRI8_OFFSET  ))
#define REGISTER_38_PRI9            ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_38_PRI9_OFFSET  ))
#define REGISTER_39_PRI10           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_39_PRI10_OFFSET ))
#define REGISTER_40_PRI11           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_40_PRI11_OFFSET ))
#define REGISTER_41_PRI12           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_41_PRI12_OFFSET ))
#define REGISTER_42_PRI13           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_42_PRI13_OFFSET ))
#define REGISTER_43_PRI14           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_43_PRI14_OFFSET ))
#define REGISTER_44_PRI15           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_44_PRI15_OFFSET ))
#define REGISTER_45_PRI16           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_45_PRI16_OFFSET ))
#define REGISTER_46_PRI17           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_46_PRI17_OFFSET ))
#define REGISTER_47_PRI18           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_47_PRI18_OFFSET ))
#define REGISTER_48_PRI19           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_48_PRI19_OFFSET ))
#define REGISTER_49_PRI20           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_49_PRI20_OFFSET ))
#define REGISTER_50_PRI21           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_50_PRI21_OFFSET ))
#define REGISTER_51_PRI22           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_51_PRI22_OFFSET ))
#define REGISTER_52_PRI23           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_52_PRI23_OFFSET ))
#define REGISTER_53_PRI24           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_53_PRI24_OFFSET ))
#define REGISTER_54_PRI25           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_54_PRI25_OFFSET ))
#define REGISTER_55_PRI26           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_55_PRI26_OFFSET ))
#define REGISTER_56_PRI27           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_56_PRI27_OFFSET ))
#define REGISTER_57_PRI28           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_57_PRI28_OFFSET ))
#define REGISTER_58_PRI29           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_58_PRI29_OFFSET ))
#define REGISTER_59_PRI30           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_59_PRI30_OFFSET ))
#define REGISTER_60_PRI31           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_60_PRI31_OFFSET ))
#define REGISTER_61_PRI32           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_61_PRI32_OFFSET ))
#define REGISTER_62_PRI33           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_62_PRI33_OFFSET ))
#define REGISTER_63_PRI34           ((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + REGISTER_63_PRI34_OFFSET ))

#define PRIORITY_REGISTER_MAX_NUM        35U

#define INTCTRL_REG_OFFESET                 ((uint32)0xD04)

#define INTCTRL_REG                    *((volatile uint32*)(CORE_PERIP_BASE_ADDRESS + INTCTRL_REG_OFFESET))

/***************************MCU Driver*************************************/
#define SYSTEM_CTRL_BASE_ADDRESS           ((uint32)0x400FE000)

#define RCC_REG_OFFSET                     ((uint32)0x060)

#define RCC_REGISTER                       *((volatile uint32*)(SYSTEM_CTRL_BASE_ADDRESS + RCC_REG_OFFSET))

#define RCC2_REG_OFFSET                     ((uint32)0x070)

#define RCC2_REGISTER                       *((volatile uint32*)(SYSTEM_CTRL_BASE_ADDRESS + RCC2_REG_OFFSET))

#define RIS_REG_OFFSET                  ((uint32)0x050)
#define RIS_REGSITER                   *((volatile uint32*)(SYSTEM_CTRL_BASE_ADDRESS + RIS_REG_OFFSET))
#define PLLLRIS_BIT     6U
/**/
#define MAIN_OSC_ENABLE          0U 
#define MAIN_OSC_DISABLE         1U 
/***RCC Register BITs***/

#define RCC_MOSCDIS_BIT_SHIFT    0U
#define RCC_OSCSRC_BIT_SHIFT     4U
#define RCC_XTAL_BIT_SHIFT       6U
#define RCC_BYPASS_BIT_SHIFT     11U
#define RCC_PWRDN_BIT_SHIFT      13U
#define RCC_USESYSDIV_BIT_SHIFT  22U
#define RCC_SYSDIV_BIT_SHIFT     23U


#define RCC_OSCSRC2_BIT_SHIFT    4U
#define RCC_BYPASS2_BIT_SHIFT    11U
#define RCC_PWRDN2_BIT_SHIFT     13U
#define RCC_USBPWRDN_BIT_SHIFT   14U


#define RCG_REG_OFFSET           ((uint32)0x600) 

#define PLL_STATUS_REG_OFFSET    ((uint32)0x168)

#define PLL_STATUS_REGISTER      *((volatile uint32*)(SYSTEM_CTRL_BASE_ADDRESS + PLL_STATUS_REG_OFFSET))

#define RESC_REG_OFFSET          ((uint32)0x05C)

#define RESC_REGISTER            *((volatile uint32*)(SYSTEM_CTRL_BASE_ADDRESS + RESC_REG_OFFSET))

#endif 
