#include "global_footer.inl"
#include "t_test.h"

#define DEBUG_SEAM 1
#define TEST_BEGIN \
  if (!::_::TestBegin(seam_log, seam_end, args)) return __FUNCTION__
#define TEST_END Print("\n\nDone testing ", __FUNCTION__)
#define PRINTNL ::_::PrintNL()
#define PRINT(item) ::_::Print(item)
#define PRINT_TIME(t) ::_::PrintTime(t)
#define PRINTF(format, ...) ::_::Printf(format, __VA_ARGS__)
#define PAUSE(message) ::_::Pause(message)
#define PAUSEF(format, ...) ::_::Pausef(format, __VA_ARGS__)
#define PRINT_LINEF(style) ::_::PrintLinef(style)
#define PRINT_LINEF_COUNT(style, count) ::_::PrintLinef(style, count)
#define PRINT_HEADING(caption) ::_::PrintHeadingf(caption)
#define PRINT_HEADINGF(caption, style) ::_::PrintHeadingf(caption, style)
#define PRINT_HEADINGF_COUNT(caption, style, column_count) \
  ::_::PrintHeadingf(caption, style, column_count)
#define PRINT_HEADINGF_2(caption, style, column_count, caption2) \
  ::_::PrintHeadingf(caption, style, column_count, caption2)
#define PRINT_HEADINGF_3(caption, style, column_count, caption2, caption3) \
  ::_::PrintHeadingf(caption, style, column_count, caption2, caption3)
#define PRINT_TYPE(type, value) ::_::Console<>().Out() << TypeValue(type, value)
#define PRINT_CHARS(begin, end_or_size) ::_::PrintChars(begin, end_or_size)
#define PRINT_HEX(item) ::_::PrintHex(item)
#define PRINT_HEXS(begin, end_or_size) ::_::PrintHex(begin, end_or_size)
#define PRINT_SOCKET_TOBJ(obj) ::_::PrintChars(obj.Begin(), obj.SizeBytes())
#define PRINT_BSQ(bsq) ::_::Console<>().Out() << header << kLF << Bsq(bsq)
#define PRINT_OBJ(stack) stack->Print()
#define PRINT_TOBJ(stack) stack.Print()
#define PRINT_FUNCTION ::_::Print("\n", __FUNCTION__)
#define PRINTLN ::_::PrintNL()
#define PRINT_FUNCTION_LINE \
  ::_::PrintNL();           \
  ::_::TestFunctionLine(__LINE__, __FUNCTION__, __FILE__)
#define SOCKET_SAVE(cursor, end_a) Socket socket_to_print(cursor, end_a)
#define SOCKET_FILL(begin, end_or_size, c) \
  ::_::SocketFill(cursor, end_or_size, c)
#define SOCKET_WIPE(begin, end_or_size) ::_::SocketWipe(begin, end_or_size)
#define CHECK(condition) \
  if (!::_::Test(condition)) ::_::TestWarn(__LINE__, __FUNCTION__, __FILE__)
#define COMPARE(a, b)                                \
  if (!::_::Test(a, b)) {                            \
    ::_::Print("\n\nExpecting:");                    \
    ::_::PrintHex(a);                                \
    ::_::Print(':');                                 \
    ::_::Print(a);                                   \
    ::_::Print("\nFound    :");                      \
    ::_::PrintHex(b);                                \
    ::_::Print(':');                                 \
    ::_::Print(b);                                   \
    ::_::TestWarn(__LINE__, __FUNCTION__, __FILE__); \
  }
#define ASSERT_INDEX(condition, index)                                \
  if (!::_::Test(condition)) {                                        \
    ::_::Printf("\nError at index:0x%x:%i!", (SI4)index, (SI4)index); \
    ::_::TestFail(__LINE__, __FUNCTION__, __FILE__);                  \
  }
#define ASSERT(condition) \
  if (!::_::Test(condition)) ::_::TestFail(__LINE__, __FUNCTION__, __FILE__)
#define DASSERT(condition) \
  if (!::_::Test(condition)) ::_::TestFail(__LINE__, __FUNCTION__, __FILE__)
#define RASSERT(condition)
#define AVOW(a, b)                                   \
  if (!::_::Test(a, b)) {                            \
    ::_::Print("\n\nExpecting:");                    \
    ::_::PrintHex(a);                                \
    ::_::Print(':');                                 \
    ::_::Print(a);                                   \
    ::_::Print("\nFound    :");                      \
    ::_::PrintHex(b);                                \
    ::_::Print(':');                                 \
    ::_::Print(b);                                   \
    ::_::TestFail(__LINE__, __FUNCTION__, __FILE__); \
  }
#define DAVOW(a, b)                                  \
  if (!::_::Test(a, b)) {                            \
    ::_::Print("\n\nExpecting:");                    \
    ::_::PrintHex(a);                                \
    ::_::Print(':');                                 \
    ::_::Print(a);                                   \
    ::_::Print("\nFound    :");                      \
    ::_::PrintHex(b);                                \
    ::_::Print(':');                                 \
    ::_::Print(b);                                   \
    ::_::TestFail(__LINE__, __FUNCTION__, __FILE__); \
  }
#define RAVOW(a, b)
#define RASSERT(condition)
#define AVOW_INDEX(a, b, index)                      \
  if (!::_::Test(a, b)) {                            \
    ::_::Print("\n\nExpecting:");                    \
    ::_::PrintHex(a);                                \
    ::_::Print(':');                                 \
    ::_::Print(a);                                   \
    ::_::Print("\nFound    :");                      \
    ::_::PrintHex(b);                                \
    ::_::Print(':');                                 \
    ::_::Print(b);                                   \
    ::_::Print("\nAt index :0x");                    \
    ::_::PrintHex(index);                            \
    ::_::Print(index);                               \
    ::_::Print(':');                                 \
    ::_::TestFail(__LINE__, __FUNCTION__, __FILE__); \
  }
//
#define RETURN(value) \
  { ::_::TestFunctionLine(__LINE__, __FUNCTION__, __FILE__) return value; }
#define DRETURN(value) \
  { ::_::TestFunctionLine(__LINE__, __FUNCTION__, __FILE__) return value; }
#define RRETURN(value)
#define RETURN_VALUE(value) \
  { ::_::TestFunctionLine(__LINE__, __FUNCTION__, __FILE__) return value; }
#define DRETURN_VALUE(value) \
  { ::_::TestFunctionLine(__LINE__, __FUNCTION__, __FILE__) return value; }
#define RRETURN_VALUE(value)
