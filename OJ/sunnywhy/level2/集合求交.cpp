/*
集合求交
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 15:07:52
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
    int n, m, x;
    cin >> n >> m;
    set<int> a;
    set<int> b;
    rep(i, n) {
        cin >> x;
        a.insert(x);
    }
    rep(i, m) {
        cin >> x;
        b.insert(x);
    }
    set<int> c;
    for (auto &e : b) {
        if (a.count(e)) {
            c.insert(e);
        }
    }
    bool first = true;
    for (auto &e : c) {
        if (!first) cout << ' ';
        cout << e;
        first = false;
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