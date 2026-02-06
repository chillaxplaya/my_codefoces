#include <bits/stdc++.h>
#include <vector>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
typedef pair<ll, ll> pi;

void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<vector<pi>> g(n);
    vector<ll> dis(n, 0x3f3f3f3f3f3f3f3f);
    vector<int> vis(n, 0);
    vector<int> pre(n, -1);
    int u, v, w;
    rep(i, m) {
        cin >> u >> v >> w;
        g[u - 1].push_back({v - 1, w});
        g[v - 1].push_back({u - 1, w});
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0LL, 0});
    dis[0] = 0;
    while (!qu.empty()) {
        auto p = qu.top();
        qu.pop();
        if (vis[p.second]) continue;
        vis[p.second] = 1;
        for (auto &e : g[p.second]) {
            if (!vis[e.first] && p.first + e.second < dis[e.first]) {
                dis[e.first] = p.first + e.second;
                pre[e.first] = p.second;
                qu.push({dis[e.first], e.first});
            }
        }
    }
    debug(dis);
    if (pre[n - 1] == -1) {
        cout << "-1\n";
        return;
    }
    int idx = n - 1;
    vector<int> res;
    while (idx != -1) {
        res.push_back(idx);
        idx = pre[idx];
    }
    reverse(all(res));
    for (auto &e : res) {
        cout << e + 1 << " ";
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