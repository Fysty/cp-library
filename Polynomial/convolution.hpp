#pragma once

#include "Polynomial/NTT.hpp"

template<typename T>
vector<T> convolution(vector<T> a, vector<T> b) {
    if (a.empty() || b.empty()) return vector<T>();
    int n = 1, sz = int(a.size()) + int(b.size()) - 1;
    while (n < sz) n <<= 1;
    assert(n <= NTT<T>::ntt_max_limit && "the result length exceeds the support limit of the modulo");
    a.resize(n), b.resize(n);
    NTT<T>::ntt(a), NTT<T>::ntt(b);
    for (int i = 0; i < n; ++i)
        a[i] = a[i] * b[i];
    NTT<T>::ntt(a, true);
    a.resize(sz);
    return a;
}