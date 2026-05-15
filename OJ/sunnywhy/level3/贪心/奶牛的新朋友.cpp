/*
奶牛的新朋友
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 18:18:40
*/
#include <bits/stdc++.h>
#include <unordered_map>
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
char farm[1005][1005];
int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
void justdoit() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> farm[i][j];
        }
    }
    int cnt = 0;
    set<pair<int, int>> vis;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (farm[i][j] == 'G') {
                int fx = -1, fy = -1, gx = -1, gy = -1;
                vector<pair<int, int>> node;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dir[d][0];
                    int ny = j + dir[d][1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && farm[nx][ny] == 'C') {
                        node.push_back({nx, ny});
                    }
                }
                if (node.size() < 2) break;
                for (int i = 0; i < node.size(); i++) {
                    for (int j = i + 1; j < node.size(); j++) {
                        fx = node[i].first;
                        fy = node[i].second;
                        gx = node[j].first;
                        gy = node[j].second;
                        debug(fx, fy, gx, gy);
                        int find1 = fx * m + fy;
                        int find2 = gx * m + gy;
                        if (gx != -1 && !vis.count(make_pair(find1, find2))) {
                            vis.insert({find1, find2});
                            vis.insert({find2, find1});
                            // vis[fx][fy] = vis[gx][gy] = 1;
                            cnt++;
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