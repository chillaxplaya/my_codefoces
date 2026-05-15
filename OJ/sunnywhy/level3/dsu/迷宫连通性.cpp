/*
迷宫连通性
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-16 14:45:34
user: playa
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
typedef pair<int, int> pi;
vector<int> pa;
int findp(int x) {
    return x == pa[x] ? x : pa[x] = findp(pa[x]);
}
void dsuunion(int x, int y) {
    if (x < y) swap(x, y);
    int pax = findp(x);
    int pay = findp(y);
    if (pax != pay)
        pa[pax] = pa[pay];
}
void justdoit() {
    int n, m;
    cin >> n >> m;
    pa.resize(n + 1);
    iota(pa.begin(), pa.end(), 0);
    int u, v;
    rep(i, m) {
        cin >> u >> v;
        dsuunion(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (pa[i] == i) cnt++;
    }
    cout << (cnt == 1 ? "Yes" : "No");
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