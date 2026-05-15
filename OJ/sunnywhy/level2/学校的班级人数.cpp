/*
学校的班级人数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 12:20:24
*/
#include <bits/stdc++.h>
#include <functional>
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
vector<int> pa;
vector<int> sz;
int find(int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}
void unite(int x, int y) {
    int xp = find(x);
    int yp = find(y);
    if (xp == yp) {
        return;
    }
    if (sz[xp] > sz[yp]) {
        pa[yp] = xp;
        sz[xp] += sz[yp];
    } else {
        pa[xp] = yp;
        sz[yp] += sz[xp];
    }
}
void justdoit() {
    int n, k;
    cin >> n >> k;
    pa.resize(n + 1);
    sz.resize(n + 1);
    iota(all(pa), 0);
    fill(all(sz), 1);
    int x, y;
    rep(i, k) {
        cin >> x >> y;
        unite(x, y);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (pa[i] == i) {
            res.push_back(sz[i]);
        }
    }
    cout << res.size() << endl;
    sort(all(res), greater<>());
    for (int i = 0; i < res.size(); i++) {
        if (i) cout << ' ';
        cout << res[i];
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