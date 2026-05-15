/*
矩阵中的块
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 00:38:49
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
int c[1005][1005];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void justdoit() {
    int n, m;
    cin >> n >> m;
    rep(i, n) {
        rep(j, m) {
            cin >> c[i][j];
        }
    }
    queue<pair<int, int>> qu;
    int cnt = 0;
    rep(i, n) {
        rep(j, m) {

            if (c[i][j]) {
                cnt++;
                qu.push({i, j});
                c[i][j] = 0;
                while (!qu.empty()) {
                    auto [x, y] = qu.front();
                    qu.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dir[i][0];
                        int ny = y + dir[i][1];
                        if (nx >= 0 && nx < n && ny >= 0 && ny < m && c[nx][ny]) {
                            c[nx][ny] = 0;
                            qu.push({nx, ny});
                        }
                    }
                }
            }

        }
    }
    cout << cnt;
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