#pragma once

#include "Polynomial/fps_inv.hpp"
#include "Polynomial/helper.hpp"

// returns {q, r} with f = q g + r, deg r < deg g
template<typename T>
pair<vector<T>, vector<T>> poly_divmod(vector<T> f, vector<T> g) {
    poly_trim(f), poly_trim(g);
    assert(!g.empty());
    int n = SZ(f), m = SZ(g);
    if (n < m) return {vector<T>(), f};
    // rev(q) = rev(f) / rev(g) mod x^(n - m + 1)
    int k = n - m + 1;
    vector<T> rf(f.rbegin(), f.rbegin() + k), rg(g.rbegin(), g.rend());
    rg.resize(k);
    vector<T> q = convolution(rf, fps_inv(rg));
    q.resize(k);
    reverse(q.begin(), q.end());
    vector<T> qg = convolution(q, g);
    vector<T> r(f.begin(), f.begin() + m - 1);
    for (int i = 0; i < m - 1; ++i) r[i] -= qg[i];
    poly_trim(q), poly_trim(r);
    return {q, r};
}
