/*
矩阵最大权值
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 23:44:15
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
int city[1005][1005];
int vis[1005][1005];
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m, k;
int ans = -0x3f3f3f3f;
void dfs(int x, int y, int sum) {
    debug(x, y, sum);
    if (x == n - 1 && y == m - 1) {
        ans = max(ans, sum + city[x][y]);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
            vis[nx][ny] = 1;
            dfs(nx, ny, sum + city[x][y]);
            vis[nx][ny] = 0;
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
    dfs(0, 0, 0);
    cout << (ans);
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