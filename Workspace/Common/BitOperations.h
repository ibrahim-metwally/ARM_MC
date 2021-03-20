/****************************************************************************************/
/** \file    BitOperations.h
 *
 *  \brief  This file provide Compiler macros.
 * 
 *  \author Ibrahim Metwally
 */
/****************************************************************************************/
#include "Std_Types.h"

#ifndef BIT_OPERATION_H
#define BIT_OPERATION_H

#define SET_BIT(Byte,BitPostion)           ((Byte)|(0x01<<(BitPostion)))

#define CLEAR_BIT(Byte,BitPostion)         ((Byte)&(~(0x01<<(BitPostion))))

#define GET_BIT(Byte,BitPostion)           ((0x01)&(Byte>>(BitPostion)))

#define SRAM_BIT_BAND_BASE_ADDRESS                  ((uint32)0x20000000)

#define SRAM_BIT_BAND_ALIAS_BASE_ADDRESS            ((uint32)0x22000000)

#define PERIPH_BIT_BAND_BASE_ADDRESS            ((uint32)0x40000000)

#define PERIPH_BIT_BAND_ALIAS_BASE_ADDRESS      ((uint32)0x42000000)

#define REGISTER_SIZE                               ((uint32)32)  /*Bits*/

#define REGISTER_WORD_SIZE                          ((uint32)4)   /*Bytes*/

#define SRAM_GET_BIT_OFFSET(BIT_POSTION,REG_ADDRESS)  \
((BIT_POSTION) + ((((REG_ADDRESS) - (SRAM_BIT_BAND_BASE_ADDRESS)) / (REGISTER_WORD_SIZE)) * (REGISTER_SIZE)))
                           
#define GET_SRAM_ALIAS_REG_ADDRESS(BIT_POSTION,REG_ADDRESS)  \
((SRAM_BIT_BAND_ALIAS_BASE_ADDRESS) + ((SRAM_GET_BIT_OFFSET(BIT_POSTION,REG_ADDRESS)) * (REGISTER_WORD_SIZE)))                          
 

static inline uint32 PERIPH_GET_BIT_OFFSET(BIT_POSTION,REG_ADDRESS)  
{
  return ((BIT_POSTION) + ((((REG_ADDRESS) - (PERIPH_BIT_BAND_BASE_ADDRESS)) / 
  (REGISTER_WORD_SIZE)) * (REGISTER_SIZE)));
}                          
static inline uint32  GET_PERIPH_ALIAS_REG_ADDRESS(BIT_POSTION,REG_ADDRESS)  
{
return ((PERIPH_BIT_BAND_ALIAS_BASE_ADDRESS) + ((PERIPH_GET_BIT_OFFSET(BIT_POSTION,REG_ADDRESS)) * 
                (REGISTER_WORD_SIZE)));
}
#endif
