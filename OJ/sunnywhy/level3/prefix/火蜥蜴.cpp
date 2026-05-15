/*
火蜥蜴
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 16:53:56
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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    int l = 0;
    int sum = 0;
    int ans = INF;
    for (int r = 0; r < n; r++) {
        cin >> a[r];
        sum += a[r];
        while (l <= r && sum >= k) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    cout << (ans == INF ? -1 : ans);
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