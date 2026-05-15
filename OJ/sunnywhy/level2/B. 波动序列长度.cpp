/*
B. 波动序列长度
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 19:37:48
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
    cin >> n;
    vector<int> a(n);
    vector<int> dpi(n, 0);
    vector<int> dpd(n, 0);
    dpi[0] = dpd[0] = 1;
    for (auto &e : a) {
        cin >> e;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            dpi[i] = dpd[i - 1] + 1;
            dpd[i] = dpd[i - 1];
            ans = max(ans, dpi[i]);
        } else if (a[i] < a[i - 1]) {
            dpd[i] = dpi[i - 1] + 1;
            dpi[i] = dpi[i - 1];
            ans = max(ans, dpd[i]);
        } else {
            dpd[i] = dpd[i - 1];
            dpi[i] = dpi[i - 1];
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