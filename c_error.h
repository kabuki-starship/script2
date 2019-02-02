/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/error.h
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
#include <pch.h>
#if SEAM >= SCRIPT2_14
#ifndef SCRIPT2_ERROR
#define SCRIPT2_ERROR

namespace _ {

typedef enum ScriptError {
  kErrorNotAnError = 0,       //< Script Error  0: Not an error.
  kErrorInputNil,             //< Script Error  1: Nil input.
  kErrorInputTooLow,          //< Script Error  2: Input too low.
  kErrorInputTooHigh,         //< Script Error  3: Input too high.
  kErrorBufferOverflow,       //< Script Error  4: Buffer overflow.
  kErrorBufferUnderflow,      //< Script Error  5: Buffer underflow.
  kErrorVarintOverflow,       //< Script Error  6: Varint overflow.
  kErrorInvalidHash,          //< Script Error  7: Invalid hash.
  kErrorInvalidType,          //< Script Error  8: Invalid type.
  kErrorInvalidIndex,         //< Script Error  9: Invalid index.
  kErrorInvalidEnquery,       //< Script Error 10: Invalid inquiry.
  kErrorInvalidArgument,      //< Script Error 11: Invalid argument.
  kErrorInvalidDoor,          //< Script Error 12: Invalid door.
  kErrorTooManyParameters,    //< Script Error 13: Too many parameters.
  kErrorStackOverflow,        //< Script Error 14: Stack overflow.
  kErrorTooManyPops,          //< Script Error 15: Too many pops.
  kErrorTextOverflow,         //< Script Error 16: Text overflow.
  kErrorInvalidErrorHandler,  //< Script Error 17: Invalid error handler.
  kErrorInvalidOperand,       //< Script Error 18: Invalid operand.
  kErrorArrayOverflow,        //< Script Error 19: Array overflow.
  kErrorInvalidOp,            //< Script Error 20: Invalid op.
  kErrorMalformedUTF8,        //< Script Error 21: Malformed UTF-8.
  kErrorMalformedUTF16,       //< Script Error 22: Malformed UTF-16.
  kErrorMalformedUTF32,       //< Script Error 23: Malformed UTF-32.
  kErrorObjLocked,            //< Script Error 24: CObject locked.
  kErrorInvalidArgs,          //< Script Error 25: Invalid args.
  kErrorAuthenticationError,  //< Script Error 26: Authentication error.
  kErrorRoomNotFound,         //< Script Error 27: Room not found.
  kErrorImplementation,       //< Script Error 28: Implementation error.
} Error;

/* Returns an array or  pointers for the KabukiError(s). */
SDK const CH1** ErrorStrands();

/* Returns one of the Errors () strings. */
SDK const CH1* ErrorStrand(Error error);

}  // namespace _
#endif  //< SCRIPT2_ERROR
#endif  //< #if SEAM >= SCRIPT2_14