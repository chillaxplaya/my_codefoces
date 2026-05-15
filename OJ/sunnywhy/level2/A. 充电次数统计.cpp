/*
A. 充电次数统计
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 19:31:25
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
    int n, s;
    string b;
    cin >> n >> s;
    int st = s;
    int cnt = 0;
    rep(i, n) {
        cin >> b;
        int t;
        if (b.size() == 1) {
            t = b[0] - '0';
        } else {
            t = b[0] - '0' + 1;
        }
        if (st >= t) {
            st -= t;
        } else {
            st = s - t;
            cnt++;
        }
        debug(st);
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