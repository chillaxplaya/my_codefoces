/*
C. Basketball Exercise
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1195/C
*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

void justdoit() {
    int n;
    cin >> n;
    vector<ll> team[2];
    team[0].resize(n);
    team[1].resize(n);

    rep(i, n) cin >> team[0][i];
    rep(i, n) cin >> team[1][i];
    vector<vector<ll>> dp(3, vector<ll>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + team[0][i - 1];
        dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + team[1][i - 1];
        dp[2][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
    }
    cout << max(dp[0][n], max(dp[1][n], dp[2][n]));
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