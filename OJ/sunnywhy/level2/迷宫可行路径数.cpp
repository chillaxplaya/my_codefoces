/*
迷宫可行路径数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 19:06:01
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
int city[25][25];
int vis[25][25];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;
int ans = 0;
void dfs(int x, int y) {
    debug(x, y);
    if (x == n - 1 && y == m - 1) {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx >=0 && nextx < n && nexty >= 0 && nexty < m && !city[nextx][nexty] && !vis[nextx][nexty]) {
            vis[nextx][nexty] = 1;
            dfs(nextx, nexty);
            vis[nextx][nexty] = 0;
        }
    }
}
void justdoit() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> city[i][j];
        }
    }
    vis[0][0] = 1;
    dfs(0, 0);
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