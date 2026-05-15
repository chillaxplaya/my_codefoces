/*
C. 最短路径与最大得分
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-14 13:45:35
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
int score[105];
void justdoit() {
    int n, m;
    cin >> n;
    vector<vector<pi>> g(n);
    rep(i, n) {
        cin >> score[i];
    }
    cin >> m;
    int u, v, w;
    rep(i, m) {
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }
    vector<int> dis(n, INF);
    vector<int> vis(n, 0);
    vector<int> gscore(n, -INF);
    gscore[0] = score[0];
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    vector<vector<pi>> path(n);
    qu.push({0, 0});
    dis[0] = 0;
    while (!qu.empty()) {
        auto [i_wi, i_x] = qu.top();
        qu.pop();
        if (vis[i_x]) continue;
        vis[i_x] = 1;
        for (auto &e : g[i_x]) {
            if (i_wi + e.second < dis[e.first]) {
                dis[e.first] = i_wi + e.second;
                gscore[e.first] = gscore[i_x] + score[e.first];
                qu.push({dis[e.first], e.first});
            } else if (i_wi + e.second == dis[e.first]) {
                if (gscore[i_x] + score[e.first] > gscore[e.first]) {
                    gscore[e.first] = gscore[i_x] + score[e.first];
                }
            }
        }
    }
    if (dis[n - 1] != INF)
        cout << dis[n - 1] << " " << gscore[n - 1];
    else 
        cout << "impossible";
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