/*
D. 网格连通性查询
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 20:14:32
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
char grid[1005][1005];
char vis[1005][1005];
int team[250010];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int teamid = 0;
void justdoit() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if ((grid[i][j] == 'A' || grid[i][j] == 'B') && (!vis[i][j])) {
                char cc = grid[i][j];
                int getid = teamid++;
                queue<pi> qu;
                qu.push({i, j});
                vis[i][j] = 1;
                team[i * c + j] = getid;
                while (!qu.empty()) {
                    auto [x, y] = qu.front();
                    qu.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dir[i][0];
                        int ny = y + dir[i][1];
                        if (nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] == cc && !vis[nx][ny]) {
                            vis[nx][ny] = 1;
                            team[nx * c + ny] = getid;
                            qu.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    int m;
    cin >> m;
    int x1, y1, x2, y2;
    rep(i, m) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;x2--;y1--;y2--;
        if (grid[x1][y1] != grid[x2][y2]) {
            cout << "neither" << endl;
            continue;
        } else if (team[x1 * c + y1] == team[x2 * c + y2]){
            cout << grid[x1][y1] << endl;
            continue;
        }
        cout << "neither" << endl;
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