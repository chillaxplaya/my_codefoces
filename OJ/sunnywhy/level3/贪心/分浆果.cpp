/*
分浆果
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 16:41:14
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
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    sort(all(a));
    int m = a[n - 1];
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int kk = 0;
        for (int j = 0; j < n; j++) {
            kk += (a[j] / i);
        }
        if (kk <= k / 2) continue;
        if (kk < k) {
            ans = max(ans, (kk - k / 2) * i);
        } else {
            ans = max(ans, (k / 2) * i);
        }
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