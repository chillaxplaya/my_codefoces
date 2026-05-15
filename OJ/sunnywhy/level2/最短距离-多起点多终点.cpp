/*
最短距离-多起点多终点
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 17:59:04
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
int city[105][105];
void floyd() {
    int n, m;
    cin >> n >> m;
    int u, v, w;
    rep(i, n) {
        rep(j, n) {
            if (i == j) {
                city[i][j] = 0;
            } else {
                city[i][j] = INF;
            }
        }
    }
    rep(i, m) {
        cin >> u >> v >> w;
        city[u][v] = w;
        city[v][u] = w;
    }
    rep(k, n) {
        rep(i, n) {
            rep(j, n) {
                city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if (j) cout << ' ';
            cout << (city[i][j] != INF ? city[i][j] : -1);
        }
        cout << endl;
    }
}
void justdoit() {
    
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