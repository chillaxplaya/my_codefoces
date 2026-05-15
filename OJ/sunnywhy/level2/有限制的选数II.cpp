/*
有限制的选数II
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 18:38:21
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
int a[10005];
int ans = 0;
int n, k;
void dfs(int pre, int sum) {
    if (sum == k) {
        ans++;
        return;
    }
    if (sum > k) {
        return;
    }
    for (int i = pre + 1; i < n; i++) {
        for (int j = 1; a[i] * j <= k - sum; j++) {
            dfs(i, a[i] * j + sum);
        }
    }
}
void justdoit() {

    cin >> n >> k;
    rep(i, n) cin >> a[i];
    dfs(-1, 0);
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