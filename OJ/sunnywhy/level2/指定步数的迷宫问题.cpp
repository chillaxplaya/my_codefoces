/*
指定步数的迷宫问题
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
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m, k;
int ans = 0;
void dfs(int x, int y, int kk) {
    debug(x, y, kk);
    if (x == n - 1 && y == m - 1 && kk == k) {
        ans++;
        return;
    }
    if (kk == k) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !city[nx][ny]) {
            city[nx][ny] = 1;
            dfs(nx, ny, kk + 1);
            city[nx][ny] = 0;
        }
    }
}
void justdoit() {

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
        }
    }
    dfs(0, 0, 0);
    cout << (ans ? "Yes" : "No");
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