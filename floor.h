/* Script2 (TM) @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /floor.h
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */

#pragma once
#include <_config.h>
#if SEAM >= SCRIPT2_DIC
#ifndef SCRIPT2_FLOOR
#define SCRIPT2_FLOOR

namespace _ {

/* Cache-aligned group of global system variables.
The Floor is the Floor in the Chinese Room. In Kabuki Crabs, the floor is
designed to store variables without having to include the classes the variable
controls. For this reason only Strings and POD types are in the Floor.
*/
struct LIB_MEMBER Floor {
  ISB epoch;
};

/* Returns the the global Floor. */
LIB_MEMBER inline Floor* Global();

}  // namespace _

#endif
#endif