/*
D. 最小占用时间
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 19:49:51
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
int R[100005], L[100005];
int pre[100005];
int n;
int getpresum(int x) {
    int idx = upper_bound(L, L + n, x) - L - 1;
    if (idx < 0) return 0;
    int p = min(x, R[idx]) - L[idx];
    return idx > 0 ? pre[idx - 1] + p : 0 + p;
}
void justdoit() {
    ll s, t;
    cin >> n >> s >> t;
    rep(i, n) {
        cin >> L[i] >> R[i];
        pre[i] =  R[i] - L[i] + (i > 0 ? pre[i - 1] : 0);
    }
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        maxx = max(maxx, getpresum(L[i] + t) - getpresum(L[i]));
    }
    cout << t - maxx;
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