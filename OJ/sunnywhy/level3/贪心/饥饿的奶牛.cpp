/*
饥饿的奶牛
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 13:15:54
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
#define endl '\n'

void justdoit() {
    int n;
    ll t;
    cin >> n >> t;
    vector<pair<ll, ll>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
    }
    sort(all(a));
    if (a[n - 1].first != t) {
        a.push_back({t, 0});
        n += 1;
    }
    a.push_back({t + 1, 0});
    n += 1;
    ll sum = 0;
    ll ans = t;
    debug(a);
    for (int i = 0; i < n; i++) {
        sum += a[i].second;
        if (sum <= a[i + 1].first - a[i].first) {
            ans -= (a[i + 1].first - a[i].first - sum);
            sum = 0;
        } else {
            sum -= (a[i + 1].first - a[i].first);
        }
        debug(sum);
    }
    cout << ans;
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