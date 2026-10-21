#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "default_code.hpp"
#include "Polynomial/product_of_polynomials.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int n;
    cin >> n;
    vector<vector<mint>> polys(n);
    for(auto &p : polys) {
        int d;
        cin >> d;
        p.resize(d + 1);
        for(auto &x : p) cin >> x;
    }
    vector<mint> b = product_of_polynomials(polys);
    rep(i, SZ(b)) cout << b[i] << " \n"[i + 1 == SZ(b)];
}
