#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "default_code.hpp"
#include "Polynomial/multipoint.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n, m;
    cin >> n >> m;
    vector<mint> c(n), p(m);
    for(auto &x : c) cin >> x;
    for(auto &x : p) cin >> x;
    vector<mint> b = multipoint_eval(c, p);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
