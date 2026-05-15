/*
中位数以上的子序列
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 17:39:04
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
    ll x, a;
    cin >> n >> x;
    vector<int> pre(200005, 0);
    int s = 100000;
    pre[s] = 1;
    int t = 1;
    ll ans = 0;
    rep(i, n) {
        cin >> a;
        if (a >= x) {
            pre[++s] += 1;
            t += pre[s];
        } else {
            t -= pre[s];
            pre[--s] += 1;
            t += 1;
        }
        debug(s, t);
        ans += t - 1;
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