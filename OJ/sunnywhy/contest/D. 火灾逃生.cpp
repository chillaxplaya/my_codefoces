/*
D. 火灾逃生
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 20:03:34
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
char city[105][105];
int dis[105][105];
int vis[105][105];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void justdoit() {
    int n, m;
    cin >> n >> m;
    queue<pi> qu;
    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> city[i][j];
            if (city[i][j] == 'E') {
                tx = i;
                ty = j;
            } else if (city[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (city[i][j] == 'F') {
                qu.push({i * m + j, 2});
            }
        }
    }

    qu.push({sx * m + sy, 1});

    while (!qu.empty()) {
        auto [xy, type] = qu.front();
        qu.pop();
        int x = xy / m;
        int y = xy % m;
        debug(x, y);
        vis[x][y] = 1;
        if (type == 2) {
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    city[nx][ny] == '.') {
                    city[nx][ny] = 'F';
                    qu.push({nx * m + ny, 2});
                    vis[nx][ny] = 1;
                }
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    city[nx][ny] == '.' && !vis[nx][ny]) {
                    qu.push({nx * m + ny, 1});
                    dis[nx][ny] = dis[x][y] + 1;
                    vis[nx][ny] = 1;
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    city[nx][ny] == 'E') {
                    cout << dis[x][y] + 1;
                    return;
                }
            }
        }
    }
    cout << "IMPOSSIBLE";
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