---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Numeric/DynamicModint.hpp
    title: Numeric/DynamicModint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/atcoder/ac-library
  bundledCode: "#line 2 \"Numeric/barrett.hpp\"\n// Reference: Atcoder Library https://github.com/atcoder/ac-library\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    explicit barrett(unsigned int m) :\
    \ _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod() const\
    \ { return _m; }\n    unsigned int modulo(unsigned long long z) const {\n    \
    \    if (_m == 1) return 0;\n#ifdef _MSC_VER\n        unsigned long long x;\n\
    \        _umul128(z, im, &x);\n#else\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n#endif\n        unsigned long\
    \ long y = x * _m;\n        return (z - y + (z < y ? _m : 0));\n    }\n    unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n        return modulo((unsigned\
    \ long long)a * b);\n    }\n    unsigned long long floor(unsigned long long z)\
    \ const {\n        if (_m == 1) return z;\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned long long y\
    \ = x * _m;\n        return (z < y ? x - 1 : x);\n    }\n    std::pair<unsigned\
    \ long long, unsigned int> divmod(unsigned long long z) const {\n        if (_m\
    \ == 1) return {z, 0};\n        unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n        unsigned long long y = x * _m;\n        if\
    \ (z < y) return {x - 1, z - y + _m};\n        return {x, z - y};\n    }\n};\n"
  code: "#pragma once\n// Reference: Atcoder Library https://github.com/atcoder/ac-library\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nstruct barrett {\n    unsigned\
    \ int _m;\n    unsigned long long im;\n    explicit barrett(unsigned int m) :\
    \ _m(m), im((unsigned long long)(-1) / m + 1) {}\n    unsigned int umod() const\
    \ { return _m; }\n    unsigned int modulo(unsigned long long z) const {\n    \
    \    if (_m == 1) return 0;\n#ifdef _MSC_VER\n        unsigned long long x;\n\
    \        _umul128(z, im, &x);\n#else\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n#endif\n        unsigned long\
    \ long y = x * _m;\n        return (z - y + (z < y ? _m : 0));\n    }\n    unsigned\
    \ int mul(unsigned int a, unsigned int b) const {\n        return modulo((unsigned\
    \ long long)a * b);\n    }\n    unsigned long long floor(unsigned long long z)\
    \ const {\n        if (_m == 1) return z;\n        unsigned long long x = (unsigned\
    \ long long)(((unsigned __int128)(z)*im) >> 64);\n        unsigned long long y\
    \ = x * _m;\n        return (z < y ? x - 1 : x);\n    }\n    std::pair<unsigned\
    \ long long, unsigned int> divmod(unsigned long long z) const {\n        if (_m\
    \ == 1) return {z, 0};\n        unsigned long long x = (unsigned long long)(((unsigned\
    \ __int128)(z)*im) >> 64);\n        unsigned long long y = x * _m;\n        if\
    \ (z < y) return {x - 1, z - y + _m};\n        return {x, z - y};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Numeric/barrett.hpp
  requiredBy:
  - Numeric/DynamicModint.hpp
  timestamp: '2026-10-05 14:53:07+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Numeric/barrett.hpp
layout: document
redirect_from:
- /library/Numeric/barrett.hpp
- /library/Numeric/barrett.hpp.html
title: Numeric/barrett.hpp
---
