/* Copyright (C) 2022 Harry Clark - Student No. 12340530 */
/* DATE: 04/01/23 */

#pragma once

/* THE FOLLOWING IS JUST A LIST OF MACROS TO DEFINE */
/* CROSS COMPATIBILTY BETWEEN WINDOWS API'S, COMPILER CONFIG */
/* AND C LOGIC AND HEADERS */

#ifndef FRAMEWORK
#define FRAMEWORK

#if defined(_WIN32)
#define WIN_32_LEAN_AND_MEAN
#endif

#ifdef __cplusplus
extern "C"
{}
#endif

#define COMPILER_CONFIG
#if defined(_WIN32)
#if MSC_VER >= 1920 && MSVC_LANG >= 2022
#undef COMPILER_CONFIG
#endif

#endif

#endif
