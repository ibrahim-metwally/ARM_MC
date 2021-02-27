#include "CPU_Irq.h"


void CpuDriver_SvcISR (void)
{
   ASM("CPSID I")                //Set PRIMASK to disable IRQ

   ASM("MRS  R0 , control")

   ASM("BIC  R0, R0, #1")        //Clear Bit 0

   ASM("MSR control , R0")
	
   ASM("CPSIE I")                //Set PRIMASK to enable IRQ
}