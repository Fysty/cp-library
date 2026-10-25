#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "default_code.hpp"
#include "Polynomial/divmod.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n, m;
    cin >> n >> m;
    vector<mint> f(n), g(m);
    for(auto &x : f) cin >> x;
    for(auto &x : g) cin >> x;
    auto [q, r] = poly_divmod(f, g);
    cout << SZ(q) << ' ' << SZ(r) << '\n';
    rep(i, SZ(q)) cout << q[i] << ' ';
    cout << '\n';
    rep(i, SZ(r)) cout << r[i] << ' ';
    cout << '\n';
}
