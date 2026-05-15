/*
数字操作
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-04 00:26:14
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
int dis[100005];
void justdoit() {
    int n;
    cin >> n;
    int cnt = 0;
    int i = 1;
    queue<int> qu;
    qu.push(1);
    dis[1] = 0;
    while (!qu.empty()) {
        auto p = qu.front();
        qu.pop();
        if (p + 1 == n || p * 2 == n) {
            cout << dis[p] + 1;
            break;
        }
        if (!dis[p + 1]) {
            qu.push(p + 1);
            dis[p + 1] = dis[p] + 1;
        }
        if (p * 2 <= n && !dis[p * 2]) {
            qu.push(p * 2);
            dis[p * 2] = dis[p] + 1;
        }
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