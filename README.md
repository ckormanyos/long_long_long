long_long_long
==================

`ckormanyos/long_long_long` implements signed and unsigned integers consisting of four constituent parts such as `uint128` or similar.

This is a legacy project that preserves an old work.
New designes should use (`ckormanyos/wide-integer`)[https://github.com/ckormanyos/wide-integer]
or `boost::multiprecision` or similar.

Use a C++ template to create a `long_long_long` unsigned integer such as a drop-in replacement
for `uint128_t`. The `unsigned_long_long_long` and `signed_long_long_long` are
located in `namespace` `math::lll`.

```cpp
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
