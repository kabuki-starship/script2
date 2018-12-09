/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2_binary.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2018 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#include "tbinary.h"

#include <cmath>

namespace _ {
char HexNibbleToUpperCase(UI1 b) {
  b = b & 0xf;
  if (b > 9) return b + ('A' - 10);
  return b + '0';
}
}  // namespace _

#if SEAM >= _0_0_0__01
namespace _ {
/*
int TStringLength(UI8 value) {
  if (value < 10) return 1;
  if (value < 100) return 2;
  if (value < 1000) return 3;
  if (value < 10000) return 4;
  if (value < 100000) return 5;
  if (value < 1000000) return 6;
  if (value < 10000000) return 7;
  if (value < 100000000) return 8;
  if (value < 1000000000) return 9;
  if (value < 10000000000) return 10;
  if (value < 100000000000) return 11;
  if (value < 1000000000000) return 12;
  if (value < 10000000000000) return 13;
  if (value < 100000000000000) return 14;
  if (value < 1000000000000000) return 15;
  if (value < 10000000000000000) return 16;
  if (value < 100000000000000000) return 17;
  if (value < 1000000000000000000) return 18;
  if (value < 10000000000000000000) return 19;
  return 20;
}

template <typename Char>
Char* PrintMod10(Char* cursor, Char* stop, UI4 value) {
  if (!cursor || cursor >= stop) return nullptr;

  UI4 length;
  if (value < 10) {
    if (cursor + 1 >= stop) return nullptr;
    *cursor = '0' + value;
    *(cursor + 1) = 0;
    return cursor + 1;
  } else if (value < 100) {
    UI4 ten = 10;
    length = value / 10;

  } else if (value < 1000)
    length = 3;
  else if (value < 10000)
    length = 4;
  else if (value < 100000)
    length = 5;
  else if (value < 1000000)
    length = 6;
  else if (value < 10000000)
    length = 7;
  else if (value < 100000000)
    length = 8;
  else if (value < 1000000000)
    length = 9;
  else if (value < 10000000000)
    length = 10;
  else if (value < 100000000000)
    length = 11;
  else
    length = 12;
  Char* stop = cursor + length - 1;
  if (stop >= stop) return nullptr;
  UI4 ten = 10;
  while (length > 0) {
    UI4 scalar = value / ten;
  }
} */

// char* PrintMod10(char* cursor, char* stop, UI8 value);

#if CPU_ENDIAN == LITTLE_ENDIAN
static const UI2 kDigits00To99[100] = {
    0x3030, 0x3130, 0x3230, 0x3330, 0x3430, 0x3530, 0x3630, 0x3730, 0x3830,
    0x3930, 0x3031, 0x3131, 0x3231, 0x3331, 0x3431, 0x3531, 0x3631, 0x3731,
    0x3831, 0x3931, 0x3032, 0x3132, 0x3232, 0x3332, 0x3432, 0x3532, 0x3632,
    0x3732, 0x3832, 0x3932, 0x3033, 0x3133, 0x3233, 0x3333, 0x3433, 0x3533,
    0x3633, 0x3733, 0x3833, 0x3933, 0x3034, 0x3134, 0x3234, 0x3334, 0x3434,
    0x3534, 0x3634, 0x3734, 0x3834, 0x3934, 0x3035, 0x3135, 0x3235, 0x3335,
    0x3435, 0x3535, 0x3635, 0x3735, 0x3835, 0x3935, 0x3036, 0x3136, 0x3236,
    0x3336, 0x3436, 0x3536, 0x3636, 0x3736, 0x3836, 0x3936, 0x3037, 0x3137,
    0x3237, 0x3337, 0x3437, 0x3537, 0x3637, 0x3737, 0x3837, 0x3937, 0x3038,
    0x3138, 0x3238, 0x3338, 0x3438, 0x3538, 0x3638, 0x3738, 0x3838, 0x3938,
    0x3039, 0x3139, 0x3239, 0x3339, 0x3439, 0x3539, 0x3639, 0x3739, 0x3839,
    0x3939,
};
#else
static const UI2 kDigits00To99[100] = {
    0x3030, 0x3031, 0x3032, 0x3033, 0x3034, 0x3035, 0x3036, 0x3037, 0x3038,
    0x3039, 0x3130, 0x3131, 0x3132, 0x3133, 0x3134, 0x3135, 0x3136, 0x3137,
    0x3138, 0x3139, 0x3230, 0x3231, 0x3232, 0x3233, 0x3234, 0x3235, 0x3236,
    0x3237, 0x3238, 0x3239, 0x3330, 0x3331, 0x3332, 0x3333, 0x3334, 0x3335,
    0x3336, 0x3337, 0x3338, 0x3339, 0x3430, 0x3431, 0x3432, 0x3433, 0x3434,
    0x3435, 0x3436, 0x3437, 0x3438, 0x3439, 0x3530, 0x3531, 0x3532, 0x3533,
    0x3534, 0x3535, 0x3536, 0x3537, 0x3538, 0x3539, 0x3630, 0x3631, 0x3632,
    0x3633, 0x3634, 0x3635, 0x3636, 0x3637, 0x3638, 0x3639, 0x3730, 0x3731,
    0x3732, 0x3733, 0x3734, 0x3735, 0x3736, 0x3737, 0x3738, 0x3739, 0x3830,
    0x3831, 0x3832, 0x3833, 0x3834, 0x3835, 0x3836, 0x3837, 0x3838, 0x3839,
    0x3930, 0x3931, 0x3932, 0x3933, 0x3934, 0x3935, 0x3936, 0x3937, 0x3938,
    0x3939};
#endif

#if SEAM >= _0_0_0__03
/* Precomputed IEEE 754 base 2 powers of ten exponents:
10^-348, 10^-340, ..., 10^340.
Size bytes is 87 elements * 8 bytes/element = 696 bytes. */
static const SI2 kCachedPowersE[] = {
    -1220, -1193, -1166, -1140, -1113, -1087, -1060, -1034, -1007, -980, -954,
    -927,  -901,  -874,  -847,  -821,  -794,  -768,  -741,  -715,  -688, -661,
    -635,  -608,  -582,  -555,  -529,  -502,  -475,  -449,  -422,  -396, -369,
    -343,  -316,  -289,  -263,  -236,  -210,  -183,  -157,  -130,  -103, -77,
    -50,   -24,   3,     30,    56,    83,    109,   136,   162,   189,  216,
    242,   269,   295,   322,   348,   375,   402,   428,   455,   481,  508,
    534,   561,   588,   614,   641,   667,   694,   720,   747,   774,  800,
    827,   853,   880,   907,   933,   960,   986,   1013,  1039,  1066};

/* Precomputed IEEE 754 powers of ten integral portions:
10^-348, 10^-340, ..., 10^340.
Size bytes is 87 elements * 8 bytes/element = 696 bytes. */
static const UI8 kCachedPowersF[] = {
    0xfa8fd5a0081c0288, 0xbaaee17fa23ebf76, 0x8b16fb203055ac76,
    0xcf42894a5dce35ea, 0x9a6bb0aa55653b2d, 0xe61acf033d1a45df,
    0xab70fe17c79ac6ca, 0xff77b1fcbebcdc4f, 0xbe5691ef416bd60c,
    0x8dd01fad907ffc3c, 0xd3515c2831559a83, 0x9d71ac8fada6c9b5,
    0xea9c227723ee8bcb, 0xaecc49914078536d, 0x823c12795db6ce57,
    0xc21094364dfb5637, 0x9096ea6f3848984f, 0xd77485cb25823ac7,
    0xa086cfcd97bf97f4, 0xef340a98172aace5, 0xb23867fb2a35b28e,
    0x84c8d4dfd2c63f3b, 0xc5dd44271ad3cdba, 0x936b9fcebb25c996,
    0xdbac6c247d62a584, 0xa3ab66580d5fdaf6, 0xf3e2f893dec3f126,
    0xb5b5ada8aaff80b8, 0x87625f056c7c4a8b, 0xc9bcff6034c13053,
    0x964e858c91ba2655, 0xdff9772470297ebd, 0xa6dfbd9fb8e5b88f,
    0xf8a95fcf88747d94, 0xb94470938fa89bcf, 0x8a08f0f8bf0f156b,
    0xcdb02555653131b6, 0x993fe2c6d07b7fac, 0xe45c10c42a2b3b06,
    0xaa242499697392d3, 0xfd87b5f28300ca0e, 0xbce5086492111aeb,
    0x8cbccc096f5088cc, 0xd1b71758e219652c, 0x9c40000000000000,
    0xe8d4a51000000000, 0xad78ebc5ac620000, 0x813f3978f8940984,
    0xc097ce7bc90715b3, 0x8f7e32ce7bea5c70, 0xd5d238a4abe98068,
    0x9f4f2726179a2245, 0xed63a231d4c4fb27, 0xb0de65388cc8ada8,
    0x83c7088e1aab65db, 0xc45d1df942711d9a, 0x924d692ca61be758,
    0xda01ee641a708dea, 0xa26da3999aef774a, 0xf209787bb47d6b85,
    0xb454e4a179dd1877, 0x865b86925b9bc5c2, 0xc83553c5c8965d3d,
    0x952ab45cfa97a0b3, 0xde469fbd99a05fe3, 0xa59bc234db398c25,
    0xf6c69a72a3989f5c, 0xb7dcbf5354e9bece, 0x88fcf317f22241e2,
    0xcc20ce9bd35c78a5, 0x98165af37b2153df, 0xe2a0b5dc971f303a,
    0xa8d9d1535ce3b396, 0xfb9b7cd9a4a7443c, 0xbb764c4ca7a44410,
    0x8bab8eefb6409c1a, 0xd01fef10a657842c, 0x9b10a4e5e9913129,
    0xe7109bfba19c0c9d, 0xac2820d9623bf429, 0x80444b5e7aa7cf85,
    0xbf21e44003acdd2d, 0x8e679c2f5e44ff8f, 0xd433179d9c8cb841,
    0x9e19db92b4e31ba9, 0xeb96bf6ebadf77d9, 0xaf87023b9bf0ee6b};

static const UI4 kIEEE754Pow10[] = {0,        1,         10,        100,
                                    1000,     10000,     100000,    1000000,
                                    10000000, 100000000, 1000000000};

#endif  //<  #if SEAM >= _0_0_0__03

const UI2* BinaryLUTDecimals() { return kDigits00To99; }

UI1 Unsigned(SI1 value) { return (UI1)(value); }

UI2 Unsigned(SI2 value) { return (UI2)(value); }

UI4 Unsigned(SI4 value) { return (UI4)(value); }

UI8 Unsigned(SI8 value) { return (UI8)(value); }

UI1 Negative(SI1 value) { return (UI1)(-value); }

UI1 Negative(UI1 value) { return (UI1)(-(SI1)value); }

UI2 Negative(SI2 value) { return (UI2)(-value); }

UI2 Negative(UI2 value) { return (UI2)(-(SI2)value); }

UI4 Negative(SI4 value) { return (UI4)(-value); }

UI4 Negative(UI4 value) { return (UI4)(-(SI4)value); }

UI8 Negative(SI8 value) { return (UI8)(-value); }

UI8 Negative(UI8 value) { return (UI8)(-(SI8)value); }

BOL IsNaN(SI1 value) {
  return (value > TUnsignedNaN<SI1>()) && (value > TSignedNaN<SI1, UI1>());
}

BOL IsNaN(UI1 value) { return value > TUnsignedNaN<UI1>(); }

BOL IsNaN(SI2 value) { return value > TSignedNaN<SI2, UI2>(); }

BOL IsNaN(UI2 value) { return value > TUnsignedNaN<UI2>(); }

BOL IsNaN(SI4 value) { return value > TSignedNaN<SI4, UI4>(); }

BOL IsNaN(UI4 value) { return value > TUnsignedNaN<UI4>(); }

BOL IsNaN(SI8 value) { return value > TSignedNaN<SI8, UI8>(); }

BOL IsNaN(UI8 value) { return value > TUnsignedNaN<UI8>(); }

char HexNibbleToLowerCase(UI1 b) {
  b = b & 0xf;
  if (b > 9) return b + ('a' - 10);
  return b + '0';
}

UI2 HexByteToLowerCase(UI1 b) {
  UI2 value = HexNibbleToLowerCase(b & 0xf);
  value = value << 8;
  value |= HexNibbleToLowerCase(b >> 4);
  return value;
}

UI2 HexByteToUpperCase(UI1 b) {
  UI2 value = HexNibbleToUpperCase(b & 0xf);
  value = value << 8;
  UI2 second_nibble = HexNibbleToUpperCase(b >> 4);
  value |= second_nibble;
  return value;
}

int HexToByte(char c) {
  if (c < '0') {
    return -1;
  }
  if (c >= 'a') {
    if (c > 'f') return -1;
    return c - ('a' - 10);
  }
  if (c >= 'A') {
    if (c > 'F') return -1;
    return c - ('A' - 10);
  }
  if (c > '9') return -1;
  return c - '0';
}

int HexToByte(UI2 h) {
  int lowerValue = HexToByte((char)(h >> 8));

  if (lowerValue < 0) return -1;

  int upper_value = HexToByte((char)h);
  if (upper_value < 0) return -1;

  return lowerValue | (upper_value << 4);
}

}  // namespace _
#endif

