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
    path: Polynomial/divmod.hpp
    title: Polynomial/divmod.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/fps_inv.hpp
    title: Polynomial/fps_inv.hpp
  - icon: ':heavy_check_mark:'
    path: Polynomial/helper.hpp
    title: Polynomial/helper.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Polynomial/bostan_mori.hpp\"\n\n#line 2 \"Polynomial/divmod.hpp\"\
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
    \    return G;\n}\n#line 2 \"Polynomial/helper.hpp\"\n\n// removes trailing zeros,\
    \ the zero polynomial is empty\ntemplate<typename T>\nvoid poly_trim(vector<T>&\
    \ f) {\n    while (!f.empty() && f.back() == 0) f.pop_back();\n}\n\n// returns\
    \ a + b, trimmed\ntemplate<typename T>\nvector<T> poly_add(vector<T> a, const\
    \ vector<T>& b) {\n    if (SZ(a) < SZ(b)) a.resize(SZ(b));\n    for (int i = 0;\
    \ i < SZ(b); ++i) a[i] += b[i];\n    poly_trim(a);\n    return a;\n}\n\n// returns\
    \ a / x^k, dropping the lowest k coefficients\ntemplate<typename T>\nvector<T>\
    \ poly_shr(const vector<T>& a, int k) {\n    if (SZ(a) <= k) return vector<T>();\n\
    \    return vector<T>(a.begin() + k, a.end());\n}\n#line 5 \"Polynomial/divmod.hpp\"\
    \n\n// returns {q, r} with f = q g + r, deg r < deg g\ntemplate<typename T>\n\
    pair<vector<T>, vector<T>> poly_divmod(vector<T> f, vector<T> g) {\n    poly_trim(f),\
    \ poly_trim(g);\n    assert(!g.empty());\n    int n = SZ(f), m = SZ(g);\n    if\
    \ (n < m) return {vector<T>(), f};\n    // rev(q) = rev(f) / rev(g) mod x^(n -\
    \ m + 1)\n    int k = n - m + 1;\n    vector<T> rf(f.rbegin(), f.rbegin() + k),\
    \ rg(g.rbegin(), g.rend());\n    rg.resize(k);\n    vector<T> q = convolution(rf,\
    \ fps_inv(rg));\n    q.resize(k);\n    reverse(q.begin(), q.end());\n    vector<T>\
    \ qg = convolution(q, g);\n    vector<T> r(f.begin(), f.begin() + m - 1);\n  \
    \  for (int i = 0; i < m - 1; ++i) r[i] -= qg[i];\n    poly_trim(q), poly_trim(r);\n\
    \    return {q, r};\n}\n#line 4 \"Polynomial/bostan_mori.hpp\"\n\n// [x^k](f(x)/g(x)),\
    \ [x^0]g != 0\ntemplate<typename T>\nT bostan_mori(const vector<T> &f, const vector<T>\
    \ &g, long long k) {\n    assert(!g.empty() && g[0] != 0);\n    if (SZ(f) >= SZ(g))\
    \ {\n        // f = qg + r, [x^k] f/g = [x^k] q + [x^k] r/g\n        auto [q,\
    \ r] = poly_divmod(f, g);\n        return (k < SZ(q) ? q[k] : T(0)) + bostan_mori(r,\
    \ g, k);\n    }\n    if (f.empty()) return T(0);\n    vector<T> F = f, G = g;\n\
    \    for(; k; k >>= 1) {\n        int m = 1;\n        while (m < SZ(G) * 2) m\
    \ <<= 1;\n        int m2 = m >> 1;\n        F.resize(m), G.resize(m);\n      \
    \  NTT<T>::ntt(F), NTT<T>::ntt(G);\n        for (int i = 0; i < m; ++i) F[i] *=\
    \ G[(i + m2) % m];\n        for (int i = 0; i < m2; ++i) {\n            int j\
    \ = i + m2;\n            G[i] = G[j] = G[i] * G[j];\n        }\n        NTT<T>::ntt(F,\
    \ true), NTT<T>::ntt(G, true);\n        for (int i = 0; i * 2 + (k & 1) < SZ(F);\
    \ ++i) F[i] = F[i * 2 + (k & 1)];\n        for (int i = 0; i * 2 < SZ(G); ++i)\
    \ G[i] = G[i * 2];\n        F.resize((SZ(F) + 1 - (k & 1)) / 2);\n        G.resize((SZ(G)\
    \ + 1) / 2);\n    }\n    return F[0] / G[0];\n}\n\n// a_n = \\sum c_j a_(n-j-1)\n\
    template<typename T>\nT find_nth_of_linear_rec(const vector<T> &a, const vector<T>\
    \ &coef, long long n) {\n    int d = SZ(coef);\n    assert(SZ(a) == d);\n    if\
    \ (n < d) return a[n];\n    vector<T> q(d + 1);\n    q[0] = 1;\n    for (int j\
    \ = 0; j < d; ++j) q[j + 1] = -coef[j];\n    vector<T> p = convolution(a, q);\n\
    \    p.resize(d);\n    return bostan_mori(p, q, n);\n}\n"
  code: "#pragma once\n\n#include \"Polynomial/divmod.hpp\"\n\n// [x^k](f(x)/g(x)),\
    \ [x^0]g != 0\ntemplate<typename T>\nT bostan_mori(const vector<T> &f, const vector<T>\
    \ &g, long long k) {\n    assert(!g.empty() && g[0] != 0);\n    if (SZ(f) >= SZ(g))\
    \ {\n        // f = qg + r, [x^k] f/g = [x^k] q + [x^k] r/g\n        auto [q,\
    \ r] = poly_divmod(f, g);\n        return (k < SZ(q) ? q[k] : T(0)) + bostan_mori(r,\
    \ g, k);\n    }\n    if (f.empty()) return T(0);\n    vector<T> F = f, G = g;\n\
    \    for(; k; k >>= 1) {\n        int m = 1;\n        while (m < SZ(G) * 2) m\
    \ <<= 1;\n        int m2 = m >> 1;\n        F.resize(m), G.resize(m);\n      \
    \  NTT<T>::ntt(F), NTT<T>::ntt(G);\n        for (int i = 0; i < m; ++i) F[i] *=\
    \ G[(i + m2) % m];\n        for (int i = 0; i < m2; ++i) {\n            int j\
    \ = i + m2;\n            G[i] = G[j] = G[i] * G[j];\n        }\n        NTT<T>::ntt(F,\
    \ true), NTT<T>::ntt(G, true);\n        for (int i = 0; i * 2 + (k & 1) < SZ(F);\
    \ ++i) F[i] = F[i * 2 + (k & 1)];\n        for (int i = 0; i * 2 < SZ(G); ++i)\
    \ G[i] = G[i * 2];\n        F.resize((SZ(F) + 1 - (k & 1)) / 2);\n        G.resize((SZ(G)\
    \ + 1) / 2);\n    }\n    return F[0] / G[0];\n}\n\n// a_n = \\sum c_j a_(n-j-1)\n\
    template<typename T>\nT find_nth_of_linear_rec(const vector<T> &a, const vector<T>\
    \ &coef, long long n) {\n    int d = SZ(coef);\n    assert(SZ(a) == d);\n    if\
    \ (n < d) return a[n];\n    vector<T> q(d + 1);\n    q[0] = 1;\n    for (int j\
    \ = 0; j < d; ++j) q[j + 1] = -coef[j];\n    vector<T> p = convolution(a, q);\n\
    \    p.resize(d);\n    return bostan_mori(p, q, n);\n}\n"
  dependsOn:
  - Polynomial/divmod.hpp
  - Polynomial/fps_inv.hpp
  - Polynomial/convolution.hpp
  - Polynomial/NTT.hpp
  - Numeric/Modint.hpp
  - Numeric/internal_math.hpp
  - Numeric/internal_primitive_root.hpp
  - Polynomial/helper.hpp
  isVerificationFile: false
  path: Polynomial/bostan_mori.hpp
  requiredBy: []
  timestamp: '2026-10-26 15:25:53+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/kth_term_of_linearly_recurrent_sequence.test.cpp
documentation_of: Polynomial/bostan_mori.hpp
layout: document
redirect_from:
- /library/Polynomial/bostan_mori.hpp
- /library/Polynomial/bostan_mori.hpp.html
title: Polynomial/bostan_mori.hpp
---
