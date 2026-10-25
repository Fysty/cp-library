---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Polynomial/helper.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"Polynomial/fps_inv.hpp\"\n#include \"Polynomial/helper.hpp\"\
    \n\n// returns {q, r} with f = q g + r, deg r < deg g, both trimmed\ntemplate<typename\
    \ T>\npair<vector<T>, vector<T>> poly_divmod(vector<T> f, vector<T> g) {\n   \
    \ poly_trim(f), poly_trim(g);\n    assert(!g.empty());\n    int n = SZ(f), m =\
    \ SZ(g);\n    if (n < m) return {vector<T>(), f};\n    // rev(q) = rev(f) / rev(g)\
    \ mod x^(n - m + 1)\n    int k = n - m + 1;\n    vector<T> rf(f.rbegin(), f.rbegin()\
    \ + k), rg(g.rbegin(), g.rend());\n    rg.resize(k);\n    vector<T> q = convolution(rf,\
    \ fps_inv(rg));\n    q.resize(k);\n    reverse(q.begin(), q.end());\n    vector<T>\
    \ qg = convolution(q, g);\n    vector<T> r(f.begin(), f.begin() + m - 1);\n  \
    \  for (int i = 0; i < m - 1; ++i) r[i] -= qg[i];\n    poly_trim(q), poly_trim(r);\n\
    \    return {q, r};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Polynomial/divmod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Polynomial/divmod.hpp
layout: document
redirect_from:
- /library/Polynomial/divmod.hpp
- /library/Polynomial/divmod.hpp.html
title: Polynomial/divmod.hpp
---
