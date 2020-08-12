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

#include <benchmark/benchmark.h>

#include <chrono>
#include <random>
#include <thread>

const float mean = 0.025;
const float stdev = 0.0025;

static void random_values(benchmark::State & state)
{
  std::random_device rdev;
  std::mt19937 rgen(rdev());
  std::normal_distribution<float> dist(mean, stdev);

  for (auto _ : state) {
    std::this_thread::sleep_for(std::chrono::duration<float>(dist(rgen)));
  }
}
BENCHMARK(random_values);
