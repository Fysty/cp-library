#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "default_code.hpp"
#include "Polynomial/fps_inv.hpp"

using mint = modint998244353;

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int n;
    cin >> n;
    vector<mint> a(n);
    for(auto &x : a) cin >> x;
    vector<mint> b = fps_inv(a);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
