#include <module_seams.h>

#define SCRIPT2 0

#define YES_0 0
#define NO_0 1

#define String_TYPE_1 1
#define String_TYPE_2 2
#define String_TYPE_3 3

#define PLATFORM_BARE_METAL 1
#define PLATFORM_MBED_BARE_METAL 2
#define PLATFORM_MBED_OS 3
#define PLATFORM_ARDUINO 4
#define PLATFORM_WIN32 5
#define PLATFORM_WINDOWS 6
#define PLATFORM_ANDROID 7
#define PLATFORM_LINUX 8
#define PLATFORM_OSX 9
#define PLATFORM_IOS 10

#define CPU_X86 1
#define CPU_X64 2
#define CPU_ARM8 3
#define CPU_ARM16 4
#define CPU_ARM32 5
#define CPU_ARM64 6

#include <cstdint>
#if defined(_MSC_VER) && defined(_M_AMD64)
#define USING_VISUAL_CPP_X64 1
#include <intrin.h"
#include <intrin0.h"
#pragma intrinsic(_umul128)
#elif (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define USING_GCC 1
#if defined(__x86_64__)
#define COMPILER_SUPPORTS_128_BIT_INTEGERS 1
#endif
#endif
//#include <climits>
//#include <new>

#define ASSEMBLE_EXE 0
#define ASSEMBLE_LIB_STATIC 1
#define ASSEMBLE_LIB_DYNAMIC 1

#define CPU_64_BIT 0
#define CPU_32_BIT 1
#define CPU_16_BIT 2
#define CPU_8_BIT 3

#define CPU_ENDIAN_LITTLE 0

typedef char CH1;
typedef char16_t CH2;
typedef char32_t CH4;
typedef wchar_t CHN;

typedef int8_t SI1;
typedef uint8_t UI1;
typedef int16_t SI2;
typedef uint16_t UI2;
typedef bool BOL;
typedef int32_t SI4;
typedef uint32_t UI4;
typedef int32_t TM4;
typedef int64_t TM8;
typedef int64_t SI8;
typedef uint64_t UI8;

typedef UI2 FP2;
typedef float FP4;
typedef double FP8;

typedef uintptr_t UIW;
typedef intptr_t SIW;

typedef int SIN;
typedef unsigned int UIN;

typedef SI4 TM4;  //< A 32-bit seconds since epoch timestamp.
typedef SI8 TM8;  //< A 64-bit seconds since epoch timestamp.

typedef UI2 UI2;  //< Using unsigned 16-bit hash type.
typedef UI4 UI4;  //< Using unsigned 32-bit hash type.
typedef UI8 UI8;  //< Using unsigned 64-bit hash type.

typedef void* PTR;
typedef const void* PTC;

typedef UIW DTW;  //< Word-sized Ascii Data TYpe.
typedef UI1 DT1;  //< 8-bit Ascii Data TYpe.
typedef UI2 DT2;  //< 16-bit Ascii Data TYpe.
typedef UI4 DT4;  //< 32-bit Ascii Data TYpe.
typedef UI8 DT8;  //< 64-bit Ascii Data TYpe.

typedef DT2 DTP;  //< A 16-bit ASCII Data Type.

