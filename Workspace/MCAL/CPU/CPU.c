#include "CPU.h"
#include "../../Common/Std_Types.h"

volatile uint8 CriticalSectionCounter = 0; 

void CpuDriver_EnableGlobalInterrupt (void)
{
	__asm("CPSIE i");
}
void CpuDriver_DisableGlobalInterrupt (void)
{
	__asm("CPSID i");
}

void CpuDriver_StartCriticalSection (void)  /*SUSPEND*/
{
	CriticalSectionCounter++;
	if(CriticalSectionCounter == 1)
	{
		__asm("CPSIE i");
	}
	else
	{
		/**/
	}
}
void CpuDriver_StopCriticalSection (void)    /*RESUME*/
{
	CriticalSectionCounter--;
	if(CriticalSectionCounter == 0)
	{
		__asm("CPSID i");
	}
	else
	{
		/**/
	}
}

void CpuDriver_EnablePrivilegedMode(void)
{
   SVC();
}