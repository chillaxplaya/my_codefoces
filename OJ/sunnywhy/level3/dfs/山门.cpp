/*
山门
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 18:11:50
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
string s;
int n;
int lim;
bool is_valid(int l, int r) {
    if (r - l <= 1) return true;
    r--;
    while (l < r) {
        if (s[l++] != s[r--]) {
            return false;
        }
    }
    return true;
}
bool dfs(int l) {
    if (l == n) {
        return true;
    }
    for (int i = lim; i + l <= n; i++) {
        debug(l, i + l, is_valid(l, i + l));
        if (is_valid(l, i + l) && dfs(i + l)) {
            
            return true;
        }
    }
    return false;
}
void justdoit() {
    cin >> s >> lim;
    n = s.size();
    cout << (dfs(0) ? "Yes" : "No");
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