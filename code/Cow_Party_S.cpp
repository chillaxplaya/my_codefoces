#include <bits/stdc++.h>
#include <cstring>
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
struct edge{
    int to;
    int w;
    int next;
}Edge[100005];
int head[100005];
int u[100005],v[100005],w[100005];
int vis0[100005];
int wi0[100005];
int vis1[100005];
int wi1[100005];
int idx = 0;
void addEdge(int x, int y, int c) {
    Edge[idx].next = head[x];
    Edge[idx].to = y;
    Edge[idx].w = c;
    head[x] = idx++;

}

void solve() {
    
    int n, m, x;
    cin >> n >> m >> x;
    idx = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        addEdge(u[i], v[i], w[i]);
    }
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    qu.push({0, x});
    memset(wi0, 0x3f, sizeof(wi0));
    wi0[x] = 0;
    while (!qu.empty()) {
        auto p = qu.top();
        
        int choosed_node = p.second;
        int choosed_cost = p.first;
        debug(choosed_node);
        qu.pop();
        if (vis0[choosed_node]) continue;
        vis0[choosed_node] = 1;
        debug(head[choosed_node]);
        for (int nextEdge = head[choosed_node]; nextEdge != -1; nextEdge = Edge[nextEdge].next) {
            debug(nextEdge, Edge[nextEdge].next);
            if (wi0[choosed_node] + Edge[nextEdge].w < wi0[Edge[nextEdge].to]) {
                wi0[Edge[nextEdge].to] = wi0[choosed_node] + Edge[nextEdge].w;
                qu.push({wi0[Edge[nextEdge].to], Edge[nextEdge].to});
            }
        }
    }
    while (!qu.empty()) qu.pop();
    memset(head, -1, sizeof(head));
    idx = 0;
    for (int i = 0; i < m; i++) {
        addEdge(v[i], u[i], w[i]);
    }
    memset(wi1, 0x3f, sizeof(wi1));
    
    wi1[x] = 0;
    qu.push({0, x});
    while (!qu.empty()) {
        auto p = qu.top();
        int choosed_node = p.second;
        int choosed_cost = p.first;
        qu.pop();
        if (vis1[choosed_node]) continue;
        vis1[choosed_node] = 1;
        for (int nextEdge = head[choosed_node]; nextEdge != -1; nextEdge = Edge[nextEdge].next) {
            if (wi1[choosed_node] + Edge[nextEdge].w < wi1[Edge[nextEdge].to]) {
                wi1[Edge[nextEdge].to] = wi1[choosed_node] + Edge[nextEdge].w;
                qu.push({wi1[Edge[nextEdge].to], Edge[nextEdge].to});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i ++) {
        ans = max(ans, wi0[i] + wi1[i]);
    }
    cout << ans << "\n";
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