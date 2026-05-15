/*
C. Number of Pairs
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1538/C
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    rep(i ,n) cin >> a[i];
    sort(all(a));
    ll res = 0;
    for (int i = 1; i < n; i++) {
        int l1 = lower_bound(a.begin(), a.begin() + i, l - a[i]) - a.begin();
        int r1 = lower_bound(a.begin(), a.begin() + i, r - a[i] + 1) - a.begin();
        res += (1LL) * (r1 - l1);
    }
    cout << res << '\n';
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}