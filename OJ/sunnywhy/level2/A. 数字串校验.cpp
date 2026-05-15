/*
A. 数字串校验
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-03 19:32:26
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
    int cnt = 1;
    int res = 0;
    for (int i = s.length() - 1; i >=0; i--) {
        if (cnt % 2) {
            res += (s[i] - '0');
            debug((s[i] - '0'));
        } else {
            int t = (s[i] - '0');
            t *= 2;
            if (t < 10) {
                res += t;
            } else {
                res += (t % 10 + t / 10);
            }
            debug(t);
        }
        cnt++;
    }
    
    cout << (res % 10 ? "NO" : "YES");
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