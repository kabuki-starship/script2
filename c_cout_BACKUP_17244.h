/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script2.git
@file    /script2/c_cout.h
@author  Cale McCollough <https://calemccollough.github.io>
@license Copyright (C) 2014-2019 Cale McCollough <cale@astartup.net>;
All right reserved (R). This Source Code Form is subject to the terms of the
Mozilla Public License, v. 2.0. If a copy of the MPL was not distributed with
this file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once
#include <pch.h>

#ifndef SCRIPT2_COUT_C
#define SCRIPT2_COUT_C 1

#if USING_UTF8 == YES
#include "c_uniprinter1.h"
#endif
#if USING_UTF16 == YES
#include "c_uniprinter2.h"
#endif
#if USING_UTF32 == YES
#include "c_uniprinter4.h"
#endif

namespace _ {

/* Converts SI4 main(SI4,CH1**) arguments back into a string.
@return nil if there are no arguments or the args string upon success.
@param arg_count The number_ of arguments.
@param args      The arguments. */
SDK const CH1* ArgsToSring(SI4 arg_count, CH1** args);

/* Force-prints a single CH1 to the console. */
SDK /*inline*/ void PrintChar(CH1 c);
SDK /*inline*/ void PrintChar(CH2 c);
SDK /*inline*/ void PrintChar(CH4 c);

/* Prints a single CH1 to the console. */
SDK void Print(CH1 first, CH1 second);

/* Prints a single CH1 to the console. */
SDK void Print(CH1 first, CH1 second, CH1 third);

/* Prints a single string to the console followed by the given delimiter. */
SDK void Print(const CH1* string, CH1 delimiter);

/* Prints two strings to the COut. */
SDK void Print(const CH1* a, const CH1* b);

/* Prints the give item to the COut. */
SDK /*inline*/ void Print(CH1 c);
SDK /*inline*/ void Print(CH2 c);
SDK /*inline*/ void Print(CH4 c);
SDK void Print(const CH1* string);
SDK void Print(const CH2* string);
SDK void Print(const CH4* string);
SDK void Print(SI8 item);
SDK void Print(UI8 item);
SDK void Print(SI4 item);
SDK void Print(UI4 item);
SDK void Print(FP4 item);
SDK void Print(FP8 item);

/* Prints a new line followed by a single CH1 to the console. */
SDK /*inline*/ void PrintNL();

/* Prints a new line followed by a single CH1 to the console. */
SDK /*inline*/ void PrintNL(CH1 c);

/* Prints a new line followed by a single CH1 to the console. */
SDK /*inline*/ void PrintNL(CH1 first, CH1 second);

/* Prints a new line followed by a single string to the console. */
SDK /*inline*/ void PrintNL(const CH1* string);

/* Prints a formatted string to the console. */
SDK void Printf(const CH1* format, ...);

/* Prints a new line followed by a formatted string to the console. */
SDK void PrintfLn(const CH1* format, ...);

/* Prints a new line followed by the given number_ of spaces.
@param The number_ of spaces to indent. */
SDK void PrintIndent(SI4 count = 1);

/* Prints a item to the COut. */
SDK void PrintBinary(UI1 item);
SDK void PrintBinary(SI1 item);
SDK void PrintBinary(UI2 item);
SDK void PrintBinary(SI2 item);
SDK void PrintBinary(UI4 item);
SDK void PrintBinary(SI4 item);
SDK void PrintBinary(UI8 item);
SDK void PrintBinary(SI8 item);
SDK void PrintBinary(FP4 item);
SDK void PrintBinary(FP8 item);
SDK void PrintBinary(const void* item);

#if SEAM >= SCRIPT2_1
/* Prints a item to the console to hex. */
SDK void PrintHex(CH1 item);
SDK void PrintHex(CH2 item);
SDK void PrintHex(CH4 item);
SDK void PrintHex(UI1 item);
SDK void PrintHex(SI1 item);
SDK void PrintHex(UI2 item);
SDK void PrintHex(SI2 item);
SDK void PrintHex(UI4 item);
SDK void PrintHex(SI4 item);
SDK void PrintHex(UI8 item);
SDK void PrintHex(SI8 item);
SDK void PrintHex(FP4 item);
SDK void PrintHex(FP8 item);

/* Prints the given socket to the stdout in hex format. */
SDK void PrintHex(const void* begin, const void* end);

/* Prints the given socket to the stdout in hex format. */
SDK void PrintHex(const void* begin, SIW size);

/* Prints a pointer to the console in hex. */
SDK void PrintHex(const void* value);
#endif

/* Prints the given socket to the stdout. */
SDK void PrintChars(const void* begin, const void* end);

/* Prints the given socket to the stdout. */
SDK void PrintChars(const void* begin, SIW size);

/* Prints the given item right aligned the given count to the stdout. */
SDK /*inline*/ void PrintRight(const CH1* item, SI4 count = 80);

/* Prints the given item center aligned the given count to the stdout. */
SDK /*inline*/ void PrintCenter(const CH1* item, SI4 count = 80);

SDK const CH1* PrintLinefCH1();

/* Prints a formatted line string with the given column_count. */
SDK const CH1* PrintLinef(const CH1* style, SI4 column_count = 80);

/* Prints the given token the specified column_count. */
void PrintLinef(CH1 token, SI4 column_count = 80);

/* Prints a the given line_count of new lines followed by a PrintLinef, the
heading, followed by another PrintLinef.
@return Nil upon success or a pointer to the
@param style       The line format string.
@param column_count The width of the line to utf. */
SDK void PrintHeadingf(const CH1* caption, const CH1* style = nullptr,
                       SI4 column_count = 80, const CH1* caption2 = nullptr,
                       const CH1* caption3 = nullptr);

#if USING_UTF16 == YES

/* Prints the given UTF-16 characters to the stdout. */
SDK void PrintChars(const CH2* start, const CH2* stop);

/* Prints the given UTF-16 characters to the stdout. */
SDK void PrintChars(const CH2* start, SI4 count);

/* Prints the given item right aligned the given count to the stdout. */
SDK /*inline*/ void PrintRight(const CH2* item, SI4 count = 80);

/* Prints the given item center aligned the given count to the stdout. */
SDK /*inline*/ void PrintCenter(const CH2* item, SI4 count = 80);

SDK const CH2* PrintLinefCH2();

/* Prints the given token a specified count. */
SDK const CH2* PrintLinef(const CH2* style = PrintLinefCH2(),
                          SI4 column_count = 80);

/* Prints the given token the specified column_count. */
void PrintLinef(CH2 token, SI4 column_count = 80);

/* Prints a the given line_count of new lines followed by a PrintLinef, the
heading, followed by another PrintLinef.
@param style       The line format string.
@param column_count The width of the line to utf. */
SDK void PrintHeadingf(const CH2* caption, const CH2* style = nullptr,
                       SI4 column_count = 80, const CH2* caption2 = nullptr,
                       const CH2* caption3 = nullptr);
#endif

#if USING_UTF32 == YES

/* Prints the given UTF-16 characters to the stdout. */
SDK void PrintChars(const CH4* start, const CH4* stop);

/* Prints the given UTF-16 characters to the stdout. */
SDK void PrintChars(const CH4* start, SI4 size);

/* Prints the given item right aligned the given count to the stdout. */
SDK /*inline*/ void PrintRight(const CH4* item, SI4 count = 80);

/* Prints the given item center aligned the given count to the stdout. */
SDK /*inline*/ void PrintCenter(const CH4* item, SI4 count = 80);

SDK const CH4* PrintLinefCH4();

/* Prints the given style a specified count. */
SDK const CH4* PrintLinef(const CH4* style, SI4 column_count = 80);

/* Prints the given token the specified column_count. */
void PrintLinef(CH4 token, SI4 column_count = 80);

/* Prints a the given line_count of new lines followed by a PrintLinef, the
heading, followed by another PrintLinef.
@param style       The line format string.
@param column_count The width of the line to utf. */
SDK void PrintHeadingf(const CH4* caption, const CH4* style = nullptr,
                       SI4 column_count = 80, const CH4* caption2 = nullptr,
                       const CH4* caption3 = nullptr);
#endif

/* Utility class for printing to the stdout. */
class COut {
 public:
  /* Does nothing. */
  COut();

