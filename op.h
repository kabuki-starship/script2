/* Script2 (TM) @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /op.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-20 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_config.h>

#if SEAM >= SCRIPT2_ROOM
#ifndef INCLUDED_SCRIPT2_OP
#define INCLUDED_SCRIPT2_OP 1

#include "strand.hpp"

namespace _ {

// enum {
//    cOpPush          = 0, //< Operation Type 0: Stack push .
//    cOpOperation     = 1, //< Operation Type 1: Abstract Operation.
//    cOpOperationPush = 2, //< Operation Type 2: Operation with stack push.
//};

struct BOut;

/* An expression Operation with name key, multiple input params,
    result, and optional description of a data set.
    @code
    static const Op kThis = { "Key",
        Params<1, 2>::Header, Params<1, 2>::Header,
        "Description", '}', ';', ' ', nullptr, "-", nullptr };

    static const Op kOpExample =   { "Key2",
        NumOps (0), FirstOp ('A'),
        "Description", '}', ';', ' ', true, nullptr, "-", nullptr };
    @endcode */
struct LIB_MEMBER Op {
  const CHA* name;          //< Op name.
  const ISC *in,            //< Input kBSQ params or OpFirst.
      *out;                 //< Output kBSQ params or OpLast.
  const CHA* description;   //< Op description.
  CHC pop,                  //< Index of the Pop Operation.
      close,                //< Index of the Close Operation.
      default_op;           //< Index of the Default Operation.
  BOL using_numbers;        //< Flag for if tokens may use numbers.
  const CHA *ignore_chars,  //< Strand of chars to ignore.
      *allowed_chars;       //< Strand of allowed symbols.
  const BOut* evaluation;   //< Evaluated expression Slot.
};

/* Converts the given value to a pointer. */
inline ISW OpCount(const Op& op) { return op.out - op.in; }

/* Converts the given value to a pointer. */
inline const ISC* OpFirst(CHC index) {
  return reinterpret_cast<const ISC*>(index);
}

/* Converts the given value to a pointer. */
inline CHC OpFirst(const Op* op) {
  A_ASSERT(op);
  return (CHC) reinterpret_cast<UIW>(op->in);
}

/* Converts the given value to a pointer. */
inline const ISC* OpLast(CHC index) {
  return reinterpret_cast<const ISC*>(index);
}

/* Converts the given value to a pointer. */
inline CHC OpLast(const Op* op) {
  A_ASSERT(op);
  return (CHC) reinterpret_cast<UIW>(op->out);
}

#if USING_SCRIPT2_TEXT == YES_0
template <typename CHT>
TSPrinter<CHT>& Print(TSPrinter<CHT>& utf, const Op* op) {}
#endif

}  // namespace _

template <typename CHT>
inline _::TSPrinter<CHT>& operator<<(_::TSPrinter<CHT>& utf,
                                      const _::Op* op) {
  return _::Print(utf, op);
}

#endif  //< #if INCLUDED_SCRIPT2_OP 1
#endif  //< #if SEAM >= SCRIPT2_DIC
