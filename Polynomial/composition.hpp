#pragma once

#include "Polynomial/fps_inv.hpp"
#include "Polynomial/middle_product.hpp"

// returns f(g(x)) mod x^len(g)
// [x^i] f(g) = \sum_k f[k] [x^i] g^k, so this is the transpose of power_projection(w, g, len(f)) as a map of w,
// running its steps on P backwards. NTT and inverse NTT are symmetric, so each is its own transpose.
template<typename T>
vector<T> composition(const vector<T>& f, vector<T> g) {
    int n = SZ(g), m = SZ(f);
    if (n == 0) return vector<T>();
    if (m == 0) return vector<T>(n);
    int X = 1, D = 1;
    while (X < n) X <<= 1;
    // denominators Q = y^D + (terms of y-degree < D), same as power_projection
    // q[j * 2X + i] = [x^i y^j] (Q - y^D), qs keeps NTT(Q) of every round
    vector<T> q(2 * X);
    for (int i = 0; i < n; ++i) q[i] = -g[i];
    vector<vector<T>> qs;
    while (X > 1) {
        int L = 4 * X * D, H = L / 2;
        q.resize(L);
        q[D * 2 * X] += 1;
        NTT<T>::ntt(q);
        qs.push_back(q);
        for (int t = 0; t < H; ++t) q[t] = q[t] * q[t + H];
        q.resize(H);
        NTT<T>::ntt(q, true);
        q[0] -= 1;
        X /= 2, D *= 2;
        for (int j = 0; j < D; ++j)
            for (int i = X; i < 2 * X; ++i) q[j * 2 * X + i] = 0;
    }
    // transpose of c = rev(P) / rev(Q) mod z^m
    vector<T> rq(D + 1), a = f;
    rq[0] = 1;
    for (int j = 0; j < D; ++j) rq[D - j] = q[2 * j];
    rq.resize(m);
    a.resize(D + m - 1);
    vector<T> rp = middle_product(a, fps_inv(rq)), p(2 * D);
    for (int j = 0; j < D; ++j) p[2 * j] = rp[D - 1 - j];
    // transpose of each round: P -> inverse NTT_H(odd part of NTT_L(P) NTT_L(Q(-x, y))), keeping x-degree < X / 2
    const T gen = internal::primitive_root_constexpr(T::mod()), inv2 = T(2).inv();
    for (; !qs.empty(); qs.pop_back()) {
        X *= 2, D /= 2;
        int L = 4 * X * D, H = L / 2;
        const vector<T>& qh = qs.back();
        NTT<T>::ntt(p, true);
        p.resize(L);
        T iz = gen.pow((T::mod() - 1) / L).inv(), c = inv2;
        for (int t = 0; t < H; ++t, c *= iz) {
            T v = p[t] * c;
            p[t] = v * qh[t + H];
            p[t + H] = -v * qh[t];
        }
        NTT<T>::ntt(p);
        p.resize(H);
        for (int j = 0; j < D; ++j)
            for (int i = X; i < 2 * X; ++i) p[j * 2 * X + i] = 0;
    }
    vector<T> h(n);
    for (int i = 0; i < n; ++i) h[i] = p[X - 1 - i];
    return h;
}
