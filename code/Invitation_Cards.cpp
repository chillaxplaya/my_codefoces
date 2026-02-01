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
//（1≤P,Q≤1000000）
//CCS站点编号恒为1。票价均为正整数且总和小于1000000000
#define MAXN 1000005
typedef pair<int, int> pi;
int u[MAXN], v[MAXN], c[MAXN];
struct Edge{
    int to;
    int cost;
    int next;
}edge[MAXN];
int head[MAXN];
int idx = 0;
int vis[MAXN];
int dis0[MAXN];
int dis1[MAXN];
void addEdge(int x, int y, int c){
    edge[idx].to = y;
    edge[idx].cost = c;
    edge[idx].next = head[x];
    head[x] = idx++;
}
void solve() {
    idx = 0;
    memset(head, -1,sizeof(head));
    memset(vis, 0,sizeof(vis));
    int n, m;
    priority_queue<pi, vector<pi>, greater<pi>> qu;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        addEdge(u[i], v[i], c[i]);
    }
    memset(dis0, 0x3f, sizeof(dis0));
    dis0[1] = 0;
    qu.push({0, 1});
    while (!qu.empty()) {
        auto p = qu.top();
        qu.pop();
        if (vis[p.second]) continue;
        vis[p.second] = 1;
        for (int nextedge = head[p.second]; nextedge != -1; nextedge = edge[nextedge].next) {
            int nextcost = dis0[p.second] + edge[nextedge].cost;
            if (dis0[edge[nextedge].to] > nextcost) {
                dis0[edge[nextedge].to] = nextcost;
                qu.push({nextcost, edge[nextedge].to});
            }
        }
    }
    
    qu.push({0, 1});
    idx = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(dis1, 0x3f, sizeof(dis1));
    dis1[1] = 0;
    for (int i = 0; i < m; i++) {
        addEdge(v[i], u[i], c[i]);
    }
    while (!qu.empty()) {
        auto p = qu.top();
        qu.pop();
        if (vis[p.second]) continue;
        vis[p.second] = 1;
        for (int nextedge = head[p.second]; nextedge != -1; nextedge = edge[nextedge].next) {
            int nextcost = dis1[p.second] + edge[nextedge].cost;
            if (dis1[edge[nextedge].to] > nextcost) {
                dis1[edge[nextedge].to] = nextcost;
                qu.push({nextcost, edge[nextedge].to});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += (dis0[i] +dis1[i]);
    }
    cout << ans << "\n";
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