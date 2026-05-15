/*
相等前后缀
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 17:38:51
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
    vector<int> pre(n);
    vector<int> suf(n);
    for (auto &e : a) {
        cin >> e;
    }
    for (int i = 0; i < n; i++) {
        pre[i] = i > 0 ? pre[i - 1] + a[i] : a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = i < n - 1 ? suf[i + 1] + a[i] : a[i];
    }
    debug(pre);
    debug(suf);
    int ans = 0;
    for (int i = n - 1; i > 0; i--) {
        int l = 0, r = i;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (pre[mid] >= suf[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l != i && pre[l] == suf[i]) {
            ans = max(ans, n - i + l + 1);
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