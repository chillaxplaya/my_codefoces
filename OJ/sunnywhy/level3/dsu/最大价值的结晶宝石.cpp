/*
最大价值的结晶宝石
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-17 13:50:01
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
vector<int> wi;
int findp(int x) {
    return x == pa[x] ? x : pa[x] = findp(pa[x]);
}
void dsuunion(int x, int y) {
    int pax = findp(x);
    int pay = findp(y);
    if (wi[pay] > wi[pax]) {
        pa[pax] = pay;
    } else {
        pa[pay] = pax;
    }
}
void justdoit() {
    int n;
    cin >> n;
    pa.resize(n + 1);
    wi.resize(n + 1);
    vector<int> a(n);
    iota(all(pa), 0);
    rep(i, n) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> wi[i];
    }
    rep(i, n) {
        dsuunion(i + 1,a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (i - 1) cout << " ";
        cout << wi[findp(i)];
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