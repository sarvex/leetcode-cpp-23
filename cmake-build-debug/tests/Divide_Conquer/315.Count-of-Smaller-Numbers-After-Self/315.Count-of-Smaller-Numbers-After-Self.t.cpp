#include "gtest/gtest.h"
#include <algorithm>
#include <chrono>// benchmark
#include <ctime>
#include <unistd.h>
#include <vector>

#include "315.binary-indexed-tree.h"
#include "315.divided-conquer.h"

#include <assert.h>
#include <cstdlib>// atexit
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>


static std::vector<int>
count_of_smaller_numbers_after_self_dc(std::vector<int> &nums) {
  static void *handle = dlopen("C:/Users/Yoga/Sources/leecode-cpp-23/cmake-build-debug/tests/Divide_Conquer/315.Count-of-Smaller-Numbers-After-Self/libdivided_conquer_315.so", RTLD_LAZY);
  assert(handle);

  static auto counter =
    (std::vector<int>(*)(std::vector<int> &)) dlsym(handle, "count_v1");

  // handle keep alive, no need to release

  return counter(nums);
}

static std::vector<int>
count_of_smaller_numbers_after_self_bit(std::vector<int> &nums) {
  static void *handle = dlopen("C:/Users/Yoga/Sources/leecode-cpp-23/cmake-build-debug/tests/Divide_Conquer/315.Count-of-Smaller-Numbers-After-Self/libbinary_indexed_tree_315.so", RTLD_LAZY);

  assert(handle);

  static auto counter =
    (std::vector<int>(*)(std::vector<int> &)) dlsym(handle, "count_v2");

  // handle keep alive, no need to release

  return counter(nums);
}

TEST(count_of_smaller_numbers_after_self, consistency) {
  std::vector<int> nums{5, 2, 6, 1};
  std::vector<int> expected{2, 1, 1, 0};

  ASSERT_EQ(count_of_smaller_numbers_after_self_dc(nums), expected);
  ASSERT_EQ(count_of_smaller_numbers_after_self_bit(nums), expected);
}

TEST(count_of_smaller_numbers_after_self, benchmark) {
  std::vector<int> nums(1e5, 0);

  for (auto &num: nums)
    num = rand() % static_cast<int>(2 * 1e4) - 1e4;

  std::vector<int> counts1;
  std::vector<int> counts2;

  counts1.reserve(1e5);
  counts2.reserve(1e5);

  {
    auto start = chrono::steady_clock::now();
    counts1 = count_of_smaller_numbers_after_self_dc(nums);
    auto end = chrono::steady_clock::now();

    printf("time cost of countSmaller using merge sort is %ld [ms]\n",
           chrono::duration_cast<chrono::milliseconds>(end - start).count());
  }

  {
    auto start = chrono::steady_clock::now();
    counts2 = count_of_smaller_numbers_after_self_bit(nums);
    auto end = chrono::steady_clock::now();

    printf("time cost of countSmaller using binary indexed tree is %ld [ms]\n",
           chrono::duration_cast<chrono::milliseconds>(end - start).count());
  }

  ASSERT_EQ(counts1, counts2);
}
