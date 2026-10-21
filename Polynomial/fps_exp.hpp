#pragma once

#include "Polynomial/fps_log.hpp"

template <typename T>
vector<T> fps_exp(const vector<T>& F) {
    int n = (int)F.size();
    assert(n > 0 && F[0] == 0);
    assert((int)bit_ceil((unsigned)n) <= NTT<T>::ntt_max_limit && "the result length exceeds the support limit of the modulo");
    vector<T> G = {1}, H = {1};
    G.reserve(n), H.reserve(n);
    int sz = 1;
    while (sz < n) {
        vector<T> df(sz * 2), g(sz * 2), h(sz * 2);
        for (int i = 0; i < sz; i++) g[i] = G[i];
        for (int i = 0; i < sz; i++) h[i] = H[i];
        for (int i = 1; i < min(n, sz * 2); i++) df[i - 1] = F[i] * i;
        NTT<T>::ntt(df), NTT<T>::ntt(g), NTT<T>::ntt(h);

        for (int i = 0; i < sz * 2; i++) df[i] *= g[i];
        NTT<T>::ntt(df, true);
        for (int i = 0; i < sz - 1; i++) df[i] = 0;
        NTT<T>::ntt(df);
        for (int i = 0; i < sz * 2; i++) df[i] *= h[i];
        NTT<T>::ntt(df, true);
        for (int i = 0; i < sz - 1; i++) df[i] = 0;
        for (int i = sz * 2 - 2; i >= 0; i--) df[i + 1] = df[i] / (i + 1);
        NTT<T>::ntt(df);
        for (int i = 0; i < sz * 2; i++) df[i] *= g[i];
        NTT<T>::ntt(df, true);
        for (int i = sz; i < min(n, sz * 2); i++) G.emplace_back(df[i]);
        
        for (int i = 0; i < min(n, sz * 2); i++) g[i] = G[i];
        NTT<T>::ntt(g);
        for (int i = 0; i < sz * 2; i++) g[i] *= h[i];
        NTT<T>::ntt(g, true);
        for (int i = 0; i < sz; i++) g[i] = 0;
        NTT<T>::ntt(g);
        for (int i = 0; i < sz * 2; i++) g[i] *= h[i];
        NTT<T>::ntt(g, true);
        for (int i = sz; i < min(n, sz * 2); i++) H.emplace_back(-g[i]);
        sz *= 2;
    }
    return G;
}
