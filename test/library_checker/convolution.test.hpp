#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "default_code.hpp"
#include "Polynomial/convolution.hpp"

using mint=modint998244353;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<mint> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    vector<mint> c = convolution(a, b);
    rep(i, SZ(c)) cout << c[i] << " \n"[i + 1 == SZ(c)];
}
