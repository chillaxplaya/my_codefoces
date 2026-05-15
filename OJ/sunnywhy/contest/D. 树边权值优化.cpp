/*
D. 树边权值优化
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 21:17:48
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
    int n, c, u, v ,w;
    cin >> n >> c;
    int maxl = 0;
    vector<vector<pair<int, int>>> g(n + 1);
    vector<int> wi(n);
    vector<int> node(n + 1, 0);
    rep(i, n - 1) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        maxl = max(w, maxl);
        wi[i] = w;
        node[u]++;
        node[v]++;
    }
    int ans = 0;
    rep(i, n - 1) {
        ans += maxl - wi[i];
    }
    int tempans = 0;
    for (int i = 1; i <= n; i++) {
        if (node[i] > 1) {
            bool need = false;
            for (int j = 1; j < g[i].size(); j++) {
                if (g[i][j].second != g[i][j - 1].second) {
                    need = true;
                }
            }
            if (need)
                tempans += c * node[i];
        }
    }
    cout << min(ans, tempans);
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