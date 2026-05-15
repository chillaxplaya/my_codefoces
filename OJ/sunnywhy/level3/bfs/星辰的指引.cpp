/*
星辰的指引
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 00:00:38
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
typedef pair<int, int> pi;
int grid[205][205];
int vis[205][205];
int bh[40005];
int score[40005];
int idx = 0;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
void justdoit() {
    int n, m;
    cin >> n >> m;
    rep(i, n) {
        rep(j, m) {
            cin >> grid[i][j];
        }
    }
    rep(i, n) {
        rep(j, m) {
            if (grid[i][j] != 0 && !vis[i][j]) {
                int team = idx++;
                queue<pi> qu;
                qu.push({i, j});
                while (!qu.empty()) {
                    auto [x, y] = qu.front();
                    qu.pop();
                    score[team] += grid[x][y];
                    vis[x][y] = 1;
                    if (grid[x][y] == -1) {
                        bh[team] = 1;
                    }
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny] != 0) {
                            qu.push({nx, ny});
                            vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < idx; i++) {
        if (bh[i] == 0 && score[i] > ans) {
            ans = score[i];
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