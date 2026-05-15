/*
A. 数位乘积核
Time Limit: ${timeLimit}ms Memory Limit: ${memoryLimit}MB
URL: ${url}
date: 2026-03-06 19:30:20
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
int change(int x) {
    int res = 1;
    while(x) {
        if (x % 10) {
            res *= (x % 10);
        }
        x /= 10;
    }
    return res;
}
void justdoit() {
    int x;
    cin >> x;
    while(x > 9) {
        x = change(x);
    }
    cout << x;
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