/* Script2 (TM) @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /bsq.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_config.h>
#if SEAM >= SCRIPT2_DIC
#ifndef SCRIPT2_BSQ_C
#define SCRIPT2_BSQ_C

#include "typevalue.h"

namespace _ {

/* Utility class for printing B-Sequences. */
struct Bsq {
  const ISC* params;  //< Bsq params.

  Bsq(const ISC* params) : params(params) {
    // Nothing to do here! (:-)-+=<
  }
};

#if ALU_SIZE == ALU_16_BIT
inline ISB UnpackSVI(ISB value) {
  if (value < 0) {
    IUB result = 0x8000 return result | ~(value - 1);
  }
  return value;
}

inline ISB PackSVI(ISB value) {
  if (value < 0) {
    IUB result = 1 << 15;
    return result | ((~value + 1) << 1);
  }
  return value;
}
#else
inline ISC UnpackSVI(ISC value) {
  if (value < 0) {
    IUC result = 0x80000000;
    return result | ~(value - 1);
  }
  return value;
}

inline ISC PackSVI(ISC value) {
  if (value < 0) {
    ISC result = 0x80000000;
    return result | ((~value + 1) << 1);
  }
  return value;
}
#endif

inline ISD UnpackSV8(ISD value) {
  if (value < 0) {
    ISD result = 0x8000000000000000;
    return result | ~(value - 1);
  }
  return value;
}

inline ISD PackSV8(ISD value) {
  if (value < 0) {
    ISD result = 0x8000000000000000;
    return result | ((~value + 1) << 1);
  }
  return value;
}

// template<typename T>
// T UnpackSVI (T value) {
//    T temp = value << sizeof (T) * 8 - 1;
//    temp |= value;
//    return temp;
//}

constexpr ISC CBsqSize(const ISC* params) {
  if (!params) {
    return 0;
  }
  ISC size_bytes = sizeof(ISC), count = *params++;

  if (count > cParamsMax) {
    return 0;
  }

  for (; count > 0; --count) {
    ISC param = *params++;

    if (param == cNIL) {  // This is illegal.
      return 0;
    }
    if (param <= kTKN) {
      size_bytes += sizeof(ISC);
      ++params;
    }
    if (param == cISE) {
      size_bytes += sizeof(ISC);
      ++params;
    }
    if (param == cIUE) {
      size_bytes += sizeof(ISC);
      ++params;
    }
    if (param >= cLST && param <= kMAP) {  // This is illegal.
      return 0;
    }
    if (param > kMAP) {
      if (param >> 8) {  // This is an error.
        return 0;
      }
      if (param & 0x20) {     // It's a multi-dimensional array so
        param = *params;      // add the number_ of dimensions + 1;
        params += param + 1;  // for the dimension count.
      }
    }
    size_bytes += sizeof(ISC);
  }
  return size_bytes;
}

/* Creates a immutable Script B-Sequence.
    C++11 variadic template to ensure only one copy in ROM
    and to eliminate some redundant typing. */
template <const ISC... N>
inline const ISC* Params() {
  static const ISC cSize = 0,  // BsqSize ({ N... })
      kList[sizeof...(N)] = {N...};
  return &cSize;
}

/* Prints out the kBSQ parameters. */
LIB_MEMBER UTF1& PrintBsq(UTF1& printer, const ISC* params);

/*  Prints out the parameters. */
// LIB_MEMBER UTF& PrintBsq (const ISC* bsq, UTF& utf);

/*< Returns the requested parameter number_. */
LIB_MEMBER ISC BsqParamNumber(const ISC* bsq, ISC param_number);

}  // namespace _

#if USING_UTF8 == YES_0
/*  Prints out the parameters. */
inline _::UTF1& operator<<(_::UTF1& printer, _::Bsq bsq) {
  return _::PrintBsq(printer, bsq.params);
}
#endif  //< USING_UTF8
#if USING_UTF16 == YES_0
/*  Prints out the parameters. */
inline _::UTF2& operator<<(_::UTF2& printer, _::Bsq bsq) {
  return _::PrintBsq(printer, bsq.params);
}
#endif  //< USING_UTF16
#if USING_UTF32 == YES_0
/*  Prints out the parameters. */
inline _::UTF4& operator<<(_::UTF4& printer, _::Bsq bsq) {
  return _::PrintBsq(printer, bsq.params);
}
#endif  //< USING_UTF8 == YES_0

#endif  //< SCRIPT2_BSQ_C
#endif  //< #if SEAM >= SCRIPT2_DIC