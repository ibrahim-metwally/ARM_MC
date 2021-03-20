
#ifndef INT_CTRL_CFG_H
#define INT_CTRL_CFG_H

#include "IntCtrl_Types.h"
#include "Mcu_Hw.h"





#define INT_RESERVED                                                    ((uint8)0xFF)
/*Enable Needed Interrupt*/
#define INT_GPIO_PORT_A                                                      STD_OFF
#define INT_GPIO_PORT_B                                                      STD_OFF
#define INT_GPIO_PORT_C                                                      STD_OFF
#define INT_GPIO_PORT_D                                                      STD_OFF
#define INT_GPIO_PORT_E                                                      STD_OFF
#define INT_UART0                                                            STD_OFF
#define INT_UART1                                                            STD_OFF
#define INT_SSI0                                                             STD_OFF
#define INT_I2C0                                                             STD_OFF
#define INT_PWM0_FAULT                                                       STD_OFF
#define INT_PWM0_GENERATOR_0                                                 STD_OFF
#define INT_PWM0_GENERATOR_1                                                 STD_OFF
#define INT_PWM0_GENERATOR_2                                                 STD_OFF
#define INT_QEI0                                                             STD_OFF
#define INT_ADC0_SEQUENCE_0                                                  STD_OFF
#define INT_ADC0_SEQUENCE_1                                                  STD_OFF
#define INT_ADC0_SEQUENCE_2                                                  STD_OFF
#define INT_ADC0_SEQUENCE_3                                                  STD_OFF
#define INT_WATCHDOGTIMERS_0_AND_1                                           STD_OFF
#define INT_16_32_BIT_TIMER_0A                                               STD_OFF
#define INT_16_32_BIT_TIMER_0B                                               STD_OFF
#define INT_16_32_BIT_TIMER_1A                                               STD_OFF
#define INT_16_32_BIT_TIMER_1B                                               STD_OFF
#define INT_16_32_BIT_TIMER_2A                                               STD_OFF
#define INT_16_32_BIT_TIMER_2B                                               STD_OFF
#define INT_ANALOG_COMPARATOR_0                                              STD_OFF
#define INT_ANALOG_COMPARATOR_1                                              STD_OFF
#define INT_RESERVED_27                                                      STD_OFF
#define INT_SYSTEM_CONTROL                                                   STD_OFF
#define INT_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL                          STD_OFF
#define INT_GPIO_PORT_F                                                      STD_OFF
#define INT_RESERVED_31                                                      INT_RESERVED
#define INT_RESERVED_32                                                      INT_RESERVED
#define INT_UART2                                                            STD_OFF
#define INT_SSI1                                                             STD_OFF
#define INT_16_32_BIT_TIMER_3A                                               STD_OFF
#define INT_16_32_BIT_TIMER_3B                                               STD_OFF
#define INT_I2C1                                                             STD_OFF
#define INT_QEI1                                                             STD_OFF
#define INT_CAN0                                                             STD_OFF
#define INT_CAN1                                                             STD_OFF
#define INT_RESERVED_41                                                      INT_RESERVED
#define INT_RESERVED_42                                                      INT_RESERVED
#define INT_HIBERNATION_MODULE                                               STD_OFF
#define INT_USB                                                              STD_OFF
#define INT_PWM_GENERATOR_3                                                  STD_OFF
#define INT_DMA_SOFTWARE                                                     STD_OFF
#define INT_DMA_ERROR                                                        STD_OFF
#define INT_ADC1_SEQUENCE_0                                                  STD_OFF
#define INT_ADC1_SEQUENCE_1                                                  STD_OFF
#define INT_ADC1_SEQUENCE_2                                                  STD_OFF
#define INT_ADC1_SEQUENCE_3                                                  STD_OFF
#define INT_RESERVED_52                                                      INT_RESERVED
#define INT_RESERVED_53                                                      INT_RESERVED
#define INT_RESERVED_54                                                      INT_RESERVED
#define INT_RESERVED_55                                                      INT_RESERVED
#define INT_RESERVED_56                                                      INT_RESERVED
#define INT_SSI2                                                             STD_OFF
#define INT_SSI3                                                             STD_OFF
#define INT_UART3                                                            STD_OFF
#define INT_UART4                                                            STD_OFF
#define INT_UART5                                                            STD_OFF
#define INT_UART6                                                            STD_OFF
#define INT_UART7                                                            STD_OFF
#define INT_RESERVED_64                                                      INT_RESERVED
#define INT_RESERVED_65                                                      INT_RESERVED
#define INT_RESERVED_66                                                      INT_RESERVED
#define INT_RESERVED_67                                                      INT_RESERVED
#define INT_I2C2                                                             STD_OFF
#define INT_I2C3                                                             STD_OFF
#define INT_16_32_BIT_TIMER_4A                                               STD_OFF
#define INT_16_32_BIT_TIMER_4B                                               STD_OFF
#define INT_RESERVED_72                                                      INT_RESERVED
#define INT_RESERVED_73                                                      INT_RESERVED
#define INT_RESERVED_74                                                      INT_RESERVED
#define INT_RESERVED_75                                                      INT_RESERVED
#define INT_RESERVED_76                                                      INT_RESERVED
#define INT_RESERVED_77                                                      INT_RESERVED
#define INT_RESERVED_78                                                      INT_RESERVED
#define INT_RESERVED_79                                                      INT_RESERVED
#define INT_RESERVED_80                                                      INT_RESERVED
#define INT_RESERVED_81                                                      INT_RESERVED
#define INT_RESERVED_82                                                      INT_RESERVED
#define INT_RESERVED_83                                                      INT_RESERVED
#define INT_RESERVED_84                                                      INT_RESERVED
#define INT_RESERVED_85                                                      INT_RESERVED
#define INT_RESERVED_86                                                      INT_RESERVED
#define INT_RESERVED_87                                                      INT_RESERVED
#define INT_RESERVED_88                                                      INT_RESERVED
#define INT_RESERVED_89                                                      INT_RESERVED
#define INT_RESERVED_90                                                      INT_RESERVED
#define INT_RESERVED_91                                                      INT_RESERVED
#define INT_16_32_BIT_TIMER_5A                                               STD_OFF
#define INT_16_32_BIT_TIMER_5B                                               STD_OFF
#define INT_32_64_BIT_TIMER_0A                                               STD_OFF
#define INT_32_64_BIT_TIMER_0B                                               STD_OFF
#define INT_32_64_BIT_TIMER_1A                                               STD_OFF
#define INT_32_64_BIT_TIMER_1B                                               STD_OFF
#define INT_32_64_BIT_TIMER_2A                                               STD_OFF
#define INT_32_64_BIT_TIMER_2B                                               STD_OFF
#define INT_32_64_BIT_TIMER_3A                                               STD_OFF
#define INT_32_64_BIT_TIMER_3B                                               STD_OFF
#define INT_32_64_BIT_TIMER_4A                                               STD_OFF
#define INT_32_64_BIT_TIMER_4B                                               STD_OFF
#define INT_32_64_BIT_TIMER_5A                                               STD_OFF
#define INT_32_64_BIT_TIMER_5B                                               STD_OFF
#define INT_SYSTEM_EXCEPTION_IMPRECISE                                       STD_OFF
#define INT_RESERVED_107                                                     INT_RESERVED
#define INT_RESERVED_108                                                     INT_RESERVED
#define INT_RESERVED_109                                                     INT_RESERVED
#define INT_RESERVED_110                                                     INT_RESERVED
#define INT_RESERVED_111                                                     INT_RESERVED
#define INT_RESERVED_112                                                     INT_RESERVED
#define INT_RESERVED_113                                                     INT_RESERVED
#define INT_RESERVED_114                                                     INT_RESERVED
#define INT_RESERVED_115                                                     INT_RESERVED
#define INT_RESERVED_116                                                     INT_RESERVED
#define INT_RESERVED_117                                                     INT_RESERVED
#define INT_RESERVED_118                                                     INT_RESERVED
#define INT_RESERVED_119                                                     INT_RESERVED
#define INT_RESERVED_120                                                     INT_RESERVED
#define INT_RESERVED_121                                                     INT_RESERVED
#define INT_RESERVED_122                                                     INT_RESERVED
#define INT_RESERVED_123                                                     INT_RESERVED
#define INT_RESERVED_124                                                     INT_RESERVED
#define INT_RESERVED_125                                                     INT_RESERVED
#define INT_RESERVED_126                                                     INT_RESERVED
#define INT_RESERVED_127                                                     INT_RESERVED
#define INT_RESERVED_128                                                     INT_RESERVED
#define INT_RESERVED_129                                                     INT_RESERVED
#define INT_RESERVED_130                                                     INT_RESERVED
#define INT_RESERVED_131                                                     INT_RESERVED
#define INT_RESERVED_132                                                     INT_RESERVED
#define INT_RESERVED_133                                                     INT_RESERVED
#define INT_PWM1_GENERATOR_0                                                 STD_OFF
#define INT_PWM1_GENERATOR_1                                                 STD_OFF
#define INT_PWM1_GENERATOR_2                                                 STD_OFF
#define INT_PWM1_GENERATOR_3                                                 STD_OFF
#define INT_PWM1_FAULT                                                       STD_OFF

