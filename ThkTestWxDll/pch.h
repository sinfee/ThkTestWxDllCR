#pragma once

#if defined(_MSVC_LANG)
#pragma message ("----------_MSVC_LANG is defined!---------")
#endif

#if (__cplusplus >= 201103)
#pragma message ("----------___cplusplus is bigger than 201103!---------")
#endif

#define THK_PRJ_NAME "ThkTestWxDll"

#include "ThkCrWrapInc.h"