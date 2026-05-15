/*
逐步接近
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-13 16:27:18
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
int dis[3000][5];
void justdoit() {
    int s, t;
    cin >> s >> t;
    memset(dis, -1, sizeof(dis));
    queue<pi> qu;
    qu.push({s, 0});
    int ans = -1000;
    while (!qu.empty()) {
        auto [state, d] = qu.front();
        qu.pop();
        int tx = state;
        if (d == 5 && abs(state - t) < abs(ans - t)) {
            ans = state;
            debug(state);
            continue;
        }
        while (1) {
            int op = tx % 10;
            if (op + state <= 2025 && dis[op + state][d + 1] == -1) {
                qu.push({op + state, d + 1});
                dis[op + state][d + 1] = 1;
            }
            if (state - op >= 0 && dis[state - op][d + 1] == -1) {
                qu.push({state - op, d + 1});
                dis[state - op][d + 1] = 1;
            }
            if (op * state <= 2025 && dis[op * state][d + 1] == -1) {
                qu.push({op * state, d + 1});
                dis[op * state][d + 1] = 1;
            }
            if (op != 0 && state / op >= 0 && dis[state / op][d + 1] == -1) {
                qu.push({state / op, d + 1});
                dis[state / op][d + 1] = 1;
            }
            tx /= 10;
            if (tx == 0) break;
        }
    }
    cout << ans;
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