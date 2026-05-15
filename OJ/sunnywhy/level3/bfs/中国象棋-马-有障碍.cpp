/*
中国象棋-马-无障碍
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 15:48:01
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
int city[105][105];
int dir[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int dir1[8][2] = {{0, -1}, {-1, 0}, {-1, 0}, {0, 1}, {0, 1}, {1, 0}, {1, 0}, {0, -1}};
void justdoit() {
    int n, m, init_x, init_y;
    cin >> n >> m >> init_x >> init_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            city[i][j] = -1;
        }
    }
    int l, tx, ty;
    cin >> l;

    rep(i, l) {
        cin >> tx >> ty;
        city[tx - 1][ty - 1] = INF;
    }
    city[init_x - 1][init_y - 1] = 0;
    queue<pi> qu;
    qu.push({init_x - 1, init_y - 1});
    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            int nnx = x + dir1[i][0];
            int nny = y + dir1[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && city[nx][ny] == -1 && city[nnx][nny] != INF) {
                city[nx][ny] = city[x][y] + 1;
                qu.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j) cout << " ";
            if (city[i][j] != INF)
                cout << city[i][j];
            else 
                cout << -1;
        }
        cout << endl;
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