/*
最长回文子串
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 09:47:41
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
int dp[105][105];

void justdoit() {
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]){
            dp[i - 1][i] = 2;
            ans = 2;
        }
            
    }
    
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            if (s[j] == s[j + i - 1] && dp[j + 1][j + i - 2]) {
                dp[j][j + i - 1] = dp[j + 1][j + i - 2] + 2;
                ans = max(ans, dp[j][j + i - 1]);
            } 
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