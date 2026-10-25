---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: Polynomial/helper.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n\n#include \"default_code.hpp\"\n#include \"Polynomial/divmod.hpp\"\n\nusing\
    \ mint = modint998244353;\n\nint main()\n{\n    MottoHayaku\n    int n, m;\n \
    \   cin >> n >> m;\n    vector<mint> f(n), g(m);\n    for(auto &x : f) cin >>\
    \ x;\n    for(auto &x : g) cin >> x;\n    auto [q, r] = poly_divmod(f, g);\n \
    \   cout << SZ(q) << ' ' << SZ(r) << '\\n';\n    rep(i, SZ(q)) cout << q[i] <<\
    \ ' ';\n    cout << '\\n';\n    rep(i, SZ(r)) cout << r[i] << ' ';\n    cout <<\
    \ '\\n';\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/division_of_polynomials.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/division_of_polynomials.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/division_of_polynomials.test.cpp
- /verify/test/library_checker/division_of_polynomials.test.cpp.html
title: test/library_checker/division_of_polynomials.test.cpp
---
