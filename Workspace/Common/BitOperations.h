/****************************************************************************************/
/** \file    BitOperation.h
 *
 *  \brief  This file provide Compiler macros.
 * 
 *  \author Ibrahim Metwally
 */
/****************************************************************************************/


#ifndef BIT_OPERATION_H
#define BIT_OPERATION_H

#define SET_BIT(Byte,BitPostion)           ((Byte)|(0x01<<(BitPostion)))

#define CLEAR_BIT(Byte,BitPostion)         ((Byte)&(~(0x01<<(BitPostion))))

#define GET_BIT(Byte,BitPostion)           ((0x01)&(Byte>>(BitPostion)))

#define SRAM_BIT_BAND_BASE_ADDRESS                  0x20000000

#define SRAM_BIT_BAND_ALIAS_BASE_ADDRESS            0x22000000

#define REGISTER_SIZE                               32  /*Bits*/

#define REGISTER_WORD_SIZE                          4   /*Bytes*/

#define GET_BIT_OFFSET(BIT_POSTION,REG_ADDRESS)  \
((BIT_POSTION) + ((((REG_ADDRESS) - (SRAM_BIT_BAND_BASE_ADDRESS)) / (REGISTER_WORD_SIZE)) * (REGISTER_SIZE)))
                           
#define GET_ALIAS_REG_ADDRESS(BIT_OFFESET)  \
((SRAM_BIT_BAND_ALIAS_BASE_ADDRESS) + ((BIT_OFFESET) * (REGISTER_WORD_SIZE)))                        

#endif
