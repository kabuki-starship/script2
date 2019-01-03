/* Script
@version 0.x
@file    /wall.h
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2018 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#pragma once
#include <pch.h>
#if SEAM >= _0_0_0__14
#ifndef SCRIPT2_WALL
#define SCRIPT2_WALL
#include "door.h"
#include "cop.h"

namespace _ {

/* A memory aligned singled contiguous socket in a Chinese Room.
Only one single wall is required for a Chinese Room, but when more memory is
needed a new Wall may be created and destroyed dynamically.

@code
+--------------+
|  Terminals   |
|      v       |
|vvvvvvvvvvvvvv|
|    Buffer    |
|^^^^^^^^^^^^^^|
|      ^       |
|  TSTack of   |
|    Doors     |
|   Offsets    |
|--------------|
|    Header    |
+--------------+
@endcode
*/
class Wall {
 public:
  enum {
    kMinSizeBytes = 512,  //< Min functional Wall size.
  };

  virtual ~Wall();

  Wall(TCArray<Door*>* doors);

  /* Constructs a wall from the given socket. */
  Wall(size_t size_bytes = kMinSizeBytes);

  /* Constructs a wall from the given socket. */
  Wall(UIW* socket, size_t size_bytes);

  /* Gets the size of the wall in bytes. */
  size_t GetSizeBytes();

  /* Gets a pointer to the array of pointers to Door(string_). */
  TCArray<Door*>* Doors();

  /* Gets the Door from the Door at the given index. */
  Door* GetDoor(int index);

  /* Adds a Door to the slot.
  @return Returns nil if the Door is full and a pointer to the Door in the
          socket upon success. */
  int OpenDoor(Door* door);

  /* Deletes the Door from the Door at the given index. */
  BOL CloseDoor(int index);

  /* Prints the given Door to the stdout. */
  Slot& Print(Slot& slot);

 private:
  BOL is_dynamic_;         //< Flag for if using dynamic memory.
  size_t size_bytes_;      //< Size of the Wall in bytes.
  UIW* begin;              //< The Wall's socket.
  TCArray<Door*>* doors_;  //< The doors in the room.
};

}  // namespace _
#endif  //< SCRIPT2_WALL
#endif  //< #if SEAM >= _0_0_0__14
