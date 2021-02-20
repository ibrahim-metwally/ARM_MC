/****************************************************************************************/
/** \file    CPU.h
 *
 *  \brief  This file provide CPU macros.
 * 
 *  \author Ibrahim Metwally
 */
/****************************************************************************************/

#ifndef CPU_H
#define CPU_H

#define ASM()                  __asm()

#define ASM_NOP()              __asm("NOP")

extern void CpuDriver_EnableGlobalInterrupt (void);
extern void CpuDriver_DisableGlobalInterrupt (void);
extern void CpuDriver_StartCriticalSection (void);
extern void CpuDriver_StopCriticalSection (void);

#endif
