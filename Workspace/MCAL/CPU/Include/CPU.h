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

#define ASM_NOP()              __asm("NOP")

#define SVC()                  __asm("SVC #0")


extern void CpuDriver_EnableGlobalInterrupt (void);
extern void CpuDriver_DisableGlobalInterrupt (void);
extern void CpuDriver_EnableFaults (void);
extern void CpuDriver_DisableFaults (void);
extern void CpuDriver_StartCriticalSection (void);
extern void CpuDriver_StopCriticalSection (void);

extern void CpuDriver_EnablePrivilegedMode(void);
extern void CpuDriver_DisablePrivilegedMode(void);

#endif
