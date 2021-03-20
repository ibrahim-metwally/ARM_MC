
#include "IntCtrl_Cfg.h"


const IntCtrl_ExceCfg IntCtr_akpExcCfg[INT_MAX_EXCEPTION] =
{
  {INT_EXCE_MEM              , 0  }
  ,{INT_EXCE_BUSFAULT         , 0  }
  ,{INT_EXCE_USAGEFAULT       , 0  }
  ,{INT_EXCE_SVCALL           , 0  }
  ,{INT_EXCE_DEBUG            , 0  }
  ,{INT_EXCE_PENDSV           , 0  }
  ,{INT_EXCE_SYSTICK          , 0  }
};

const IntCtrl_InterruptCfg IntCtr_aku8InteruptCfg[INT_u8MAX_INTERRUPT_NUM] = 
{  /*Interupt Enable state           Group Priority SubGroup Priority */
 {INT_GPIO_PORT_A                              , 0    ,  0}
  ,{INT_GPIO_PORT_B                             ,0    ,  0 }
  ,{INT_GPIO_PORT_C                             ,0    ,  0 }
  ,{INT_GPIO_PORT_D                             ,0    ,  0 }
  ,{INT_GPIO_PORT_E                             ,0    ,  0 }
  ,{INT_UART0                                   ,0    ,  0 }
  ,{INT_UART1                                   ,0    ,  0 }
  ,{INT_SSI0                                    ,0    ,  0 }
  ,{INT_I2C0                                    ,0    ,  0 }
  ,{INT_PWM0_FAULT                              ,0    ,  0 }
  ,{INT_PWM0_GENERATOR_0                        ,0    ,  0 }
  ,{INT_PWM0_GENERATOR_1                        ,0    ,  0 }
  ,{INT_PWM0_GENERATOR_2                        ,0    ,  0 }
  ,{INT_QEI0                                    ,0    ,  0 }
  ,{INT_ADC0_SEQUENCE_0                         ,0    ,  0 }
  ,{INT_ADC0_SEQUENCE_1                         ,0    ,  0 }
  ,{INT_ADC0_SEQUENCE_2                         ,0    ,  0 }
  ,{INT_ADC0_SEQUENCE_3                         ,0    ,  0 }
  ,{INT_WATCHDOGTIMERS_0_AND_1                  ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_0A                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_0B                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_1A                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_1B                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_2A                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_2B                      ,0    ,  0 }
  ,{INT_ANALOG_COMPARATOR_0                     ,0    ,  0 }
  ,{INT_ANALOG_COMPARATOR_1                     ,0    ,  0 }
  ,{INT_RESERVED_27                             ,0    ,  0 }
  ,{INT_SYSTEM_CONTROL                          ,0    ,  0 }
  ,{INT_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL ,0    ,  0 }
  ,{INT_GPIO_PORT_F                             ,0    ,  0 }
  ,{INT_RESERVED_31                             ,0    ,  0 }
  ,{INT_RESERVED_32                             ,0    ,  0 }
  ,{INT_UART2                                   ,0    ,  0 }
  ,{INT_SSI1                                    ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_3A                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_3B                      ,0    ,  0 }
  ,{INT_I2C1                                    ,0    ,  0 }
  ,{INT_QEI1                                    ,0    ,  0 }
  ,{INT_CAN0                                    ,0    ,  0 }
  ,{INT_CAN1                                    ,0    ,  0 }
  ,{INT_RESERVED_41                             ,0    ,  0 }
  ,{INT_RESERVED_42                             ,0    ,  0 }
  ,{INT_HIBERNATION_MODULE                      ,0    ,  0 }
  ,{INT_USB                                     ,0    ,  0 }
  ,{INT_PWM_GENERATOR_3                         ,0    ,  0 }
  ,{INT_DMA_SOFTWARE                            ,0    ,  0 }
  ,{INT_DMA_ERROR                               ,0    ,  0 }
  ,{INT_ADC1_SEQUENCE_0                         ,0    ,  0 }
  ,{INT_ADC1_SEQUENCE_1                         ,0    ,  0 }
  ,{INT_ADC1_SEQUENCE_2                         ,0    ,  0 }
  ,{INT_ADC1_SEQUENCE_3                         ,0    ,  0 }
  ,{INT_RESERVED_52                             ,0    ,  0 }
  ,{INT_RESERVED_53                             ,0    ,  0 }
  ,{INT_RESERVED_54                             ,0    ,  0 }
  ,{INT_RESERVED_55                             ,0    ,  0 }
  ,{INT_RESERVED_56                             ,0    ,  0 }
  ,{INT_SSI2                                    ,0    ,  0 }
  ,{INT_SSI3                                    ,0    ,  0 }
  ,{INT_UART3                                   ,0    ,  0 }
  ,{INT_UART4                                   ,0    ,  0 }
  ,{INT_UART5                                   ,0    ,  0 }
  ,{INT_UART6                                   ,0    ,  0 }
  ,{INT_UART7                                   ,0    ,  0 }
  ,{INT_RESERVED_64                             ,0    ,  0 }
  ,{INT_RESERVED_65                             ,0    ,  0 }
  ,{INT_RESERVED_66                             ,0    ,  0 }
  ,{INT_RESERVED_67                             ,0    ,  0 }
  ,{INT_I2C2                                    ,0    ,  0 }
  ,{INT_I2C3                                    ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_4A                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_4B                      ,0    ,  0 }
  ,{INT_RESERVED_72                             ,0    ,  0 }
  ,{INT_RESERVED_73                             ,0    ,  0 }
  ,{INT_RESERVED_74                             ,0    ,  0 }
  ,{INT_RESERVED_75                             ,0    ,  0 }
  ,{INT_RESERVED_76                             ,0    ,  0 }
  ,{INT_RESERVED_77                             ,0    ,  0 }
  ,{INT_RESERVED_78                             ,0    ,  0 }
  ,{INT_RESERVED_79                             ,0    ,  0 }
  ,{INT_RESERVED_80                             ,0    ,  0 }
  ,{INT_RESERVED_81                             ,0    ,  0 }
  ,{INT_RESERVED_82                             ,0    ,  0 }
  ,{INT_RESERVED_83                             ,0    ,  0 }
  ,{INT_RESERVED_84                             ,0    ,  0 }
  ,{INT_RESERVED_85                             ,0    ,  0 }
  ,{INT_RESERVED_86                             ,0    ,  0 }
  ,{INT_RESERVED_87                             ,0    ,  0 }
  ,{INT_RESERVED_88                             ,0    ,  0 }
  ,{INT_RESERVED_89                             ,0    ,  0 }
  ,{INT_RESERVED_90                             ,0    ,  0 }
  ,{INT_RESERVED_91                             ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_5A                      ,0    ,  0 }
  ,{INT_16_32_BIT_TIMER_5B                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_0A                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_0B                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_1A                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_1B                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_2A                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_2B                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_3A                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_3B                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_4A                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_4B                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_5A                      ,0    ,  0 }
  ,{INT_32_64_BIT_TIMER_5B                      ,0    ,  0 }
  ,{INT_SYSTEM_EXCEPTION_IMPRECISE              ,0    ,  0 }
  ,{INT_RESERVED_107                            ,0    ,  0 }
  ,{INT_RESERVED_108                            ,0    ,  0 }
  ,{INT_RESERVED_109                            ,0    ,  0 }
  ,{INT_RESERVED_110                            ,0    ,  0 }
  ,{INT_RESERVED_111                            ,0    ,  0 }
  ,{INT_RESERVED_112                            ,0    ,  0 }
  ,{INT_RESERVED_113                            ,0    ,  0 }
  ,{INT_RESERVED_114                            ,0    ,  0 }
  ,{INT_RESERVED_115                            ,0    ,  0 }
  ,{INT_RESERVED_116                            ,0    ,  0 }
  ,{INT_RESERVED_117                            ,0    ,  0 }
  ,{INT_RESERVED_118                            ,0    ,  0 }
  ,{INT_RESERVED_119                            ,0    ,  0 }
  ,{INT_RESERVED_120                            ,0    ,  0 }
  ,{INT_RESERVED_121                            ,0    ,  0 }
  ,{INT_RESERVED_122                            ,0    ,  0 }
  ,{INT_RESERVED_123                            ,0    ,  0 }
  ,{INT_RESERVED_124                            ,0    ,  0 }
  ,{INT_RESERVED_125                            ,0    ,  0 }
  ,{INT_RESERVED_126                            ,0    ,  0 }
  ,{INT_RESERVED_127                            ,0    ,  0 }
  ,{INT_RESERVED_128                            ,0    ,  0 }
  ,{INT_RESERVED_129                            ,0    ,  0 }
  ,{INT_RESERVED_130                            ,0    ,  0 }
  ,{INT_RESERVED_131                            ,0    ,  0 }
  ,{INT_RESERVED_132                            ,0    ,  0 }
  ,{INT_RESERVED_133                            ,0    ,  0 }
  ,{INT_PWM1_GENERATOR_0                        ,0    ,  0 }
  ,{INT_PWM1_GENERATOR_1                        ,0    ,  0 }
  ,{INT_PWM1_GENERATOR_2                        ,0    ,  0 }
  ,{INT_PWM1_GENERATOR_3                        ,0    ,  0 }
  ,{INT_PWM1_FAULT                              ,0    ,  0 }
};
/*Interrupt Enable Register Address*/
volatile uint32* IntCtr_akpIntEnableRegSet[INT_u8INT_ENABLE_REG_NUM] = 
{ 
    REG_4_INT_SET_ENABLE
    ,REG_5_INT_SET_ENABLE
    ,REG_6_INT_SET_ENABLE
    ,REG_7_INT_SET_ENABLE
    ,REG_8_INT_SET_ENABLE
};

