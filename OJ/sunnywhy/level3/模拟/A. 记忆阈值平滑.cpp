/*
A. 记忆阈值平滑
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 19:31:46
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
#define eps 1E-12
int state[1005];
void justdoit() {
    double a, b;
    cin >> a >> b;
    double c;
    while (cin >> c) {
        if (!(abs(c - 0) > eps) && c - 1.0 < -eps) {
            cout << 0 << endl;
        } else if (c - 1.0 < -eps) {
            cout << 1 << endl;
        } else {
            int t = (int)c;
            c = (c - (int)c);
            if (c - a < eps) {
                state[t] = 0;
                cout << t << endl;
            } else if (b - c < eps) {
                c = (c - (int)c);
                state[t] = 1;
                cout << t + 1 << endl;
            } else {
                debug("no");
                cout << t + state[t] << endl;
            }
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