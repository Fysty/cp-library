#pragma once

// removes trailing zeros, the zero polynomial is empty
template<typename T>
void poly_trim(vector<T>& f) {
    while (!f.empty() && f.back() == 0) f.pop_back();
}

// returns a + b, trimmed
template<typename T>
vector<T> poly_add(vector<T> a, const vector<T>& b) {
    if (SZ(a) < SZ(b)) a.resize(SZ(b));
    for (int i = 0; i < SZ(b); ++i) a[i] += b[i];
    poly_trim(a);
    return a;
}

// returns a / x^k, dropping the lowest k coefficients
template<typename T>
vector<T> poly_shr(const vector<T>& a, int k) {
    if (SZ(a) <= k) return vector<T>();
    return vector<T>(a.begin() + k, a.end());
}
