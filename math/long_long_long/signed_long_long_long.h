///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2003 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef SIGNED_LONG_LONG_LONG_2003_12_08_H
  #define SIGNED_LONG_LONG_LONG_2003_12_08_H

  #include <math/long_long_long/unsigned_long_long_long.h>

  namespace math { namespace lll {

  // Forward declaration of the signed_long_long_long class.
  template<typename UnsignedSmallType, typename UnsignedLargeType>
  class signed_long_long_long;

  } } // namespace math::lll

  namespace std
  {
    // Forward declaration of the specialization of std::numeric_limits<signed_long_long_long>.
    template<typename UnsignedSmallType, typename UnsignedLargeType>
    class numeric_limits<math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>;
  }

  namespace math { namespace lll {

  template<typename UnsignedSmallType,
           typename UnsignedLargeType = typename detail::integer_type_helper<std::numeric_limits<UnsignedSmallType>::digits * 2>::exact_unsigned_type>
  class signed_long_long_long : public unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>
  {
  private:
    using base_class_type = unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>;

  public:
    using unsigned_small_type = typename base_class_type::unsigned_small_type;
    using unsigned_large_type = typename base_class_type::unsigned_large_type;

    static constexpr int my_digits   = base_class_type::my_digits - 1;
    static constexpr int my_digits10 = static_cast<int>(static_cast<long long>(my_digits * 30103LL) / 100000LL);

    // Default constructor.
    signed_long_long_long() { }


    // Constructors from built-in integral types.
    template<typename UnsignedIntegralType>
    signed_long_long_long(const UnsignedIntegralType& u,
                          typename std::enable_if<   (std::is_integral<UnsignedIntegralType>::value == true)
                                                  && (std::is_signed  <UnsignedIntegralType>::value == false)>::type const* = nullptr)
      : base_class_type(u) { }

    template<typename SignedIntegralType>
    signed_long_long_long(const SignedIntegralType& n,
                          typename std::enable_if<   (std::is_integral<SignedIntegralType>::value == true)
                                                  && (std::is_signed  <SignedIntegralType>::value == true)>::type const* = nullptr)
      : base_class_type(n) { }

    // Constructor from unsigned_long_long_long.
    signed_long_long_long(const base_class_type& u) : base_class_type(u) { }

    // Copy constructor.
    signed_long_long_long(const signed_long_long_long& n) : base_class_type(n) { }

    // Move constructor.
    signed_long_long_long(signed_long_long_long&& v) : base_class_type(v) { }

    virtual ~signed_long_long_long() { }

    // Assignment operator.
    signed_long_long_long& operator=(const signed_long_long_long& other)
    {
      if(this != &other)
      {
        std::copy(other.m_data.cbegin(), other.m_data.cend(), base_class_type::m_data.begin());
      }

      return *this;
    }

    // Elementary mathematical operations.
    signed_long_long_long& operator+=(const signed_long_long_long& v)
    {
      return static_cast<signed_long_long_long&>(base_class_type::operator+=(v));
    }

    signed_long_long_long& operator-=(const signed_long_long_long& v)
    {
      return static_cast<signed_long_long_long&>(base_class_type::operator-=(v));
    }

    signed_long_long_long& operator*=(const signed_long_long_long& v)
    {
      const bool u_neg =   is_neg();
      const bool v_neg = v.is_neg();

      if(u_neg == v_neg)
      {
        if(u_neg)
        {
          return static_cast<signed_long_long_long&>(base_class_type::negate().base_class_type::operator*=(-v));
        }
        else
        {
          return static_cast<signed_long_long_long&>(base_class_type::operator*=(v));
        }
      }
      else
      {
        if(u_neg)
        {
          return static_cast<signed_long_long_long&>((base_class_type::negate().base_class_type::operator*=(v)).negate());
        }
        else
        {
          return static_cast<signed_long_long_long&>((base_class_type::operator*=(-v)).negate());
        }
      }
    }

    signed_long_long_long& operator/=(const signed_long_long_long& v)
    {
      const bool u_neg =   is_neg();
      const bool v_neg = v.is_neg();

      if(u_neg == v_neg)
      {
        if(u_neg)
        {
          return static_cast<signed_long_long_long&>(base_class_type::negate().base_class_type::operator/=(-v));
        }
        else
        {
          return static_cast<signed_long_long_long&>(base_class_type::operator/=(v));
        }
      }
      else
      {
        if(u_neg)
        {
          return static_cast<signed_long_long_long&>((base_class_type::negate().base_class_type::operator/=(v)).negate());
        }
        else
        {
          return static_cast<signed_long_long_long&>((base_class_type::operator/=(-v)).negate());
        }
      }
    }

    signed_long_long_long& operator%=(const signed_long_long_long& v)
    {
      const bool u_neg =   is_neg();
      const bool v_neg = v.is_neg();

      if(u_neg == v_neg)
      {
        if(u_neg)
        {
          return static_cast<signed_long_long_long&>(base_class_type::negate().base_class_type::operator%=(-v));
        }
        else
        {
          return static_cast<signed_long_long_long&>(base_class_type::operator%=(v));
        }

        return *this;
      }
      else
      {
        if(u_neg)
        {
          return static_cast<signed_long_long_long&>((base_class_type::negate().base_class_type::operator%=(v)).negate());
        }
        else
        {
          return static_cast<signed_long_long_long&>((base_class_type::operator/=(-v)).negate());
        }
      }
    }

    // Shift operations.
    signed_long_long_long& operator<<=(const int n)
    {
      return static_cast<signed_long_long_long&>(base_class_type::operator<<=(n));
    }

    signed_long_long_long& operator>>=(const int n)
    {
      if(is_neg())
      {
        return static_cast<signed_long_long_long&>((base_class_type::negate().base_class_type::operator>>=(n)).negate());
      }
      else
      {
        return static_cast<signed_long_long_long&>(base_class_type::operator>>=(n));
      }
    }

    // Unary not.
    signed_long_long_long operator~() const { return signed_long_long_long(~base_class_type::m_data[0U], ~base_class_type::m_data[1U], ~base_class_type::m_data[2U], ~base_class_type::m_data[3U]); }

    // Logic operations.
    signed_long_long_long& operator&=(const signed_long_long_long& v) { base_class_type::m_data[0U] &= v.m_data[0U]; base_class_type::m_data[1U] &= v.m_data[1U]; base_class_type::m_data[2U] &= v.m_data[2U]; base_class_type::m_data[3U] &= v.m_data[3U]; return *this; }
    signed_long_long_long& operator|=(const signed_long_long_long& v) { base_class_type::m_data[0U] |= v.m_data[0U]; base_class_type::m_data[1U] |= v.m_data[1U]; base_class_type::m_data[2U] |= v.m_data[2U]; base_class_type::m_data[3U] |= v.m_data[3U]; return *this; }
    signed_long_long_long& operator^=(const signed_long_long_long& v) { base_class_type::m_data[0U] ^= v.m_data[0U]; base_class_type::m_data[1U] ^= v.m_data[1U]; base_class_type::m_data[2U] ^= v.m_data[2U]; base_class_type::m_data[3U] ^= v.m_data[3U]; return *this; }

    signed_long_long_long& operator&=(const unsigned_small_type& t) { base_class_type::m_data[0U] &= t; return *this; }
    signed_long_long_long& operator|=(const unsigned_small_type& t) { base_class_type::m_data[0U] |= t; return *this; }
    signed_long_long_long& operator^=(const unsigned_small_type& t) { base_class_type::m_data[0U] ^= t; return *this; }

    // Comparison operators
    bool operator< (const signed_long_long_long& v) const { return (cmp(v) <  0); }
    bool operator<=(const signed_long_long_long& v) const { return (cmp(v) <= 0); }
    bool operator==(const signed_long_long_long& v) const { return (cmp(v) == 0); }
    bool operator!=(const signed_long_long_long& v) const { return (cmp(v) != 0); }
    bool operator>=(const signed_long_long_long& v) const { return (cmp(v) >= 0); }
    bool operator> (const signed_long_long_long& v) const { return (cmp(v) >  0); }

    // Various explicit comparison functions
    bool is_neg() const { return ((base_class_type::m_data[3U] & value_neg_bit()) != 0); }
    bool is_pos() const { return (!is_neg()); }

    // Operators pre-increment and pre-decrement
    signed_long_long_long& operator++() { base_class_type::inc(); return *this; }
    signed_long_long_long& operator--() { base_class_type::dec(); return *this; }

    // Operators post-increment and post-decrement.
    signed_long_long_long operator++(int)  { const signed_long_long_long w(*this); ++(*this); return w; }
    signed_long_long_long operator--(int)  { const signed_long_long_long w(*this); --(*this); return w; }

        // Conversion routines.
    std::int16_t to_int16() const
    {
      return ((!is_neg()) ?  std::int16_t(base_class_type::to_uint16())
                          : -std::int16_t(base_class_type::to_uint16(-*this)));
    }

    std::int32_t to_int32() const
    {
      return ((!is_neg()) ?  std::int32_t(base_class_type::to_uint32())
                          : -std::int32_t(base_class_type::to_uint32(-*this)));
    }

    std::int64_t to_int64() const
    {
      return ((!is_neg()) ?  std::int32_t(base_class_type::to_uint64())
                          : -std::int32_t(base_class_type::to_uint64(-*this)));
    }

    static std::int16_t to_int16 (const signed_long_long_long& n) { return n.to_int16(); }
    static std::int32_t to_int32 (const signed_long_long_long& n) { return n.to_int32(); }
    static std::int64_t to_int64 (const signed_long_long_long& n) { return n.to_int64(); }

    static bool to_string(const   signed_long_long_long& n,
                          char*                          p,
                          char*                          p_sign = nullptr,
                          const detail::base_type        base   = detail::base_type_dec,
                          const bool                     upper  = true)
    {
      const bool b_neg = n.is_neg();

      if(p_sign != nullptr)
      {
        *p_sign = char((!b_neg) ? char('+') : char('-'));
      }

      return base_class_type::to_string(base_class_type((!b_neg) ? n : -n), p, 0, base, upper);
    }

  private:
    // Private constant values.
    static signed_long_long_long value_max()
    {
      return signed_long_long_long((std::numeric_limits<unsigned_small_type>::max)(),
                                   (std::numeric_limits<unsigned_small_type>::max)(),
                                   (std::numeric_limits<unsigned_small_type>::max)(),
                                    value_neg_bit() - 1U);
    }

    static signed_long_long_long value_min()
    {
      return signed_long_long_long(unsigned_small_type(0U),
                                   unsigned_small_type(0U),
                                   unsigned_small_type(0U),
                                   value_neg_bit());
    }

    static unsigned_small_type value_neg_bit()
    {
      // The negative bit of the type signed_long_long_long::unsigned_small_type.
      return unsigned_small_type(unsigned_small_type(1U) << (std::numeric_limits<unsigned_small_type>::digits - 1));
    }

    signed_long_long_long(const unsigned_small_type& t0,
                          const unsigned_small_type& t1,
                          const unsigned_small_type& t2,
                          const unsigned_small_type& t3) : base_class_type(t0, t1, t2, t3) { }

    // Comparison
    int cmp(const signed_long_long_long& v) const
    {
      const bool v_neg = v.is_neg();
      const int  v_cmp = base_class_type::cmp(v);

      return (is_neg() ? (v_neg ? v_cmp : -1) : (v_neg ? +1 : v_cmp));
    }

    friend class std::numeric_limits<signed_long_long_long>;
  };

  // Non-member unary +/- of signed_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator+(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& self) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(self); }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator-(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& self) { signed_long_long_long<UnsignedSmallType, UnsignedLargeType> tmp(self); tmp.negate(); return tmp; }

  // Non-member binary add/sub/mul/div/mod of signed_long_long_long with signed_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator+(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) += v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator-(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) -= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator*(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) *= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator/(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) /= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator%(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) %= v; }

  // Non-member binary add/sub/mul/div of signed_long_long_long with IntegralType.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator+(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) += v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator-(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) -= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator*(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) *= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator/(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) /= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator%(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) %= v; }

  // Non-member binary add/sub/mul/div of IntegralType with signed_long_long_long.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator+(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) += v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator-(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) -= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator*(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) *= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator/(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) /= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator%(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) %= v; }

  // Non-member shift of const signed_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator<<(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const int n) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) <<= n; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator>>(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const int n) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) >>= n; }

  // Non-member logic operators of signed_long_long_long with signed_long_long_long.
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator&(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) &= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator|(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) |= v; }
  template<typename UnsignedSmallType, typename UnsignedLargeType> signed_long_long_long<UnsignedSmallType, UnsignedLargeType> operator^(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) ^= v; }

  // Non-member logic operators of signed_long_long_long with IntegralType.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator&(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) &= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator|(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) |= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator^(const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& u, const IntegralType& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) ^= v; }

  // Non-member logic operators of IntegralType with signed_long_long_long.
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator&(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) &= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator|(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) |= v; }
  template<typename IntegralType, typename UnsignedSmallType, typename UnsignedLargeType> typename std::enable_if<std::is_integral<IntegralType>::value, signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::type operator^(const IntegralType& u, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& v) { return signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(u) ^= v; }

  } } // namespace math::lll

  // Specialization of numeric_limits<signed_long_long_long>
  namespace std
  {
    template<typename UnsignedSmallType, typename UnsignedLargeType>
    class numeric_limits<math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>
    {
    public:
      static const bool                    is_specialized    = true;
      static const int                     digits            = math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>::my_digits;
      static const int                     digits10          = math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>::my_digits10;
      static const int                     max_digits10      = 0;
      static const bool                    is_signed         = true;
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

      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> (min)        () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>::value_min(); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> (max)        () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>::value_max(); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> lowest       () throw() { return (min)(); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> epsilon      () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> round_error  () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> infinity     () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> quiet_NaN    () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> signaling_NaN() throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
      static const math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType> denorm_min   () throw() { return math::lll::signed_long_long_long<UnsignedSmallType, UnsignedLargeType>(0U); }
    };
  }

#endif // SIGNED_LONG_LONG_LONG_2003_12_08_H
