#include <bits/stdc++.h>
#include <vector>
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
int cst[1005][1005];
int cs1[1005];
int vis[1005];
int dfsvis[1005];
int road = 0;
int maxk = 0x3fffff;
void dfs(vector<vector<int>> &Map, int now,int n, int k, int ncos,const int &mmax) {
    if(ncos > mmax) return;
    if(now == 2) {
        if (ncos != mmax) return;
        debug("in", now, ncos, k);
        road++;
        if (k < maxk) maxk = k;
        return;
    }
    debug(now, ncos, k);
    for(auto &e : Map[now]) {
        debug(now, e);
        if (dfsvis[e] == 0) {
            dfsvis[e] = 1;
            dfs(Map, e, n, k + 1, ncos + cst[now][e], mmax);
            dfsvis[e] = 0;
        }
    }
}
void solve() {
    int n, m;
    int x, y, cost;
    
    cin >> n >> m;
    vector<vector<int>> Map(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> cost;
        Map[x].push_back(y);
        Map[y].push_back(x);
        cst[x][y] = cst[y][x] = cost;
    }
    
    for (int i = 1; i <= n; i++) {
        cs1[i] = 0x3fffff;
    }
    for (auto e : Map[1]) {
        cs1[e] = cst[1][e];
    }
    vis[1] = 1;
    cs1[1] = 0;
    queue<int> qu;
    qu.push(1);
    dfsvis[1] = 1;
    while(!qu.empty()) {
        int now = qu.front();
        qu.pop();
        for (auto e : Map[now]) {
            if(cs1[e] > cs1[now] + cst[now][e]) {
                cs1[e] = cs1[now] + cst[now][e];
            }
        }
        int mi = -1, mincos = 0x3fffff;
        for (int i = 2; i <= n; i++) {
            if (cs1[i] < mincos && !vis[i]) {
                mi = i;
                mincos = cs1[i];
            }
        }
        if (mi == -1) break;
        vis[mi] = 1;
        qu.push(mi);
    }
    if (cs1[2] == 0x3fffff) {
        cout << "0 0\n";
        return;
    }
    dfs(Map, 1, n, 0, 0, cs1[2]);
    
    cout << road << " " << maxk + 1 << "\n";
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