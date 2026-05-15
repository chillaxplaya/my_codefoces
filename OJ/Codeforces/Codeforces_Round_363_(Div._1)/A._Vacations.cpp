/*
A. Vacations
Time Limit: 1000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/698/A
*/
#include <bits/stdc++.h>
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
//[dp] = [{{1,1061109567,1061109567,1061109567},{2,1061109567,1061109567,1061109567},{3,1061109567,1061109567,1061109567},{4,1061109567,1061109567,1061109567}}]
void justdoit() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(4, 0x3f3f3f3f));
    vector<int> d(n); //day
    rep(i, n) cin >> d[i];
    dp[0][d[0] & 1] = 0;
    dp[0][d[0] & 2] = 0;
    debug(d[0] & 1);
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (d[i] & 1) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if (d[i] & 2) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1],dp[i - 1][2])) + 1;
    }
    debug(dp);
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

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