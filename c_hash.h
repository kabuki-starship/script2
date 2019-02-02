/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/c_hash.h
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

#if SEAM >= SCRIPT2_9

#ifndef INCLUDED_SCRIPTHASH
#define INCLUDED_SCRIPTHASH
#include "c_onfig.h"

typedef UI2 hash16_t;
typedef UI4 hash32_t;
typedef UI8 hash64_t;

namespace _ {

/* Basic prime multiple hash algorithm.
@return hash + value * hash.
@param  value The CH1 value to hash.
@param  hash  The hash. */
SDK inline hash16_t Hash16(CH1 value, hash16_t hash = 65535);

/* Basic prime multiple hash algorithm.
@return hash + value * hash.
@param  value The CH1 value to hash.
@param  hash  The hash. */
SDK inline hash32_t Hash32(CH2 value, hash32_t hash = 4294967291);

/* Basic prime multiple hash algorithm.
@return hash + value * hash.
@param  value The CH1 value to hash.
@param  hash  The hash. */
SDK inline hash64_t Hash64(CH4 value,
                           hash64_t hash = 18446744073709551557);

/* Hashes the given CH1 using the primeHash function.
If you are experiencing collisions in your hash table, you may want to change
the see to a different prime number_.
@return A prime multiple hash of the given .
@param   The  to hash.
@param  hash   A prime number_ seed hash. */
SDK hash16_t Hash16(const CH1* , hash16_t hash = 65535);

/* Hashes the given CH1 using the primeHash function.
If you are experiencing collisions in your hash table, you may want to change
the see to a different prime number_.
@return A prime multiple hash of the given .
@param   The  to hash.
@param  hash   A prime number_ seed hash. */
SDK hash32_t Hash32(const CH1* , hash32_t hash = 4294967291);

/* Hashes the given CH1 using the primeHash function.
If you are experiencing collisions in your hash table, you may want to change
the see to a different prime number_.
@return A prime multiple hash of the given .
@param   The  to hash.
@param  hash   A prime number_ seed hash. */
SDK hash64_t Hash64(const CH1* , hash64_t hash = 18446744073709551557);

}  // namespace _
#endif  //< #if SEAM >= SCRIPT2_9
#endif  //< INCLUDED_SCRIPTHASH