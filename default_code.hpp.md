---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/composition_of_formal_power_series.test.cpp
    title: test/library_checker/composition_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/composition_of_formal_power_series_large.test.cpp
    title: test/library_checker/composition_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/compositional_inverse_of_formal_power_series.test.cpp
    title: test/library_checker/compositional_inverse_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/compositional_inverse_of_formal_power_series_large.test.cpp
    title: test/library_checker/compositional_inverse_of_formal_power_series_large.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution.test.cpp
    title: test/library_checker/convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/division_of_polynomials.test.cpp
    title: test/library_checker/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/fps_exp.test.cpp
    title: test/library_checker/fps_exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/fps_inv.test.cpp
    title: test/library_checker/fps_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/fps_log.test.cpp
    title: test/library_checker/fps_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/fps_pow.test.cpp
    title: test/library_checker/fps_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/multipoint_evaluation.test.cpp
    title: test/library_checker/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/multipoint_evaluation_on_geometric_sequence.test.cpp
    title: test/library_checker/multipoint_evaluation_on_geometric_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial_interpolation.test.cpp
    title: test/library_checker/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/product_of_polynomial_sequence.test.cpp
    title: test/library_checker/product_of_polynomial_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"default_code.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\ntypedef long long ll;\ntypedef pair<int, int> pii;\ntypedef pair<ll, ll>\
    \ pll;\n#define MottoHayaku ios::sync_with_stdio(false); cin.tie(0);\n#define\
    \ rep(i, n) for(int i = 0; i < n; i++)\n#define rep1(i, n) for(int i = 1; i <=\
    \ n; i++)\n#define F first\n#define S second\n#define pb push_back\n#define SZ(a)\
    \ ((int)a.size())\n#define ALL(v) v.begin(), v.end()\ntemplate<class A, class\
    \ B>\nostream& operator<<(ostream& os, const pair<A, B> &a) {\n    os << \"(\"\
    \ << a.first << \", \" << a.second << \")\";\n    return os;\n}\ntemplate <typename\
    \ T>\nconcept PrintableContainer = requires(T& a) {\n    a.begin();\n    a.end();\n\
    } && !std::same_as<std::remove_cvref_t<T>, std::string> &&\n     !std::same_as<std::remove_cvref_t<T>,\
    \ std::string_view> &&\n     !std::is_convertible_v<T, const char*>;\ntemplate\
    \ <PrintableContainer T>\nstd::ostream& operator<<(std::ostream& os, const T&\
    \ a) {\n    os << \"[ \";\n    bool first = true;\n    for (const auto& item :\
    \ a) {\n        if (!first) os << \", \";\n        os << item;\n        first\
    \ = false;\n    }\n    return os << \" ]\";\n}\n#ifdef fysty\n#include <experimental/iterator>\n\
    #define safe cerr<<__PRETTY_FUNCTION__<<\" line \"<<__LINE__<<\" safe\\n\"\n#define\
    \ sepline sepline_() \n#define debug(a...) debug_(#a, a)\n#define orange(a...)\
    \ orange_(#a, a)\nvoid debug_(auto s, auto ...a) {\n    cerr << \"\\e[1;32m(\"\
    \ << s << \") = (\";\n    int f = 0;\n    (..., (cerr << (f++ ? \", \" : \"\"\
    ) << a));\n    cerr << \")\\e[0m\\n\";\n}\nvoid sepline_(int length = 50) {\n\
    \    cerr << \"\\e[1;35m\";\n    cerr << string(length, '=');\n    cerr << \"\\\
    e[0m\\n\";\n}\n#else\n#define safe ((void)0)\n#define sepline safe\n#define debug(...)\
    \ safe\n#define orange(...) safe\n#endif\n\nvoid chmax(auto &x, auto val) {\n\
    \    x = max(x, val);\n}\n\nvoid chmin(auto &x, auto val) {\n    x = min(x, val);\n\
    }\n\ntemplate<class T>\nvoid discretization(vector<T> &vals) {\n    ranges::sort(vals);\n\
    \    vals.erase(ranges::unique(vals).begin(), vals.end());\n}\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef pair<int, int> pii;\ntypedef pair<ll, ll> pll;\n#define MottoHayaku\
    \ ios::sync_with_stdio(false); cin.tie(0);\n#define rep(i, n) for(int i = 0; i\
    \ < n; i++)\n#define rep1(i, n) for(int i = 1; i <= n; i++)\n#define F first\n\
    #define S second\n#define pb push_back\n#define SZ(a) ((int)a.size())\n#define\
    \ ALL(v) v.begin(), v.end()\ntemplate<class A, class B>\nostream& operator<<(ostream&\
    \ os, const pair<A, B> &a) {\n    os << \"(\" << a.first << \", \" << a.second\
    \ << \")\";\n    return os;\n}\ntemplate <typename T>\nconcept PrintableContainer\
    \ = requires(T& a) {\n    a.begin();\n    a.end();\n} && !std::same_as<std::remove_cvref_t<T>,\
    \ std::string> &&\n     !std::same_as<std::remove_cvref_t<T>, std::string_view>\
    \ &&\n     !std::is_convertible_v<T, const char*>;\ntemplate <PrintableContainer\
    \ T>\nstd::ostream& operator<<(std::ostream& os, const T& a) {\n    os << \"[\
    \ \";\n    bool first = true;\n    for (const auto& item : a) {\n        if (!first)\
    \ os << \", \";\n        os << item;\n        first = false;\n    }\n    return\
    \ os << \" ]\";\n}\n#ifdef fysty\n#include <experimental/iterator>\n#define safe\
    \ cerr<<__PRETTY_FUNCTION__<<\" line \"<<__LINE__<<\" safe\\n\"\n#define sepline\
    \ sepline_() \n#define debug(a...) debug_(#a, a)\n#define orange(a...) orange_(#a,\
    \ a)\nvoid debug_(auto s, auto ...a) {\n    cerr << \"\\e[1;32m(\" << s << \"\
    ) = (\";\n    int f = 0;\n    (..., (cerr << (f++ ? \", \" : \"\") << a));\n \
    \   cerr << \")\\e[0m\\n\";\n}\nvoid sepline_(int length = 50) {\n    cerr <<\
    \ \"\\e[1;35m\";\n    cerr << string(length, '=');\n    cerr << \"\\e[0m\\n\"\
    ;\n}\n#else\n#define safe ((void)0)\n#define sepline safe\n#define debug(...)\
    \ safe\n#define orange(...) safe\n#endif\n\nvoid chmax(auto &x, auto val) {\n\
    \    x = max(x, val);\n}\n\nvoid chmin(auto &x, auto val) {\n    x = min(x, val);\n\
    }\n\ntemplate<class T>\nvoid discretization(vector<T> &vals) {\n    ranges::sort(vals);\n\
    \    vals.erase(ranges::unique(vals).begin(), vals.end());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: default_code.hpp
  requiredBy: []
  timestamp: '2026-06-03 17:39:04+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/product_of_polynomial_sequence.test.cpp
  - test/library_checker/fps_log.test.cpp
  - test/library_checker/compositional_inverse_of_formal_power_series.test.cpp
  - test/library_checker/multipoint_evaluation.test.cpp
  - test/library_checker/fps_pow.test.cpp
  - test/library_checker/compositional_inverse_of_formal_power_series_large.test.cpp
  - test/library_checker/composition_of_formal_power_series.test.cpp
  - test/library_checker/polynomial_interpolation.test.cpp
  - test/library_checker/fps_inv.test.cpp
  - test/library_checker/convolution.test.cpp
  - test/library_checker/composition_of_formal_power_series_large.test.cpp
  - test/library_checker/multipoint_evaluation_on_geometric_sequence.test.cpp
  - test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/library_checker/division_of_polynomials.test.cpp
  - test/library_checker/fps_exp.test.cpp
documentation_of: default_code.hpp
layout: document
redirect_from:
- /library/default_code.hpp
- /library/default_code.hpp.html
title: default_code.hpp
---
