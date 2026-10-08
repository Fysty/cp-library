#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"

#include "default_code.hpp"
#include "Polynomial/fps_pow.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n;
    ll m;
    cin >> n >> m;
    vector<mint> a(n);
    for(auto &x : a) cin >> x;
    vector<mint> b = fps_pow(a, m);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
