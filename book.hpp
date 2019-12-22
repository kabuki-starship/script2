/* Script2 (TM) @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /book.hpp
@author  Cale McCollough <https://cale-mccollough.github.io>
@license Copyright (C) 2015-9 Kabuki Starship (TM) <kabukistarship.com>.
This Source Code Form is subject to the terms of the Mozilla Public License,
v. 2.0. If a copy of the MPL was not distributed with this file, You can obtain
one at <https://mozilla.org/MPL/2.0/>. */
#pragma once
#include <_config.h>
#if SEAM >= SCRIPT2_BOOK
#ifndef SCRIPT2_BOOK_CODE
#define SCRIPT2_BOOK_CODE
#include "book.hpp"
#include "list.hpp"
#if SEAM == SCRIPT2_BOOK
#include "_debug.inl"
#else
#include "_release.inl"
#endif
namespace _ {
/* @ingroup Book
Please see the ASCII Data Specificaiton for DRY documentation.
@link ./spec/data/map_types/book.md */

#define TPARAMS ISZ, IUZ, ISY, CHT
#define TARGS \
  typename ISZ = ISN, typename IUZ = UIN, typename ISY = ISM, typename CHT = CHR

/* A contiguous memory Associative List created from a List and a Loom.
@ingroup Book
@code
+-----------------+
|      List       |
|-----------------|
|      Loom       |
|-----------------|  ^ Up in addresses
|  TBook Struct   |  |
+-----------------+ 0xN
@endcode
*/
template <TARGS>
struct TBook {
  TLoom<ISZ, ISY>* keys;
};

template <TARGS>
constexpr ISZ CBookCountMin() {
  return 8 / sizeof(ISZ);
}

template <TARGS>
constexpr ISZ CBookSizeMin() {
  enum {
    cCountMin = TBookCountMin(),
    cSizeMin = sizeof(TBook<TPARAMS>) + cCountMin * (sizeof(ISZ) + 2),
  };
  return cSizeMin;
}

template <TARGS>
constexpr ISZ CBookCountDefault() {
  return 32;
}

template <TARGS>
constexpr ISZ CBookSizeDefault() {
  return (32 * CBookCountDefault<TPARAMS>() * sizeof(CHT)) & (sizeof(ISW) - 1);
}

template <TARGS>
inline CHT* TBookStart(TBook<TPARAMS>* book, ISZ count_max) {
  ISZ* top = &TStackStart<ISZ, ISZ>(&book->offsets)[count_max];
  return reinterpret_cast<CHT*>(top);
}

template <TARGS>
inline CHT* TBookStart(TBook<TPARAMS>* book) {
  return TBookStart<TPARAMS>(book, book->offsets.count_max);
}

template <TARGS>
inline TBook<TPARAMS>* TBookInit(TBook<TPARAMS>* book, ISZ count_max) {
  D_ASSERT(book);
  A_ASSERT((count_max >= CBookCountMin<TPARAMS>()));

  TLoomInit(book->keys, count_max);

  return book;
}

template <TARGS>
inline CHT* TBookEnd(TBook<TPARAMS>* book) {
  CHT* list = TLoomEnd(book->keys);
  return TListEnd<ISZ>(reinterpret_cast<TList<ISZ>*>(list));
}

template <TARGS>
inline TList<ISZ>* TBookList(TBook<TPARAMS>* book, ISZ size_bytes) {
  return TPtr<TList<ISZ>>(book, size_bytes);
}

template <TARGS>
inline TList<ISZ>* TBookList(TBook<TPARAMS>* book) {
  return TBookList<TPARAMS>(book, book->keys->size);
}

/* Gets the element at the given index. */
template <TARGS>
inline CHT* TBookGet(TBook<TPARAMS>* book, ISY index) {
  D_ASSERT(book);
  auto count = book->keys->map.count;
  if (index < 0 || count) return nullptr;
  return TPtr<CHT>(book, TStackStart<ISZ, ISZ>(&book->keys->map)[index]);
}

template <TARGS>
inline ISZ TBookSize(TBook<TPARAMS>* book) {
  TList<ISZ>* list = TBookList<TPARAMS>(book);
  return book->keys->size + list->size_bytes;
}

template <TARGS, typename Printer>
Printer& TBookPrint(Printer& o, TBook<TPARAMS>* book) {
  ISZ count = book->keys->map.count;
  o << "\nBook<SI" << CHA('0' + sizeof(ISZ)) << ",UI" << CHA('0' + sizeof(IUZ))
    << ",SI" << CHA('A' + sizeof(ISY)) << CHA('0' + sizeof(CHT))
    << "> size:" << book->keys->size << " top:" << book->keys->top
    << " stack_size:" << book->keys->map.count_max << " count:" << count;
  auto types = TListTypes<ISZ, DT2>(TBookList<TPARAMS>(book));
  for (ISY i = 0; i < count; ++i)
    o << '\n'
      << i << ".) \"" << TBookGet<TPARAMS>(book, i)
      << "\" type:" << TPrintType<Printer, DT2>(o, *types++);
  D_COUT(Linef('-') << Charsf(book, TBookSize<TPARAMS>(book)));
  return o << '\n';
}

/* Doubles the size and count_max of the book.
@return Returns nil if the size is greater than the amount of memory that
can fit in type ISW, the unaltered socket pointer if the Stack has grown to the
size upper bounds, or a new dynamically allocated socket upon failure. */
template <TARGS>
BOL TBookGrow(Autoject& obj) {
  D_COUT("\n\nGrowing Book...");
  /* Grow Algoirhm.
  1. Check if we can grow and if so, create a new block of memory.
  2. Copy the Loom.
  3. Copy the List.
  */
  auto book = reinterpret_cast<TBook<TPARAMS>*>(obj.origin);
  A_ASSERT(book);
  ISZ size = TBookSize<TPARAMS>(book);
  if (!TCanGrow<ISZ>(size)) return false;
  ISZ count_max = book->keys.offsets.count_max;
  if (!TCanGrow<ISZ>(count_max)) return false;

  size = size << 1;
  count_max = count_max << 1;

  D_COUT(" new size:" << size << " count_max:" << count_max);

#if D_THIS
  D_COUT("\n\nBefore:\n");
  TBookPrint<TPARAMS, COut>(COut().Star(), book);
  D_COUT(Charsf(book, TBookEnd<TPARAMS>(book)));
#endif

  UIW* new_begin = obj.socket_factory(nullptr, size);
  D_ARRAY_WIPE(new_begin, size);
  TLoom<ISZ, ISY>* other = reinterpret_cast<TLoom<ISZ, ISY>*>(new_begin);

  return true;
}

/* Removes the given index from the Book.
@return The index upon success or -1 upon failure. */
template <TARGS>
void* TBookListRemove(TBook<TPARAMS>* book, ISY index) {
  TList<ISZ>* list = TBookList<TPARAMS>(book);
  ISZ count = list->offsets.count;
  ISZ* offsets = TListOffsets<ISZ>(list);
  TStackRemove<ISZ, ISZ>(offsets, count, index);
  TStackRemove<DT2, ISZ>(TListTypes<ISZ, DT2>(list), count, index);
  return offsets + index;
}

/* Removes the given index from the Book.
@return The index upon success or -1 upon failure. */
template <TARGS>
void* TBookRemove(TBook<TPARAMS>* book, ISY index) {
  ISY index = TLoomRemove<CHT, ISZ>(book->keys, index);
  return TBookListRemove<TPARAMS>(book, index);
}

/* Removes the given key from the Book.
@return Nil upon failure or a pointer to the item removed upon success. */
template <TARGS>
void* TBookRemove(TBook<TPARAMS>* book, const CHT* key) {
  ISY index = TLoomFind<TPARAMS>(book->keys, key);
  if (index < 0) return index;
  TLoomRemove<TPARAMS>(book->keys, index);
  return TBookListRemove<TPARAMS>(book, index);
}

/* Adds a string to the end of the Book.
@return The index upon success or -1 upon failure. */
template <TARGS>
ISZ TBookPop(TBook<TPARAMS>* book) {
  return TBookRemove<TPARAMS>(book, book->keys->map->count - 1);
}

/* Adds a key-value tuple to the end of the Book.
@return The index upon success or -1 upon failure. */
template <typename T, TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, T item,
                       ISY index = cPush) {
  A_ASSERT(book);
  if (!key) return cErrorNilInput;
  if (index == cAnywhere) {
    index = TLoomInsert<CHT, ISY>(book->keys, key, index);
  } else {
    if (index == cPush) index = book->keys.map.count - 1;
  }
  if (index < 0) return index;
  ISY result = ISY(TListInsert<ISZ, DT2>(TBookList<TPARAMS>(book), item));
  if (result) TBookRemove<TPARAMS>(book, index, item);
  return result;
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, ISA item) {
  return TBookInsert<ISA, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, IUA item) {
  return TBookInsert<ISA, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, ISB item) {
  return TBookInsert<ISB, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, IUB item) {
  return TBookInsert<ISB, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, ISC item) {
  return TBookInsert<ISC, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, IUC item) {
  return TBookInsert<ISC, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, ISD item) {
  return TBookInsert<ISD, TPARAMS>(book, key, item);
}
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, IUD item) {
  return TBookInsert<IUD, TPARAMS>(book, key, item);
}
#if USING_FPC == YES_0
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, FPC item) {
  return TBookInsert<FPC, TPARAMS>(book, key, item);
}
#endif
#if USING_FPD == YES_0
template <TARGS>
inline ISY TBookInsert(TBook<TPARAMS>* book, const CHT* key, FPD item) {
  return TBookInsert<FPD, TPARAMS>(book, key, item);
}
#endif

