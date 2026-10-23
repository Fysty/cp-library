#pragma once

#include "Polynomial/fps_inv.hpp"
#include "Polynomial/middle_product.hpp"

// returns {f(x[0]), ..., f(x[m - 1])}
template<typename T>
vector<T> multipoint_eval(const vector<T>& f, const vector<T>& x) {
    int n = (int)f.size(), m = (int)x.size();
    if (m == 0) return vector<T>();
    if (n == 0) return vector<T>(m);

    vector<vector<T>> Q(4 * m);
    auto build = [&](auto&& self, int k, int l, int r) -> void {
        if (r - l == 1) {
            Q[k] = {1, -x[l]};
            return;
        }
        int mid = (l + r) / 2;
        self(self, 2 * k, l, mid), self(self, 2 * k + 1, mid, r);
        Q[k] = convolution(Q[2 * k], Q[2 * k + 1]);
    };
    build(build, 1, 0, m);

    vector<T> q = Q[1];
    q.resize(n);
    vector<T> a = f;
    a.resize(n + m - 1);
    vector<T> root = middle_product(a, fps_inv(q));

    // transpose of N = N_L Q_R + N_R Q_L, going top-down
    vector<T> res(m);
    auto down = [&](auto&& self, int k, int l, int r, const vector<T>& u) -> void {
        if (r - l == 1) {
            res[l] = u[0];
            return;
        }
        int mid = (l + r) / 2;
        self(self, 2 * k, l, mid, middle_product(u, Q[2 * k + 1]));
        self(self, 2 * k + 1, mid, r, middle_product(u, Q[2 * k]));
    };
    down(down, 1, 0, m, root);
    return res;
}