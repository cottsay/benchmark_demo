cmake_minimum_required(VERSION 3.5)
project(benchmark_demo CXX)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)

if(BUILD_TESTING)
  # BENCHMARK_F seems to break cppcheck 2.1
  set(ament_cmake_cppcheck_FOUND TRUE)

  find_package(ament_cmake_google_benchmark REQUIRED)
  find_package(ament_lint_auto REQUIRED)
  find_package(performance_test_fixture REQUIRED)
  ament_lint_auto_find_test_dependencies()

  # Set the thresholds file
  set(AMENT_CMAKE_GOOGLE_BENCHMARK_OVERLAY test/benchmark_thresholds.json)

  # Standalone Google Benchmark
  ament_add_google_benchmark(simple_benchmark test/simple_benchmark.cpp)

  # Standalone Google Benchmark with randomized data
  ament_add_google_benchmark(random_values test/random_values.cpp)

  # With osrf_testing_tools_cpp integration
  add_performance_test(memory_benchmark test/memory_benchmark.cpp)
endif()

ament_package()
