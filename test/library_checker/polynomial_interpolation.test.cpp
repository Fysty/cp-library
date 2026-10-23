#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include "default_code.hpp"
#include "Polynomial/interpolate.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n;
    cin >> n;
    vector<mint> x(n), y(n);
    for(auto &v : x) cin >> v;
    for(auto &v : y) cin >> v;
    vector<mint> b = polynomial_interpolation(x, y);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
