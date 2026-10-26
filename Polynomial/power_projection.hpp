#pragma once

#include "Polynomial/fps_inv.hpp"

// returns {\sum_i w[i] [x^i] f^k}_{k < m}
// \sum_k y^(-k-1) \sum_i w[i] [x^i] f^k = [x^(X-1)] P(x, y) / Q(x, y), P = \sum_i w[i] x^(X-1-i), Q = y - f(x)
// Bostan-Mori on x, X is a power of 2 and Q = y^D + (terms of y-degree < D) throughout
template<typename T>
vector<T> power_projection(const vector<T>& w, vector<T> f, int m) {
    if (m == 0) return vector<T>();
    int n = SZ(w);
    if (n == 0) return vector<T>(m);
    f.resize(n);
    int X = 1, D = 1;
    while (X < n) X <<= 1;
    // p[j * 2X + i] = [x^i y^j] P, q[j * 2X + i] = [x^i y^j] (Q - y^D), i < X, j < D
    vector<T> p(2 * X), q(2 * X);
    for (int i = 0; i < n; ++i) p[X - 1 - i] = w[i], q[i] = -f[i];
    const T g = internal::primitive_root_constexpr(T::mod()), inv2 = T(2).inv();
    while (X > 1) {
        // the products have x-degree < 2X and y-degree <= 2D, so a cyclic NTT of length L = 4XD works,
        // with y^(2D) wrapping onto y^0
        int L = 4 * X * D, H = L / 2;
        p.resize(L), q.resize(L);
        q[D * 2 * X] += 1;
        NTT<T>::ntt(p), NTT<T>::ntt(q);
        // NTT(Q(-x, y))[t] = NTT(Q)[t + H], so with U = P(x, y) Q(-x, y), V = Q(x, y) Q(-x, y):
        // NTT(odd part of U)[t] = (U[t] - U[t + H]) / 2z^t, NTT(even part of V)[t] = V[t]
        T iz = g.pow((T::mod() - 1) / L).inv(), c = inv2;
        for (int t = 0; t < H; ++t, c *= iz) {
            p[t] = (p[t] * q[t + H] - p[t + H] * q[t]) * c;
            q[t] = q[t] * q[t + H];
        }
        p.resize(H), q.resize(H);
        NTT<T>::ntt(p, true), NTT<T>::ntt(q, true);
        q[0] -= 1;
        // now laid out as [x^i y^j] at j * X + i, keep x-degree < X / 2
        X /= 2, D *= 2;
        for (int j = 0; j < D; ++j)
            for (int i = X; i < 2 * X; ++i) p[j * 2 * X + i] = q[j * 2 * X + i] = 0;
    }
    // [x^0] P / Q, P(y) = \sum_k c[k] y^(-k-1) Q(y): with z = 1/y, \sum_k c[k] z^k = rev(P) / rev(Q)
    vector<T> rp(D), rq(D + 1);
    rq[0] = 1;
    for (int j = 0; j < D; ++j) rp[D - 1 - j] = p[2 * j], rq[D - j] = q[2 * j];
    rq.resize(m);
    vector<T> res = convolution(rp, fps_inv(rq));
    res.resize(m);
    return res;
}
