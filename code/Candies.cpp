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
//30,000
int vis[30005];
int dis[30005];
void solve() {
    int n, m, x, y, c;
    vector<vector<pi>> g;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> c;
        g[x].push_back({y, c});
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0, 0});
    
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