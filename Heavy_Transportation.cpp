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
#define INF 0x3f3f3f3f
typedef pair<int, int> pi;
int vis[1005];
int wi[1005];
int rd = 1;
void solve() {
    int n, m, x, y ,c;
    cin >> n >> m;
    vector<vector<pi>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        g[x - 1].push_back({y - 1, c});
        g[y - 1].push_back({x - 1, c});
    }
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        wi[i] = -INF;
    }
    wi[0] = INF;
    priority_queue<pi, vector<pi>, less<pi>> qu;
    qu.push({INF, 0});
    while (!qu.empty()) {
        auto p = qu.top();
        int choosed_node = p.second;
        int choosed_cost = p.first;
        qu.pop();
        if (vis[choosed_node]) continue;
        vis[choosed_node] = 1;
        for (auto e : g[choosed_node]) {
            int maxc = min(wi[choosed_node], e.second);
            if (wi[e.first] < maxc) {
                wi[e.first] = maxc;
                qu.push({maxc, e.first});
            }
        }
    }
    cout << "Scenario #" << rd++ << ":\n";
    cout << wi[n - 1] << "\n\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}