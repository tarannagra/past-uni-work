/* Copyright (C) 2023 Harry Clark - Student No. 12340530 */
/* DATE: 02/02/23 */

#pragma once

/* DECLARATION OF DATA TYPES FOR THE USE CASE */
/* OF OUR OWN DATA STRUCTURES */

/* ALL OF THIS INFORMATON IS LEARNT FROM 4004CEM */
/* COMPUTER ARCHITECURE */

/* WE WENT ABOUT DECLARING OUR OWN DATA TYPES FOR */
/* SCALBILITY PURPOSES AS WELL AS MAKING OUR METHODS */
/* TYPE DEFINED */

/* TYPE DEFINED DATA TYPES ALLOW FOR US TO DECLARE METHODS */
/* BY AN ABBREVIATION TO MINIMISE BOILERPLATE CODE */

/* SOURCE USED: https://www.tutorialspoint.com/cprogramming/c_typedef.htm */
/* https://en.cppreference.com/w/cpp/language/typedef */


#ifndef COMMON_TYPES
#define COMMON_TYPES

#include <string>
#include <stdint.h>
#include <Windows.h>

#ifndef UNSIGNED_TYPES
#define UNSIGNED_TYPES

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;

#endif 

#ifndef SIGNED_TYPES
#define SIGNED_TYPES

typedef int8_t S8;
typedef int16_t S16;
typedef int32_t S32;
typedef int64_t S64;

#endif 

#ifndef WIDE_TYPES
#define WIDE_TYPES

using std::wstring;

typedef wchar_t WIDE_CHAR;
typedef wstring WIDE_STRING;

#endif 

#ifndef UNKNOWN_TYPES
#define UNKNOWN_TYPES

typedef unsigned char UNK_8;
typedef unsigned short UNK_16;
typedef unsigned int UNK_32;
typedef unsigned long UNK_64;
typedef unsigned long UNK_;
typedef size_t UNK_SIZE;

#endif

#ifndef MISC_WINDOWS_TYPES
#define MISC_WINDOWS_TYPES

typedef short SHORT; // Bart Simpson would say "eat my shorts" 
typedef COORD COORD_BUFF;

#endif

#ifndef FLOATING_POINT
#define FLOATING_POINT 

typedef float F32;
typedef double F64;
typedef volatile F32 VF32;
typedef volatile F64 VF64;

#endif
#endif
