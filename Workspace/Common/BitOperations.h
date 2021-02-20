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

#endif
