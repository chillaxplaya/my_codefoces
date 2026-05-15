/*
重复求和
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 16:43:53
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
    int n, k, l, r;
    cin >> n >> k;
    cin >> l >> r;
    vector<ll> pre(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        sum += pre[i];
        pre[i] = pre[i] + (i > 0 ? pre[i - 1] : 0);
    }
    int lk = l / n;
    int rk = r / n;
    rk -= lk;
    cout << rk * sum + pre[r % n] - (l % n > 0 ? pre[l % n - 1] : 0);
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