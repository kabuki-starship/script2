/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/script2_vk.cc
@author  Cale McCollough <cale@astartup.net>
@license Copyright (C) 2014-2019 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#if SEAM >= SCRIPT2_3
#include "c_vk.h"

#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <iostream>

namespace _ {

const UI1* KeyboardHIDToNative() {
#if PLATFORM == WINDOWS
  static const UI1 kHIDToNative[256] = {
      255, 255, 255, 255, 65,  66,  67,  68,  69,  70,  71,  72,  73,  74,  75,
      76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,  88,  89,  90,
      49,  50,  51,  52,  53,  54,  55,  56,  57,  48,  13,  27,  8,   9,   32,
      189, 187, 219, 221, 220, 255, 186, 222, 192, 188, 190, 191, 20,  112, 113,
      114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 44,  145, 19,  45,  36,
      33,  46,  35,  34,  39,  37,  40,  38,  144, 111, 106, 109, 107, 255, 97,
      98,  99,  100, 101, 102, 103, 104, 105, 96,  110, 255, 255, 255, 255, 124,
      125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 17,
      16,  18,  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255};
  return kHIDToNative;
#elif PLATFORM == MAC
  static const UI1 kHIDToNative[256] = {
      255, 255, 255, 255, 0,   11,  8,   2,   14,  3,   5,   4,   34,  38,  40,
      37,  46,  45,  31,  35,  12,  15,  1,   17,  32,  9,   13,  7,   16,  6,
      18,  19,  20,  21,  23,  22,  26,  28,  25,  29,  36,  53,  51,  48,  49,
      27,  24,  33,  30,  42,  255, 41,  39,  50,  43,  47,  44,  57,  122, 120,
      99,  118, 96,  97,  98,  100, 101, 109, 103, 111, 255, 255, 255, 255, 115,
      116, 117, 119, 121, 124, 123, 125, 126, 71,  75,  67,  78,  69,  76,  83,
      84,  85,  86,  87,  88,  89,  91,  92,  82,  65,  255, 255, 255, 81,  105,
      107, 113, 106, 64,  79,  80,  90,  255, 255, 255, 255, 255, 114, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 59,
      56,  58,  55,  62,  60,  61,  54,  255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255};
  return kHIDToNative;
#elif PLATFORM == EVDEV
  static const UI1 kHIDToNative[256] = {
      255, 255, 255, 255, 38,  56,  54,  40,  26,  41,  42,  43,  31,  44,  45,
      46,  58,  57,  32,  33,  24,  27,  39,  28,  30,  55,  25,  53,  29,  52,
      10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  36,  9,   22,  23,  65,
      20,  21,  34,  35,  51,  255, 47,  48,  49,  59,  60,  61,  66,  67,  68,
      69,  70,  71,  72,  73,  74,  75,  76,  95,  96,  107, 78,  127, 118, 110,
      112, 119, 115, 117, 114, 113, 116, 111, 77,  106, 63,  82,  86,  104, 87,
      88,  89,  83,  84,  85,  79,  80,  81,  90,  91,  94,  255, 255, 125, 191,
      192, 193, 194, 195, 196, 197, 198, 199, 200, 201, 202, 255, 255, 135, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 37,
      50,  64,  133, 105, 62,  108, 134, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255};
  return kHIDToNative;
#endif
}

const UI1* KeyboardNativeToHID() {
#if PLATFORM == WINDOWS
  static const UI1 kNativeToHID[256] = {
      255, 255, 255, 255, 255, 255, 255, 255, 42,  43,  255, 255, 255, 40,  255,
      255, 225, 224, 226, 72,  57,  255, 255, 255, 255, 255, 255, 41,  255, 255,
      255, 255, 44,  75,  78,  77,  74,  80,  82,  79,  81,  255, 255, 255, 70,
      73,  76,  255, 39,  30,  31,  32,  33,  34,  35,  36,  37,  38,  255, 255,
      255, 255, 255, 255, 255, 4,   5,   6,   7,   8,   9,   10,  11,  12,  13,
      14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,  26,  27,  28,
      29,  255, 255, 255, 255, 255, 98,  89,  90,  91,  92,  93,  94,  95,  96,
      97,  85,  87,  255, 86,  99,  84,  58,  59,  60,  61,  62,  63,  64,  65,
      66,  67,  68,  69,  104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114,
      115, 255, 255, 255, 255, 255, 255, 255, 255, 83,  71,  255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 51,  46,  54,  45,  55,  56,  53,  255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 47,  49,  48,  52,  255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255};
  return kNativeToHID;
#elif PLATFORM == MAC
  static const UI1 kNativeToHID[128] = {
      4,   22,  7,   9,   11,  10,  29,  27,  6,   25,  255, 5,   20,  26,  8,
      21,  28,  23,  30,  31,  32,  33,  35,  34,  46,  38,  36,  45,  37,  39,
      48,  18,  24,  47,  12,  19,  40,  15,  13,  52,  14,  51,  49,  54,  56,
      17,  16,  55,  43,  44,  53,  42,  255, 41,  231, 227, 225, 57,  226, 224,
      229, 230, 228, 255, 108, 99,  255, 85,  255, 87,  255, 83,  255, 255, 255,
      84,  88,  255, 86,  109, 110, 103, 98,  89,  90,  91,  92,  93,  94,  95,
      111, 96,  97,  255, 255, 255, 62,  63,  64,  60,  65,  66,  255, 68,  255,
      104, 107, 105, 255, 67,  255, 69,  255, 106, 117, 74,  75,  76,  61,  77,
      59,  78,  58,  80,  79,  81,  82,  255};
  return kNativeToHID;
#elif PLATFORM == EVDEV
  static const UI1 kNativeToHID[256] = {
      255, 255, 255, 255, 255, 255, 255, 255, 255, 41,  30,  31,  32,  33,  34,
      35,  36,  37,  38,  39,  45,  46,  42,  43,  20,  26,  8,   21,  23,  28,
      24,  12,  18,  19,  47,  48,  40,  224, 4,   22,  7,   9,   10,  11,  13,
      14,  15,  51,  52,  53,  225, 49,  29,  27,  6,   25,  5,   17,  16,  54,
      55,  56,  229, 85,  226, 44,  57,  58,  59,  60,  61,  62,  63,  64,  65,
      66,  67,  83,  71,  95,  96,  97,  86,  92,  93,  94,  87,  89,  90,  91,
      98,  99,  255, 255, 100, 68,  69,  255, 255, 255, 255, 255, 255, 255, 88,
      228, 84,  70,  230, 255, 74,  82,  75,  80,  79,  77,  81,  78,  73,  76,
      255, 255, 255, 255, 255, 103, 255, 72,  255, 255, 255, 255, 255, 227, 231,
      118, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 104, 105, 106, 107,
      108, 109, 110, 111, 112, 113, 114, 115, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
      255};
  return kNativeToHID;
#endif
}

const CH1* KeyIdName() {
  static const CH1 kKeyIdName[598] =
      "0\0001\0002\0003\0004\0005\0006\0007\0008\0009\0A\0B\0Backslash\0C\0Caps"
      "Lock\0Comma\0D\0Delete\0DeleteForward\0Down\0E\0End\0Enter\0Equals\0"
      "Escape\0F\0F1\0F10\0F11\0F12\0F13\0F14\0F15\0F16\0F17\0F18\0F19\0F2\0F20"
      "\0F21\0F22\0F23\0F24\0F3\0F4\0F5\0F6\0F7\0F8\0F9\0G\0Grave\0H\0Help\0Hom"
      "e\0I\0Insert\0J\0K\0KP0\0KP1\0KP2\0KP3\0KP4\0KP5\0KP6\0KP7\0KP8\0KP9\0"
      "KPAdd\0KPDivide\0KPEnter\0KPEquals\0KPMultiply\0KPNumLock\0KPPoint\0"
      "KPSubtract\0L\0Left\0LeftAlt\0LeftBracket\0LeftControl\0LeftGUI\0Left"
      "Shift\0M\0Menu\0Minus\0N\0NonUSBackslash\0O\0P\0PageDown\0PageUp\0Pause"
      "\0Period\0PrintScreen\0Q\0Quote\0R\0Right\0RightAlt\0RightBracket\0Right"
      "Control\0RightGUI\0RightShift\0S\0ScrollLock\0Semicolon\0Slash\0Space\0T"
      "\0Tab\0U\0Up\0V\0W\0X\0Y\0Z";
  return kKeyIdName;
}

const SI2* KeyIdOffset() {
  static const SI2 kKeyIdOffset[256] = {
      -1,  -1,  -1,  -1,  20,  22,  34,  51,  79,  105, 194, 202, 214, 223, 225,
      339, 396, 409, 426, 428, 471, 479, 542, 577, 583, 588, 590, 592, 594, 596,
      2,   4,   6,   8,   10,  12,  14,  16,  18,  0,   85,  98,  53,  579, 571,
      403, 91,  354, 496, 24,  -1,  555, 473, 196, 45,  452, 565, 36,  107, 150,
      173, 176, 179, 182, 185, 188, 191, 110, 114, 118, 459, 544, 446, 216, 209,
      439, 60,  81,  430, 481, 341, 74,  585, 310, 273, 299, 328, 267, 282, 231,
      235, 239, 243, 247, 251, 255, 259, 263, 227, 320, 411, -1,  -1,  290, 122,
      126, 130, 134, 138, 142, 146, 153, 157, 161, 165, 169, -1,  204, 398, -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  366,
      386, 346, 378, 509, 531, 487, 522, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      -1};
  return kKeyIdOffset;
  return nullptr;
}

inline const UI1* KeyIdOrder() {
  static const UI1 kKeyIdOrder[119] = {
      39,  30,  31,  32,  33,  34,  35,  36,  37,  38,  4,   5,   49,  6,   57,
      54,  7,   42,  76,  81,  8,   77,  40,  46,  41,  9,   58,  67,  68,  69,
      104, 105, 106, 107, 108, 109, 110, 59,  111, 112, 113, 114, 115, 60,  61,
      62,  63,  64,  65,  66,  10,  53,  11,  117, 74,  12,  73,  13,  14,  98,
      89,  90,  91,  92,  93,  94,  95,  96,  97,  87,  84,  88,  103, 85,  83,
      99,  86,  15,  80,  226, 47,  224, 227, 225, 16,  118, 45,  17,  100, 18,
      19,  78,  75,  72,  55,  70,  20,  52,  21,  79,  230, 48,  228, 231, 229,
      22,  71,  51,  56,  44,  23,  43,  24,  82,  25,  26,  27,  28,  29};
  return kKeyIdOrder;
}

SI4 KeyIdCodeFromName(const CH1* name) {
  unsigned l = 0, r = 119, m;
  SI4 x, c;
  while (l < r) {
    m = (l + r) / 2;
    x = KeyIdOrder()[m];
    c = strcmp(name, KeyIdName() + KeyIdOffset()[x]);
    if (c < 0)
      r = m;
    else if (c > 0)
      l = m + 1;
    else
      return x;
  }
  return -1;
}

const CH1* KeyIdNameFromCode(SI4 code) {
  SI4 offset;
  if (code < 0 || code > 255) return 0;
  offset = KeyIdOffset()[code];
  if (offset == (UI2)-1) return 0;
  return KeyIdName() + offset;
}

KeyId::KeyId(VKCode vk_code, const CH1* label)
    : vk_code(vk_code), label(label) {}

void KeyId::ReprogramConsole() {}

}  // namespace _
#endif  //< #if SEAM >= SCRIPT2_3
