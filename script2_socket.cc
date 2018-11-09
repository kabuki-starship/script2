/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script.git
@file    /script2_socket.cc
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>
#if SEAM >= _0_0_0__02

#include "tbinary.h"
#include "tsocket.h"

#if SEAM == _0_0_0__02
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif

namespace _ {

char* AlignDown(char* pointer, uintptr_t mask) {
  return AlignDown<char*>(pointer);
}

const char* AlignDown(const char* pointer, uintptr_t mask) {
  return AlignDown<const char*>(pointer);
}

const uintptr_t* AlignDown(const uintptr_t* pointer, uintptr_t mask) {
  return AlignDown<const uintptr_t*>(pointer);
}

uintptr_t* AlignDown(uintptr_t* pointer, uintptr_t mask) {
  return AlignDown<uintptr_t*>(pointer);
}

uintptr_t* AlignUp(uintptr_t* buffer, uintptr_t mask) {
  return AlignUp<uintptr_t>(buffer, mask);
}

char* AlignUp(char* pointer, uintptr_t mask) {
  return AlignUp<char>(pointer, mask);
}

const char* AlignUp(const char* pointer, uintptr_t mask) {
  return AlignUp<const char>(pointer, mask);
}

UI1 AlignUp(UI1 value, UI1 mask) { return AlignUpUnsigned<UI1>(value, mask); }

SI1 AlignUp(SI1 value, SI1 mask) { return AlignUpSigned<SI1>(value, mask); }

UI2 AlignUp(UI2 value, UI2 mask) { return AlignUpUnsigned<UI2>(value, mask); }

SI2 AlignUp(SI2 value, SI2 mask) { return AlignUpSigned<SI2>(value, mask); }

UI4 AlignUp(UI4 value, UI4 mask) { return AlignUpUnsigned<UI4>(value, mask); }

SI4 AlignUp(SI4 value, SI4 mask) { return AlignUpSigned<SI4>(value, mask); }

UI8 AlignUp(UI8 value, UI8 mask) { return AlignUpUnsigned<UI8>(value, mask); }

SI8 AlignUp(SI8 value, SI8 mask) { return AlignUpSigned<SI8>(value, mask); }

uintptr_t* New(intptr_t size) { return new uintptr_t[size]; }

void Delete(uintptr_t* socket) {
  ASSERT(socket);
  delete[] socket;
}

uintptr_t UIntPtr(const void* value) {
  return reinterpret_cast<uintptr_t>(value);
}

void* VoidPtr(uintptr_t value) { return reinterpret_cast<void*>(value); }

const void* ConstVoidPtr(uintptr_t value) {
  return reinterpret_cast<const void*>(value);
}

intptr_t SizeOf(void* begin, void* end) {
  return reinterpret_cast<char*>(end) - reinterpret_cast<char*>(begin);
}

intptr_t SizeOf(const void* begin, const void* end) {
  return reinterpret_cast<const char*>(end) -
         reinterpret_cast<const char*>(begin);
}

inline uintptr_t FillWord(char fill_char) {
  uintptr_t value = fill_char;
#if CPU_WORD_SIze == 32
  return value | (value << 8) | (value << 16) | (value << 24);
#else
  return value | (value << 8) | (value << 16) | (value << 24) | (value << 32) |
         (value << 48) | (value << 56);
#endif
}

char* SocketFill(char* cursor, char* end, intptr_t byte_count, char fill_char) {
  ASSERT(cursor);
  PRINTF("\ncursor:%p\nbyte_count:%d", cursor, (int)byte_count);
  ASSERT(byte_count >= 0);

  if ((end - cursor) < byte_count) {
    PRINT("\nBuffer overflow!");
    return nullptr;
  }
  end = cursor + byte_count;

  PRINTF("\nFilling %i bytes from %p", (int)byte_count, cursor);

  if (byte_count < (2 * sizeof(void*) + 1)) {
    while (cursor < end) *cursor++ = fill_char;
    return cursor;
  }

  uintptr_t fill_word = FillWord(fill_char);

  // Algorithm:
  // 1.) Save return value.
  // 2.) Align write pointer up and copy the unaligned bytes in
  // the lower
  //     memory region.
  // 3.) Align write_end pointer down and copy the unaligned
  // bytes in the
  //     upper memory region.
  // 4.) Copy the word-aligned middle region.
  char *success = end, *aligned_pointer = AlignUp<>(cursor);
  while (cursor < aligned_pointer) *cursor++ = fill_char;
  aligned_pointer = AlignDown<char*>(end);
  while (end > aligned_pointer) *end-- = fill_char;

  uintptr_t *words = reinterpret_cast<uintptr_t*>(cursor),
            *words_end = reinterpret_cast<uintptr_t*>(end);

  while (words < words_end) *words++ = fill_word;

  return success;
}

char* SocketFill(void* cursor, intptr_t count, char fill_char) {
  return SocketFill(reinterpret_cast<char*>(cursor),
                    reinterpret_cast<char*>(cursor) + count, count, fill_char);
}

BOL SocketWipe(void* cursor, void* end, intptr_t count) {
  return SocketFill(reinterpret_cast<char*>(cursor),
                    reinterpret_cast<char*>(end), count) != nullptr;
}

char* SocketCopy(void* begin, intptr_t size, const void* read,
                 intptr_t read_size) {
  ASSERT(begin);
  ASSERT(read);
  ASSERT(size > 0);
  ASSERT(read_size > 0);

  if (size < read_size) return nullptr;
  char *cursor = reinterpret_cast<char*>(begin), *end_ptr = cursor + size;
  const char *start_ptr = reinterpret_cast<const char*>(read),
             *stop_ptr = start_ptr + read_size;

  if (read_size < (2 * sizeof(void*) + 1)) {
    // There is not enough bytes to copy in words.
    while (start_ptr < stop_ptr) *cursor++ = *start_ptr++;
    return cursor;
  }

  PRINTF("\nCopying %i bytes from %p and writing to %p",
         (int)(stop_ptr - start_ptr), cursor, stop_ptr);

  // Debug stuff.
  char *begin_debug = cursor, *end_debug = end_ptr;

  // Algorithm:
  // 1.) Save return value.
  // 2.) Align write pointer up and copy the unaligned bytes in the lower
  //     memory region.
  // 3.) Align write_end pointer down and copy the unaligned bytes in the
  //     upper memory region.
  // 4.) Copy the word-aligned middle region.
  char *success = end_ptr, *aligned_pointer = AlignUp<>(cursor);
  PRINTF("\n  AlignUpPointer<> (begin):0x%p", aligned_pointer);
  while (cursor < aligned_pointer) *cursor++ = *start_ptr++;
  aligned_pointer = AlignDown<char*>(end_ptr);
  PRINTF("\n  AlignDownPointer<> (begin):0x%p", aligned_pointer);
  while (end_ptr > aligned_pointer) *end_ptr-- = *stop_ptr--;
  PRINTF("\n  Down-stage pointers are now begin:0x%p end:0x%p", cursor,
         end_ptr);

  uintptr_t *words = reinterpret_cast<uintptr_t*>(cursor),
            *words_end = reinterpret_cast<uintptr_t*>(end_ptr);
  const uintptr_t* read_word = reinterpret_cast<const uintptr_t*>(start_ptr);

  while (words < words_end) *words++ = *read_word++;

  return success;
}

char* SocketCopy(void* begin, void* end, const void* begin_read,
                 intptr_t read_size) {
  return SocketCopy(begin, SizeOf(begin, end), begin_read, read_size);
}

char* SocketCopy(void* begin, void* end, const void* begin_read,
                 const void* read_end) {
  return SocketCopy(begin, SizeOf(begin, end), begin_read,
                    SizeOf(begin_read, read_end));
}

BOL SocketCompare(const void* begin_a, intptr_t size_a, const void* begin_b,
                  intptr_t size_b) {
  if (size_a != size_b) return false;
  const char *cursor_a = reinterpret_cast<const char*>(begin_a),
             *end_a = cursor_a + size_a,
             *cursor_b = reinterpret_cast<const char*>(begin_b),
             *end_b = cursor_b + size_b;
  while (cursor_a < end_a) {
    char a = *cursor_a++, b = *end_a++;
    if (a != b) return false;
  }
  return true;
}

BOL SocketCompare(const void* begin, const void* end, const void* start,
                  const void* stop) {
  return SocketCompare(begin, SizeOf(begin, end), start, SizeOf(start, stop));
}

BOL SocketCompare(const void* begin_a, void* end_a, const void* begin_b,
                  intptr_t size_b) {
  return SocketCompare(begin_a, end_a, begin_a,
                       reinterpret_cast<const char*>(begin_b) + size_b);
}

Socket::Socket() {
  // Nothing to do here! (:-)-+=<
}

Socket::Socket(void* begin, void* end)
    : begin(reinterpret_cast<char*>(begin)), end(reinterpret_cast<char*>(end)) {
  if (!begin || !end || begin > end) {
    begin = end = 0;
    return;
  }
}

Socket::Socket(void* begin, intptr_t size)
    : begin(reinterpret_cast<char*>(begin)),
      end(reinterpret_cast<char*>(begin) + size) {
  if (!begin || size < 0) {
    end = reinterpret_cast<char*>(begin);
    return;
  }
}

Socket::Socket(const Socket& other) : begin(other.begin), end(other.end) {
  // Nothing to do here! (:-)-+=<
}

Socket& Socket::operator=(const Socket& other) {
  begin = other.begin;
  end = other.end;
  return *this;
}

void DestructorNoOp(uintptr_t* buffer) {
  // Nothing to do here! (:-)+==<
}

void DestructorDeleteBuffer(uintptr_t* buffer) {
  ASSERT(buffer);
  delete buffer;
}

intptr_t SocketShiftUp(void* begin, void* end, intptr_t count) {
  if (!begin || begin <= end || count <= 0) return 0;
  char *start = reinterpret_cast<char*>(begin),
       *stop = reinterpret_cast<char*>(end);
  if (count < 3 * sizeof(void*)) {
    for (int i = 0; i < count; ++i) *(stop + count) = *stop;
    return 0;
  }
  char* pivot = AlignDown(stop);
  for (int i = 0; i < count; ++i) *(stop + count) = *stop--;
  uintptr_t *stop_word = reinterpret_cast<uintptr_t*>(stop),
            *start_word =
                reinterpret_cast<uintptr_t*>(AlignUp<uintptr_t*>(begin));
  while (stop_word >= start_word) *(stop_word + count) = *stop_word--;
  pivot = reinterpret_cast<char*>(stop_word + 1);
  while (pivot >= start) *(pivot + count) = *pivot--;
  return count;
}

}  // namespace _
#include "test_footer.inl"
#endif  //<  #if SEAM >= _0_0_0__02