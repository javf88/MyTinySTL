#ifndef MYTINYSTL_ALGORITHM_PERFORMANCE_TEST_H_
#define MYTINYSTL_ALGORITHM_PERFORMANCE_TEST_H_

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "algorithm.h"

#define LEN1    10000
#define LEN2    100000
#define LEN3    1000000
#define WIDE    14

namespace mystl
{
namespace test
{
namespace algorithm_performance_test
{

// 函数性能测试宏定义
//FUN_TEST1(std, sort, LEN1);
#define FUN_TEST1(mode, fun, count) do {                      \
    std::string fun_name = #fun;                               \
    srand((int)time(0));                                       \
    char buf[10];                                              \
    clock_t start, end;                                        \
    int *arr = new int[count];                                 \
    for(size_t i = 0; i < count; ++i)  *(arr + i) = rand();    \
    start = clock();                                           \
    mode::fun(arr, arr + count);                               \
    end = clock();                                             \
    int n = static_cast<int>(static_cast<double>(end - start)  \
        / CLOCKS_PER_SEC * 1000);                              \
    std::snprintf(buf, sizeof(buf), "%d", n);                  \
    std::string t = buf;                                       \
    t += "ms   |";                                             \
    std::cout << std::setw(WIDE) << t;                         \
    delete []arr;                                              \
} while(0)

void fun_test1(int mode, int count)
{
    clock_t start, end;
    std::vector<int> vals;
    srand(time(0));

    for (int i = 0; i < count; ++i)
        vals.push_back(rand());

    if (mode == 0) // std := 0
    {
        start = clock();
        std::sort(vals.begin(), vals.end());
        end = clock();
    }
    else
    {
        start = clock();
        mystl::sort(vals.begin(), vals.end());
        end = clock();
    }

    double ms = end - start;
    ms = ms / CLOCKS_PER_SEC * 1000;
    std::cout << std::setw(WIDE) << ms << "ms    |";
}

#define FUN_TEST2(mode, fun, count) do {                      \
    std::string fun_name = #fun;                               \
    srand((int)time(0));                                       \
    char buf[10];                                              \
    clock_t start, end;                                        \
    int *arr = new int[count];                                 \
    for(size_t i = 0; i < count; ++i)  *(arr + i) = rand();    \
    start = clock();                                           \
    for(size_t i = 0; i < count; ++i)                          \
        mode::fun(arr, arr + count, rand());                   \
    end = clock();                                             \
    int n = static_cast<int>(static_cast<double>(end - start)  \
        / CLOCKS_PER_SEC * 1000);                              \
    std::snprintf(buf, sizeof(buf), "%d", n);                  \
    std::string t = buf;                                       \
    t += "ms   |";                                             \
    std::cout << std::setw(WIDE) << t;                         \
    delete []arr;                                              \
} while(0)

void test_len(size_t len1, size_t len2, size_t len3, size_t wide)
{
  std::string str1, str2, str3;
  std::stringstream ss;
  ss << len1 << " " << len2 << " " << len3;
  ss >> str1 >> str2 >> str3;
  str1 += "   |";
  std::cout << std::setw(wide) << str1;
  str2 += "   |";
  std::cout << std::setw(wide) << str2;
  str3 += "   |";
  std::cout << std::setw(wide) << str3 << "\n";
}

void binary_search_test()
{
  std::cout << "[------------------- function : binary_search ------------------]" << std::endl;
  std::cout << "| orders of magnitude |";
  test_len(LEN1, LEN2, LEN3, WIDE);
  std::cout << "|         std         |";
  FUN_TEST2(std, binary_search, LEN1);
  FUN_TEST2(std, binary_search, LEN2);
  FUN_TEST2(std, binary_search, LEN3);
  std::cout << std::endl << "|        mystl        |";
  FUN_TEST2(mystl, binary_search, LEN1);
  FUN_TEST2(mystl, binary_search, LEN2);
  FUN_TEST2(mystl, binary_search, LEN3);
  std::cout << std::endl;
}

void sort_test()
{
  std::cout << "[----------------------- function : sort -----------------------]" << std::endl;
  std::cout << "| orders of magnitude |";
  test_len(LEN1, LEN2, LEN3, WIDE);
  std::cout << "|         std         |";
  fun_test1(0, LEN1);
  fun_test1(0, LEN2);
  fun_test1(0, LEN3);
  std::cout << std::endl << "|        mystl        |";
  fun_test1(1, LEN1);
  fun_test1(1, LEN2);
  fun_test1(1, LEN3);
  std::cout << std::endl;
}

} // namespace algorithm_performance_test
} // namespace test
} // namespace mystl

int main()
{
//    mystl::test::algorithm_performance_test::binary_search_test();
    mystl::test::algorithm_performance_test::sort_test();
}
#endif // !MYTINYSTL_ALGORITHM_PERFORMANCE_TEST_H_