#define INT_PRIORITY_GROUP_X_X_X                              4
#define INT_PRIORITY_GROUP_X_X_Y                              5
#define INT_PRIORITY_GROUP_X_Y_Y                              6
#define INT_PRIORITY_GROUP_Y_Y_Y                              7

#define INT_PRIORITY_GROUP                                    INT_PRIORITY_GROUP_X_Y_Y

#define INT_PRIORITY_BIT_COUNT                               ((uint8)3)
#define INT_PRIGROUP_REG_IDX                                 ((uint8)10)
#define INT_PRIORITY_INT_SHIFT          (INT_PRIGROUP_REG_IDX - INT_PRIORITY_BIT_COUNT + 1)

#define INT_PRIORITY_INTA_IDX            ((uint8)7)
#define INT_PRIORITY_INTB_IDX            ((uint8)15)
#define INT_PRIORITY_INTC_IDX            ((uint8)23)
#define INT_PRIORITY_INTD_IDX            ((uint8)31)

#define INT_PRIORITY_INT_BIT_COUNT      ((uint8)3)

#define INT_PRIORITY_INTA_SHIFT          (INT_PRIORITY_INTA_IDX - INT_PRIORITY_INT_BIT_COUNT + 1)
#define INT_PRIORITY_INTB_SHIFT          (INT_PRIORITY_INTB_IDX - INT_PRIORITY_INT_BIT_COUNT + 1)
#define INT_PRIORITY_INTC_SHIFT          (INT_PRIORITY_INTC_IDX - INT_PRIORITY_INT_BIT_COUNT + 1)
#define INT_PRIORITY_INTD_SHIFT          (INT_PRIORITY_INTD_IDX - INT_PRIORITY_INT_BIT_COUNT + 1)


#define INT_u8MAX_INTERRUPT_NUM                                             139U

#define INT_u8INT_ENABLE_REG_NUM                                            5U

#define INT_LAST_INTERRUPT_IDX                                (INT_u8MAX_INTERRUPT_NUM - 1)

#define INTTERUPT_NUM_PER_REG                                                4U

/*EXC*/
extern const IntCtrl_ExceCfg IntCtr_akpExcCfg[INT_MAX_EXCEPTION];
/*INT*/
extern volatile uint32* IntCtr_akpIntEnableRegSet[INT_u8INT_ENABLE_REG_NUM];
extern volatile uint32* IntCtr_akpIntPriorityReg[PRIORITY_REGISTER_MAX_NUM];
extern const IntCtrl_InterruptCfg IntCtr_aku8InteruptCfg[INT_u8MAX_INTERRUPT_NUM];
extern const uint8 IntCtr_aku8InterruptPriIdxReg[INTTERUPT_NUM_PER_REG];

#endif
