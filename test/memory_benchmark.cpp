// Copyright 2020 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Note that including osrf_testing_tools_cpp is necessary because
// of the call to guaranteed_malloc. It isn't necessary for the
// PerformanceTest fixture to be used.

#include <osrf_testing_tools_cpp/memory_tools/is_working.hpp>
#include <performance_test_fixture/performance_test_fixture.hpp>

using performance_test_fixture::PerformanceTest;

BENCHMARK_F(PerformanceTest, memory_test)(benchmark::State & st)
{
  for (auto _ : st) {
    osrf_testing_tools_cpp::memory_tools::guaranteed_malloc("Hello, World!");
    osrf_testing_tools_cpp::memory_tools::guaranteed_malloc("¡Hola, mundo!");
  }
}
