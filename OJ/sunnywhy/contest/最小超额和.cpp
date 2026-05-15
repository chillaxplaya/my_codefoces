/*
最小超额和
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-12 00:51:33
user: playa
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
    int T, n;
    cin >> T >> n;
    vector<int> dp(20001, INF);
    dp[0] = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        for (int j = 20000; j >= x; j--) {
            if (dp[j - x] != INF && dp[j] > dp[j - x] + 1) {
                dp[j] = dp[j - x] + 1;
            }
        }
    }
    debug(dp);
    for (int i = T; ; i++) {
        if (dp[i] != INF) {
            cout << i << " " << dp[i] << endl;
            break;
        }
    }

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