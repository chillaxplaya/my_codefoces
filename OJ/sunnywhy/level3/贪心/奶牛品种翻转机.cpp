/*
奶牛品种翻转机
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-07 12:26:48
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
    cin >> n;
    string a, b;
    cin >> a >> b;
    int diff = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (diff == 0) {
                res++;
            }
            diff = 1;
        } else {
            diff = 0;
        }
    }
    cout << res;
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