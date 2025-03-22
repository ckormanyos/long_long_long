///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2003 - 2025.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef LONG_LONG_LONG_IO_2010_07_26_H
  #define LONG_LONG_LONG_IO_2010_07_26_H

  #include <math/long_long_long/signed_long_long_long.h>

  #include <ostream>

  namespace math { namespace lll {

  template<typename UnsignedSmallType, typename UnsignedLargeType>
  class unsigned_long_long_long;

  template<typename UnsignedSmallType, typename UnsignedLargeType>
  class signed_long_long_long;

  template<typename UnsignedSmallType,
           typename UnsignedLargeType>
  std::ostream& operator<<(std::ostream& os, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u);

  template<typename UnsignedSmallType,
           typename UnsignedLargeType>
  std::ostream& operator<<(std::ostream& os, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& n);

  template<typename UnsignedSmallType,
           typename UnsignedLargeType>
  std::ostream& operator<<(std::ostream& os, const unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>& u)
  {
    // Get the output stream flags.
    const std::ios::fmtflags flags = os.flags();

    // Determine the base.
    // If both std::ios::dec as well as std::ios::hex
    // are set, then decimal std::ios::dec is assumed.
    const detail::base_type base = (((flags & std::ios::dec) != 0) ? detail::base_type_dec : detail::base_type_hex);

    // Upper case or lower case?
    const bool upper = ((flags & std::ios::uppercase) != 0);

    // Declare array data for the left-justified character
    // string aligned on a 16-byte boundary.
    char str[16 * (std::numeric_limits<unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>>::digits10 / 16) + 16];

    // Get the left-justified character string and the sign.
    const bool b_str = math::lll::unsigned_long_long_long<UnsignedSmallType, UnsignedLargeType>::to_string(u, str, 0, base, upper);

    if(b_str)
    {
      // Is it decimal base?
      if(base == math::lll::detail::base_type_dec)
      {
        // Output stream prints sign?
        if((flags & std::ios::showpos) != 0)
        {
          static_cast<void>(os << char('+'));
        }
      }
      else
      {
        // It must be hexadecimal base.
        // Show the base?
        if((flags & std::ios::showbase) != 0)
        {
          const char str_base[] =
          {
            char('0'),
            ((!upper) ? char('x') : char('X')),
            char('\0')
          };

          static_cast<void>(os << std::string(str_base));
        }
      }

      return (os << std::string(str));
    }
    else
    {
      // String conversion failed.
      return os;
    }
  }

  template<typename UnsignedSmallType,
           typename UnsignedLargeType>
  std::ostream& operator<<(std::ostream& os, const signed_long_long_long<UnsignedSmallType, UnsignedLargeType>& n)
  {
    // Get the output stream flags.
    const std::ios::fmtflags flags = os.flags();

    // Which base? If both std::ios::dec as well as std::ios::hex
    // are set, then decimal std::ios::dec is assumed.
    const detail::base_type base = (((flags & std::ios::dec) != 0) ? detail::base_type_dec : detail::base_type_hex);

    // Upper case or lower case?
    const bool upper = ((flags & std::ios::uppercase) != 0);

    // Declare variables for the left-justified character string and the sign.
    char sign;
    char str[16 * (std::numeric_limits<signed_long_long_long<UnsignedSmallType, UnsignedLargeType>>::digits10 / 16) + 16];

    // Get the left-justified character string and the sign.
    const bool b_str = signed_long_long_long<UnsignedSmallType, UnsignedLargeType>::to_string(n, str, &sign, base, upper);

    if(b_str)
    {
      // Is it decimal base?
      if(base == detail::base_type_dec)
      {
        // Output stream prints sign?
        if(n.is_neg() || ((flags & std::ios::showpos) != 0))
        {
          os << sign;
        }
      }
      else
      {
        // It must be hexadecimal base.
        // Show the base?
        if((flags & std::ios::showbase) != 0)
        {
          os << (upper ? "0X" : "0x");
        }
      }

      return (os << std::string(str));
    }
    else
    {
      // String conversion failed.
      return os;
    }
  }

  } } // namespace math::lll

#endif // LONG_LONG_LONG_IO_2010_07_26_H
