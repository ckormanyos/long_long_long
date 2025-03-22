#ifndef LONG_LONG_LONG_DETAIL_2016_09_26_H
  #define LONG_LONG_LONG_DETAIL_2016_09_26_H

  #include <cstdint>
  #include <type_traits>

  namespace math { namespace lll { namespace detail {

  typedef enum base_type_tag_enum
  {
    base_type_bin = 0x02,
    base_type_dec = 0x0A,
    base_type_hex = 0x10
  }
  base_type;

  template<const int BitCount,
           typename EnableType = void>
  struct integer_type_helper
  {
  private:
    typedef std::int8_t  exact_signed_type;
    typedef std::uint8_t exact_unsigned_type;
  };

  template<const int BitCount>
  struct integer_type_helper<BitCount,
                             typename std::enable_if<(BitCount <= 8U)>::type>
  {
  public:
    typedef std::int8_t  exact_signed_type;
    typedef std::uint8_t exact_unsigned_type;
  };

  template<const int BitCount>
  struct integer_type_helper<BitCount,
                             typename std::enable_if<   (BitCount >   8)
                                                     && (BitCount <= 16)>::type>
  {
  public:
    typedef std::int16_t  exact_signed_type;
    typedef std::uint16_t exact_unsigned_type;
  };

  template<const int BitCount>
  struct integer_type_helper<BitCount,
                             typename std::enable_if<   (BitCount >  16)
                                                     && (BitCount <= 32)>::type>
  {
  public:
    typedef std::int32_t  exact_signed_type;
    typedef std::uint32_t exact_unsigned_type;
  };

  template<const int BitCount>
  struct integer_type_helper<BitCount,
                             typename std::enable_if<   (BitCount >  32)
                                                     && (BitCount <= 64)>::type>
  {
  public:
    typedef std::int64_t  exact_signed_type;
    typedef std::uint64_t exact_unsigned_type;
  };

  } } } // namespace math::lll::detail

#endif // LONG_LONG_LONG_DETAIL_2016_09_26_H
