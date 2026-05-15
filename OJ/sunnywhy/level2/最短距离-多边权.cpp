/*
最短距离-多边权
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 14:08:15
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
typedef tuple<int, int, int> tup;
void justdoit() {
    int n, k, s, e;
    cin >> n >> k >> s >> e;
    vector<vector<tup>> g(n);
    vector<int> vis(n, 0);
    vector<int> dis(n, INF);
    vector<int> cost(n, INF);
    int u, v, d, w; 
    rep(i, k) {
        cin >> u >> v >> d >> w;
        g[u].push_back({v, d, w});
        g[v].push_back({u, d, w});
    }
    priority_queue<tup, vector<tup>, greater<tup>> qu;
    qu.push({0, 0, s});// dis, wi, node
    dis[s] = 0;
    cost[s] = 0;
    while (!qu.empty()) {
        auto [diss, wi, node] = qu.top();
        qu.pop();
        vis[node] = 1;

        for (auto [next, di, co] : g[node]) {
            if (diss + di < dis[next]) {
                dis[next] = diss + di;
                cost[next] =  (wi + co);
                qu.push({dis[next], cost[next], next});
            } else if (diss + di == dis[next]) {
                cost[next] = min(cost[next], wi + co);
                qu.push({dis[next], cost[next], next});
            }
        }

    }
    debug(dis);
    debug(cost);
    cout << dis[e] << " " << cost[e];
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