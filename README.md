# Build-Time Config Calculator

A small header-only C++ utility computing a handful of derived build
configuration values — a clamped buffer size, a packed version checksum,
and a couple of validity checks — designed so everything that can be
computed at compile time actually is, with the compiler itself used as
proof rather than assumption.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter F: `constexpr` functions, `consteval` functions, and using
`static_assert` as compiler-verified proof of compile-time evaluation —
not just the `constexpr`/`consteval` keywords themselves. Earlier
material (bit-packing from Ch O, named constants, function overloading
from Ch 11) is folded in deliberately rather than left behind.

## What it does

- `bufferSize(baseUnit, scaleFactor)` — a `constexpr` function that
  multiplies and clamps the result into a named, shared valid range
- `versionChecksum(major, minor, patch)` — a `constexpr` function that
  bit-packs three version components into a single integer, with
  `getMajorVersion` / `getMinorVersion` / `getPatchVersion` as its
  inverse (unpacking) counterparts
- `isConfigValid(...)` — a `constexpr` predicate checking a buffer size
  and a version checksum against shared bounds, overloaded so it can
  also accept the raw inputs to either or both and compose the other
  two functions internally
- `requireSupportedVersion(major, minor, patch)` — a `consteval`
  function (not `constexpr`) that can *only* be called with
  compile-time-known arguments, enforcing a minimum supported version
  via an internal `assert` that hard-fails the build if violated
- A `tests.h` full of `static_assert`s proving each function's actual
  computed result against real expected values, evaluated entirely by
  the compiler before the program ever runs

## Project structure

```
main.cpp                            // demonstrates each function running
utils/
  utils.h                           // umbrella include
  tools/
    constants.h                     // shared constexpr bounds, reused across functions
    buffer_size.h                   // bufferSize
    version_checksum.h              // versionChecksum + its unpack counterparts
    is_config_valid.h               // isConfigValid + its composing overloads
    require_supported_version.h     // the consteval enforcement function
    internal_utils.h                // utils::internal — a general-purpose byte-clamp helper
  helpers/
    tests.h                         // static_assert proofs for every function
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app main.cpp
```

Or open `Build-Time Config Calculator.slnx` in Visual Studio.

## Running

```bash
./app
```

Example output:

```
256 8 512
132365
2
5
13
1
```

## Notes

`requireSupportedVersion` compares two packed `versionChecksum` values
rather than checking major/minor/patch independently — packing puts
`major` in the highest-order byte, so a plain integer comparison between
two packed checksums automatically gives correct version ordering, which
independent per-component range checks cannot. It halts compilation via
an internal `assert` rather than returning a `bool`, since a non-template
function's own parameters are never usable inside a `static_assert`
written in its body — only `assert`'s failure path being non-`constexpr`
makes it a valid way to fail a constant evaluation from within the
function itself. `utils::internal::clamp8BitInt` is a naming convention
signaling "not meant for outside use," not a compiler-enforced
restriction — true encapsulation isn't available the same way for a
`constexpr` helper that must live in a header. `constants.h` bounds are
reused across functions where the underlying concept is genuinely the
same (e.g. buffer size validity), and given fresh, separately-named
bounds where the concept genuinely differs (e.g. minimum supported
version).