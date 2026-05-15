/*
冰淇淋的优化
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 12:22:15
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

char city[1005][1005];
int vis[1005][1005];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void justdoit() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >>city[i][j];
        }
    }
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (city[i][j] == '#' && !vis[i][j]) {
                int peri = 0, count = 0;
                queue<pair<int, int>> qu;
                qu.push({i, j});
                while (!qu.empty()) {
                    auto [x, y] = qu.front();
                    qu.pop();
                    if (vis[x][y]) continue;
                    vis[x][y] = 1;
                    count++;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dir[k][0];
                        int ny = y + dir[k][1];
                        if (nx >= 0 && nx < n && ny >=0 && ny < n) {
                            if (city[nx][ny] == '#' && !vis[nx][ny]) {
                                qu.push({nx, ny});
                            } else if (city[nx][ny] == '.') {
                                peri++;
                            }
                        } else {
                            peri++;
                        }
                    }
                }
                res.push_back({count, peri});
            }
        }
    }
    sort(res.begin(), res.end(), [&](const pi &a, const pi &b) {
        return (a.first == b.first ? a.second < b.second : a.first > b.first);
    });
    cout << res[0].first << " " << res[0].second;
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