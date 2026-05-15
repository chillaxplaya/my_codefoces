/*
寻找奶牛
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-05 17:56:53
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
    cin >> s;
    int n = s.size();
    int cntl = 0;
    int cntr = 0;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '(' && s[i + 1] == '(') {
            cntl++;
        }
        if (s[i] == ')' && s[i + 1] == ')') {
            cntr++;
            ans += cntl;
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