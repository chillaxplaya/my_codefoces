/*
学校的班级个数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 12:09:16
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
vector<int> pa;
int findp(int x) {
    return pa[x] == x ? x :pa[x] = findp(pa[x]);
}
void unite(int x, int y) {
    pa[findp(x)] = findp(y);
}
void justdoit() {
    int n, k;
    cin >> n >> k;
    pa.resize(n + 1);
    iota(pa.begin(), pa.end(), 0);
    int x, y;
    int cnt = 0;
    rep(i, k) {
        cin >> x >> y;
        unite(x, y);
    }
    for (int i = 1; i <= n; i++) {
        if (pa[i] == i) cnt++;
    }
    cout << cnt;
    
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