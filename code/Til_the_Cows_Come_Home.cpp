#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n) \
    cerr << "[" << #a << "] = {"; \
    for (int i = 0; i < (n); i++) cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";


#define all(x) (x).begin(), (x).end()
#define ll long long
typedef pair<int, int> pi;
void solve() {
    int n, t, x, y, c;
    cin >> t >> n;
    vector<vector<pi>> g(n);
    vector<int> vis(n);
    vector<int> dis(n, 0x3f3f3f3f);
    for (int i = 0; i < t; i++) {
        cin >> x >> y >> c;
        g[x - 1].push_back({y - 1, c});
        g[y - 1].push_back({x - 1, c});
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0, n - 1});
    while (!qu.empty()) {
        auto p = qu.top();
        qu.pop();
        int choosed_node = p.second;
        int wi = p.first;
        if (vis[choosed_node]) continue;
        vis[choosed_node] = 1;
        for (auto e : g[choosed_node]) {
            if(dis[e.first] > wi + e.second) {
                dis[e.first] = wi + e.second;
                qu.push({dis[e.first], e.first});
            }
        }
    }
    cout << dis[0];
    
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}