/* Adds a string to the end of the Book, auto-growing if neccissary.
@return The index upon success or -1 if the obj can't grow anymore. */
template <typename T, typename BUF, TARGS>
ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, T item,
                ISY index = cPush) {
  if (!key) return -cErrorNilInput;
  auto book = obj.OriginAs<TBook<TPARAMS>*>();
  D_COUT("\nAdding:\"" << item << '\"');
  ISY result = TBookInsert<T, TPARAMS>(book, key, item, index);
  while (result < 0) {
    if (!TBookGrow<TPARAMS>(obj.AJT())) {
      D_COUT("\n\nFailed to grow.\n\n");
      return -cErrorBufferOverflow;
    }
    result = TBookInsert<T, TPARAMS>(book, key, item, index);
  }
  return result;
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, ISA item,
                       ISY index) {
  return TBookInsert<ISA, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, IUA item,
                       ISY index) {
  return TBookInsert<ISA, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, ISB item,
                       ISY index) {
  return TBookInsert<ISB, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, IUB item,
                       ISY index) {
  return TBookInsert<ISB, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, ISC item,
                       ISY index = cPush) {
  return TBookInsert<ISC, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, IUC item,
                       ISY index = cPush) {
  return TBookInsert<ISC, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, ISD item,
                       ISY index = cPush) {
  return TBookInsert<ISD, BUF, TPARAMS>(obj, key, item, index);
}
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, IUD item,
                       ISY index = cPush) {
  return TBookInsert<IUD, BUF, TPARAMS>(obj, key, item, index);
}
#if USING_FPC == YES_0
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, FPC item,
                       ISY index = cPush) {
  return TBookInsert<FPC, BUF, TPARAMS>(obj, key, item, index);
}
#endif
#if USING_FPD == YES_0
template <typename BUF, TARGS>
inline ISY TBookInsert(AArray<IUA, ISZ, BUF>& obj, const CHT* key, FPD item,
                       ISY index = cPush) {
  return TBookInsert<FPD, BUF, TPARAMS>(obj, key, item, index);
}
#endif

