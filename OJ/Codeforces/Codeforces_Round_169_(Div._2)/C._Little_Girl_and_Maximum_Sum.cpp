/*
C. Little Girl and Maximum Sum
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/276/C
*/
#include <algorithm>
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
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    int l, r;
    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cnt[l - 1]++;
        cnt[r]--;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    sort(all(a));
    sort(cnt.begin(),cnt.begin() + n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += cnt[i] * a[i];
    }
    debug(a);
    debug(cnt);
    cout << sum;
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}