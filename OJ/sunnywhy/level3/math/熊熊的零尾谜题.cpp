/*
熊熊的零尾谜题
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-11 13:32:26
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
    int r, l;
    cin >> r >> l;
    int cnt = 1;
    int ans = 0;
    for (int i = l + 1; i <= r; i++) {
        cnt *= i;
        while (cnt % 10 == 0) {
            cnt /= 10;
            ans++;
        }
    }
    while (cnt % 10 == 0) {
        cnt /= 10;
        ans++;
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