namespace _ {
/* ASCII C0 Control codes. */
enum {
  kNUL = 0,    //< ASCII C0 NUL 0
  kSOH,        //< ASCII C0 NUL 1
  kSTX,        //< ASCII C0 STX 2
  kETX,        //< ASCII C0 ETX 3
  kEOT,        //< ASCII C0 EOT 4
  kENQ,        //< ASCII C0 ENQ 5
  kACK,        //< ASCII C0 ACK 6
  kBEL,        //< ASCII C0 BEL 7
  kBS,         //< ASCII C0 BS 8
  kTAB,        //< ASCII C0 TAB 9
  kLF,         //< ASCII C0 LF 10
  kVT,         //< ASCII C0 VT 11
  kFF,         //< ASCII C0 FF 12
  kCR,         //< ASCII C0 CR 13
  kSO,         //< ASCII C0 SO 14
  kSI,         //< ASCII C0 SI 15
  kDLE,        //< ASCII C0 DLE 16
  kDC1,        //< ASCII C0 DC1 17
  kDC2,        //< ASCII C0 DC2 18
  kDC3,        //< ASCII C0 DC3 19
  kDC4,        //< ASCII C0 DC4 20
  kNAK,        //< ASCII C0 NAK 21
  kSYN,        //< ASCII C0 SYN 22
  kETB,        //< ASCII C0 ETB 23
  kCAN,        //< ASCII C0 CAN 24
  kEM,         //< ASCII C0 EM 25
  kSUB,        //< ASCII C0 SUB 26
  kESC,        //< ASCII C0 ESC 27
  kFS,         //< ASCII C0 FS 28
  kGS,         //< ASCII C0 GS 29
  kRS,         //< ASCII C0 RS 30
  kUS,         //< ASCII C0 US 31
  kDEL = 127,  //< ASCII C0 DEL 127
  NIL = 0,
};

/* List of the 32 ASCII POD Data Types.
@link ./spec/data/readme.md */
typedef enum AsciiTypes {
  kNIL = 0,  //< 00. Nil/void type or a BigNum (BGN) of 1 to 2047 bytes wide.
  kST1,      //< 01. Nil-terminated AString Type 1 (UTF-8).
  kST2,      //< 02. Nil-terminated AString Type 2 (UTF-16).
  kST3,      //< 03. Nil-terminated AString Type 3 (UTF-32).
  kCH1,      //< 04. 1-byte character.
  kSI1,      //< 05. 1-byte signed integer.
  kUI1,      //< 06. 1-byte unsigned integer.
  kCH2,      //< 07. 2-byte character.
  kSI2,      //< 08. 2-byte signed integer.
  kUI2,      //< 10. 2-byte unsigned integer.
  kDT2,      //< 11. 2-byte Data Type.
  kFP2,      //< 12. 2-byte floating-point number.
  kBLN,      //< 13. 2-byte SI2 boolean.
  kDTB,      //< 14. 2-byte Data Type stores 2 1-byte Data Types.
  kDTC,      //< 15. 2-byte Data Type stores 3 POD types plus a MBT bit.
  kCH4,      //< 16. 4-byte character.
  kSI4,      //< 17. 4-byte signed integer.
  kUI4,      //< 18. 4-byte unsigned integer.
  kDT4,      //< 19. 4-byte Data Type.
  kFP4,      //< 20. 4-byte floating-point number.
  kBOL,      //< 21. 4-byte Boolean value at least 16-bits wide.
  kTM4,      //< 22. 4-byte second since epoch timestamp.
  kTME,      //< 23. 8-byte sub-second timestamp with TM4 and an UI4 tick.
  kTM8,      //< 24. 8-byte second since epoch timestamp.
  kSI8,      //< 25. 8-byte signed integer.
  kUI8,      //< 26. 8-byte unsigned integer.
  kDT8,      //< 27. 8-byte Data Type.
  kFP8,      //< 28. 8-byte floating-point number.
  kSIH,      //< 29. 16-byte (Hexadeca-byte) signed integer.
  kUIH,      //< 30. 16-byte (Hexadeca-byte) unsigned integer.
  kFPH,      //< 31. 16-byte (Hexadeca-byte) floating-point number.
} AsciiType;

enum {
  kPTR = 1 << 14,          //< 64. Pointer modifier.
  kCST = 1 << 15,          //< 128. Const modifier.
  kCNS_PTR = 3 << 14,      //< 192. Const Pointer modifier.
  kCNS_ST1 = kCST | kST1,  //< 129. Const ST1 pointer.
  kCNS_ST2 = kCST | kST2,  //< 129. Const ST2 pointer.
  kCNS_ST3 = kCST | kST3,  //< 129. Const ST3 pointer.
};

enum {
  kRS1 = 97,  //< 97. A type-value tuple list with 2-byte signed size_bytes.
  kRS2 = 98,  //< 98. A type-value tuple list with 4-byte signed size_bytes.
  kRS4 = 99,  //< 99. A type-value tuple list with 8-byte signed size_bytes.
  kINV = 64,  //< The number of Ascii Data Type base types.
  kTypeBitCount = 5,      //< Bit
  kTypeCount = 32,        //< The starting index of invalid types.
  kTypePODMask = 32 - 1,  //< The starting index of invalid types.
};

enum {
  kTYP = 0,  //< 0. Class or POD type.
  kTY2 = 1,  //< 1. size_width of size_bytes is 16-bits wide.
  kTY4 = 2,  //< 2. size_width of size_bytes is 32-bits wide.
  kTY8 = 3,  //< 3. size_width of size_bytes is 64-bits wide.
};

enum {
  kPOD = 0,  //< A POD type.
  kARY = 1,  //< Array of POD types.
  kVEC = 2,  //< Vector of POD types.
  kMAT = 3,  //< Matrix of POD types.
};

enum {
  kATypeBitCount = 6,  //< Number of bits required to represent the Core types.
  kWordBitCount = (sizeof(void*) == 2)
                      ? 1
                      : (sizeof(void*) == 4) ? 2 : (sizeof(void*) == 8) ? 3 : 0,
  kWordLSbMask = sizeof(void*) - 1,
  kNaNInt = sizeof(SI4) == 4 ? static_cast<SI4>(0xFFFFFFFF)
                             : sizeof(SI4) == 2 ? static_cast<SI4>(0xFFFF) : 0,
};
}  // namespace _
