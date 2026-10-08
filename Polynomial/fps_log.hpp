#pragma once

#include "Polynomial/fps_inv.hpp"

template <typename T>
vector<T> fps_log(const vector<T> &F) {
    assert(!F.empty() && F[0] == 1);
    int n = (int)F.size();
    vector<T> dF = F;
    for (int i = 1; i < n; i++) dF[i - 1] = dF[i] * i;
    dF.pop_back();
    vector<T> F_inv = fps_inv(F);
    vector<T> G = convolution(dF, F_inv);
    G.resize(n - 1);
    G.insert(G.begin(), 0);
    for (int i = 1; i < n; i++) G[i] /= i;
    return G;
}