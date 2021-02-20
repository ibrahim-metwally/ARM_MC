/****************************************************************************************/
/** \file    Std_Types.h
 *
 *  \brief  This file provide Standard types.
 * 
 *  \author Ibrahim Metwally
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include "Platform_Types.h"

typedef uint8 Std_ReturnType;

#ifndef NULL_PTR
#define	NULL_PTR	((void *)0)
#endif

#define E_OK 		    0U
#define E_NOT_OK 		1U

#define STD_HIGH		1U
#define STD_LOW			0U

#define STD_ACTIVE		1U
#define STD_IDLE		0U

#define STD_ON			1U
#define STD_OFF			0U

#endif