template <TARGS, typename BUF>
ISZ TBookCharCount(TBook<TPARAMS>* book) {
  return (ISZ)(TBookEnd<TPARAMS>(book) - TBookStart<TPARAMS>(book));
}
template <TARGS, typename BUF>
BOL TBookWrite(TBook<TPARAMS>* destination, TBook<TPARAMS>* soure) {
  return true;
}

/* Adds a string to the end of the Book.
@return The index upon success or -1 upon failure. */
template <TARGS>
CHT* TBookPop(TBook<TPARAMS>* book) {
  if (book->offsets.count == 0) return nullptr;
  ISZ offset = TStackPop<ISZ, ISZ>(book->offsets), top = book->top;
  book->top = offset;
  return reinterpret_cast<CHT*>(reinterpret_cast<ISW>(book) + offset);
}

/* Searches for the given string in the book.
@return -1 if the book doesn't contain the string or the index if it does. */
template <TARGS>
ISZ TBookFind(TBook<TPARAMS>* book, const CHT* string) {
  D_ASSERT(book);
  D_ASSERT(string);
  return TLoomFind<CHT, ISZ>(book->keys, string);
}

/* An ASCII Book Autoject. */
template <TARGS, ISZ cSize_ = 512,
          typename BUF = TUIB<cSize_, CHT, TStrand<ISN>>>
