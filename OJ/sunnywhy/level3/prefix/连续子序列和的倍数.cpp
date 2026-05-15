/*
连续子序列和的倍数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 16:22:45
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> premod(x, 0);
    premod[0] = 1;
    int premodnum = 0;
    ll ans = 0;
    for (auto &e : a) {
        cin >> e;
        premodnum = (premodnum + e) % x;
        ans += premod[premodnum];
        premod[premodnum]++;
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