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
struct Edge {
    int u, v;
    double rate;
} edge[40005];
int idx = 0;
int n, m;
const double EPS = 1e-10;
bool spfa() {
    vector<double> dis(n + 1, 1.0L);
    vector<int> cnt(n + 1, 0);
    vector<char> inq(n + 1);

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        inq[i] = 1;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = 0;

        for (int i = 0; i < idx; i++) {
            if (edge[i].u != u) continue;
            int v = edge[i].v;
            double nd = dis[u] * edge[i].rate;

            if (nd > dis[v] + EPS) {
                debug(nd);
                dis[v] = nd;
                
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = 1;
                    if (++cnt[v] >= n) return true;
                }
            }
        }
    }
    return false;
}

bool bellman_ford(int x) {
    vector<double> dis(n + 1, 1.0);
    for (int i = 1; i < n; i++) {
        bool up = true;
        for (int j = 0; j < idx; j++) {
            if (dis[edge[j].u] * edge[j].rate > dis[edge[j].v] + +EPS) {
                dis[edge[j].v] = dis[edge[j].u] * edge[j].rate;
                up = false;
            }
        }
        if (up) { break; }
    }
    for (int j = 0; j < idx; j++) {
        if (dis[edge[j].u] * edge[j].rate > dis[edge[j].v] + EPS) {
            return true;
        }
    }
    return false;
}
void solve() {
    int u, v, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a >> b;
        edge[idx].u = u;
        edge[idx].v = v;
        edge[idx++].rate = (double)b / a;
    }
    if (spfa()) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}
int main() {
    idx = 0;
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}