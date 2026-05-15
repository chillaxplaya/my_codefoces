/*
D - Many Repunit Sum
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc444/tasks/abc444_d
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
    int n, r;
    cin >> n;
    vector<int> a(500005, 0);
    int maxr = 0;
    rep(i, n) {
        cin >> r;
        a[0]++;
        a[r]--;
        maxr = max(maxr, r);
    }
    for (int i = 1; i <= maxr; i++) {
        a[i] += a[i - 1];
    }
    for (int i = 0; i < maxr; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while (a[maxr] > 0) {
        a[maxr + 1] += a[maxr] / 10;
        a[maxr] %= 10;
        maxr++;
    }
    a.resize(maxr);
    reverse(all(a));
    for (auto &e : a) {
        cout << e;
    }
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