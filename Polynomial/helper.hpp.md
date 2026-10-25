---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Polynomial/divmod.hpp
    title: Polynomial/divmod.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/division_of_polynomials.test.cpp
    title: test/library_checker/division_of_polynomials.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Polynomial/helper.hpp\"\n\n// removes trailing zeros, the\
    \ zero polynomial is empty\ntemplate<typename T>\nvoid poly_trim(vector<T>& f)\
    \ {\n    while (!f.empty() && f.back() == 0) f.pop_back();\n}\n\n// returns a\
    \ + b, trimmed\ntemplate<typename T>\nvector<T> poly_add(vector<T> a, const vector<T>&\
    \ b) {\n    if (SZ(a) < SZ(b)) a.resize(SZ(b));\n    for (int i = 0; i < SZ(b);\
    \ ++i) a[i] += b[i];\n    poly_trim(a);\n    return a;\n}\n\n// returns a / x^k,\
    \ dropping the lowest k coefficients\ntemplate<typename T>\nvector<T> poly_shr(const\
    \ vector<T>& a, int k) {\n    if (SZ(a) <= k) return vector<T>();\n    return\
    \ vector<T>(a.begin() + k, a.end());\n}\n"
  code: "#pragma once\n\n// removes trailing zeros, the zero polynomial is empty\n\
    template<typename T>\nvoid poly_trim(vector<T>& f) {\n    while (!f.empty() &&\
    \ f.back() == 0) f.pop_back();\n}\n\n// returns a + b, trimmed\ntemplate<typename\
    \ T>\nvector<T> poly_add(vector<T> a, const vector<T>& b) {\n    if (SZ(a) < SZ(b))\
    \ a.resize(SZ(b));\n    for (int i = 0; i < SZ(b); ++i) a[i] += b[i];\n    poly_trim(a);\n\
    \    return a;\n}\n\n// returns a / x^k, dropping the lowest k coefficients\n\
    template<typename T>\nvector<T> poly_shr(const vector<T>& a, int k) {\n    if\
    \ (SZ(a) <= k) return vector<T>();\n    return vector<T>(a.begin() + k, a.end());\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Polynomial/helper.hpp
  requiredBy:
  - Polynomial/divmod.hpp
  timestamp: '2026-10-25 16:11:59+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/division_of_polynomials.test.cpp
documentation_of: Polynomial/helper.hpp
layout: document
redirect_from:
- /library/Polynomial/helper.hpp
- /library/Polynomial/helper.hpp.html
title: Polynomial/helper.hpp
---
