#include "app_main.h"
#include "IntCtrl.h"
#include "CPU.h"
#include "Std_Types.h"
#include "BitOperations.h"
#include "MCU.h"
#include "Wdg.h"
#include "Port.h"
#include "Gpt.h"


void Wdg_ToutCbk(void)
{
   /*Action*/
}

volatile static Mcu_PllStatusType PllStatusType = MCU_PLL_UNLOCKED;

int main(void)
{
   Wdg_Init(WdgConfigSet);
   IntCtrl_init();
   Mcu_Init(MCU_DRIVER_CFG);
   Mcu_InitClock(MCU_CLOCK_CFG_SET_0);
   Gpt_Init(GptConfigSet);
   while (PllStatusType != MCU_PLL_LOCKED)
   {
     PllStatusType = Mcu_GetPllStatus();
   }
   Mcu_DistributePllClock();
   Port_Init(PortConfigSet);
	while(1)
	{
    
	}
	return 0;
}
