/*
八皇后问题
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 18:43:18
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
int col[8];
int dpl[15];
int dpr[15];
int ans = 0;
void dfs(int row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (!col[i] && !dpl[row - i + 7] && !dpr[i + row]) {
            col[i] = 1;
            dpl[row - i + 7] = 1;
            dpr[i + row] = 1;
            dfs(row + 1);
            col[i] = 0;
            dpl[row - i + 7] = 0;
            dpr[i + row] = 0;
        }
    }
}
void justdoit() {
    dfs(0);
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