#pragma once

#include "Polynomial/NTT.hpp"

// len(a) >= len(b)
// c[i] = sum_j b[j]a[i+j], deg = len(a) - len(b)
template<typename T>
vector<T> middle_product(vector<T> a, vector<T> b) {
    int na = (int)a.size(), nb = (int)b.size();
    assert(na >= nb);
    if (nb == 0) return vector<T>();
    // c[i] = (a * rev(b))[i + nb - 1]; a cyclic convolution of length >= na
    // only wraps onto indices < nb - 1, which are discarded
    int n = 1;
    while (n < na) n <<= 1;
    assert(n <= NTT<T>::ntt_max_limit && "the result length exceeds the support limit of the modulo");
    reverse(b.begin(), b.end());
    a.resize(n), b.resize(n);
    NTT<T>::ntt(a), NTT<T>::ntt(b);
    for (int i = 0; i < n; ++i)
        a[i] *= b[i];
    NTT<T>::ntt(a, true);
    return vector<T>(a.begin() + nb - 1, a.begin() + na);
}
