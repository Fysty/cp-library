#pragma once

#include "Polynomial/fps_exp.hpp"

template <typename T>
vector<T> fps_pow(const vector<T>& F, long long k) {
    assert(k >= 0);
    int n = (int)F.size();
    if (k == 0) {
        vector<T> res(n);
        res[0] = 1;
        return res;
    }
    int d = 0;
    while (d < n && F[d] == 0) d++;
    if (d >= (n + k - 1) / k) return vector<T>(n, T(0));
    
    T alpha = F[d], alpha_inv = alpha.inv();
    vector<T> G(F.begin() + d, F.begin() + (d + n - d * k));
    for (int i = 0; i < (int)G.size(); i++) G[i] *= alpha_inv;
    G = fps_log(G);
    for (int i = 0; i < (int)G.size(); i++) G[i] *= k;
    G = fps_exp(G);
    T alpha_k = alpha.pow(k);
    for (int i = 0; i < (int)G.size(); i++) G[i] *= alpha_k;
    G.insert(G.begin(), d * k, 0);
    return G;
}