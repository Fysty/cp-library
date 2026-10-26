#pragma once

#include "Polynomial/power_projection.hpp"
#include "Polynomial/fps_exp.hpp"

// f[0] = 0, f[1] != 0, returns g with f(g(x)) = g(f(x)) = x mod x^n
template<typename T>
vector<T> compositional_inverse(const vector<T>& f) {
    int n = SZ(f);
    assert(n > 0 && f[0] == 0);
    if (n == 1) return {0};
    assert(f[1] != 0);
    int N = n - 1;
    vector<T> w(n);
    w[N] = 1;
    vector<T> p = power_projection(w, f, n), h(N);
    for (int k = 1; k <= N; ++k) h[N - k] = p[k] * N / k;
    T c = h[0].inv(), iN = T(N).inv();
    for (auto& x : h) x *= c;
    h = fps_log(h);
    for (auto& x : h) x *= iN;
    h = fps_exp(h);
    for (auto& x : h) x *= f[1];
    h = fps_inv(h);
    vector<T> g(n);
    for (int i = 0; i < N; ++i) g[i + 1] = h[i];
    return g;
}
