/*
最短距离
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 13:32:26
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
typedef pair<int,int> pi;
void justdoit() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<vector<pi>> g(n);
    vector<int> vis(n, 0);
    vector<int> dis(n, 0x3f3f3f3f);
    int x, y, w;
    rep(i, m) {
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0, s});
    dis[s] = 0;
    while (!qu.empty()) {
        auto [wi, start] = qu.top();
        qu.pop();
        vis[start] = 1;
        for (auto &next : g[start]) {
            debug(start, next.first);
            if (!vis[next.first] && wi + next.second < dis[next.first]) {
                dis[next.first] = wi + next.second;
                qu.push({dis[next.first], next.first});
            }
        }
    }
    debug(dis);
    if (dis[e] != 0x3f3f3f3f)
        cout << dis[e];
    else
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