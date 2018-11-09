/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script.git
@file    /script2_hash.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>
#if SEAM >= _0_0_0__06
#include "thash.h"

namespace _ {

hash16_t Hash16(char value, hash16_t hash) { return hash + hash * value; }

hash16_t Hash16(const char* string, hash16_t hash) {
  UI1 c = *string;
  while (c) {
    hash = Hash16(c, hash);
    ++string;
    c = *string;
  }
  return hash;
}

hash32_t Hash32(char16_t value, hash32_t hash) { return hash + hash * value; }

hash32_t Hash32(const char* string, hash32_t hash) {
  UI1 c = *string;
  while (c) {
    hash = Hash32(c, hash);
    ++string;
    c = *string;
  }
  return hash;
}
hash64_t Hash64(char32_t value, hash64_t hash) { return hash + hash * value; }

hash64_t Hash64(const char* string, hash64_t hash) {
  UI1 c = *string;
  while (c) {
    hash = Hash64(c, hash);
    ++string;
    c = *string;
  }
  return hash;
}

UI2 Hash16UI2(UI2 value, UI2 hash) {
  UI2 prime = PrimeMaxUnigned<UI2>();
  hash = ((value & 0xff) * prime) + hash;
  hash = ((value >> 8) * prime) + hash;
  return hash;
}

UI2 Hash16UI4(UI4 value, UI2 hash) {
  UI2 prime = PrimeMaxUnigned<UI2>();
  hash = ((value & 0xff) * prime) + hash;
  hash = (((value >> 8) & 0xff) * prime) + hash;
  hash = (((value >> 16) & 0xff) * prime) + hash;
  hash = (((value >> 24) & 0xff) * prime) + hash;
  return hash;
}

UI2 Hash16UI8(UI8 value, UI2 hash) {
  UI2 prime = PrimeMaxUnigned<UI2>();
  hash = ((value & 0xff) * prime) + hash;
  hash = (((value >> 8) & 0xff) * prime) + hash;
  hash = (((value >> 16) & 0xff) * prime) + hash;
  hash = (((value >> 24) & 0xff) * prime) + hash;
  hash = (((value >> 32) & 0xff) * prime) + hash;
  hash = (((value >> 40) & 0xff) * prime) + hash;
  hash = (((value >> 48) & 0xff) * prime) + hash;
  hash = (((value >> 56) & 0xff) * prime) + hash;
  return hash;
}

}  //< namespace _
#endif  //> #if SEAM >= _0_0_0__06