///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2003 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

// cd /mnt/c/Users/ckorm/Documents/Ks/PC_Software/NumericalPrograms/ExtendedNumberTypes/long_long_long
// g++ -O3 -std=c++20 -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion -O3 -I. -I/mnt/c/boost/boost_1_87_0 test/test.cpp -o test.exe

#include <math/long_long_long/long_long_long.h>

#define LONG_LONG_LONG_TEST_CASE(name) auto name() -> void

#define BOOST_TEST_MODULE test_long_long_long
#define BOOST_LIB_DIAGNOSTIC

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/core/lightweight_test.hpp>

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>

typedef math::lll::unsigned_long_long_long<std::uint32_t> uint128_type;
typedef math::lll::signed_long_long_long  <std::uint32_t>  int128_type;

typedef boost::multiprecision::uint128_t unsigned_control_type;
typedef boost::multiprecision::int128_t    signed_control_type;

namespace
{
  #if defined(_DEBUG)
    const std::uint_fast32_t test_case_count = UINT32_C(0x00000200);
  #else
    const std::uint_fast32_t test_case_count = UINT32_C(0x00020000);
  #endif

  using random_generator_type = ::std::mt19937_64;

  ::std::uniform_int_distribution<unsigned> uniform_bit_range(UINT8_C(0), UINT8_C(1));

  random_generator_type engine { static_cast<typename random_generator_type::result_type>(::std::clock()) };

  template<const unsigned BitCount>
  auto uint128_generator() -> uint128_type
  {
    static_assert(BitCount <= 128U, "Error: 128 bits has been exceeded in the uint128 generator!");

    uint128_type u(0U);

    for(unsigned bpos {UINT8_C(0) }; bpos < BitCount; ++bpos)
    {
      u |= uint128_type { uint128_type { uniform_bit_range(engine) } << static_cast<int>(bpos) };
    }

    return u;
  }

  template<typename IntegralType>
  auto my_lexical_cast(const IntegralType& val) -> std::string
  {
    ::std::stringstream strm { };

    strm << val;

    return strm.str();
  }
}

#include <math/long_long_long/long_long_long.h>

LONG_LONG_LONG_TEST_CASE(test_unsigned_example)
{
  using uint128_t = math::lll::unsigned_long_long_long<std::uint32_t>;

  uint128_t p3 { uint128_t { 3 } };

  p3 *= p3;
  p3 *= p3;
  p3 *= p3;
  p3 *= p3;
  p3 *= p3;
  p3 *= p3;

  // 3^64
  const uint128_t
    ctrl
    {
        uint128_t { UINT64_C(1853020188851841) }
      * uint128_t { UINT64_C(1853020188851841) }
    };

  BOOST_TEST(p3 == ctrl);
}

