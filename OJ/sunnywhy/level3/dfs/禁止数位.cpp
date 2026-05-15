/*
禁止数位
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-12 14:25:29
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
int oknum[10];
string s;
bool dfs(string num ,int k, int n) {
    if (k == 0) {
        if (num.size() > s.size() || num > s) {
            cout << num;
            return true;
        } else {
            return false;
        }
    }
    for (int i = 0; i <= 9; i++) {
        if (!oknum[i] && (i != 0 || k != n) && dfs(num + (char)(i + '0'), k - 1, n)) {
            return true;
        }
    }
    return false;
}
void justdoit() {
    int num, n, x;
    cin >> s >> n;
    rep(i, n) {
        cin >> x;
        oknum[x] = 1;
    }
    if (dfs("", s.size(), s.size())) {
        return;
    }
    dfs("", s.size() + 1, s.size() + 1);
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