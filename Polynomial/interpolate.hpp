#pragma once

#include "Polynomial/multipoint.hpp"

// x[i] pairwise distinct, returns f with deg f < n and f(x[i]) = y[i]
// f = \sum_i y[i] / M'(x[i]) * M(x) / (x - x[i]), M(x) = \prod_i (x - x[i])
template<typename T>
vector<T> polynomial_interpolation(const vector<T>& x, const vector<T>& y) {
    assert(x.size() == y.size());
    int n = (int)x.size();
    if (n == 0) return vector<T>();

    // subproduct tree, M[k] = prod_{i in node k} (x - x[i])
    vector<vector<T>> M(4 * n);
    auto build = [&](auto&& self, int k, int l, int r) -> void {
        if (r - l == 1) {
            M[k] = {-x[l], 1};
            return;
        }
        int mid = (l + r) / 2;
        self(self, 2 * k, l, mid), self(self, 2 * k + 1, mid, r);
        M[k] = convolution(M[2 * k], M[2 * k + 1]);
    };
    build(build, 1, 0, n);

    vector<T> dM(n);
    for (int i = 1; i <= n; ++i) dM[i - 1] = M[1][i] * i;
    vector<T> w = multipoint_eval(dM, x);
    for (int i = 0; i < n; ++i) w[i] = y[i] / w[i];

    // f_node = f_L M_R + f_R M_L
    auto calc = [&](auto&& self, int k, int l, int r) -> vector<T> {
        if (r - l == 1) return {w[l]};
        int mid = (l + r) / 2;
        vector<T> a = convolution(self(self, 2 * k, l, mid), M[2 * k + 1]);
        vector<T> b = convolution(self(self, 2 * k + 1, mid, r), M[2 * k]);
        for (int i = 0; i < r - l; ++i) a[i] += b[i];
        return a;
    };
    return calc(calc, 1, 0, n);
}
