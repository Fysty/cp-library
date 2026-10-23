#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include "default_code.hpp"
#include "Polynomial/chirp_z.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n, m;
    mint a, r;
    cin >> n >> m >> a >> r;
    vector<mint> c(n);
    for(auto &x : c) cin >> x;
    vector<mint> b = multipoint_eval_geo(c, a, r, m);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
