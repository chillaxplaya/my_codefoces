#include <bits/stdc++.h>
#include <cmath>
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
int n, m, s;
double V;
struct Edge{
    int u, v;
    double cost, rate;
}edge[205];
int idx = 0;
void addEdge(int u, int v, double r, double c) {
    edge[idx].u = u;
    edge[idx].v = v;
    edge[idx].rate = r;
    edge[idx++].cost = c;
}
bool bellman_ford() {
    vector<double> dis(n + 1, 0);
    dis[s] = V;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < idx; j++) {
            if(dis[edge[j].v] < (dis[edge[j].u] - edge[j].cost) * edge[j].rate) {
                dis[edge[j].v] = (dis[edge[j].u] - edge[j].cost) * edge[j].rate;
                
            }
        }
    }

    for (int j = 0; j < idx; j++) {
        if(dis[edge[j].v] < (dis[edge[j].u] - edge[j].cost) * edge[j].rate) {
            return true;
        }
    }
    return false;
}
void solve() {
    while (cin >> n >> m >> s >> V) {
        idx = 0;
        debug(n, m, s, V);
        int u, v;
        double ur, uc, vr, vc;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            cin >> ur >> uc >> vr >> vc;
            addEdge(u, v, ur, uc);
            addEdge(v, u, vr, vc);
            
        }
        if (bellman_ford()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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