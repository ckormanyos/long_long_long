long_long_long
==================

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

  return (p3 == ctrl) ? 0 : -1;
}
```
