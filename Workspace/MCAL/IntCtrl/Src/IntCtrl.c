
#include "IntCtrl_Cfg.h"
#include "IntCtrl.h"
#include "BitOperations.h"
#include "CPU_Irq.h"
#include "CPU.h"

static void SetIntPriority(uint8 IntNum);
static void SetBasePriorityMask(void);
static void SetExcePriority(void);

static void SetIntPriority(uint8 IntNum)
{
    uint32 PriorityRegValue = 0;
    uint8 PriorityRegNum = 0;
    uint8 ShiftNum = 0;
    uint8 IntIdx = 0;
    uint8 GroupField = 0;
    uint8 SubGroupFiled = 0;
    uint8 PriorityFiled = 0;
    uint8 ShiftParam1 = 0;
    uint8 ShiftParam2 = 0;

    PriorityRegNum = IntNum / INTTERUPT_NUM_PER_REG;
    IntIdx = IntNum % INTTERUPT_NUM_PER_REG;

    ShiftNum = IntCtr_aku8InterruptPriIdxReg[IntIdx];
#ifdef SOLUTION_1
   #if (INT_PRIORITY_GROUP == INT_PRIORITY_GROUP_X_X_X)
      GroupField = IntCtr_aku8InteruptCfg[IntNum].IntGroupPrio;
      SubGroupFiled = IntCtr_aku8InteruptCfg[IntNum].IntSubGroupPrio; 
      PriorityFiled =  ((GroupField << 0x00 ) & 0x07) | (SubGroupFiled & 0x00);
   #elif (INT_PRIORITY_GROUP == INT_PRIORITY_GROUP_X_X_Y)
      GroupField = IntCtr_aku8InteruptCfg[IntNum].IntGroupPrio;
      SubGroupFiled = IntCtr_aku8InteruptCfg[IntNum].IntSubGroupPrio; 
      PriorityFiled =  ((GroupField << 0x01 ) & 0x06) | (SubGroupFiled & 0x01);
   #elif (INT_PRIORITY_GROUP == INT_PRIORITY_GROUP_X_Y_Y)
      GroupField = IntCtr_aku8InteruptCfg[IntNum].IntGroupPrio;
      SubGroupFiled = IntCtr_aku8InteruptCfg[IntNum].IntSubGroupPrio; 
      PriorityFiled =  ((GroupField << 0x02 ) & 0x04) | (SubGroupFiled & 0x03);
   #elif (INT_PRIORITY_GROUP == INT_PRIORITY_GROUP_Y_Y_Y)
      GroupField = IntCtr_aku8InteruptCfg[IntNum].IntGroupPrio;
      SubGroupFiled = IntCtr_aku8InteruptCfg[IntNum].IntSubGroupPrio; 
      PriorityFiled =  ((GroupField << 0x03 ) & 0x00) | (SubGroupFiled & 0x07);
   #endif
#else
    GroupField = IntCtr_aku8InteruptCfg[IntNum].IntGroupPrio;
    SubGroupFiled = IntCtr_aku8InteruptCfg[IntNum].IntSubGroupPrio;
    ShiftParam1 = INT_PRIORITY_GROUP - INT_PRIORITY_GROUP_X_X_X;
    ShiftParam2 = INT_PRIORITY_GROUP_Y_Y_Y - INT_PRIORITY_GROUP;
    PriorityFiled =  ((GroupField << ShiftParam1) & ((0x07 << ShiftParam1)&0x07)) |
                                         (SubGroupFiled & ((INT_PRIORITY_GROUP >> ShiftParam2) & 0x07));
#endif
    PriorityRegValue = (uint32)(((uint32)PriorityFiled) << ShiftNum);
    *IntCtr_akpIntPriorityReg[PriorityRegNum] |= PriorityRegValue;
}

static void SetBasePriorityMask(void)
{
    __asm("MOVS R0, #7");
    __asm("MOV R0, R0, LSL #5"); 
    __asm("MSR BASEPRI, R0");
}

static void SetExcePriority(void)
{
   uint8 Idx = 0;
   uint8 ShiftNum = 0;
   uint32 RegAddress = 0;
   uint32 SYSPRI_Offset = 0;
   uint32 *RegPtr = NULL_PTR;

    for (Idx = 0; Idx < INT_MAX_EXCEPTION; Idx++)
    {
       SYSPRI_Offset = (uint32)(IntCtr_akpExcCfg[Idx].ExceptionType >> 8); /*Shist righ to take MSB*/
       SYSPRI_Offset = SYSPRI_ORIGIN + SYSPRI_Offset;
       RegAddress = CORE_PERIP_BASE_ADDRESS + SYSPRI_Offset;
       RegPtr = RegAddress;
       ShiftNum = (uint8)(IntCtr_akpExcCfg[Idx].ExceptionType);  /*cast u16 with u8 to take LSB*/
       *RegPtr |= (uint32)(((uint32)IntCtr_akpExcCfg[Idx].ExcePriority) << ShiftNum);
    }
}


void IntCtrl_init (void)
{
    uint8 Idx = 0;
    uint8 RegNum = 0;
    uint8 RegBitIdx = 0;
    uint8 RegLastIdx = 0;
    uint32 EnableRegValue = 0;

    CpuDriver_EnablePrivilegedMode();

    APINT_REG = (uint32)(APINT_REG_VECTKEY | ((uint32)(INT_PRIORITY_GROUP << INT_PRIORITY_INT_SHIFT)));
    
    SetBasePriorityMask();

    CpuDriver_EnableGlobalInterrupt();
    CpuDriver_DisableFaults();

    SetExcePriority();

    for (Idx = 0; Idx < INT_u8MAX_INTERRUPT_NUM;Idx++)
    {
        RegBitIdx = Idx % REGISTER_SIZE;

        if(IntCtr_aku8InteruptCfg[Idx].IntEnable == STD_ON)
        {
           SetIntPriority(Idx);
           EnableRegValue |= (uint32)(((uint32)0x01) << RegBitIdx);
        }
        else
        {
            /*OFF or Reserved*/
        } 
        
        RegLastIdx = (RegNum * REGISTER_SIZE) + REGISTER_MSB_IDX;
        
       if(Idx == RegLastIdx)
        {
            *IntCtr_akpIntEnableRegSet[RegNum] |= EnableRegValue;
            RegNum++;
            EnableRegValue = 0;
        }
        else if(Idx == INT_LAST_INTERRUPT_IDX)
        {
           *IntCtr_akpIntEnableRegSet[RegNum] |= EnableRegValue;
           RegNum = 0;
           EnableRegValue = 0;
        }
        else
        {
            /**/
        }
    }
}
