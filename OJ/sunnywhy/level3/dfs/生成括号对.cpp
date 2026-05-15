/*
生成括号对
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 18:35:48
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
int n;
void dfs(string s, int left, int right) {
    if (left == n && right == n) {
        cout << s << endl;
    }
    if (left <= n) {
        dfs(s + "(", left + 1, right);
    }
    if (right < left) {
        dfs(s + ")", left, right + 1);
    }
}
void justdoit() {
    cin >> n;
    dfs(string(""), 0, 0);
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