#if SEAM >= _0_0_0__03
//#include <cmath>

#if SEAM == _0_0_0__03
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif

#include <cstdio>

namespace _ {
const SI2* BinaryLUTE() { return kCachedPowersE; }

const UI8* BinaryLUTF() { return kCachedPowersF; }

char* Print(char* cursor, char* stop, FLT value) {
  if (!cursor || cursor >= stop) return nullptr;
  SIW size = stop - cursor;
  PRINTF("\ncursor:%p end:%p size:%i\nExpecting:%f", cursor, stop, (int)size,
         value);
  int count = sprintf_s(cursor, stop - cursor, "%f", value);
  if (count <= 0) return nullptr;
  return cursor + count;
  // return TBinary<FLT, UI4>::TPrint<char>(cursor, stop, value);
}

char* Print(char* cursor, char* stop, DBL value) {
  if (!cursor || cursor >= stop) return nullptr;
  SIW size = stop - cursor;
  int count = sprintf_s(cursor, size, "%lf", value);
  if (count <= 0) return nullptr;
  return cursor + count;
  // return TBinary<DBL, UI8>::TPrint<char>(cursor, stop, value);
}

template <typename Char>
const Char* TStringFloatStop(const Char* cursor) {
  const char* stop = TStringDecimalEnd<char>(cursor);
  if (!stop) return stop;
  char c = *stop++;
  if (c == '.') {
    stop = TStringDecimalEnd<char>(cursor);
    c = *stop++;
  }
  if (c == 'e' || c != 'E') {
    if (c == '-') c = *stop++;
    return TStringDecimalEnd<char>(cursor);
  }
  return stop;
}

const char* Scan(const char* cursor, FLT& value) {
  int count = sscanf_s(cursor, "%f", &value);
  return TStringFloatStop<char>(cursor);
}

const char* Scan(const char* cursor, DBL& value) {
  int count = sscanf_s(cursor, "%lf", &value);
  return TStringFloatStop<char>(cursor);
}

#if USING_UTF16
char16_t* Print(char16_t* cursor, char16_t* stop, FLT value) {
  return TBinary<FLT, UI4>.TPrint<char16_t>(cursor, stop, value);
}

char16_t* Print(char16_t* cursor, char16_t* stop, DBL value) {
  return TBinary<DBL, UI8>.TPrint<char16_t>(cursor, stop, value);
}
#endif

#if USING_UTF32
char32_t* Print(char32_t* cursor, char32_t* stop, FLT value) {
  return TBinary<FLT, UI4>.TPrint<char32_t>(cursor, stop, value);
}

char32_t* Print(char32_t* cursor, char32_t* stop, DBL value) {
  return TBinary<DBL, UI8>.TPrint<char32_t>(cursor, stop, value);
}
#endif

int FloatDigitsMax() { return 15; }

int DoubleDigitsMax() { return 31; }

int MSbAsserted(UI1 value) { return TMSbAssertedReverse<UI1>(value); }

int MSbAsserted(SI1 value) { return TMSbAssertedReverse<UI1>((UI8)value); }

int MSbAsserted(UI2 value) { return TMSbAssertedReverse<UI2>(value); }

int MSbAsserted(SI2 value) { return TMSbAssertedReverse<UI2>((UI8)value); }

int MSbAsserted(UI4 value) { return TMSbAssertedReverse<UI4>(value); }

int MSbAsserted(SI4 value) { return TMSbAssertedReverse<UI4>((UI8)value); }

int MSbAsserted(UI8 value) { return TMSbAssertedReverse<UI8>(value); }

int MSbAsserted(SI8 value) { return TMSbAssertedReverse<UI8>((UI8)value); }

void FloatBytes(FLT value, char& byte_0, char& byte_1, char& byte_2,
                char& byte_3) {
  UI4 ui_value = *reinterpret_cast<UI4*>(&value);
  byte_0 = (char)(ui_value);
  byte_1 = (char)(ui_value >> 8);
  byte_2 = (char)(ui_value >> 16);
  byte_3 = (char)(ui_value >> 24);
}

char* Print(char* begin, UI2 chars) {
#if ALIGN_MEMORY
  *reinterpret_cast<UI2*>(chars);
  return begin + 2;
#else
  *reinterpret_cast<UI2*>(chars);
  return begin + 2;
#endif
}

char* Print(char* begin, char byte_0, char byte_1) {
#if ALIGN_MEMORY
  if (reinterpret_cast<UIW>(begin) & 1) {
    begin[0] = byte_1;
    begin[1] = '\0';
  }
  if (align == 0) begin[0] = byte_0;
  begin[0] = byte_0;
  begin[1] = '\0';
#else
  *reinterpret_cast<UI2*>(begin) = byte_0 | (((UI2)byte_1) << 8);
#endif
  return &begin[2];
}

char* Print(char* begin, char* stop, char byte_0, char byte_1, char byte_2) {
#if ALIGN_MEMORY
  switch (reinterpret_cast<UIW>(begin) & 3) {
    case 0: {
      *reinterpret_cast<UI4*>(begin) = ((UI4)byte_0) | ((UI4)byte_1) << 8 |
                                       ((UI4)byte_1) << 16 |
                                       ((UI4)byte_1) << 24;
      return &begin[4];
    }
    case 1: {
      UI4* ptr = reinterpret_cast<UI4*>(begin) - 1;
      UI4 word = (*ptr) & ((UI4)0xff) << 24;  //< Mask off byte_0 UI1.
      *ptr = word;
      begin[3] = 0;
      return &begin[4];
    }
    case 2: {
      UI2 ptr = *reinterpret_cast<UI2*>(begin);
      *ptr++ = ((UI2)byte_0) | ((UI2)byte_1) << 8;
      *ptr++ = ((UI2)byte_2) | ((UI2)byte_3) << 8;
      return reinterpret_cast<char*>(ptr);
    }
    case 3: {
      *begin = byte_0;
      UI4* ptr = reinterpret_cast<UI4*>(begin) - 1;
      UI4 word = (*ptr) & ((UI4)0xff) << 24;  //< Mask off byte_0 UI1.
      word |= ((UI4)byte_0) | ((UI4)byte_0) << 8 |
              ((UI4)byte_0) << 16;  //< OR together three.
      begin[3] = 0
    }
  }
#else
  *reinterpret_cast<UI4*>(begin) = ((UI4)byte_0) | ((UI4)byte_1) << 8 |
                                   ((UI4)byte_1) << 16 | ((UI4)byte_1) << 24;
#endif
  return &begin[4];
}

// char puff_lut[2 * 100 + (8 + 2) * 87]; //< Experiment for cache aligned LUT.

constexpr SIW IEEE754LutElementCount() { return 87; }

const SI2* IEEE754Pow10E() {
  /* Precomputed powers of 10 exponents for Grisu. */
  return kCachedPowersE;
}

const UI8* IEEE754Pow10F() { return kCachedPowersF; }

void BinaryLUTAlignedGenerate(char* lut, size_t size) {
  ASSERT(size);
  SIW iee754_pow_10_count = IEEE754LutElementCount();
  if (size != ((100 + iee754_pow_10_count) * 2 + iee754_pow_10_count * 8))
    return;
  UI2* ui2_ptr = reinterpret_cast<UI2*>(lut);

  for (char tens = '0'; tens <= '9'; ++tens)
    for (int ones = '0'; ones <= '9'; ++ones)
#if ENDIAN == LITTLE
      *ui2_ptr++ = (tens << 8) | ones;
#else
      *ui2_ptr++ = (ones << 8) | tens;
#endif

  for (int i = 0; i < 87; ++i) *ui2_ptr = IEEE754Pow10E()[i];

  UI8* ui8_ptr = reinterpret_cast<UI8*>(ui2_ptr);

  for (int i = 0; i < 87; ++i) *ui8_ptr = IEEE754Pow10F()[i];
}

const UI2* DigitsLut(const char* puff_lut) {
  return reinterpret_cast<const UI2*>(puff_lut);
}

const UI2* PuffLutExponents(char* puff_lut) {
  return reinterpret_cast<const UI2*>(puff_lut + 200);
}

const UI8* PufLutPow10(char* puff_lut) {
  return reinterpret_cast<const UI8*>(puff_lut + 374);
}

UI4 Value(FLT value) { return *reinterpret_cast<UI4*>(&value); }

UI8 Value(DBL value) { return *reinterpret_cast<UI8*>(&value); }

BOL IsNaNPositive(SI1 value) { return value > TUnsignedNaN<SI1>(); }

BOL IsNaNNegative(SI1 value) { return value > TUnsignedNaN<SI1>(); }

BOL IsNaN(FLT value) { return isnan(value); }

BOL IsNaN(DBL value) { return isnan(value); }

BOL IsFinite(FLT value) { return isfinite(value); }

BOL IsFinite(DBL value) { return isfinite(value); }

BOL IsInfinite(FLT value) { return isinf(value); }

BOL IsInfinite(DBL value) { return isinf(value); }

/* Masks the lower bits using faster bit shifting.
@brief The algorithm has you enter the highest bit rather than bit count because
it would introduce an extra instruction and you should do that manually if you
wish to do so.
@param value The value to mask.
@param left_bits Number of bits to shift left.
@param right_bits Number of bits to shift right. */
template <typename UI>
UI ShiftLeftRight(UI value, int left_bits, int right_bits) {
  value = value << left_bits;
  return value >> right_bits;
}

/* Creates a mask with the given number_ of zeros in the MSb(s).
@param msb_zero_count The number_ of zeros in the Most Significant bits. */
template <typename UI>
UI CreateMaskLSb(UI msb_zero_count) {
  UI mask = 0;
  return (~mask) >> msb_zero_count;
}

/* Masks off the lower bits.
@param msb_zero_count The number_ of zeros in the Most Significant bits. */
template <typename UI>
UI MaskLSb(UI value, UI msb_zero_count) {
  return value & CreateMaskLSb<UI>(msb_zero_count);
}

/* Returns 2^n.
@brief Function forces the compiler to create the mask without a LDR
instruction. */
template <typename I>
I PowerOf2(I n) {
  I value = 1;
  return value << n;
}

UI8 ComputePow10(int e, int alpha, int gamma) {
  DBL pow_10 = 0.30102999566398114,  //< 1/lg(10)
      alpha_minus_e_plus_63 = static_cast<DBL>(alpha - e + 63),
      ceiling = Ceiling(alpha_minus_e_plus_63 * pow_10);
  return *reinterpret_cast<UI8*>(&pow_10);
}

DBL Ceiling(DBL value) { return ceil(value); }

FLT Ceiling(FLT value) { return ceil(value); }

char* LastByte(char* c) { return c; }

#if USING_UTF16
char* LastByte(char16_t* c) { return reinterpret_cast<char*> + 1; }

char16_t* Print(char16_t* cursor, char16_t* stop, FLT value) { return nullptr; }

char16_t* Print(char16_t* cursor, char16_t* stop, DBL value) { return nullptr; }
#endif

#if USING_UTF32
char* LastByte(char32_t* c) { return reinterpret_cast<char*> + 3; }

char32_t* Print(char32_t* cursor, char32_t* stop, FLT value) { return nullptr; }

char32_t* Print(char32_t* cursor, char32_t* stop, DBL value) { return nullptr; }
#endif

}  // namespace _

#endif  //< #if SEAM >= _0_0_0__03
