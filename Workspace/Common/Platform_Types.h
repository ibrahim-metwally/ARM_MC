/****************************************************************************************/
/** \file    Platform_Types.h
 *
 *  \brief  This file provide platform types.
 * 
 *  \author Ibrahim Metwally
 */
/****************************************************************************************/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


#ifndef TRUE
#define TRUE         1U
#endif

#ifndef FALSE
#define FALSE        0U
#endif

#define LOW_BYTE_FIRST     0U   /*Little Endian*/
#define HIGH_BYTE_FIRST    1U   /*Big    Endian*/

#define CPU_BYTE_ORDER     LOW_BYTE_FIRST

/****************************************************************************************/
/* GOBAL DATA TYPES*/
/****************************************************************************************/

typedef unsigned char           uint8;        /* 0 to 255                         */
typedef signed char             sint8;        /* -127 to  128                     */
typedef unsigned short int      uint16;       /* 0 to 65,535                      */
typedef signed short int        sint16;       /* −32768 to 32,767                 */
typedef unsigned long int       uint32;       /* 0  to 4,294,967,295              */
typedef signed short int        sint32;       /* -2,147,483,648  to 2,147,483,647 */
typedef unsigned long long int  uint64;       /* 0  to 18,446,744,073,709,551,615 */
typedef signed long long int    sint64;       /* -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807*/

typedef float  floaf32;
typedef double float64;

typedef uint8 boolean;

#endif
