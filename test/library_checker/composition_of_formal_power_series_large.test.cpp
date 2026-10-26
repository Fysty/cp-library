#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"

#include "default_code.hpp"
#include "Polynomial/composition.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n;
    cin >> n;
    vector<mint> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector<mint> c = composition(a, b);
    rep(i, SZ(c)) cout << c[i] << " \n"[i + 1 == SZ(c)];
}
