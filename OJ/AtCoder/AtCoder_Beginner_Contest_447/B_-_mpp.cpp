/*
B - mpp
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc447/tasks/abc447_b
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
    string s;
    vector<int> vis(26, 0);
    cin >> s;
    int maxc = 0;
    for (auto &e : s) {
        vis[e - 'a']++;
        if (vis[e - 'a'] > maxc) {
            maxc = vis[e - 'a'];
        }
    }
    for (auto &e : s) {
        if (vis[e - 'a'] == maxc) {
            continue;
        }
        cout << e;
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