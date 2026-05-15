/*
关闭所有灯泡
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-15 00:38:19
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

int vis[1 << 18];
void justdoit() {
    int n;
    cin >> n;
    vector<int> op;
    if (n >= 2) {
        op.push_back(3);
        for (int i = 0; i <= n - 3; i++) {
            op.push_back(7 << i);
        }
        op.push_back(3 << (n - 2));
    } else {
        op.push_back(1);
    }
    int x;
    int state = 0;
    rep(i, n) {
        cin >> x;
        state = state << 1;
        state += x;
    }
    queue<pi> qu;
    qu.push({state, 0});
    while (!qu.empty()) {
        auto [s, d] = qu.front();
        qu.pop();
        if (s == 0) {
            cout << d << endl;
            return;
        }
        for (auto &ops : op) {
            if (!vis[s ^ ops]) {
                vis[s ^ ops] = 1;
                qu.push({s ^ ops, d + 1});
            }
        }
    }
    cout << -1;
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