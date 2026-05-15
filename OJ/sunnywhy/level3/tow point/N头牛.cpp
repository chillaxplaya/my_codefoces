/*
N头牛
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 12:35:30
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
    ll n;
    cin >> n;
    ll wi[3];
    rep(i, 3) cin >> wi[i];
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(all(a), [&](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
    int left = 0;
    ll ans = 0;
    for (int right = 0; right < n; right++) {
        while (left <= right && a[left].second < a[right].first) {
            left++;
        }
        debug(right, left);
        ans = max(ans, (left) * wi[2] + (right - left + 1) * wi[1] + (n - right - 1) * wi[0]);
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