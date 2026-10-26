#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"

#include "default_code.hpp"
#include "Polynomial/compositional_inverse.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n;
    cin >> n;
    vector<mint> a(n);
    for(auto &x : a) cin >> x;
    vector<mint> b = compositional_inverse(a);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
