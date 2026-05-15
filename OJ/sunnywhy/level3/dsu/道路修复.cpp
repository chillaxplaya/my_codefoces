/*
道路修复
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-17 13:59:21
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
vector<int> dsusz;
int findp(int x) {
    int tx = x;
    while(pa[tx] != tx) {
        tx = pa[tx];
    }

    while(x != pa[x]) {
        int tp = pa[x];
        pa[x] = tx;
        x = tp;
    }
    return tx;
}
void dsuunion(int x, int y) {
    int pax = findp(x);
    int pay = findp(y);
    if (pax == pay) return;
    if (dsusz[pax] >= dsusz[pay]) {
        pa[pay] = pax;
        dsusz[pax] += dsusz[pay];
    } else {
        pa[pax] = pay;
        dsusz[pay] += dsusz[pax];
    }
}
void justdoit() {
    int n, m;
    cin >> n >> m;
    pa.resize(n + 1);
    dsusz.resize(n + 1);
    fill(all(dsusz), 1);
    iota(all(pa), 0);
    int u, v;
    rep(i, m) {
        cin >> u >> v;
        dsuunion(u, v);
    }
    int anssz = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i == pa[i]) {
            cnt++;
            if (dsusz[i] > anssz)
                anssz = dsusz[i];
        }
    }
    cout << cnt << " " << anssz << endl;
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