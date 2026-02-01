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
struct node {
    int to;
    int k;
    int w;
    node() : to(0), k(0), w(0) {}
    node(int _to, int _k, int _w) : to(_to), k(_k), w(_w) {}
};
typedef pair<int, int> pi;
set<int> res;
void solve() {
    int n, m, l, s, t;
    int from, to, cost;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pi>> g(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        g[from].push_back({to, cost});
    }
    debug(g);
    queue<node> qu;
    qu.push(node(1, 0, 0));
    while (!qu.empty()) {
        auto p = qu.front();
        qu.pop();
        if (p.k == l) {
            if (p.w >= s) {
                res.insert(p.to);
            }
            continue;
        }
        for (auto& e : g[p.to]) {
            if (p.w + e.second <= t) {
                qu.push(node(e.first, p.k + 1, p.w + e.second));
                debug(e.first, p.k + 1, p.w + e.second);
            }
        }
    }
    for (auto& e : res) {
        cout << e << " ";
    }
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