class ABook {
  AArray<IUA, ISZ, BUF> obj_;  //< An Auto-Array object.
 public:
  enum { cCountDefault = cSize_ / 16 };
  /* Constructs a Book. */
  ABook(ISZ count_max = cCountDefault) {
    TBookInit<TPARAMS>(This(), count_max);
  }

  /* Constructs a Book subclass.
  @param factory SocketFactory to call when the Strand overflows. */
  ABook(SocketFactory socket_factory, ISZ count = cCountDefault)
      : obj_(socket_factory) {
    TBookInit<TPARAMS>(This(), count);
  }

  /* Constructs a Book subclass.
  @param factory SocketFactory to call when the Strand overflows. */
  ABook(SocketFactory socket_factory, ISZ size = CBookSizeDefault<TPARAMS>(),
        ISZ count = CBookCountDefault<TPARAMS>())
      : obj_(socket_factory) {
    TBookInit<TPARAMS>(This(), count);
  }

  inline ISZ Size() { return obj_.Size(); }

  inline ISZ SizeBytes() { return obj_.SizeBytes(); }

  inline ISZ SizeWords() { return obj_.SizeWords(); }

  inline ISY Count() { return This()->keys->map->count; }

  /* Inserts the key and item on into the Loom and List at the given index.
  @return The index of the string in the Book. */
  inline ISY Insert(const CHT* key, ISA item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, IUA item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, ISB item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, IUB item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, ISC item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, IUC item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, ISD item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
  inline ISY Insert(const CHT* key, IUD item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
#if USING_FPC == YES_0
  inline ISY Insert(const CHT* key, FPC item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
#endif
#if USING_FPD == YES_0
  inline ISY Insert(const CHT* key, FPD item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }
#endif
  inline ISY Insert(const CHT* key, const CHT* item, ISY index = cPush) {
    return TBookInsert<BUF, TPARAMS>(AJT_ARY(), key, item, index);
  }

  /* Removes the string at the given index from the Book. */
  inline void* Remove(ISY index) { return TBookRemove<TPARAMS>(This(), index); }

  /* Removes the string at the given index from the Book. */
  inline void* Remove(const CHT* key) {
    return TBookRemove<TPARAMS>(This(), key);
  }

  /* Removes the string at the given index from the Book. */
  inline ISZ Pop() { return TBookRemove<TPARAMS>(This()); }

  /* Gets the string at the given index. */
  inline CHT* Get(ISY index) { return TBookGet<TPARAMS>(This(), index); }

  /* Searches for the given string.
  @return -1 if the Book doesn't contain the string or the index if it does.
*/
  inline ISZ Find(const CHT* string) {
    return TBookFind<TPARAMS>(This(), string);
  }

  /* Gets the Autoject. */
  inline Autoject AJT() { return obj_.AJT(); }

  /* Gets the Auto-Array. */
  inline AArray<IUA, ISZ, BUF>& AJT_ARY() { return obj_; }

  /* Gets the ASCII Object. */
  inline TBook<TPARAMS>* This() { return obj_.OriginAs<TBook<TPARAMS>*>(); }

  template <typename Printer>
  inline Printer& PrintTo(Printer& o) {
    TBookPrint<TPARAMS, Printer>(o, This());
    return o;
  }

  inline void COut() { PrintTo<_::COut>(_::COut().Star()); }
};

}  // namespace _
#undef TARGS
#undef TPARAMS
#endif
#endif