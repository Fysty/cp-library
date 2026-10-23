#pragma once

#include "Polynomial/middle_product.hpp"

// returns {f(r^0), f(r^1), ..., f(r^(m - 1))}
template<typename T>
vector<T> chirp_z(const vector<T>& f, T r, int m) {
    int n = SZ(f);
    if (m == 0) return vector<T>();
    if (n == 0) return vector<T>(m);
    if (r == 0) {
        vector<T> res(m, f[0]);
        res[0] = accumulate(f.begin(), f.end(), T(0));
        return res;
    }
    // ij = C(i + j, 2) - C(i, 2) - C(j, 2)
    // f(r^i) = r^-C(i, 2) \sum_j f[j] r^-C(j, 2) r^C(i + j, 2)
    T ir = r.inv();
    vector<T> a(n + m - 1), b(n);
    a[0] = 1;
    T p = 1;
    for (int t = 0; t + 1 < n + m - 1; ++t, p *= r) a[t + 1] = a[t] * p;
    p = 1;
    T q = 1;
    for (int j = 0; j < n; ++j, q *= p, p *= ir) b[j] = f[j] * q;
    vector<T> res = middle_product(a, b);
    p = 1, q = 1;
    for (int i = 0; i < m; ++i, q *= p, p *= ir) res[i] *= q;
    return res;
}

// returns {f(a r^0), f(a r^1), ..., f(a r^(m - 1))}
template<typename T>
vector<T> multipoint_eval_geo(vector<T> f, T a, T r, int m) {
    T p = 1;
    for (auto& x : f) x *= p, p *= a;
    return chirp_z(f, r, m);
}
