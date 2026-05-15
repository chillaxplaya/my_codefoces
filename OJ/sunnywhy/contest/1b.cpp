/*
1b
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-02 19:30:21
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
bool vis[26];

void justdoit() {
    string s, p;
    cin >> s >> p;
    int cnt = 0;
    rep(i, 26) {
        vis[i] = false;
    }
    int sum = 0;
    for (auto &check : s) {
        if (vis[check - 'A'] == false) {
            sum++;
            vis[check - 'A'] = true;
        }
    }
    rep(i, 26) {
        vis[i] = false;
    }
    for (auto &check : p) {
        if (s.find(check) != string::npos) {
            sum--;
            if (sum == 0) {
                break;
            }
        } else {
            cnt++;
            if (cnt == 10) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES";
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