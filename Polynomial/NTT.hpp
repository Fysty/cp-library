#pragma once

#include "Numeric/Modint.hpp"
#include "Numeric/internal_primitive_root.hpp"

template<typename T>
requires std::derived_from<T, internal::modint_base>
class NTT {
    inline static int max_size = 1;
    inline static std::vector<T> w{1, T(1)};
    inline static const T root = internal::primitive_root_constexpr(T::mod());
    static void ensure_root_table_size(int n) {
        if (max_size < n) {
            while (max_size <= n) max_size <<= 1;
            w.resize(max_size);
            std::ranges::fill(w, 1);
            T dw = root.pow((T::mod() - 1) / max_size);
            for (int s = max_size / 2; s; s >>= 1, dw *= dw) {
                w[s] = 1;
                for (int j = 1; j < s; ++j) 
                    w[s + j] = w[s + j - 1] * dw;
            }
        }
    }
public:
    static constexpr int ntt_max_limit = []() {
        unsigned int m = T::mod() - 1;
        int limit = 1;
        while ((m & 1) == 0) {
            limit <<= 1;
            m >>= 1;
        }
        return limit;
    }();
    /*
    0 <= a[i] < mod
    a.size() must be a power of 2
    */
    static void ntt(vector<T> &a, bool inv = false) {
        int n = a.size();
        assert((n & (n - 1)) == 0);
        ensure_root_table_size(n);
        for (int i = 0, j = 1; j < n - 1; ++j) {
            for (int k = n >> 1; (i ^= k) < k; k >>= 1);
            if (j < i) swap(a[i], a[j]);
        }
        for (int s = 1; s < n; s <<= 1) {
            for (int i = 0; i < n; i += s * 2) {
                for (int j = 0; j < s; ++j) {
                    T tmp = a[i + s + j] * w[s + j];
                    a[i + s + j] = a[i + j] - tmp;
                    a[i + j] += tmp;
                }
            }
        }
        if (!inv) return;
        T iv = T(n).inv(); 
        reverse(a.begin() + 1, a.begin() + n);
        for (int i = 0; i < n; ++i) a[i] *= iv;
    }
    static size_t maxsize() {
        return max_size;
    }
    static vector<T> convolution(vector<T> a, vector<T> b) {
        if (a.empty() || b.empty()) return vector<T>();
        int n = 1, sz = int(a.size()) + int(b.size()) - 1;
        while (n < sz) n <<= 1;
        assert(n <= ntt_max_limit && "the result length exceeds the support limit of the modulo");
        a.resize(n), b.resize(n);
        ntt(a), ntt(b);
        for (int i = 0; i < n; ++i)
            a[i] = a[i] * b[i];
        ntt(a, true);
        a.resize(sz);
        return a;
    }
};