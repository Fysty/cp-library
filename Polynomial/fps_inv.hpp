#pragma once

#include "Polynomial/convolution.hpp"

template <typename T>
vector<T> fps_inv(const vector<T>& F) {
    assert(!F.empty() && F[0] != 0);
    int n = (int)F.size();
    assert((int)bit_ceil((unsigned)n) <= NTT<T>::ntt_max_limit && "the result length exceeds the support limit of the modulo");
    vector<T> G = {F[0].inv()};
    G.reserve(n);
    int sz = 1;
    while (sz < n) {
        vector<T> f(sz * 2), g(sz * 2);
        for (int i = 0; i < min(n, sz * 2); i++) f[i] = F[i];
        for (int i = 0; i < sz; i++) g[i] = G[i];
        NTT<T>::ntt(f), NTT<T>::ntt(g);
        for (int i = 0; i < sz * 2; i++) f[i] *= g[i];
        NTT<T>::ntt(f, true);
        for (int i = 0; i < sz; i++) f[i] = 0;
        NTT<T>::ntt(f);
        for (int i = 0; i < sz * 2; i++) f[i] *= g[i];
        NTT<T>::ntt(f, true);
        for (int i = sz; i < min(n, sz * 2); i++) G.emplace_back(-f[i]);
        sz *= 2;
    }
    return G;
}