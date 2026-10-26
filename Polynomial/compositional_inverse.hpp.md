---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Numeric/Modint.hpp
    title: Numeric/Modint.hpp
  - icon: ':heavy_check_mark:'
    path: Numeric/internal_math.hpp
    title: Numeric/internal_math.hpp
  - icon: ':heavy_check_mark:'
    path: Numeric/internal_primitive_root.hpp
    title: Numeric/internal_primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/NTT.hpp
    title: Polynomial/NTT.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/convolution.hpp
    title: Polynomial/convolution.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/fps_exp.hpp
    title: Polynomial/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/fps_inv.hpp
    title: Polynomial/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/fps_log.hpp
    title: Polynomial/fps_log.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/power_projection.hpp
    title: Polynomial/power_projection.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/compositional_inverse_of_formal_power_series.test.cpp
    title: test/library_checker/compositional_inverse_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/compositional_inverse_of_formal_power_series_large.test.cpp
    title: test/library_checker/compositional_inverse_of_formal_power_series_large.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Polynomial/compositional_inverse.hpp\"\n\n#line 2 \"Polynomial/power_projection.hpp\"\
    \n\n#line 2 \"Polynomial/fps_inv.hpp\"\n\n#line 2 \"Polynomial/convolution.hpp\"\
    \n\n#line 2 \"Polynomial/NTT.hpp\"\n\n#line 2 \"Numeric/Modint.hpp\"\n\n// Reference:\
    \ Atcoder Library https://github.com/atcoder/ac-library\n#line 2 \"Numeric/internal_math.hpp\"\
    \n// Reference: Atcoder Library https://github.com/atcoder/ac-library\n\n#ifdef\
    \ _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace internal {\nconstexpr long\
    \ long safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x +=\
    \ m;\n    return x;\n}\nconstexpr long long pow_mod_constexpr(long long x, long\
    \ long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m = (unsigned\
    \ int)(m);\n    unsigned long long r = 1;\n    unsigned long long y = safe_mod(x,\
    \ m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y *\
    \ y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1)\n            y =\
    \ y * y % n, t <<= 1;\n        if (y != n - 1 && t % 2 == 0)\n            return\
    \ false;\n    }\n    return true;\n}\ntemplate <int n> constexpr bool is_prime\
    \ = is_prime_constexpr(n);\nconstexpr std::pair<long long, long long> inv_gcd(long\
    \ long a, long long b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b,\
    \ 0};\n    long long s = b, t = a, m0 = 0, m1 = 1;\n    while (t) {\n        long\
    \ long u = s / t;\n        s -= t * u, m0 -= m1 * u;\n        auto tmp = s;\n\
    \        s = t, t = tmp, tmp = m0, m0 = m1, m1 = tmp;\n    }\n    if (m0 < 0)\
    \ m0 += b / s;\n    return {s, m0};\n}\n}  // namespace internal\n\nnamespace\
    \ internal {\n#ifndef _MSC_VER\n    template <class T>\n        using is_signed_int128\
    \ =\n        typename std::conditional<std::is_same<T, __int128_t>::value ||\n\
    \        std::is_same<T, __int128>::value,\n        std::true_type,\n        std::false_type>::type;\n\
    \    template <class T>\n        using is_unsigned_int128 =\n        typename\
    \ std::conditional<std::is_same<T, __uint128_t>::value ||\n        std::is_same<T,\
    \ unsigned __int128>::value,\n        std::true_type,\n        std::false_type>::type;\n\
    \    template <class T>\n        using make_unsigned_int128 =\n        typename\
    \ std::conditional<std::is_same<T, __int128_t>::value,\n                 __uint128_t,\n\
    \                 unsigned __int128>;\n    template <class T>\n        using is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n        is_signed_int128<T>::value\
    \ ||\n        is_unsigned_int128<T>::value,\n        std::true_type,\n       \
    \ std::false_type>::type;\n    template <class T>\n        using is_signed_int\
    \ = typename std::conditional<(is_integral<T>::value &&\n                std::is_signed<T>::value)\
    \ ||\n        is_signed_int128<T>::value,\n        std::true_type,\n        std::false_type>::type;\n\
    \    template <class T>\n        using is_unsigned_int =\n        typename std::conditional<(is_integral<T>::value\
    \ &&\n                std::is_unsigned<T>::value) ||\n        is_unsigned_int128<T>::value,\n\
    \        std::true_type,\n        std::false_type>::type;\n    template <class\
    \ T>\n        using to_unsigned = typename std::conditional<\n        is_signed_int128<T>::value,\n\
    \        make_unsigned_int128<T>,\n        typename std::conditional<std::is_signed<T>::value,\n\
    \        std::make_unsigned<T>,\n        std::common_type<T>>::type>::type;\n\
    #else\n    template <class T> using is_integral = typename std::is_integral<T>;\n\
    \    template <class T>\n        using is_signed_int =\n        typename std::conditional<is_integral<T>::value\
    \ && std::is_signed<T>::value,\n                 std::true_type,\n           \
    \      std::false_type>::type;\n    template <class T>\n        using is_unsigned_int\
    \ =\n        typename std::conditional<is_integral<T>::value &&\n        std::is_unsigned<T>::value,\n\
    \        std::true_type,\n        std::false_type>::type;\n    template <class\
    \ T>\n        using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n\
    \              std::make_unsigned<T>,\n              std::common_type<T>>::type;\n\
    #endif\n    template <class T> using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \    template <class T> using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \    template <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\
    \    struct modint_base {};\n    struct static_modint_base : modint_base {};\n\
    \    template <class T> using is_modint = std::is_base_of<modint_base, T>;\n \
    \   template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    }  // namespace internal\n#line 5 \"Numeric/Modint.hpp\"\n\ntemplate <int m, std::enable_if_t<(1\
    \ <= m)>* = nullptr>\nstruct static_modint : internal::static_modint_base {\n\
    \    using mint = static_modint;\n\n  public:\n    static constexpr int mod()\
    \ { return m; }\n    static mint raw(int v) {\n        mint x;\n        x._v =\
    \ v;\n        return x;\n    }\n\n    static_modint() : _v(0) {}\n    template\
    \ <class T, internal::is_signed_int_t<T>* = nullptr>\n    static_modint(T v) {\n\
    \        long long x = (long long)(v % (long long)(umod()));\n        if (x <\
    \ 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n    template <class\
    \ T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T v) {\n  \
    \      _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val() const\
    \ { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v ==\
    \ umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n  \
    \      if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n\
    \    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n    friend std::strong_ordering operator<=>(const mint& lhs, const mint&\
    \ rhs) {\n        return lhs._v <=> rhs._v;\n    }\n    friend ostream& operator<<(ostream&\
    \ os, const mint& v) {\n        os << v._v;\n        return os;\n    }\n    friend\
    \ istream& operator>>(istream& is, mint& v) {\n        long long x;\n        is\
    \ >> x;\n        x %= (long long)(umod());\n        if (x < 0) x += umod();\n\
    \        v._v = (unsigned int)(x);\n        return is;\n    }\n\n  private:\n\
    \    unsigned int _v;\n    static constexpr unsigned int umod() { return m; }\n\
    \    static constexpr bool prime = internal::is_prime<m>;\n};\n\nusing modint998244353\
    \ = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    #line 2 \"Numeric/internal_primitive_root.hpp\"\n\n#line 4 \"Numeric/internal_primitive_root.hpp\"\
    \n\n// reference: Atcoder Library https://github.com/atcoder/ac-library\n\nnamespace\
    \ internal { \n// Compile time primitive root\n// @param m must be prime\n// @return\
    \ primitive root (and minimum in now)\nconstexpr int primitive_root_constexpr(int\
    \ m) {\n    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m\
    \ == 469762049) return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353)\
    \ return 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int\
    \ x = (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long\
    \ long)(i)*i <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++]\
    \ = i;\n            while (x % i == 0) {\n                x /= i;\n          \
    \  }\n        }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n  \
    \  for (int g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) ==\
    \ 1) {\n                ok = false;\n                break;\n            }\n \
    \       }\n        if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int\
    \ primitive_root = primitive_root_constexpr(m);\n}  // namespace internal\n#line\
    \ 5 \"Polynomial/NTT.hpp\"\n\ntemplate<typename T>\nrequires std::derived_from<T,\
    \ internal::modint_base>\nclass NTT {\n    inline static int max_size = 1;\n \
    \   inline static std::vector<T> w{1, T(1)};\n    inline static const T root =\
    \ internal::primitive_root_constexpr(T::mod());\n    static void ensure_root_table_size(int\
    \ n) {\n        if (max_size < n) {\n            while (max_size <= n) max_size\
    \ <<= 1;\n            w.resize(max_size);\n            std::ranges::fill(w, 1);\n\
    \            T dw = root.pow((T::mod() - 1) / max_size);\n            for (int\
    \ s = max_size / 2; s; s >>= 1, dw *= dw) {\n                w[s] = 1;\n     \
    \           for (int j = 1; j < s; ++j) \n                    w[s + j] = w[s +\
    \ j - 1] * dw;\n            }\n        }\n    }\npublic:\n    static constexpr\
    \ int ntt_max_limit = []() {\n        unsigned int m = T::mod() - 1;\n       \
    \ int limit = 1;\n        while ((m & 1) == 0) {\n            limit <<= 1;\n \
    \           m >>= 1;\n        }\n        return limit;\n    }();\n    /*\n   \
    \ 0 <= a[i] < mod\n    a.size() must be a power of 2\n    */\n    static void\
    \ ntt(vector<T> &a, bool inv = false) {\n        int n = (int)a.size();\n    \
    \    assert((n & (n - 1)) == 0);\n        ensure_root_table_size(n);\n       \
    \ for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n >> 1; (i\
    \ ^= k) < k; k >>= 1);\n            if (j < i) swap(a[i], a[j]);\n        }\n\
    \        for (int s = 1; s < n; s <<= 1) {\n            for (int i = 0; i < n;\
    \ i += s * 2) {\n                for (int j = 0; j < s; ++j) {\n             \
    \       T tmp = a[i + s + j] * w[s + j];\n                    a[i + s + j] = a[i\
    \ + j] - tmp;\n                    a[i + j] += tmp;\n                }\n     \
    \       }\n        }\n        if (!inv) return;\n        T iv = T(n).inv(); \n\
    \        reverse(a.begin() + 1, a.begin() + n);\n        for (int i = 0; i < n;\
    \ ++i) a[i] *= iv;\n    }\n    static size_t maxsize() {\n        return max_size;\n\
    \    }\n};\n#line 4 \"Polynomial/convolution.hpp\"\n\ntemplate<typename T>\nvector<T>\
    \ convolution(vector<T> a, vector<T> b) {\n    if (a.empty() || b.empty()) return\
    \ vector<T>();\n    int n = 1, sz = int(a.size()) + int(b.size()) - 1;\n    while\
    \ (n < sz) n <<= 1;\n    assert(n <= NTT<T>::ntt_max_limit && \"the result length\
    \ exceeds the support limit of the modulo\");\n    a.resize(n), b.resize(n);\n\
    \    NTT<T>::ntt(a), NTT<T>::ntt(b);\n    for (int i = 0; i < n; ++i)\n      \
    \  a[i] = a[i] * b[i];\n    NTT<T>::ntt(a, true);\n    a.resize(sz);\n    return\
    \ a;\n}\n#line 4 \"Polynomial/fps_inv.hpp\"\n\ntemplate <typename T>\nvector<T>\
    \ fps_inv(const vector<T>& F) {\n    assert(!F.empty() && F[0] != 0);\n    int\
    \ n = (int)F.size();\n    assert((int)bit_ceil((unsigned)n) <= NTT<T>::ntt_max_limit\
    \ && \"the result length exceeds the support limit of the modulo\");\n    vector<T>\
    \ G = {F[0].inv()};\n    G.reserve(n);\n    int sz = 1;\n    while (sz < n) {\n\
    \        vector<T> f(sz * 2), g(sz * 2);\n        for (int i = 0; i < min(n, sz\
    \ * 2); i++) f[i] = F[i];\n        for (int i = 0; i < sz; i++) g[i] = G[i];\n\
    \        NTT<T>::ntt(f), NTT<T>::ntt(g);\n        for (int i = 0; i < sz * 2;\
    \ i++) f[i] *= g[i];\n        NTT<T>::ntt(f, true);\n        for (int i = 0; i\
    \ < sz; i++) f[i] = 0;\n        NTT<T>::ntt(f);\n        for (int i = 0; i < sz\
    \ * 2; i++) f[i] *= g[i];\n        NTT<T>::ntt(f, true);\n        for (int i =\
    \ sz; i < min(n, sz * 2); i++) G.emplace_back(-f[i]);\n        sz *= 2;\n    }\n\
    \    return G;\n}\n#line 4 \"Polynomial/power_projection.hpp\"\n\n// returns {\\\
    sum_i w[i] [x^i] f^k}_{k < m}\n// \\sum_k y^(-k-1) \\sum_i w[i] [x^i] f^k = [x^(X-1)]\
    \ P(x, y) / Q(x, y), P = \\sum_i w[i] x^(X-1-i), Q = y - f(x)\n// Bostan-Mori\
    \ on x, X is a power of 2 and Q = y^D + (terms of y-degree < D) throughout\ntemplate<typename\
    \ T>\nvector<T> power_projection(const vector<T>& w, vector<T> f, int m) {\n \
    \   if (m == 0) return vector<T>();\n    int n = SZ(w);\n    if (n == 0) return\
    \ vector<T>(m);\n    f.resize(n);\n    int X = 1, D = 1;\n    while (X < n) X\
    \ <<= 1;\n    // p[j * 2X + i] = [x^i y^j] P, q[j * 2X + i] = [x^i y^j] (Q - y^D),\
    \ i < X, j < D\n    vector<T> p(2 * X), q(2 * X);\n    for (int i = 0; i < n;\
    \ ++i) p[X - 1 - i] = w[i], q[i] = -f[i];\n    const T g = internal::primitive_root_constexpr(T::mod()),\
    \ inv2 = T(2).inv();\n    while (X > 1) {\n        // the products have x-degree\
    \ < 2X and y-degree <= 2D, so a cyclic NTT of length L = 4XD works,\n        //\
    \ with y^(2D) wrapping onto y^0\n        int L = 4 * X * D, H = L / 2;\n     \
    \   p.resize(L), q.resize(L);\n        q[D * 2 * X] += 1;\n        NTT<T>::ntt(p),\
    \ NTT<T>::ntt(q);\n        // NTT(Q(-x, y))[t] = NTT(Q)[t + H], so with U = P(x,\
    \ y) Q(-x, y), V = Q(x, y) Q(-x, y):\n        // NTT(odd part of U)[t] = (U[t]\
    \ - U[t + H]) / 2z^t, NTT(even part of V)[t] = V[t]\n        T iz = g.pow((T::mod()\
    \ - 1) / L).inv(), c = inv2;\n        for (int t = 0; t < H; ++t, c *= iz) {\n\
    \            p[t] = (p[t] * q[t + H] - p[t + H] * q[t]) * c;\n            q[t]\
    \ = q[t] * q[t + H];\n        }\n        p.resize(H), q.resize(H);\n        NTT<T>::ntt(p,\
    \ true), NTT<T>::ntt(q, true);\n        q[0] -= 1;\n        // now laid out as\
    \ [x^i y^j] at j * X + i, keep x-degree < X / 2\n        X /= 2, D *= 2;\n   \
    \     for (int j = 0; j < D; ++j)\n            for (int i = X; i < 2 * X; ++i)\
    \ p[j * 2 * X + i] = q[j * 2 * X + i] = 0;\n    }\n    // [x^0] P / Q, P(y) =\
    \ \\sum_k c[k] y^(-k-1) Q(y): with z = 1/y, \\sum_k c[k] z^k = rev(P) / rev(Q)\n\
    \    vector<T> rp(D), rq(D + 1);\n    rq[0] = 1;\n    for (int j = 0; j < D; ++j)\
    \ rp[D - 1 - j] = p[2 * j], rq[D - j] = q[2 * j];\n    rq.resize(m);\n    vector<T>\
    \ res = convolution(rp, fps_inv(rq));\n    res.resize(m);\n    return res;\n}\n\
    #line 2 \"Polynomial/fps_exp.hpp\"\n\n#line 2 \"Polynomial/fps_log.hpp\"\n\n#line\
    \ 4 \"Polynomial/fps_log.hpp\"\n\ntemplate <typename T>\nvector<T> fps_log(const\
    \ vector<T> &F) {\n    assert(!F.empty() && F[0] == 1);\n    int n = (int)F.size();\n\
    \    vector<T> dF = F;\n    for (int i = 1; i < n; i++) dF[i - 1] = dF[i] * i;\n\
    \    dF.pop_back();\n    vector<T> F_inv = fps_inv(F);\n    vector<T> G = convolution(dF,\
    \ F_inv);\n    G.resize(n - 1);\n    G.insert(G.begin(), 0);\n    for (int i =\
    \ 1; i < n; i++) G[i] /= i;\n    return G;\n}\n#line 4 \"Polynomial/fps_exp.hpp\"\
    \n\ntemplate <typename T>\nvector<T> fps_exp(const vector<T>& F) {\n    int n\
    \ = (int)F.size();\n    assert(n > 0 && F[0] == 0);\n    assert((int)bit_ceil((unsigned)n)\
    \ <= NTT<T>::ntt_max_limit && \"the result length exceeds the support limit of\
    \ the modulo\");\n    vector<T> G = {1}, H = {1};\n    G.reserve(n), H.reserve(n);\n\
    \    int sz = 1;\n    while (sz < n) {\n        vector<T> df(sz * 2), g(sz * 2),\
    \ h(sz * 2);\n        for (int i = 0; i < sz; i++) g[i] = G[i];\n        for (int\
    \ i = 0; i < sz; i++) h[i] = H[i];\n        for (int i = 1; i < min(n, sz * 2);\
    \ i++) df[i - 1] = F[i] * i;\n        NTT<T>::ntt(df), NTT<T>::ntt(g), NTT<T>::ntt(h);\n\
    \n        for (int i = 0; i < sz * 2; i++) df[i] *= g[i];\n        NTT<T>::ntt(df,\
    \ true);\n        for (int i = 0; i < sz - 1; i++) df[i] = 0;\n        NTT<T>::ntt(df);\n\
    \        for (int i = 0; i < sz * 2; i++) df[i] *= h[i];\n        NTT<T>::ntt(df,\
    \ true);\n        for (int i = 0; i < sz - 1; i++) df[i] = 0;\n        for (int\
    \ i = sz * 2 - 2; i >= 0; i--) df[i + 1] = df[i] / (i + 1);\n        NTT<T>::ntt(df);\n\
    \        for (int i = 0; i < sz * 2; i++) df[i] *= g[i];\n        NTT<T>::ntt(df,\
    \ true);\n        for (int i = sz; i < min(n, sz * 2); i++) G.emplace_back(df[i]);\n\
    \        \n        for (int i = 0; i < min(n, sz * 2); i++) g[i] = G[i];\n   \
    \     NTT<T>::ntt(g);\n        for (int i = 0; i < sz * 2; i++) g[i] *= h[i];\n\
    \        NTT<T>::ntt(g, true);\n        for (int i = 0; i < sz; i++) g[i] = 0;\n\
    \        NTT<T>::ntt(g);\n        for (int i = 0; i < sz * 2; i++) g[i] *= h[i];\n\
    \        NTT<T>::ntt(g, true);\n        for (int i = sz; i < min(n, sz * 2); i++)\
    \ H.emplace_back(-g[i]);\n        sz *= 2;\n    }\n    return G;\n}\n#line 5 \"\
    Polynomial/compositional_inverse.hpp\"\n\n// f[0] = 0, f[1] != 0, returns g with\
    \ f(g(x)) = g(f(x)) = x mod x^n\ntemplate<typename T>\nvector<T> compositional_inverse(const\
    \ vector<T>& f) {\n    int n = SZ(f);\n    assert(n > 0 && f[0] == 0);\n    if\
    \ (n == 1) return {0};\n    assert(f[1] != 0);\n    int N = n - 1;\n    vector<T>\
    \ w(n);\n    w[N] = 1;\n    vector<T> p = power_projection(w, f, n), h(N);\n \
    \   for (int k = 1; k <= N; ++k) h[N - k] = p[k] * N / k;\n    T c = h[0].inv(),\
    \ iN = T(N).inv();\n    for (auto& x : h) x *= c;\n    h = fps_log(h);\n    for\
    \ (auto& x : h) x *= iN;\n    h = fps_exp(h);\n    for (auto& x : h) x *= f[1];\n\
    \    h = fps_inv(h);\n    vector<T> g(n);\n    for (int i = 0; i < N; ++i) g[i\
    \ + 1] = h[i];\n    return g;\n}\n"
  code: "#pragma once\n\n#include \"Polynomial/power_projection.hpp\"\n#include \"\
    Polynomial/fps_exp.hpp\"\n\n// f[0] = 0, f[1] != 0, returns g with f(g(x)) = g(f(x))\
    \ = x mod x^n\ntemplate<typename T>\nvector<T> compositional_inverse(const vector<T>&\
    \ f) {\n    int n = SZ(f);\n    assert(n > 0 && f[0] == 0);\n    if (n == 1) return\
    \ {0};\n    assert(f[1] != 0);\n    int N = n - 1;\n    vector<T> w(n);\n    w[N]\
    \ = 1;\n    vector<T> p = power_projection(w, f, n), h(N);\n    for (int k = 1;\
    \ k <= N; ++k) h[N - k] = p[k] * N / k;\n    T c = h[0].inv(), iN = T(N).inv();\n\
    \    for (auto& x : h) x *= c;\n    h = fps_log(h);\n    for (auto& x : h) x *=\
    \ iN;\n    h = fps_exp(h);\n    for (auto& x : h) x *= f[1];\n    h = fps_inv(h);\n\
    \    vector<T> g(n);\n    for (int i = 0; i < N; ++i) g[i + 1] = h[i];\n    return\
    \ g;\n}\n"
  dependsOn:
  - Polynomial/power_projection.hpp
  - Polynomial/fps_inv.hpp
  - Polynomial/convolution.hpp
  - Polynomial/NTT.hpp
  - Numeric/Modint.hpp
  - Numeric/internal_math.hpp
  - Numeric/internal_primitive_root.hpp
  - Polynomial/fps_exp.hpp
  - Polynomial/fps_log.hpp
  isVerificationFile: false
  path: Polynomial/compositional_inverse.hpp
  requiredBy: []
  timestamp: '2026-10-26 15:25:53+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/compositional_inverse_of_formal_power_series.test.cpp
  - test/library_checker/compositional_inverse_of_formal_power_series_large.test.cpp
documentation_of: Polynomial/compositional_inverse.hpp
layout: document
redirect_from:
- /library/Polynomial/compositional_inverse.hpp
- /library/Polynomial/compositional_inverse.hpp.html
title: Polynomial/compositional_inverse.hpp
---
