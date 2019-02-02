/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/c_address.h
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
#ifndef SCRIPT2_CADDRESS
#define SCRIPT2_CADDRESS 1

#include "c_onfig.h"

namespace _ {

/* C++11 constexpr function for creating Script addresses headers with less
    typing as well as ensuring there is only a single copy in ROM.
    Template solves the problem of not being able using array constructors to
    create data structures in ROM.

    @code
    Address<'A', 'B', 'C'> ()
    @endcode
*/
template <const CH1... N>
SDK const CH1* Address() {
  static const CH1 path[sizeof...(N)] = {N...};
  static const CH1 term_char = 0;
  return path;
}

/* Returns a pointer to static variable for writing the address { a, \0 } to.
 */
inline UI2 PackAddress(UI1 a) { return ((1 << 8) | a); }

/* Returns a pointer to static variable for writing the
    address { a, b, \0, \0 } to. */
inline UI4 PackAddress(UI4 a, UI4 b) {
  return ((1 << 16) | a | (b << 8));
}

/* Returns a pointer to static variable for writing the address { a, b, c, \0 }
    to. */
inline UI4 PackAddress(UI4 a, UI4 b, UI4 c) {
  return ((1 << 24) | a | (b << 8) | (c << 16));
}

/* Returns a pointer to static variable for writing the address { a, b, c, d,
    e, f, g, \0 } to. */
inline UI8 PackAddress(UI8 a, UI8 b, UI8 c, UI8 d) {
  UI8 one = 1;
  return (one << 32 | a | (b << 8) | (c << 16) | (d << 24));
}

/* Returns a pointer to static variable for writing the address { a, b, c, d,
    e, f, g, \0 } to. */
inline UI8 PackAddress(UI8 a, UI8 b, UI8 c, UI8 d,
                            UI8 e) {
  UI8 one = 1;
  return (one << 40 | a | (b << 8) | (c << 16) | (d << 24) | (e << 32));
}

/* Returns a pointer to static variable for writing the address
    { a, b, c, d, e, f, g, \0 } to. */
inline UI8 PackAddress(UI8 a, UI8 b, UI8 c, UI8 d,
                            UI8 e, UI8 f) {
  UI8 one = 1;
  return (one << 48 | a | (b << 8) | (c << 16) | (d << 24) | (e << 32) |
          (f << 40));
}

/* Returns a pointer to static variable for writing the address
    { a, b, c, d, e, f, g, \0 } to. */
inline UI8 PackAddress(UI8 a, UI8 b, UI8 c, UI8 d,
                            UI8 e, UI8 f, UI8 g) {
  UI8 one = 1;
  return (one << 56 | a | (b << 8) | (c << 16) | (d << 24) | (e << 32) |
          (f << 40) | (g << 48));
}

}  // namespace _
#endif  //< SCRIPT2_CADDRESS
#endif  //< #if SEAM >= SCRIPT2_14