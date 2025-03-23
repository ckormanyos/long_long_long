long_long_long
==================

<p align="center">
    <a href="https://github.com/ckormanyos/long_long_long/actions">
        <img src="https://github.com/ckormanyos/long_long_long/actions/workflows/long_long_long.yml/badge.svg" alt="Build Status"></a>
    <a href="https://github.com/ckormanyos/wide-integer/blob/master/LICENSE">
        <img src="https://img.shields.io/badge/license-BSL%201.0-blue.svg" alt="Boost Software License 1.0"></a>
    <a href="https://godbolt.org/z/Pfn7bnsd4" alt="godbolt">
        <img src="https://img.shields.io/badge/try%20it%20on-godbolt-green" /></a>
</p>

This is a legacy project that preserves an old work.
New designs should use [`ckormanyos/wide-integer`](https://github.com/ckormanyos/wide-integer)
or [`boost::multiprecision`](https://github.com/boostorg/multiprecision) or similar.

`ckormanyos/long_long_long` implements signed and unsigned integers consisting of four constituent parts
such as a synthesized drop-in replacement for `uint128_t` or similar.

Use the C++ templates `unsigned_long_long_long` and `signed_long_long_long`
to create unsigned or signed _long_ _long_ _long_ integers (i.e., like `uint128_t`).
See the detailed example below.

The `unsigned_long_long_long` and `signed_long_long_long` template classes
are located in `namespace` `math::lll`.

```cpp
#include <math/long_long_long/long_long_long.h>

#include <iostream>

auto main() -> int
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

  // 3433683820292512484657849089281
  std::cout << "p3: " << p3 << std::endl;

  return (p3 == ctrl) ? 0 : -1;
}
```
