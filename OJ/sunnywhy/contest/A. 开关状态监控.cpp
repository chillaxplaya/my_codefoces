/*
A. 开关状态监控
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-09 19:33:03
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
    int n;
    map<string, int> dic;
    cin >> n;
    string op, dev;
    rep(i, n) {
        cin >> op >> dev;
        if (!dic.count(dev)) dic[dev] = 0;
        if (op == "open") {
            cout << dev << " opened";
            if (dic[dev] == 1) {
                cout << " (ANOMALY)";
            }
            cout << endl;
            dic[dev] = 1;
        } else {
            cout << dev << " closed";
            if (dic[dev] == 0) {
                cout << " (ANOMALY)";
            }
            cout << endl;
            dic[dev] = 0;
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