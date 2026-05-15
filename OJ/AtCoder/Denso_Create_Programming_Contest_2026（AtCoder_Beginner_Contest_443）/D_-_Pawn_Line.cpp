/*
D - Pawn Line
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc443/tasks/abc443_d
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] > a[i] + 1) {
            res += a[i + 1] - (a[i] + 1);
            a[i + 1] = a[i] + 1;
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] > a[i] + 1) {
            res += a[i - 1] - (a[i] + 1);
            a[i - 1] = a[i] + 1;
        }
    }
    debug(a);
    cout << res << "\n";
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