#include "CPU_Irq.h"


void CpuDriver_SvcISR (void)
{
   __asm("CPSID I");                //Set PRIMASK to disable IRQ

   __asm("MRS  R0 , control");      //Copy from Control Reg to R0

   __asm("BIC  R0, R0, #1");        //Clear Bit 0

   __asm("MSR control , R0");       //Enter Privilage Mode
	
   __asm("CPSIE I");                //Set PRIMASK to enable IRQ
}