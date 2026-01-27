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
struct Edge{
    int u, v;
    int c;
}edge[5205];
int idx;
int n, m ,w, x, y, c;
#define INF 0x3f3f3f3f
bool bellman(int x) {
    vector<int> dis(n + 1, 0);
    dis[x] = 0;
    for (int i = 1; i < n; i++) {
        bool up = false;
        for(int j = 0; j < idx; j++) {
            if (dis[edge[j].u] != INF && dis[edge[j].v] > dis[edge[j].u] + edge[j].c) {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].c;
                up = true;
            }
        }
        if (!up) break;
    }
    for(int j = 0; j < idx; j++) {
        if (dis[edge[j].u] != INF && dis[edge[j].v] > dis[edge[j].u] + edge[j].c) {
            return true;
        }
    } 
    return false;
}
void solve() {
    idx = 0;
    
    cin >> n >> m >> w;
    for (int i = 0; i < m;i++) {
        cin >> x >> y >> c;
        edge[idx].u = x;
        edge[idx].v = y;
        edge[idx++].c = c;
        edge[idx].u = y;
        edge[idx].v = x;
        edge[idx++].c = c;
    }
    for (int i = 0; i < w;i++) {
        cin >> x >> y >> c;
        edge[idx].u = x;
        edge[idx].v = y;
        edge[idx++].c = -c;
    }
        if (bellman(1)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
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