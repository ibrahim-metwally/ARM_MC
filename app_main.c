#include "app_main.h"

#include "../MCAL/CPU/CPU.h"
#include "../Common/Std_Types.h"
#include "../Common/BitOperations.h"

int main(void)
{
	CpuDriver_DisableGlobalInterrupt ();
	ASM_NOP();
	CpuDriver_EnableGlobalInterrupt ();

	CpuDriver_StartCriticalSection ();
	ASM_NOP();
	CpuDriver_StopCriticalSection ();

	while(1)
	{

	}
	return 0;
}
