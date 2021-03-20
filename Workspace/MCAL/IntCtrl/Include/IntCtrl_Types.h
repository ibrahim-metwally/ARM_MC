

#ifndef INT_CTRL_TYPES_H
#define INT_CTRL_TYPES_H

#include "Std_Types.h"

#define EXCE_RESERVED     0xFF
#define EXCE_FIXED_PRI    0xFF

/*System Handler Priority 1 (SYSPRI1), offset 0xD18*/
/*System Handler Priority 2 (SYSPRI2), offset 0xD1C*/
/*System Handler Priority 3 (SYSPRI3), offset 0xD20*/
#define SYSPRI_ORIGIN             ((uint32)0xD00)
/*Byte 1 is the LSB from Reg Offset, Byte 0 is the Num of bits to shift*/
#define INT_EXCE_MEM              ((uint16)0x1805)  /*MSB Bit postion - Bits Length + 1*/ /*7-3+1 = 5*/
#define INT_EXCE_BUSFAULT         ((uint16)0x180D)  /*MSB Bit postion - Bits Length + 1*/ /*15-3+1 = 13*/
#define INT_EXCE_USAGEFAULT       ((uint16)0x1815)  /*MSB Bit postion - Bits Length + 1*/ /*23-3+1 = 21*/
#define INT_EXCE_SVCALL           ((uint16)0x1C1D)  /*MSB Bit postion - Bits Length + 1*/ /*31-3+1 = 29*/
#define INT_EXCE_DEBUG            ((uint16)0x2005)  /*MSB Bit postion - Bits Length + 1*/ /*7-3+1 = 5*/
#define INT_EXCE_PENDSV           ((uint16)0x2015)  /*MSB Bit postion - Bits Length + 1*/ /*23-3+1 = 21*/
#define INT_EXCE_SYSTICK          ((uint16)0x201D)  /*MSB Bit postion - Bits Length + 1*/ /*31-3+1 = 29*/

#define INT_MAX_EXCEPTION         ((uint8)7)    

typedef struct
{
  uint16 ExceptionType;
  uint8 ExcePriority;
}IntCtrl_ExceCfg;

typedef struct
{
  uint8 IntEnable;
  uint8 IntGroupPrio;
  uint8 IntSubGroupPrio;
}IntCtrl_InterruptCfg;


#endif