volatile uint32 *IntCtr_akpIntPriorityReg[PRIORITY_REGISTER_MAX_NUM] = 
{
  REGISTER_29_PRI0  
  ,REGISTER_30_PRI1 
  ,REGISTER_31_PRI2 
  ,REGISTER_32_PRI3 
  ,REGISTER_33_PRI4 
  ,REGISTER_34_PRI5 
  ,REGISTER_35_PRI6 
  ,REGISTER_36_PRI7 
  ,REGISTER_37_PRI8 
  ,REGISTER_38_PRI9 
  ,REGISTER_39_PRI10
  ,REGISTER_40_PRI11
  ,REGISTER_41_PRI12
  ,REGISTER_42_PRI13
  ,REGISTER_43_PRI14
  ,REGISTER_44_PRI15
  ,REGISTER_45_PRI16
  ,REGISTER_46_PRI17
  ,REGISTER_47_PRI18
  ,REGISTER_48_PRI19
  ,REGISTER_49_PRI20
  ,REGISTER_50_PRI21
  ,REGISTER_51_PRI22
  ,REGISTER_52_PRI23
  ,REGISTER_53_PRI24
  ,REGISTER_54_PRI25
  ,REGISTER_55_PRI26
  ,REGISTER_56_PRI27
  ,REGISTER_57_PRI28
  ,REGISTER_58_PRI29
  ,REGISTER_59_PRI30
  ,REGISTER_60_PRI31
  ,REGISTER_61_PRI32
  ,REGISTER_62_PRI33
  ,REGISTER_63_PRI34
};

const uint8 IntCtr_aku8InterruptPriIdxReg[INTTERUPT_NUM_PER_REG] = 
{
   INT_PRIORITY_INTA_SHIFT
   ,INT_PRIORITY_INTB_SHIFT
   ,INT_PRIORITY_INTC_SHIFT
   ,INT_PRIORITY_INTD_SHIFT
};