LONG_LONG_LONG_TEST_CASE(test_unsigned_long_long_long)
{
  std::cout << "Test unsigned add ((128 + 128) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a + b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control + b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned sub ((128 - 128) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a - b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control - b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned sub (( 71 - 128) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator< 71U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a - b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control - b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned mul ((  3 * 125) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<  3U>());
    const uint128_type b(::uint128_generator<125U>());

    const uint128_type c(a * b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control * b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned mul (( 33 *  95) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<33U>());
    const uint128_type b(::uint128_generator<95U>());

    const uint128_type c(a * b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control * b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned mul (( 65 *  63) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<65U>());
    const uint128_type b(::uint128_generator<63U>());

    const uint128_type c(a * b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control * b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned mul (( 96 *  32) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<96U>());
    const uint128_type b(::uint128_generator<32U>());

    const uint128_type c(a * b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control * b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned mul ((111 *  17) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<111U>());
    const uint128_type b(::uint128_generator< 17U>());

    const uint128_type c(a * b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control * b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /   3) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<  3U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /  17) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 17U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /  32) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 32U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /  47) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 47U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string c_str        (my_lexical_cast(c));
    const std::string c_control_str(my_lexical_cast(c_control));

    BOOST_TEST(c_str == c_control_str);
  }

  std::cout << "Test unsigned div ((128 /  57) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 57U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /  64) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 64U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /  89) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 89U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 /  92) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator< 92U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 / 101) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<101U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned div ((128 / 128) --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a / b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control((b_control != 0U) ? a_control / b_control : a_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned cmp (128 > 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const bool is_gt(a > b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const bool is_gt_control(a_control > b_control);

    BOOST_TEST(is_gt == is_gt_control);
  }

  std::cout << "Test unsigned cmp (128 < 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const bool is_lt(a < b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const bool is_lt_control(a_control < b_control);

    BOOST_TEST(is_lt == is_lt_control);
  }

  std::cout << "Test unsigned cmp (128 != 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const bool is_ne(a != b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const bool is_ne_control(a_control != b_control);

    BOOST_TEST(is_ne == is_ne_control);
  }

  std::cout << "Test unsigned cmp (128 == 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(a);

    const bool is_eq(a == b);

    BOOST_TEST(is_eq == true);
  }

  std::cout << "Test unsigned shl (128 << int)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int shift { static_cast<int>(::uint128_generator<7U>().to_uint32()) };

    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(a << shift);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(a_control * (unsigned_control_type(1U) << shift));

    const std::string str        (my_lexical_cast(b));
    const std::string str_control(my_lexical_cast(b_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned shr (128 >> int)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int shift { static_cast<int>(::uint128_generator<7U>().to_uint32()) };

    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(a >> shift);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(a_control / (unsigned_control_type(1U) << shift));

    const std::string str        (my_lexical_cast(b));
    const std::string str_control(my_lexical_cast(b_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned mod (128 % uint32_t)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint32_t mod_arg(::uint128_generator<32U>().to_uint32());

    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(a % mod_arg);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(a_control % mod_arg);

    const std::string str        (my_lexical_cast(b));
    const std::string str_control(my_lexical_cast(b_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned not (128 ~ self)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(~a);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(~a_control);

    const std::string str        (my_lexical_cast(b));
    const std::string str_control(my_lexical_cast(b_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned and (128 & 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a & b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control & b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned or  (128 | 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a | b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control | b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned xor (128 ^ 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const uint128_type a(::uint128_generator<128U>());
    const uint128_type b(::uint128_generator<128U>());

    const uint128_type c(a ^ b);

    const unsigned_control_type a_control(my_lexical_cast(a));
    const unsigned_control_type b_control(my_lexical_cast(b));

    const unsigned_control_type c_control(a_control ^ b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned inc (++127 --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    uint128_type a(::uint128_generator<127U>());

    unsigned_control_type a_control(my_lexical_cast(a));

    ++a;
    ++a_control;

    const std::string str        (my_lexical_cast(a));
    const std::string str_control(my_lexical_cast(a_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test unsigned dec (--128 --> 128)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    uint128_type a(::uint128_generator<128U>());

    unsigned_control_type a_control(my_lexical_cast(a));

    --a;
    --a_control;

    const std::string str        (my_lexical_cast(a));
    const std::string str_control(my_lexical_cast(a_control));

    BOOST_TEST(str == str_control);
  }
}

LONG_LONG_LONG_TEST_CASE(test_signed_long_long_long)
{
  std::cout << "Test   signed add ((  126  +   126 ) --> 127)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c(a + b);

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control(a_control + b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed add ((  126  + (-126)) --> 126)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c(a + (-b));

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control(a_control + (-b_control));

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed add (((-126) +   126 ) --> 126)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c((-a) + b);

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control((-a_control) + b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed add (((-126) + (-126)) --> 127)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c(((-a) + (-b)));

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control((-a_control) + (-b_control));

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed sub ((  126  -   126 ) --> 126)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c(a - b);

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control(a_control - b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed sub ((  126  - (-126)) --> 127)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c(a - (-b));

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control(a_control - (-b_control));

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed sub (((-126) -   126 ) --> 127)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c((-a) - b);

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control((-a_control) - b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed sub (((-126) - (-126)) --> 126)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<126U>());

    const int128_type c(((-a) - (-b)));

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control((-a_control) - (-b_control));

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed mul (((- 32) *    94 ) --> 126)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<32U>());
    const int128_type b(::uint128_generator<94U>());

    const int128_type c((-a) * b);

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control((-a_control) * b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }

  std::cout << "Test   signed div (((-126) /    92 ) --> 126)" << std::endl;

  for(std::uint_fast32_t i { UINT32_C(0) }; i < test_case_count; ++i)
  {
    const int128_type a(::uint128_generator<126U>());
    const int128_type b(::uint128_generator<92U>());

    const int128_type c((-a) / b);

    const signed_control_type a_control(my_lexical_cast(a));
    const signed_control_type b_control(my_lexical_cast(b));

    const signed_control_type c_control((-a_control) / b_control);

    const std::string str        (my_lexical_cast(c));
    const std::string str_control(my_lexical_cast(c_control));

    BOOST_TEST(str == str_control);
  }
}

auto main() -> int
{
  test_unsigned_example();
  test_signed_long_long_long();
  test_unsigned_long_long_long();

  return boost::report_errors();
}
