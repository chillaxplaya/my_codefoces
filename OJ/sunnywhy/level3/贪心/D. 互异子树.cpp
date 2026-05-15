/*
D. 互异子树
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 20:16:28
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
vector<int> wi;
vector<vector<int>> g;
vector<vector<int>> wg;
int res = 0;
int dfs(int n) {
    wg[n].push_back(wi[n]);
    bool ok = true;
    debug(n);
    for (auto &e : g[n]) {
        if (!dfs(e)) {
            ok = false;
        }
        for (auto &e1 : wg[e]) {
            wg[n].push_back(e1);
        }
    }
    if (!ok) return 0;
    sort(all(wg[n]));
    for (int i = 1; i < wg[n].size(); i++) {
        if (wg[n][i] == wg[n][i - 1]) {
            return 0;
        }
    }
    res++;
    return 1;
}
void justdoit() {
    int n;
    cin >> n;
    wi.resize(n);
    g.resize(n);
    wg.resize(n);
    for (auto &e : wi) {
        cin >> e;
    }
    int c, v;
    for (int i = 0; i < n; i++) {
        cin >> c;
        for (int j = 0; j < c; j++) {
            cin >> v;
            g[i].push_back(v - 1);
        }
    }
    
    dfs(0);
    debug(wg);
    cout << res;
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