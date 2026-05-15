/*
牧场的多样化种植
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 15:19:54
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define endl '\n'

void justdoit() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    int u, v;
    int ans[n];
    rep(i, m) {
        cin >> u >> v;
        if (u < v) swap(u,v);
        g[u - 1].push_back(v - 1);
    }
    ans[0] = 1;
    debug(g);
    for (int i = 1; i < n;i++) {
        int vis[5] = {0 , 1, 1, 1, 1};
        for (auto &e : g[i]) {
            vis[ans[e]] = 0;
        }
        int j = 0;
        while(!vis[++j]);
        ans[i] = j;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        justdoit();
    return 0;
}