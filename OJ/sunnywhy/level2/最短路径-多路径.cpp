/*
最短路径-多路径
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 15:03:09
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
int n, m, s, e;
typedef pair<int, int> pi;
vector<vector<int>> pre;
vector<vector<int>> path;
vector<int> pathtemp;
void dfs(int node) {
    pathtemp.push_back(node);
    if (node == s) {
        path.push_back(pathtemp);
        pathtemp.pop_back();
        return;
    } else {
        for (auto e : pre[node]) {
            dfs(e);
        }
    }
    pathtemp.pop_back();
}
void justdoit() {
    
    cin >> n >> m >> s >> e;
    vector<vector<pi>> g(n);
    vector<int> dis(n, INF);
    vector<int> vis(n);
    pre.resize(n);
    int u, v, d;
    rep(i, m) {
        cin >> u >> v >> d;
        g[u].push_back(make_pair(v, d));
        g[v].push_back(make_pair(u, d));
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0, s});
    dis[s] = 0;
    while (!qu.empty()) {
        auto [w_cost, chs] = qu.top();
        qu.pop();
        vis[chs] = 1;
        for (auto [edge_v, edge_w] : g[chs]) {
            if (!vis[edge_v] && w_cost + edge_w < dis[edge_v]) {
                dis[edge_v] = w_cost + edge_w;
                pre[edge_v].clear();
                pre[edge_v].push_back(chs);
                qu.push(make_pair(dis[edge_v], edge_v));
            } else if (!vis[edge_v] && w_cost + edge_w == dis[edge_v]) {
                dis[edge_v] = w_cost + edge_w;
                pre[edge_v].push_back(chs);
            }
        }
    }
    debug(pre);
    dfs(e);
    debug(path);
    cout << path.size() << endl;
    for (auto &pathnode : path) {
        reverse(all(pathnode));
    }
    sort(all(path));
    for (auto &pathnode : path) {
        for (int i = 0 ; i < pathnode.size(); i++) {
            if (i) cout << "->";
            cout << pathnode[i];
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