  /* Prints the given item to the COut stream. */
  COut(CH1 item);
  COut(CH2 item);
  COut(CH4 item);
  COut(const CH1* item);
  COut(const CH2* item);
  COut(const CH4* item);
  COut(SI1 item);
  COut(UI1 item);
  COut(SI2 item);
  COut(UI2 item);
  COut(SI4 item);
  COut(UI4 item);
  COut(SI8 item);
  COut(UI8 item);
#if SEAM >= SCRIPT2_4
  COut(FP4 item);
  COut(FP8 item);
#endif

  /* Returns reference to this. */
  COut& Star();

  /* Prints the given item to the stdout. */
<<<<<<< HEAD:c_cout.h
  COut& PrintChar(CH1 item);
=======
>>>>>>> e603515384a6a36733c3c027bc6bf0225197321f:c_cout.h
  COut& Print(CH1 item);
  COut& Print(const CH1* item);
  COut& Print(SI4 item);
  COut& Print(UI4 item);
  COut& Print(SI8 item);
  COut& Print(UI8 item);
#if USING_FP4 == YES
  COut& Print(FP4 item);
#endif
#if USING_FP8 == YES
  COut& Print(FP8 item);
#endif
#if SEAM >= SCRIPT2_1
  COut& Print(const void* begin, SIW size_bytes);
  COut& Print(Hex item);
#endif

#if SEAM >= SCRIPT2_3
  COut& Print(Right1 item);
  COut& Print(Center1 item);
  COut& Print(Linef1 item);
  COut& Print(Headingf1 item);
  COut& Print(Chars1 item);
#endif
#if USING_UTF16 == YES
<<<<<<< HEAD:c_cout.h
  COut& PrintChar(CH2 item);
=======
>>>>>>> e603515384a6a36733c3c027bc6bf0225197321f:c_cout.h
  COut& Print(CH2 item);
  COut& Print(const CH2* item);
  COut& Print(Right2 item);
  COut& Print(Center2 item);
  COut& Print(Linef2 item);
  COut& Print(Headingf2 item);
  COut& Print(Chars2 item);
#endif
#if USING_UTF32 == YES
<<<<<<< HEAD:c_cout.h
  COut& PrintChar(CH4 item);
=======
>>>>>>> e603515384a6a36733c3c027bc6bf0225197321f:c_cout.h
  COut& Print(CH4 item);
  COut& Print(const CH4* item);
  COut& Print(Right4 item);
  COut& Print(Center4 item);
  COut& Print(Linef4 item);
  COut& Print(Headingf4 item);
  COut& Print(Chars4 item);
#endif
};

}  // namespace _

