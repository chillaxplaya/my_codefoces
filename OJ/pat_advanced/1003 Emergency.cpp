/*
${title}
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define eps 1E-12
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

typedef pair<int, int> pi;
void justdoit() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;

    vector<int> rt(n);
    vector<int> dis(n, INF);
    vector<int> vis(n, 0);
    vector<vector<pi>> g(n);
    vector<int> rt_num(n);
    vector<int> path(n, 0);
    rep(i, n) cin >> rt[i];
    dis[start] = 0;
    rt_num[start] = rt[start];
    int u, v, w;
    rep(i, m) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0, start});
    path[start] = 1;
    while (!qu.empty()) {
        auto p = qu.top();
        qu.pop();
        if (vis[p.second]) continue;
        vis[p.second] = 1;
        for (auto &e : g[p.second]) {
            if (dis[e.first] >= p.first + e.second) {
                if (dis[e.first] > p.first + e.second) {
                    path[e.first] = path[p.second];
                    rt_num[e.first] = rt_num[p.second] + rt[e.first];
                } else {
                    path[e.first] += path[p.second];
                    rt_num[e.first] = max(rt_num[e.first], rt_num[p.second] + rt[e.first]);
                }
                
                dis[e.first] = p.first + e.second;
                rt_num[e.first] = max(rt_num[e.first], rt_num[p.second] + rt[e.first]);
                qu.push({dis[e.first], e.first});
            }
        }
    }
    debug(rt);
    debug(dis);
    debug(rt_num);
    cout << path[end] << " " << rt_num[end];
}
int main() {
    // srand(time(0));
    // ios::sync_with_stdio(0);
    // cout.tie(0), cin.tie(0);
    justdoit();
    return 0;
}