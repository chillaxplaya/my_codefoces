/*
最优装箱
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 16:54:13
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
    int n, w;
    cin >> n >> w;
    int temp_w = w;
    vector<int> a(n);
    for (auto &e : a) {
        cin >> e;
    }
    sort(all(a));
    int cnt = 0;
    debug(a);
    for (auto &e : a) {
        if (w >= e) {
            w -= e;
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt << " " << temp_w - w;
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