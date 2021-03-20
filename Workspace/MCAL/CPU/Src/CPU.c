#include "CPU.h"
#include "Std_Types.h"

volatile static uint8 CriticalSectionCounter = 0; 

void CpuDriver_EnableGlobalInterrupt (void)
{
	__asm("CPSIE i");
}
void CpuDriver_DisableGlobalInterrupt (void)
{
	__asm("CPSID i");
}

void CpuDriver_EnableFaults (void)
{
   __asm("CPSIE f");
}

void CpuDriver_DisableFaults  (void)
{
   __asm("CPSID f");
}

void CpuDriver_StartCriticalSection (void)  /*SUSPEND*/
{
	if(CriticalSectionCounter == 0)
	{
		__asm("CPSIE i");
	}
	if(CriticalSectionCounter < 255)
	{
      CriticalSectionCounter++;
	}
}
void CpuDriver_StopCriticalSection (void)    /*RESUME*/
{
	if(CriticalSectionCounter > 0)
	{
	  CriticalSectionCounter--;
	}
	if(CriticalSectionCounter == 0)
	{
		__asm("CPSID i");
	}
}

void CpuDriver_EnablePrivilegedMode(void)
{
   SVC();
}

void CpuDriver_DisablePrivilegedMode(void)
{
	
}
