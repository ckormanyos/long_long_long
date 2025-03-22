///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2003 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef UNSIGNED_LONG_LONG_LONG_2003_12_08_H
  #define UNSIGNED_LONG_LONG_LONG_2003_12_08_H

  #include <math/long_long_long/detail/long_long_long_detail.h>

  #include <algorithm>
  #include <array>
  #include <cstddef>
  #include <cstdint>
  #include <limits>
  #include <utility>

  namespace math { namespace lll {

  // Forward declaration of the unsigned_long_long_long class.
  template<typename UnsignedSmallType, typename UnsignedLargeType>
  class unsigned_long_long_long;

  // Non-member unary +/- of unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator+(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& self);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator-(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& self);

  // Non-member binary add/sub/mul/div/mod of unsigned_long_long_long with unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator+(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator-(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator*(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator/(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator%(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);

  // Non-member binary add/sub/mul/div of unsigned_long_long_long with IntegralType.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator+(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator-(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator*(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator/(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);

  // Non-member binary add/sub/mul/div of IntegralType with unsigned_long_long_long.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator+(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator-(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator*(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator/(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u);

  // Non-member shift of const unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator<<(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const int n);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator>>(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const int n);

  // Non-member logic operators of unsigned_long_long_long with unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator&(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator|(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator^(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v);

  // Non-member logic operators of unsigned_long_long_long with IntegralType.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator&(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator|(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator^(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v);

  // Non-member logic operators of IntegralType with unsigned_long_long_long.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator&(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, const UnsignedLargeType>& u);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator|(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, const UnsignedLargeType>& u);
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator^(const IntegralType& v, const unsigned_long_long_long<UnsignedSmallType, const UnsignedLargeType>& u);
  } } // namespace math::lll

  namespace std
  {
    // Forward declaration of the specialization of std::numeric_limits<unsigned_long_long_long>.
    template<typename UnsignedSmallType, typename UnsignedLargeType>
    class numeric_limits<math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>;
  }

  namespace math { namespace lll {

  template<typename UnsignedSmallType,
           typename UnsignedLargeType = typename ::math::lll::detail::integer_type_helper<std::numeric_limits<UnsignedSmallType>::digits * 2>::exact_unsigned_type>
  class unsigned_long_long_long
  {
  protected:
    // Type definitions for types used in internal calculations.
    using unsigned_small_type = UnsignedSmallType;
    using unsigned_large_type = UnsignedLargeType;

    // Define a fixed-length data array with four data elements of type unsigned_small_type.
    // This data array contains the internal representation of unsigned_long_long_long.
    using data_array_type = ::std::array<unsigned_small_type, 4U>;

    data_array_type m_data { };

  public:
    // The signed_short_type must be the signed counterpart of unsigned_small_type.
    using signed_short_type = typename detail::integer_type_helper<std::numeric_limits<unsigned_small_type>::digits>::exact_signed_type;

    // The types of unsigned_large_type and unsigned_small_type must be unsigned.
    static_assert(   (std::numeric_limits<unsigned_small_type>::is_signed == false)
                  && (std::numeric_limits<unsigned_large_type >::is_signed == false),
                  "Error the unsigned short and unsigned long types must be unsigned!");

    // The unsigned_small_type must have exactly half as many digits as the unsigned_large_type.
    static_assert((std::numeric_limits<unsigned_small_type>::digits * 2) == std::numeric_limits<unsigned_large_type>::digits,
                  "Error: The unsigned_small_type must have exactly half as many digits as the unsigned_large_type!");

    // The signed short type must have exactly one digit fewer than the unsigned short type.
    static_assert((std::numeric_limits<unsigned_small_type>::digits - 1) == std::numeric_limits<signed_short_type>::digits,
                  "Error: The signed_short_type must have exactly one digit fewer than the unsigned_small_type!");

    // The signed_short_type type must be signed.
    static_assert(std::numeric_limits<signed_short_type>::is_signed,
                  "Error the signed_short_type must be signed!");

    static const int my_digits   = std::numeric_limits<unsigned_small_type>::digits * 4;
    static const int my_digits10 = static_cast<int>(static_cast<long long>(static_cast<long long>(unsigned_long_long_long::my_digits) * 30103LL) / 100000LL);
    static const int my_digits16 = unsigned_long_long_long::my_digits / 4;

    // Default constructor.
    unsigned_long_long_long() : m_data() { }

    // Constructors from built-in integral types.
    template<typename UnsignedIntegralType>
    unsigned_long_long_long(const UnsignedIntegralType& u,
                            typename std::enable_if<   (std::is_integral<UnsignedIntegralType>::value == true)
                                                    && (std::is_signed  <UnsignedIntegralType>::value == false)>::type const* = nullptr)
      : m_data()
    {
      from_unsigned_integral_type(u);
    }

    template<typename SignedIntegralType>
    unsigned_long_long_long(const SignedIntegralType& n,
                            typename std::enable_if<   (std::is_integral<SignedIntegralType>::value == true)
                                                    && (std::is_signed  <SignedIntegralType>::value == true)>::type const* = nullptr)
      : m_data()
    {
      typedef typename detail::integer_type_helper<std::numeric_limits<SignedIntegralType>::digits + 1>::exact_unsigned_type local_unsigned_type;

      if(n < 0)
      {
        from_unsigned_integral_type(static_cast<local_unsigned_type>(-n));

        negate();
      }
      else
      {
        from_unsigned_integral_type(static_cast<local_unsigned_type>(n));
      }
    }

    // Copy constructor.
    unsigned_long_long_long(const unsigned_long_long_long& other) : m_data()
    {
      m_data[0U] = other.m_data[0U];
      m_data[1U] = other.m_data[1U];
      m_data[2U] = other.m_data[2U];
      m_data[3U] = other.m_data[3U];
    }

    // Move constructor.
    unsigned_long_long_long(unsigned_long_long_long&& other) : m_data(static_cast<data_array_type&&>(other.m_data)) { }

    // Assignment operator.
    unsigned_long_long_long& operator=(const unsigned_long_long_long& other)
    {
      if(this != &other)
      {
        m_data[0U] = other.m_data[0U];
        m_data[1U] = other.m_data[1U];
        m_data[2U] = other.m_data[2U];
        m_data[3U] = other.m_data[3U];
      }

      return *this;
    }

    virtual ~unsigned_long_long_long() { }

    // Unary arithmetic operators.
    unsigned_long_long_long& operator+=(const unsigned_long_long_long& v)
    {
      const unsigned_large_type res0(unsigned_large_type(m_data[0U]) + v.m_data[0U]);
      const unsigned_large_type res1(unsigned_large_type(m_data[1U]) + v.m_data[1U] + hi_part(res0));
      const unsigned_large_type res2(unsigned_large_type(m_data[2U]) + v.m_data[2U] + hi_part(res1));
      const unsigned_large_type res3(unsigned_large_type(m_data[3U]) + v.m_data[3U] + hi_part(res2));

      m_data[0U] = lo_part(res0);
      m_data[1U] = lo_part(res1);
      m_data[2U] = lo_part(res2);
      m_data[3U] = lo_part(res3);

      return *this;
    }

    unsigned_long_long_long& operator-=(const unsigned_long_long_long& v)
    {
      const unsigned_large_type res0(unsigned_large_type(m_data[0U]) - v.m_data[0U]);
      const unsigned_large_type res1(unsigned_large_type(m_data[1U]) - v.m_data[1U] - unsigned_small_type((hi_part(res0) != unsigned_small_type(0U)) ? 1U : 0U));
      const unsigned_large_type res2(unsigned_large_type(m_data[2U]) - v.m_data[2U] - unsigned_small_type((hi_part(res1) != unsigned_small_type(0U)) ? 1U : 0U));
      const unsigned_large_type res3(unsigned_large_type(m_data[3U]) - v.m_data[3U] - unsigned_small_type((hi_part(res2) != unsigned_small_type(0U)) ? 1U : 0U));

      m_data[0U] = lo_part(res0);
      m_data[1U] = lo_part(res1);
      m_data[2U] = lo_part(res2);
      m_data[3U] = lo_part(res3);

      return *this;
    }

    unsigned_long_long_long& operator*=(const unsigned_long_long_long& v)
    {
      // The algorithm has been derived from the polynomial multiplication
      // given by: (D + Cx + Bx^2 + Ax^3) * (d + cx + bx^2 + ax^3).
      // After the multiplication terms of equal order are grouped
      // together and retained up to order(3). The carries from the
      // multiplications are included when adding up the terms.
      // The results of the intermediate multiplications are stored
      // in local variables in memory.

      std::array<unsigned_large_type, 4U - 1U> result;

      unsigned_large_type dD;
      unsigned_large_type Cd;
      unsigned_large_type cD;
      unsigned_large_type cC;

      // One special case is considered, the case of multiplication
      // of the form BITS/2 * BITS/2 = BITS. In this case, the algorithm
      // can be significantly simplified by using only the lower-halves
      // of the data.
      if(    (  m_data[2U] == unsigned_small_type(0U))
          && (v.m_data[2U] == unsigned_small_type(0U))
          && (  m_data[3U] == unsigned_small_type(0U))
          && (v.m_data[3U] == unsigned_small_type(0U))
        )
      {
        dD = m_data[0U] * unsigned_large_type(v.m_data[0U]);
        Cd = m_data[0U] * unsigned_large_type(v.m_data[1U]);

        cD = m_data[1U] * unsigned_large_type(v.m_data[0U]);
        cC = m_data[1U] * unsigned_large_type(v.m_data[1U]);

        result[0U] = unsigned_large_type(lo_part(dD));
        result[1U] = unsigned_large_type(lo_part(Cd)) + lo_part(cD) + hi_part(dD);
        result[2U] = unsigned_large_type(lo_part(cC)) + hi_part(Cd) + hi_part(cD) + hi_part(result[1]);
        m_data[3U] = hi_part(cC) + hi_part(result[2]);
      }
      else
      {
        dD                           = m_data[0U] * unsigned_large_type(v.m_data[0U]);
        Cd                           = m_data[0U] * unsigned_large_type(v.m_data[1U]);
        const unsigned_large_type Bd = m_data[0U] * unsigned_large_type(v.m_data[2U]); // 0 for BITS/2 * BITS/2 = BITS
        const unsigned_large_type Ad = m_data[0U] * unsigned_large_type(v.m_data[3U]); // 0 for BITS/2 * BITS/2 = BITS

        cD                           = m_data[1U] * unsigned_large_type(v.m_data[0U]);
        cC                           = m_data[1U] * unsigned_large_type(v.m_data[1U]);
        const unsigned_large_type Bc = m_data[1U] * unsigned_large_type(v.m_data[2U]); // 0 for BITS/2 * BITS/2 = BITS

        const unsigned_large_type bD = m_data[2U] * unsigned_large_type(v.m_data[0U]); // 0 for BITS/2 * BITS/2 = BITS
        const unsigned_large_type bC = m_data[2U] * unsigned_large_type(v.m_data[1U]); // 0 for BITS/2 * BITS/2 = BITS

        const unsigned_large_type aD = m_data[3U] * unsigned_large_type(v.m_data[0U]); // 0 for BITS/2 * BITS/2 = BITS

        result[0U] = unsigned_large_type(lo_part(dD));
        result[1U] = unsigned_large_type(lo_part(Cd)) + lo_part(cD) + hi_part(dD);
        result[2U] = unsigned_large_type(lo_part(cC)) + lo_part(Bd) + lo_part(bD) + hi_part(Cd) + hi_part(cD) + hi_part(result[1U]);
        m_data[3U] = lo_part(Bc) + lo_part(bC) + lo_part(aD) + lo_part(Ad) + hi_part(cC) + hi_part(Bd) + hi_part(bD) + hi_part(result[2U]);
      }

      m_data[0U] = lo_part(result[0U]);
      m_data[1U] = lo_part(result[1U]);
      m_data[2U] = lo_part(result[2U]);

      return *this;
    }

    unsigned_long_long_long& operator/=(const unsigned_long_long_long& v)
    {
      *this = divide(*this, v);

      return *this;
    }

    unsigned_long_long_long& operator%=(const unsigned_long_long_long& v)
    {
      const unsigned_long_long_long u(*this);

      static_cast<void>(divide(u, v, this));

      return *this;
    }

    // Shift operations.
    unsigned_long_long_long& operator<<=(const int n)
    {
      if(n < 0)
      {
        return (*this >>= -n);
      }
      else if (n == 0)
      {
        return *this;
      }

      std::uint_fast8_t n_fill;

      if(n < unsigned_long_long_long::my_digits)
      {
        // Perform a pure left shift on unsigned unsigned_long_long_long.

        // Determine the shifting amount for the algorithm.
        const int n_shift = n % std::numeric_limits<unsigned_small_type>::digits;

        n_fill = std::uint_fast8_t(n / std::numeric_limits<unsigned_small_type>::digits);

        // Left shift algorithm shifting by (n % std::numeric_limits<unsigned_small_type>::digits)
        const data_array_type w =
        {{
           m_data[0U] << n_shift,
          (m_data[1U] << n_shift) | hi_part(unsigned_large_type(m_data[0U]) << n_shift),
          (m_data[2U] << n_shift) | hi_part(unsigned_large_type(m_data[1U]) << n_shift),
          (m_data[3U] << n_shift) | hi_part(unsigned_large_type(m_data[2U]) << n_shift)
        }};

        std::copy(w.cbegin(),
                  w.cend() - n_fill,
                  m_data.begin() + n_fill);
      }
      else
      {
        n_fill = 4U;
      }

      // Fill in the zero data for n >= std::numeric_limits<unsigned_small_type>::digits.
      std::fill(m_data.begin(),
                m_data.begin() + n_fill,
                unsigned_small_type(0U));

      return *this;
    }

    unsigned_long_long_long& operator>>=(const int n)
    {
      if(n < 0)
      {
        return (*this <<= -n);
      }
      else if(n == 0)
      {
        return *this;
      }

      std::uint_fast8_t n_fill;

      if(n < unsigned_long_long_long::my_digits)
      {
        // Perform a pure right shift on unsigned unsigned_long_long_long.

        // Determine the shifting amount for the algorithm.
        const int n_shift = n % std::numeric_limits<unsigned_small_type>::digits;

        n_fill = std::uint_fast8_t(n / std::numeric_limits<unsigned_small_type>::digits);

        // Right shift algorithm shifting by (n % std::numeric_limits<unsigned_small_type>::digits)
        const data_array_type w =
        {{
          (m_data[0U] >> n_shift) | lo_part(unsigned_large_type(m_data[1U]) << (std::numeric_limits<unsigned_small_type>::digits - n_shift)),
          (m_data[1U] >> n_shift) | lo_part(unsigned_large_type(m_data[2U]) << (std::numeric_limits<unsigned_small_type>::digits - n_shift)),
          (m_data[2U] >> n_shift) | lo_part(unsigned_large_type(m_data[3U]) << (std::numeric_limits<unsigned_small_type>::digits - n_shift)),
           m_data[3U] >> n_shift
        }};

        std::copy(w.cbegin() + n_fill,
                  w.cend(),
                  m_data.begin());
      }
      else
      {
        n_fill = 4U;
      }

      // Fill in the zero data for n >= std::numeric_limits<unsigned_small_type>::digits
      std::fill(m_data.end() - n_fill,
                m_data.end(),
                unsigned_small_type(0U));

      return *this;
    }

    // Unary not.
    unsigned_long_long_long operator~() const { return unsigned_long_long_long(~m_data[0U], ~m_data[1U], ~m_data[2U], ~m_data[3U]); }

    // Logic operations.
    unsigned_long_long_long& operator&=(const unsigned_long_long_long& v) { m_data[0U] &= v.m_data[0U]; m_data[1U] &= v.m_data[1U]; m_data[2U] &= v.m_data[2U]; m_data[3U] &= v.m_data[3U]; return *this; }
    unsigned_long_long_long& operator|=(const unsigned_long_long_long& v) { m_data[0U] |= v.m_data[0U]; m_data[1U] |= v.m_data[1U]; m_data[2U] |= v.m_data[2U]; m_data[3U] |= v.m_data[3U]; return *this; }
    unsigned_long_long_long& operator^=(const unsigned_long_long_long& v) { m_data[0U] ^= v.m_data[0U]; m_data[1U] ^= v.m_data[1U]; m_data[2U] ^= v.m_data[2U]; m_data[3U] ^= v.m_data[3U]; return *this; }

    unsigned_long_long_long& operator&=(const unsigned_small_type& t) { m_data[0U] &= t; return *this; }
    unsigned_long_long_long& operator|=(const unsigned_small_type& t) { m_data[0U] |= t; return *this; }
    unsigned_long_long_long& operator^=(const unsigned_small_type& t) { m_data[0U] ^= t; return *this; }

    // Operations with a single element of type unsigned_small_type.
    unsigned_long_long_long& add_ulll_ushort(const unsigned_small_type& t)
    {
      // Add the data elements with carry.
      const unsigned_large_type res0(unsigned_large_type(m_data[0U]) + t);
      const unsigned_large_type res1(unsigned_large_type(m_data[1U]) + hi_part(res0));
      const unsigned_large_type res2(unsigned_large_type(m_data[2U]) + hi_part(res1));
      const unsigned_large_type res3(unsigned_large_type(m_data[3U]) + hi_part(res2));

      m_data[0U] = lo_part(res0);
      m_data[1U] = lo_part(res1);
      m_data[2U] = lo_part(res2);
      m_data[3U] = lo_part(res3);

      return *this;
    }

    unsigned_long_long_long& sub_ulll_ushort(const unsigned_small_type& t)
    {
      // Subtract the data elements with borrow.
      const unsigned_large_type res0(unsigned_large_type(m_data[0U]) - t);
      const unsigned_large_type res1(unsigned_large_type(m_data[1U]) - unsigned_small_type((hi_part(res0) != unsigned_small_type(0U)) ? 1U : 0U));
      const unsigned_large_type res2(unsigned_large_type(m_data[2U]) - unsigned_small_type((hi_part(res1) != unsigned_small_type(0U)) ? 1U : 0U));
      const unsigned_large_type res3(unsigned_large_type(m_data[3U]) - unsigned_small_type((hi_part(res2) != unsigned_small_type(0U)) ? 1U : 0U));

      m_data[0U] = lo_part(res0);
      m_data[1U] = lo_part(res1);
      m_data[2U] = lo_part(res2);
      m_data[3U] = lo_part(res3);

      return *this;
    }

    unsigned_long_long_long& mul_ulll_ushort(const unsigned_small_type& t)
    {
      const unsigned_large_type cD = m_data[1U] * unsigned_large_type(t);
      const unsigned_large_type bD = m_data[2U] * unsigned_large_type(t);

      const unsigned_large_type res0(m_data[0U] * unsigned_large_type(t));
      const unsigned_large_type res1(unsigned_large_type(lo_part(cD)) + hi_part(res0));
      const unsigned_large_type res2(unsigned_large_type(lo_part(bD)) + hi_part(cD) + hi_part(res1));

      m_data[3U] = lo_part(m_data[3U] * unsigned_large_type(t)) + hi_part(bD) + hi_part(res2);

      m_data[0U] = lo_part(m_data[0U]);
      m_data[1U] = lo_part(m_data[1U]);
      m_data[2U] = lo_part(m_data[2U]);

      return *this;
    }

    unsigned_long_long_long& div_ulll_ushort(const unsigned_small_type& t, unsigned_small_type* const p_rem = nullptr)
    {
      // Special handling for zero numerator and/or zero denominator.
      if(is_zero() || (t == unsigned_small_type(0)))
      {
        // The remainder is zero.
        if(p_rem != nullptr)
        {
          *p_rem = 0U;
        }

        // Do nothing if the numerator or the denominator is zero.
        return *this;
      }

      // See Knuth, Semi-numerical Algorithms, exercise 16 after Section 4.3.1.
      // The division loop has been unrolled and the loop-order has been
      // reversed for the little-endian storage convention of unsigned_long_long_long.

      unsigned_large_type lt = m_data[3U];

      m_data[3U] /= t;

      lt          = m_data[2U] + unsigned_large_type(unsigned_large_type(lt - unsigned_large_type(unsigned_large_type(t) * m_data[3U])) << std::numeric_limits<unsigned_small_type>::digits);
      m_data[2U]  = lo_part(unsigned_large_type(lt / t));

      lt          = m_data[1U] + unsigned_large_type(unsigned_large_type(lt - unsigned_large_type(unsigned_large_type(t) * m_data[2U])) << std::numeric_limits<unsigned_small_type>::digits);
      m_data[1U]  = lo_part(unsigned_large_type(lt / t));

      lt          = m_data[0U] + unsigned_large_type(unsigned_large_type(lt - unsigned_large_type(unsigned_large_type(t) * m_data[1U])) << std::numeric_limits<unsigned_small_type>::digits);
      m_data[0U]  = lo_part(unsigned_large_type(lt / t));

      if(p_rem != nullptr)
      {
        *p_rem = lo_part(unsigned_large_type(lt - unsigned_large_type(unsigned_large_type(t) * m_data[0U])));
      }

      return *this;
    }

    unsigned_long_long_long& add_ulll_short(const signed_short_type& st)
    {
      return ((st < signed_short_type(0)) ? sub_ulll_ushort(unsigned_small_type(-st))
                                          : add_ulll_ushort(unsigned_small_type( st)));
    }

    unsigned_long_long_long& sub_ulll_short(const signed_short_type& st)
    {
      return ((st < signed_short_type(0)) ? add_ulll_ushort(unsigned_small_type(-st))
                                          : sub_ulll_ushort(unsigned_small_type( st)));
    }

    unsigned_long_long_long& mul_ulll_short(const signed_short_type& st)
    {
      return ((st < signed_short_type(0)) ? mul_ulll_ushort(unsigned_small_type(-st)).negate()
                                          : mul_ulll_ushort(unsigned_small_type( st)));
    }

    unsigned_long_long_long& div_ulll_short(const signed_short_type& st)
    {
      return ((st < signed_short_type(0)) ? div_ulll_ushort(unsigned_small_type(-st)).negate()
                                          : div_ulll_ushort(unsigned_small_type( st)));
    }

    // Comparison operators
    bool operator< (const unsigned_long_long_long& v) const { return (cmp(v) <  0); }
    bool operator<=(const unsigned_long_long_long& v) const { return (cmp(v) <= 0); }
    bool operator==(const unsigned_long_long_long& v) const { return (cmp(v) == 0); }
    bool operator!=(const unsigned_long_long_long& v) const { return (cmp(v) != 0); }
    bool operator>=(const unsigned_long_long_long& v) const { return (cmp(v) >= 0); }
    bool operator> (const unsigned_long_long_long& v) const { return (cmp(v) >  0); }

    // Comparison with exactly zero.
    bool is_zero() const
    {
      return (   (m_data[0U] == unsigned_small_type(0U))
              && (m_data[1U] == unsigned_small_type(0U))
              && (m_data[2U] == unsigned_small_type(0U))
              && (m_data[3U] == unsigned_small_type(0U)));
    }

    // Operators pre-increment and pre-decrement
    unsigned_long_long_long& operator++() { inc(); return *this; }
    unsigned_long_long_long& operator--() { dec(); return *this; }

    // Operators post-increment and post-decrement.
    unsigned_long_long_long operator++(int)  { const unsigned_long_long_long w(*this); ++(*this); return w; }
    unsigned_long_long_long operator--(int)  { const unsigned_long_long_long w(*this); --(*this); return w; }

    // Conversion routines.
    std::uint16_t to_uint16() const { return to_unsigned_integral_type<std::uint16_t>(); }
    std::uint32_t to_uint32() const { return to_unsigned_integral_type<std::uint32_t>(); }
    std::uint64_t to_uint64() const { return to_unsigned_integral_type<std::uint64_t>(); }

    static bool to_string(const unsigned_long_long_long& un,
                          char*                          p,
                          char*                          p_sign,
                          const detail::base_type        base,
                          const bool                     upper)
    {
      // Convert an unsigned_long_long_long to a character-based string.
      // Notice that this routine does not use STL-string because
      // other platforms might not tolerate the overhead of string.

      if(p_sign != nullptr)
      {
        *p_sign = char('+');
      }

      // Return "0" for zero.
      if(un.is_zero())
      {
        *p       = char('0');
        *(p + 1) = char('\0');

        return true;
      }

      unsigned_long_long_long::unsigned_small_type unsigned_short_base(1U);

      // Base  2: String length expected to have length my_digits       + '\0'.
      // Base 10: String length expected to have length my_digits10 + 1 + '\0'.
      // Base 16: String length expected to have length my_digits16     + '\0'.
      int i;
      int offset;

      switch(base)
      {
        case detail::base_type_bin:
          offset = unsigned_long_long_long::my_digits + 1;
          break;

        case detail::base_type_dec:
        default:
          offset = (unsigned_long_long_long::my_digits10 + 1) + 1;

          // Initialize a sub base used for the decimal digit extractions.
          for(i = 0; i < std::numeric_limits<unsigned_long_long_long::unsigned_small_type>::digits10; ++i)
          {
            unsigned_short_base *= 10U;
          }

          break;

        case detail::base_type_hex:
          offset = unsigned_long_long_long::my_digits16 + 1;
          break;
      }

      // Make a non-constant local copy.
      unsigned_long_long_long u(un);

      // Allocate a local character array of the absolute maximum expected
      // length, aligned on a 16-byte boundary. A local array is used
      // since the user might have trimmed the call to the maximum expected
      // length of the unsigned_long_long_long at hand, whereas the extraction algorithm
      // below is based on the maximum allowed length.
      char local[static_cast<std::size_t>(16 * (unsigned_long_long_long::my_digits / 16) + 16)];

      const int char_a((!upper) ? int('a') : int('A'));

      int count = 0;

      while(u.is_zero() == false)
      {
        switch(base)
        {
          case detail::base_type_bin:
            {
              const bool bit_is_set = ((u.crepresentation()[0U] & 1U) != 0U);

              u >>= 1;

              *(local + std::uint_fast8_t(offset - count)) = char(bit_is_set ? char('1') : char('0'));

              ++count;
            }
            break;

          case detail::base_type_dec:
          default:
            {
              // Extract the digits using a sub-loop.
              unsigned_long_long_long::unsigned_small_type u_rem;
              u.div_ulll_ushort(unsigned_short_base, &u_rem);

              if(u.is_zero())
              {
                // If u is 0, then we only need the non-zero digits of data.
                while(u_rem != 0U)
                {
                  const unsigned_long_long_long::unsigned_small_type digit(u_rem % 10U);

                  u_rem /= 10U;

                  *(local + std::uint_fast8_t(offset - count)) = char(char(digit) + char('0'));

                  ++count;
                }
              }
              else
              {
                // Here u is not zero, we need all of the digits
                // of data including the zero digits.
                for(i = 0; i < std::numeric_limits<unsigned_long_long_long::unsigned_small_type>::digits10; ++i)
                {
                  const unsigned_long_long_long::unsigned_small_type next_digit(u_rem % 10U);

                  u_rem /= 10U;

                  *(local + std::uint_fast8_t(offset - count)) = char(char(next_digit) + char('0'));

                  ++count;
                }
              }
            }
            break;

          case detail::base_type_hex:
            {
              // Extract the digits.
              unsigned_long_long_long::unsigned_small_type data = u.crepresentation()[0U];

              u >>= std::numeric_limits<unsigned_long_long_long::unsigned_small_type>::digits;

              if(u.is_zero())
              {
                while(data != 0U)
                {
                  // If u is 0, then we only need the non-zero digits of data.
                  const unsigned_long_long_long::unsigned_small_type nibble = (data & 0xFU);

                  data >>= 4;

                  *(local + std::uint_fast8_t(offset - count)) = char(nibble + (nibble < 0xAU ? char('0') : char(char_a - 10)));

                  ++count;
                }
              }
              else
              {
                // Here u is not zero, we need all of the digits
                // of data including the zero digits.
                for(i = 0; i < std::numeric_limits<unsigned_long_long_long::unsigned_small_type>::digits / 4; ++i)
                {
                  const unsigned_long_long_long::unsigned_small_type nibble = (data & 0xFU);

                  data >>= 4;

                  *(local + std::uint_fast8_t(offset - count)) = char(nibble + ((nibble < 0xAU) ? char('0') : char(char_a - 10)));

                  ++count;
                }
              }
            }
            break;
        }
      }

      // Copy and shift the local characters, including '\0', such that
      // they are left-justified for the subroutine caller. This could
      // be done using ::memmove(...). However ::memmove(...) is not used,
      // rather a simple, portable loop has been implemented. Do not
      // include the base or the sign.
      for(i = 0; i < count; ++i)
      {
        *(p + i) = *(local + std::uint_fast8_t((offset - count) + (1 + i)));
      }

      *(p + i) = char('\0');

      return (count != 0);
    }

    unsigned_long_long_long& negate()
    {
      // Efficiently set (*this = -(*this)) without passing any arguments.
      m_data[0U] = (~m_data[0U]);
      m_data[1U] = (~m_data[1U]);
      m_data[2U] = (~m_data[2U]);
      m_data[3U] = (~m_data[3U]);

      inc();

      return *this;
    }

    // Read-only and read/write access to the internal data representation.
    const data_array_type&  representation() const { return m_data; }
    const data_array_type& crepresentation() const { return m_data; }
          data_array_type&  representation()       { return m_data; }

  protected:
    unsigned_long_long_long(const unsigned_small_type& t0,
                            const unsigned_small_type& t1,
                            const unsigned_small_type& t2,
                            const unsigned_small_type& t3) : m_data( { t0, t1, t2, t3 } ) { }

    // Utility functions for extracting lo-unsigned_small_type and hi-unsigned_small_type from unsigned_large_type.
    static unsigned_small_type lo_part(const unsigned_large_type& lt) { return unsigned_small_type(lt); }
    static unsigned_small_type hi_part(const unsigned_large_type& lt) { return unsigned_small_type(lt >> std::numeric_limits<unsigned_small_type>::digits); }

    // Comparison function
    int cmp(const unsigned_long_long_long& v) const
    {
      // Compare the data of u with those of v.

      const std::pair<typename data_array_type::const_reverse_iterator,
                      typename data_array_type::const_reverse_iterator> mismatch_pair =
        std::mismatch(  m_data.crbegin(),
                        m_data.crend(),
                      v.m_data.crbegin());

      const bool is_equal = (   (mismatch_pair.first  ==   m_data.crend())
                             && (mismatch_pair.second == v.m_data.crend()));

      return ((is_equal) ? 0
                         : ((*mismatch_pair.first > *mismatch_pair.second) ? 1 : -1));
    }

    // Increment and decrement
    void inc()
    {
      if(   (++m_data[0U] == unsigned_small_type(0U))
         && (++m_data[1U] == unsigned_small_type(0U))
         && (++m_data[2U] == unsigned_small_type(0U)))
      {
        ++m_data[3U];
      }
    }

    void dec()
    {
      if(   (m_data[0U]-- == unsigned_small_type(0U))
         && (m_data[1U]-- == unsigned_small_type(0U))
         && (m_data[2U]-- == unsigned_small_type(0U)))
      {
        --m_data[3U];
      }
    }

  private:
    // Local conversion routine.
    template<typename UnsignedIntegralType>
    UnsignedIntegralType to_unsigned_integral_type() const
    {
      typedef UnsignedIntegralType local_unsigned_type;

      const std::uint_fast8_t n = static_cast<std::uint_fast8_t>((std::max)(1, std::numeric_limits<local_unsigned_type>::digits / std::numeric_limits<unsigned_small_type>::digits));

      local_unsigned_type u(0U);

      for(std::uint_fast8_t i = 0U; i < n; ++i)
      {
        u += local_unsigned_type(local_unsigned_type(m_data[i]) << (std::numeric_limits<unsigned_small_type>::digits * i));
      }

      return u;
    }

    // Private constant values.
    static unsigned_long_long_long value_max()
    {
      return unsigned_long_long_long((std::numeric_limits<unsigned_small_type>::max)(),
                                     (std::numeric_limits<unsigned_small_type>::max)(),
                                     (std::numeric_limits<unsigned_small_type>::max)(),
                                     (std::numeric_limits<unsigned_small_type>::max)());
    }

    static unsigned_long_long_long value_min()
    {
      return unsigned_long_long_long(unsigned_small_type(0U),
                                     unsigned_small_type(0U),
                                     unsigned_small_type(0U),
                                     unsigned_small_type(0U));
    }

    // Division algorithm with remainder
    static unsigned_long_long_long divide(const unsigned_long_long_long& u,
                                          const unsigned_long_long_long& v,
                                                unsigned_long_long_long* const p_rem = nullptr)
    {
      // Divide unsigned_long_long_long u by unsigned_long_long_long v
      // and return the result. The pointer parameter p_rem can be
      // optionally used to store the remainder.

      // The Knuth long division algorithm is used. The loop-ordering
      // of the Knuth algorithm has been reversed due to the little endian
      // data format of unsigned_long_long_long.

      // Special handling for zero numerator and/or zero denominator.
      if(u.is_zero() || v.is_zero())
      {
        // The remainder is zero.
        if(p_rem != nullptr)
        {
          *p_rem = 0U;
        }

        // Do nothing if the numerator or the denominator is zero.
        return u;
      }

      // Calculate the number of significant limbs in u and v.
      // These are the offsets for u and v.

      // Compute the number of significant limbs for u and v.
      std::uint_fast8_t sig_limbs_u = 4U;
      std::uint_fast8_t sig_limbs_v = 4U;

      for(std::uint_fast8_t i = std::uint_fast8_t(4U - 1U); (std::int_fast8_t(i) >= std::int_fast8_t(0)) && (u.m_data[i] == 0U); --i)
      {
        --sig_limbs_u;
      }

      for(std::uint_fast8_t i = std::uint_fast8_t(4U - 1U); (std::int_fast8_t(i) >= std::int_fast8_t(0)) && (v.m_data[i] == 0U); --i)
      {
        --sig_limbs_v;
      }

      if(sig_limbs_v == 1U)
      {
        // The absolute value of the denominator has one single limb
        // of type unsigned_small_type. Use a simplified linear
        // algorithm for division by unsigned_small_type.

        unsigned_long_long_long result(u);

        unsigned_small_type u_rem;

        result.div_ulll_ushort(v.m_data[0], &u_rem);

        if(p_rem != nullptr)
        {
          *p_rem = unsigned_long_long_long(u_rem);
        }

        return result;
      }

      // The result of the division is zero if the denominator
      // has more digits than the numerator.
      bool b_zero = false;

      if(sig_limbs_u < sig_limbs_v)
      {
        b_zero = true;
      }
      else if(sig_limbs_u == sig_limbs_v)
      {
        // Check the highest non-zero limb for zero result.
        // This check is equivalent to u < v.

        if(u.m_data[sig_limbs_u - 1U] < v.m_data[sig_limbs_v - 1U])
        {
          b_zero = true;
        }
        else if(u.m_data[sig_limbs_u - 1U] == v.m_data[sig_limbs_v - 1U])
        {
          // In this case, the numerator is equal to the denominator and
          // the result of the division is one with remainder of zero.
          if(p_rem != nullptr)
          {
            *p_rem = 0U;
          }

          return unsigned_long_long_long(1U);
        }
      }

      if(b_zero)
      {
        // The result is zero.
        if(p_rem != nullptr)
        {
          *p_rem = u;
        }

        return unsigned_long_long_long(0U);
      }

      // Now use the Knuth long division algorithm.

      unsigned_long_long_long result;

      const std::uint_fast8_t sig_limbs_uv_delta = (sig_limbs_u - sig_limbs_v);

      // Initialize the data elements of the result which will
      // not be computed in the upcoming algorithm.
      std::fill(result.m_data.begin() + (sig_limbs_uv_delta + 1U),
                result.m_data.end(),
                unsigned_small_type(0U));

      // Compute the normalization factor d.
      const unsigned_small_type d_norm = lo_part(unsigned_large_type(unsigned_large_type(1) << std::numeric_limits<unsigned_small_type>::digits) / (unsigned_large_type(v.m_data[sig_limbs_v - 1U]) + 1U));

      // Step D1(b), normalize u -> u * d = uu.
      // Note the added digit in uu and that the data uu
      // are not initialized.
      std::array<unsigned_small_type, 4U + 1U> uu;

      if(d_norm == unsigned_small_type(1U))
      {
        // Normalization is one: In this case uu = *this, in other words u.
        std::copy(u.m_data.cbegin(), u.m_data.cend(), uu.begin());

        uu.back() = unsigned_small_type(0U);
      }
      else
      {
        // Multiply u by d.
        unsigned_small_type carry(0U);

        std::uint_fast8_t i;

        for(i = 0U; i < sig_limbs_u; ++i)
        {
          const unsigned_large_type lt(unsigned_large_type(u.m_data[i] * unsigned_large_type(d_norm)) + carry);

          uu[i] = lo_part(lt);
          carry = hi_part(lt);
        }

        uu[i] = carry;
      }

      // Step D1(c), normalize v -> v * d = vv.
      // The data vv are not initialized.
      data_array_type vv;

      if(d_norm == unsigned_small_type(1U))
      {
        // The normalization is one: In this case vv = v.
        std::copy(v.m_data.cbegin(), v.m_data.cend(), vv.begin());
      }
      else
      {
        // Multiply v by d.
        unsigned_small_type carry(0U);

        for(std::uint_fast8_t i = 0U; i < sig_limbs_v; ++i)
        {
          const unsigned_large_type lt(unsigned_large_type(v.m_data[i] * unsigned_large_type(d_norm)) + carry);

          vv[i] = lo_part(lt);
          carry = hi_part(lt);
        }
      }

      // D2: Initialize j.
      // D7: Loop on j from 0 to m.
      for(std::uint_fast8_t j = 0U; j <= sig_limbs_uv_delta; ++j)
      {
        // * D3 [Calculate q^]
        //    if u[j] == v[1]
        //      set q^ = b - 1
        //    else
        //      set q^ = (u[j] * b + u[j+1]) / v[1]

        const std::uint_fast8_t uj (static_cast<std::uint_fast8_t>(sig_limbs_u - j));
        const std::uint_fast8_t vj0(static_cast<std::uint_fast8_t>(sig_limbs_v - 1U));

        const unsigned_large_type u_j_j1((unsigned_large_type(uu[uj]) << std::numeric_limits<unsigned_small_type>::digits) + uu[uj - 1U]);

        unsigned_large_type q_hat =
          ((uu[uj] == vv[vj0]) ? unsigned_large_type((std::numeric_limits<unsigned_small_type>::max)())
                               : unsigned_large_type(u_j_j1 / vv[vj0]));

        // Decrease q^ if necessary: q^ must be decreased if the
        // expression "(u[uj] * b + u[uj - 1] - q^ * v[vj0 - 1]) * b"
        // exceeds the size of unsigned_large_type.
        for(;;)
        {
          unsigned_large_type lt(u_j_j1 - unsigned_large_type(q_hat * vv[vj0]));

          if(hi_part(lt) != 0U)
          {
            break;
          }

          if(unsigned_large_type(vv[vj0 - 1] * q_hat) <= unsigned_large_type(unsigned_large_type(lt << std::numeric_limits<unsigned_small_type>::digits) + uu[uj - 2U]))
          {
            break;
          }

          --q_hat;
        }

        // D4: Multiply and subtract.
        // Replace u[j..j+n] by u[j..j+n] - q^ * v[1..n]

        // Set nv = q^ * (v[1..n])
        std::array<unsigned_small_type, 4U + 1U> nv;

        {
          unsigned_small_type carry(0U);

          std::uint_fast8_t i;

          for(i = 0U; i < sig_limbs_v; ++i)
          {
            const unsigned_large_type lt(unsigned_large_type(vv[i] * q_hat) + carry);

            nv[i] = lo_part(lt);
            carry = hi_part(lt);
          }

          nv[i] = carry;
        }

        // Subtract nv[0..n] from u[j..j+n].
        unsigned_small_type borrow(0U);

        {
          std::uint_fast8_t ul(uj - sig_limbs_v);

          for(std::uint_fast8_t i = 0U; i <= sig_limbs_v; ++i)
          {
            const unsigned_large_type lt(unsigned_large_type(unsigned_large_type(uu[ul]) - nv[i]) - borrow);

            uu[ul] = lo_part(lt);

            ++ul;

            borrow = ((hi_part(lt) != 0U) ? 1U : 0U);
          }
        }

        // Get the result data.
        result.m_data[sig_limbs_uv_delta - j] = lo_part(q_hat);

        // D5: Test the remainder
        //     Set the result value: Set result.m_data[m - j] = q^
        //     Condition: If u[j] < 0, in other words borrow is non-zero,
        //     then step D6 must be done.
        if(borrow != 0U)
        {
          // D6: Add back
          //     Add v[1..n] back to u[j..j+n]
          //     and decrease the result by 1.
          unsigned_small_type carry(0U);

          std::uint_fast8_t ul = uj - sig_limbs_v;

          for(std::uint_fast8_t i = 0U; i <= sig_limbs_v; ++i)
          {
            const unsigned_large_type lt(unsigned_large_type(unsigned_large_type(uu[ul]) + nv[i]) + carry);

            uu[ul] = lo_part(lt);

            ++ul;

            carry = ((hi_part(lt) != 0U) ? 1U : 0U);
          }

          uu[sig_limbs_uv_delta - j] += carry;

          --result.m_data[sig_limbs_uv_delta - j];
        }
      }

      // Compute the remainder if requested.
      if(p_rem != nullptr)
      {
        *p_rem = u - (result * v);
      }

      return result;
    }

    template<typename UnsignedIntegralType>
    void from_unsigned_integral_type(const UnsignedIntegralType& u)
    {
      const std::uint_fast8_t n = static_cast<std::uint_fast8_t>((std::max)(1, std::numeric_limits<UnsignedIntegralType>::digits / std::numeric_limits<unsigned_small_type>::digits));

      std::uint_fast8_t i;

      for(i = 0U; i < n; ++i)
      {
        m_data[i] = unsigned_small_type(u >> (std::numeric_limits<unsigned_small_type>::digits * i));
      }

      std::fill(m_data.begin() + i, m_data.end(), unsigned_small_type(0U));
    }

    friend class std::numeric_limits<unsigned_long_long_long>;
  };

  // Non-member unary +/- of unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator+(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& self) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(self); }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator-(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& self) { unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> tmp(self); tmp.negate(); return tmp; }

  // Non-member binary add/sub/mul/div/mod of unsigned_long_long_long with unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator+(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) += v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator-(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) -= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator*(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) *= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator/(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) /= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator%(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) %= v; }

  // Non-member binary add/sub/mul/div of unsigned_long_long_long with IntegralType.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator+(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) += v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator-(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) -= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator*(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) *= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator/(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) /= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator%(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) %= v; }

  // Non-member binary add/sub/mul/div of IntegralType with unsigned_long_long_long.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator+(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) += v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator-(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) -= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator*(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) *= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator/(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) /= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator%(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) %= v; }

  // Non-member shift of unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator<<(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const int n) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) <<= n; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator>>(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const int n) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) >>= n; }

  // Non-member logic operators of unsigned_long_long_long with unsigned_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator&(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) &= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator|(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) |= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> operator^(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) ^= v; }

  // Non-member logic operators of unsigned_long_long_long with IntegralType.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator&(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) &= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator|(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) |= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator^(const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) ^= v; }

  // Non-member logic operators of IntegralType with unsigned_long_long_long.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator&(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, const UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) &= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator|(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, const UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) |= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator^(const IntegralType& u, const unsigned_long_long_long<UnsignedSmallType, const UnsignedLargeType>& v) { return unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) ^= v; }

  } } // namespace math::lll

  // Specialization of numeric_limits<unsigned_long_long_long>
  namespace std
  {
    template<typename UnsignedSmallType, typename UnsignedLargeType>
    class numeric_limits<math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>
    {
    public:
      static const bool                    is_specialized    = true;
      static const int                     digits            = math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>::my_digits;
      static const int                     digits10          = math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>::my_digits10;
      static const int                     max_digits10      = 0;
      static const bool                    is_signed         = false;
      static const bool                    is_integer        = true;
      static const bool                    is_exact          = true;
      static const int                     radix             = 2;
      static const int                     min_exponent      = 0;
      static const int                     min_exponent10    = 0;
      static const int                     max_exponent      = 0;
      static const int                     max_exponent10    = 0;
      static const bool                    has_infinity      = false;
      static const bool                    has_quiet_NaN     = false;
      static const bool                    has_signaling_NaN = false;
      static const std::float_denorm_style has_denorm        = std::denorm_absent;
      static const bool                    has_denorm_loss   = false;
      static const bool                    is_iec559         = false;
      static const bool                    is_bounded        = true;
      static const bool                    is_modulo         = true;
      static const bool                    traps             = false;
      static const bool                    tinyness_before   = false;
      static const std::float_round_style  round_style       = std::round_toward_zero;

      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> (min)        () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>::value_min(); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> (max)        () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>::value_max(); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> lowest       () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> epsilon      () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> round_error  () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> infinity     () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> quiet_NaN    () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> signaling_NaN() throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType> denorm_min   () throw() { return math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
    };
  }

#endif // UNSIGNED_LONG_LONG_LONG_2003_12_08_H
