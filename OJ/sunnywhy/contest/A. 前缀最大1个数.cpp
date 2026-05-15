/*
A. 前缀最大1个数
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-10 19:32:58
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
int cntx(int x) {
    int cnt = 0;
    while(x) {
        if (x & 1) {
            cnt++;
        }
        x /= 2;
    }
    return cnt;
}
void justdoit() {
    int x;
    cin >> x;
    int ans = 0;
    while (x) {
        ans = max(ans, cntx(x));
        x /= 10;
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