#include <module_seams.h>

#define SCRIPT2 0

#define YES_0 0
#define NO_0 1

#define STRING_TYPE_1 1
#define STRING_TYPE_2 2
#define STRING_TYPE_3 3

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
#include <intrin.h>
#include <intrin0.h>
#pragma intrinsic(_umul128)
#elif (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
#define USING_GCC 1
#if defined(__x86_64__)
#define COMPILER_SUPPORTS_16_BYTE_INTEGERS 1
#endif
#endif
//#include <climits>
//#include <new>

#define ASSEMBLE_EXE 0
#define ASSEMBLE_LIB_STATIC 1
#define ASSEMBLE_LIB_DYNAMIC 1

#define ALU_64_BIT 0
#define ALU_32_BIT 1
#define ALU_16_BIT 2
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

typedef void* PTR;
typedef const void* PTC;

typedef UIW DTW;  //< Word-sized Ascii Data TYpe.
typedef UI1 DT1;  //< 8-bit Ascii Data TYpe.
typedef UI2 DT2;  //< 16-bit Ascii Data TYpe.
typedef UI4 DT4;  //< 32-bit Ascii Data TYpe.
typedef UI8 DT8;  //< 64-bit Ascii Data TYpe.

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
enum {
  kNIL = 0,  //< 00. Nil/void type or a BigNum (BGN) of 1 to 2047 bytes wide.
  kCH1,      //< 01. 1-byte character.
  kSI1,      //< 02. 1-byte signed integer.
  kUI1,      //< 03. 1-byte unsigned integer.
  kCH2,      //< 04. 2-byte character.
  kSI2,      //< 05. 2-byte signed integer.
  kUI2,      //< 06. 2-byte unsigned integer.
  kFP2,      //< 07. 2-byte floating-point number.
  kBOL,      //< 08. 2 or 4-byte boolean value.
  kCH4,      //< 09. 4-byte character.
  kSI4,      //< 10. 4-byte signed integer.
  kUI4,      //< 11. 4-byte unsigned integer.
  kFP4,      //< 12. 4-byte floating-point number.
  kTME,      //< 13. 8-byte sub-second timestamp with TM4 and an UI4 tick.
  kSI8,      //< 14. 8-byte signed integer.
  kUI8,      //< 15. 8-byte unsigned integer.
  kFP8,      //< 16. 8-byte floating-point number.
  kSIH,      //< 17. 16-byte (Hexadeca-byte) signed integer.
  kUIH,      //< 18. 16-byte (Hexadeca-byte) unsigned integer.
  kFPH,      //< 19. 16-byte (Hexadeca-byte) floating-point number.
  kDTA,      //< 20 Implementation-defined word-aligned Data Type A.
  kDTB,      //< 21 Implementation-defined word-aligned Data Type B.
  kDTC,      //< 22 Implementation-defined word-aligned Data Type C.
  kDTD,      //< 23 Implementation-defined word-aligned Data Type D.
  kDTE,      //< 24 Implementation-defined word-aligned Data Type E.
  kDTF,      //< 25 Implementation-defined word-aligned Data Type F.
  kDTG,      //< 26 Implementation-defined word-aligned Data Type G.
  kDTH,      //< 27 Implementation-defined word-aligned Data Type H.
  kDTI,      //< 28 Implementation-defined word-aligned Data Type I.
  kDTJ,      //< 29 Implementation-defined word-aligned Data Type J.
  kDTK,      //< 30 Implementation-defined word-aligned Data Type K.
  kDTL,      //< 31 Implementation-defined word-aligned Data Type L.
};

enum {
  kST1,  //< 01. Nil-terminated string Type 1 (UTF-8).
  kST2,  //< 02. Nil-terminated string Type 2 (UTF-16).
  kST3,  //< 03. Nil-terminated string Type 3 (UTF-32).
  kWLD,  //< 26. A pointer.
  kVAL,  //< 27. A 2-word value.
  kTVT,  //< 28. A Type-Value tuple.
  kBGV,  //< 29. A 2-word value.
  kTBT,  //< 30. A Type-BigVal tuple.
  kTST,  //< 31. A Type-String tuple.
};

enum {
  kPTR = 1 << 14,          //< 64. Pointer modifier.
  kCNS = 1 << 15,          //< 128. Constant.
  kCNS_PTR = kCNS | kPTR,  //< 128. Constant Pointer.
  kCNS_ST1 = kCNS | kCH1,  //< 133. Constant CH1*.
  kCNS_ST2 = kCNS | kCH2,  //< 134. Constant CH2*.
  kCNS_ST3 = kCNS | kCH4,  //< 135. Constant CH4*.
};

enum {
  kRS1 = 97,  //< 97. A type-value tuple list with 2-byte signed size_bytes.
  kRS2 = 98,  //< 98. A type-value tuple list with 4-byte signed size_bytes.
  kRS4 = 99,  //< 99. A type-value tuple list with 8-byte signed size_bytes.
  kINV = 64,  //< The number of Ascii Data Type base types.
  kTypePODBitCount = 5,   //< Bit
  kTypeCount = 32,        //< The starting index of invalid types.
  kTypePODMask = 32 - 1,  //< The starting index of invalid types.
};

enum {
  kSW1 = 0,  //< 0. Class or POD type.
  kSW2 = 1,  //< 1. size_width of size_bytes is 16-bits wide.
  kSW4 = 2,  //< 2. size_width of size_bytes is 32-bits wide.
  kSW8 = 3,  //< 3. size_width of size_bytes is 64-bits wide.
};

enum {
  kPOD = 0,  //< A POD type.
  kARY = 1,  //< Array of POD types.
  kVEC = 2,  //< Vector of POD types.
  kMAT = 3,  //< Matrix of POD types.
};

enum {
  kLST = 48,  //< ASCII List type.
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
