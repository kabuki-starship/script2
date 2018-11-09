/* Script^2 @version 0.x
@link    https://github.com/kabuki-starship/script.git
@file    /script2_benchmark.cc
@author  Cale McCollough <cale.mccollough@gmail.com>
@license Copyright (C) 2014-2017 Cale McCollough <calemccollough.github.io>;
All right reserved (R). Licensed under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at www.apache.org/licenses/LICENSE-2.0.
Unless required by applicable law or agreed to in writing, software distributed
under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License. */

#include <pch.h>

#if SEAM >= _0_0_0__12
#include "tbenchmark.h"

#include "rng.h"
#include "tbinary.h"
#include "ttest.h"

#include <chrono>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;
using namespace std::chrono;

#if SEAM == _0_0_0__12
#include "test_debug.inl"
#else
#include "test_release.inl"
#endif

namespace _ {

BenchmarkCase::BenchmarkCase(const char* name, TestCase* cases, int count)
    : name(name), cases(cases), count(count) {}

const char* BenchmarkCase::Run(char* cursor, char* end, const char* args) {
  /*
  DBL nil_reading;
  int i;
  int columns_max;
  ASSERT(Scan<>(args, columns_max));

  for (i = 0; i < count; ++i) {
    const char* result = (*cases[i])(nullptr, nullptr, nullptr);
    Print(result);
    if (i < count) Print(',', ' ');
  }
  for (; i < columns_max; ++i) Print(',');
  PrintLn();
  for (i = 0; i < count; ++i) {
    const char* result = (*cases[i])(nullptr, nullptr, nullptr);
    if (i < count) Print(',', ' ');
  }
  PrintLn();
  */
  return nullptr;
}

int BenchmarkCase::GetCount() { return count; }

Benchmark::Benchmark(const char* name, const char* filename,
                     BenchmarkCase* groups, int count)
    : name(name), filename(filename), groups(groups), count(count) {
  ASSERT(count > 0);
  int l_test_count_max = 0;
  for (intptr_t i = 0; i < count; ++i) {
  }
}

const char* Benchmark::Run(char* cursor, char* end, const char* args) {
  /*
  std::ofstream out(filename);

  auto* coutbuf = std::cout.rdbuf();
  std::cout.rdbuf(out.rdbuf());

  for (size_t i = 0; i < count; ++i) {
    BenchmarkCase group = groups[i];
    const char* result = group.Run(cursor, end, args);
    ASSERT(result);
    Print(result);
  }
  BenchmarkCase *benchmark_case = groups, *end = groups + count - 1;
  for (int i = 0; i <  {
    groups[i]->Run(cursor, end, args);
  }
  std::cout.rdbuf(coutbuf);*/
  return nullptr;
}

}  // namespace _

#include "test_footer.inl"
#endif