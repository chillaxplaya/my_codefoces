/*
B. 简单多项式乘法
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-06 19:33:50
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
    int d1, d2;
    
    cin >> d1;
    vector<ll> a1(d1 + 1);
    for (auto &e : a1) {
        cin >> e;
    }
    cin >> d2;
    vector<ll> a2(d2 + 1);
    for (auto &e : a2) {
        cin >> e;
    }
    vector<ll> res(1005, 0);
    for (int i = 0; i <= d1; i++) {

        for (int j = 0; j <= d2; j++) {
            res[i + j] += (a1[i] * a2[j]);
        }
    }
    int dres = 0;
    for (int i = 0; i < 700; i++) {
        if (res[i] != 0) {
            dres = i;
        }
    }
    cout << d1 + d2 << endl;
    for (int i = 0; i <= d1 + d2; i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    debug(res);
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