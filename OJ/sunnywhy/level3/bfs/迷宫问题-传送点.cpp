/*
迷宫问题-传送点
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 15:06:20
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
int dis[105][105];
int city[105][105];
vector<pi> all2;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
void justdoit() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> city[i][j];
            if (city[i][j] == 2) {
                all2.push_back({i, j});
            }
        }
    }

    queue<pi> qu;
    qu.push({0, 0});
    city[0][0] = 1;
    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();
        if (x == n - 1 && y == m - 1) {
            cout << dis[x][y] << endl;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (city[nx][ny] == 0 || city[nx][ny] == 2) {
                    dis[nx][ny] = dis[x][y] + 1;
                    if (city[nx][ny] == 0) city[nx][ny] = 1;
                    qu.push({nx, ny});
                }
                if (city[nx][ny] == 2) {
                    for (auto [tx, ty] : all2) {
                        dis[tx][ty] = dis[x][y] + 1;
                        city[tx][ty] = 1;
                        qu.push({tx, ty});
                    }
                }
            }
        }
    }
    cout << -1;
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