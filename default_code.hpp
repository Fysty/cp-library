#pragma once

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define MottoHayaku ios::sync_with_stdio(false); cin.tie(0);
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i <= n; i++)
#define F first
#define S second
#define pb push_back
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
template<class A, class B>
ostream& operator<<(ostream& os, const pair<A, B> &a) {
    os << "(" << a.first << ", " << a.second << ")";
    return os;
}
template <typename T>
concept PrintableContainer = requires(T& a) {
    a.begin();
    a.end();
} && !std::same_as<std::remove_cvref_t<T>, std::string> &&
     !std::same_as<std::remove_cvref_t<T>, std::string_view> &&
     !std::is_convertible_v<T, const char*>;
template <PrintableContainer T>
std::ostream& operator<<(std::ostream& os, const T& a) {
    os << "[ ";
    bool first = true;
    for (const auto& item : a) {
        if (!first) os << ", ";
        os << item;
        first = false;
    }
    return os << " ]";
}
#ifdef fysty
#include <experimental/iterator>
#define safe cerr<<__PRETTY_FUNCTION__<<" line "<<__LINE__<<" safe\n"
#define sepline sepline_() 
#define debug(a...) debug_(#a, a)
#define orange(a...) orange_(#a, a)
void debug_(auto s, auto ...a) {
    cerr << "\e[1;32m(" << s << ") = (";
    int f = 0;
    (..., (cerr << (f++ ? ", " : "") << a));
    cerr << ")\e[0m\n";
}
void sepline_(int length = 50) {
    cerr << "\e[1;35m";
    cerr << string(length, '=');
    cerr << "\e[0m\n";
}
#else
#define safe ((void)0)
#define sepline safe
#define debug(...) safe
#define orange(...) safe
#endif

void chmax(auto &x, auto val) {
    x = max(x, val);
}

void chmin(auto &x, auto val) {
    x = min(x, val);
}

template<class T>
void discretization(vector<T> &vals) {
    ranges::sort(vals);
    vals.erase(ranges::unique(vals).begin(), vals.end());
}
