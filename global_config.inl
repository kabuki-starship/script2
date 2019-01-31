/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/global_config.inl
@author  Cale McCollough <cale@astartup.net>
@license Copyright (C) 2014-2019 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once

#ifndef SCRIPT2_GLOBAL_INLINE_CONFIG
#define SCRIPT2_GLOBAL_INLINE_CONFIG 1

#define WORD_SIZE 64

#define SDK

#include <climits>
#include <cstdarg>
#include <cstdint>
#include <new>

#define UTF8 1
#define UTF16 2
#define UTF32 4
#define USING_UTF UTF8
#define USING_UTF8 YES
#define USING_UTF16 NO
#define USING_UTF32 NO

#define SCRIPT2_CHAR_SIZE UTF8

typedef char CH1;
typedef char16_t CH2;
typedef char32_t CH4;
typedef wchar_t CHW;

typedef int8_t SI1;
typedef uint8_t UI1;
typedef int16_t SI2;
typedef uint16_t UI2;
typedef UI2 HLF;
typedef HLF FP2;
typedef bool BOL;
typedef int32_t SI4;
typedef uint32_t UI4;
typedef float FP4;
typedef FP4 FLT;
typedef int32_t TM4;
typedef int64_t TM8;
typedef int64_t SI8;
typedef uint64_t UI8;
typedef double DBL;
typedef DBL FP8;

typedef uintptr_t UIW;
typedef intptr_t SIW;

typedef SI4 SIN;
typedef UI4 UIN;

typedef CH1 CHT;  //< Default Char type.

#if WORD_SIZE == 64
typedef DBL FPW;
#else
typedef FLT FPW;
#endif

enum {
  NIL = 0,
  kWordBitCount = (sizeof(void*) == 2)
                      ? 1
                      : (sizeof(void*) == 4) ? 2 : (sizeof(void*) == 8) ? 3 : 0,
  kWordLSbMask = sizeof(void*) - 1,
  kStackCountMaxDefault = 16,
  kObjSizeDefault = 256,
  kAlignMask = 0x7,
  kStrandCountMax = 32,
  kPrintC0Offset = 176,    //< Value add to values 0-32 when printing.
  kTokenCount = 32,    //< Max length of a token plus one.
};

#define STRANDFACTORY TStrandFactoryStack
#define STACKFACTORY TStrandFactoryStack
#define ARRAYFACTORY TStrandFactoryStack
#define MAPFACTORY TStrandFactoryStack
#define BOOKFACTORY TStrandFactoryStack
#define DICFACTORY TStrandFactoryStack

#if COMPILER == VISUAL_CPP
#define FORMAT_SI8 "%I64i"
#define FORMAT_UI8 "%I64u"
#else
#define FORMAT_SI8 "%lld"
#define FORMAT_UI8 "%llu"
#endif

#if PLATFORM == WINDOWS
#define APP_EXIT_SUCCESS 0
#define APP_EXIT_FAILURE 1
#else
#define APP_EXIT_SUCCESS 0
#define APP_EXIT_FAILURE 1
#endif

#define SCRIPT2_0 1   //< rng
#define SCRIPT2_1 2   //< itos_and_stoi
#define SCRIPT2_2 3   //< socket
#define SCRIPT2_3 4   //< ascii_strings_and_socket
#define SCRIPT2_4 5   //< ftos_and_stof
#define SCRIPT2_5 6   //< clock
#define SCRIPT2_6 7   //< stack
#define SCRIPT2_7 8   //< array
#define SCRIPT2_8 9   //< loom
#define SCRIPT2_9 10  //< table
#define SCRIPT2_10 11  //< list
#define SCRIPT2_11 12  //< map
#define SCRIPT2_12 13  //< book
#define SCRIPT2_13 14  //< dictionary
#define SCRIPT2_14 15  //< expr
#define SCRIPT2_15 16  //< door
#define SCRIPT2_16 17  //< room
#define SEAM_N 17
#endif  //< #ifndef SCRIPT2_GLOBAL_INLINE_CONFIG
