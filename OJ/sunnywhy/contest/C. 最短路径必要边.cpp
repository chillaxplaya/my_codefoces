/*
C. 最短路径必要边
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-12 19:53:32
user: playa
*/
#include <bits/stdc++.h>
#include <algorithm>
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
void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> G(n);
    int u, v, w;
    rep(i, m) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    vector<int> dis(n, INF);
    vector<int> vis(n, 0);
    vector<vector<pi>> vecres(n);
    dis[0] = 0;
    qu.push({0, 0});
    while (!qu.empty()) {
        auto [wi, xi] = qu.top();
        qu.pop();
        if (vis[xi]) continue;
        vis[xi] = 1;
        for (auto &[e_next, e_cost] : G[xi]) {
            if (wi + e_cost < dis[e_next]) {
                dis[e_next] = wi + e_cost;
                vecres[e_next].clear();
                vecres[e_next].push_back({xi, e_cost});
                qu.push({dis[e_next], e_next});
            } else if (wi + e_cost == dis[e_next]) {
                vecres[e_next].push_back({xi, e_cost});
            }
        }
    }
    debug(vecres);
    fill(vis.begin(), vis.end(), 0);

    queue<int> prequ;
    prequ.push(n - 1);
    ll ans = 0;
    while (!prequ.empty()) {
        auto xi = prequ.front();
        prequ.pop();
        if (vis[xi]) continue;
        vis[xi] = 1;
        for (auto &[prexi, cost] : vecres[xi]) {
            ans += (cost * 2);
            prequ.push(prexi);
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