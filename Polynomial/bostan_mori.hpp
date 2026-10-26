#pragma once

#include "Polynomial/divmod.hpp"

// [x^k](f(x)/g(x)), [x^0]g != 0
template<typename T>
T bostan_mori(const vector<T> &f, const vector<T> &g, long long k) {
    assert(!g.empty() && g[0] != 0);
    if (SZ(f) >= SZ(g)) {
        // f = qg + r, [x^k] f/g = [x^k] q + [x^k] r/g
        auto [q, r] = poly_divmod(f, g);
        return (k < SZ(q) ? q[k] : T(0)) + bostan_mori(r, g, k);
    }
    if (f.empty()) return T(0);
    vector<T> F = f, G = g;
    for(; k; k >>= 1) {
        int m = 1;
        while (m < SZ(G) * 2) m <<= 1;
        int m2 = m >> 1;
        F.resize(m), G.resize(m);
        NTT<T>::ntt(F), NTT<T>::ntt(G);
        for (int i = 0; i < m; ++i) F[i] *= G[(i + m2) % m];
        for (int i = 0; i < m2; ++i) {
            int j = i + m2;
            G[i] = G[j] = G[i] * G[j];
        }
        NTT<T>::ntt(F, true), NTT<T>::ntt(G, true);
        for (int i = 0; i * 2 + (k & 1) < SZ(F); ++i) F[i] = F[i * 2 + (k & 1)];
        for (int i = 0; i * 2 < SZ(G); ++i) G[i] = G[i * 2];
        F.resize((SZ(F) + 1 - (k & 1)) / 2);
        G.resize((SZ(G) + 1) / 2);
    }
    return F[0] / G[0];
}

// a_n = \sum c_j a_(n-j-1)
template<typename T>
T find_nth_of_linear_rec(const vector<T> &a, const vector<T> &coef, long long n) {
    int d = SZ(coef);
    assert(SZ(a) == d);
    if (n < d) return a[n];
    vector<T> q(d + 1);
    q[0] = 1;
    for (int j = 0; j < d; ++j) q[j + 1] = -coef[j];
    vector<T> p = convolution(a, q);
    p.resize(d);
    return bostan_mori(p, q, n);
}
