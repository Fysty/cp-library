#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "default_code.hpp"
#include "Polynomial/bostan_mori.hpp"

using mint = modint998244353;

int main()
{
    MottoHayaku
    int d;
    long long k;
    cin >> d >> k;
    vector<mint> a(d), c(d);
    for(auto &x : a) cin >> x;
    for(auto &x : c) cin >> x;
    cout << find_nth_of_linear_rec(a, c, k) << '\n';
}