/*inline*/ ::_::COut& operator<<(::_::COut& cout, CH1 c);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, const CH1* string);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, UI1 value);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, SI2 value);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, UI2 value);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, SI4 value);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, UI4 value);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, SI8 value);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, UI8 value);
#if USING_FP4 == YES
/*inline*/ ::_::COut& operator<<(::_::COut& cout, FP4 value);
#endif
#if USING_FP8 == YES
/*inline*/ ::_::COut& operator<<(::_::COut& cout, FP8 value);
#endif
#if SEAM >= SCRIPT2_1
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Hex item);
#endif

#if SEAM >= SCRIPT2_3
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Center1 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Right1 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Linef1 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Headingf1 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Chars1 item);
#if USING_UTF16 == YES
<<<<<<< HEAD:c_cout.h
/*inline*/ ::_::COut& operator<<(::_::COut& cout, CH2 c);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, const CH2* string);
=======
/*inline*/ ::_::COut& operator<<(::_::COut& cout, CH2 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, const CH2* item);
>>>>>>> e603515384a6a36733c3c027bc6bf0225197321f:c_cout.h
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Center2 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Right2 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Linef2 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Headingf2 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Chars2 item);
#endif
#if USING_UTF32 == YES
<<<<<<< HEAD:c_cout.h
/*inline*/ ::_::COut& operator<<(::_::COut& cout, CH4 c);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, const CH4* string);
=======
/*inline*/ ::_::COut& operator<<(::_::COut& cout, CH4 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, const CH4* item);
>>>>>>> e603515384a6a36733c3c027bc6bf0225197321f:c_cout.h
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Center4 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Right4 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Linef4 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Headingf4 item);
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::Chars4 item);
#endif
#endif
<<<<<<< HEAD:c_cout.h
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::COut& o);
=======
/*inline*/ ::_::COut& operator<<(::_::COut& cout, ::_::COut& item);
>>>>>>> e603515384a6a36733c3c027bc6bf0225197321f:c_cout.h
#endif