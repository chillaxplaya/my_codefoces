/*
B - Digit Sum
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc444/tasks/abc444_b
*/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

#define debug_arr(a, n)                 \
    cerr << "[" << #a << "] = {";       \
    for (int i = 0; i < (n); i++)       \
        cerr << (i ? "," : "") << a[i]; \
    cerr << "}\n";

#define all(x) (x).begin(), (x).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
int sumk(int x) {
    int sum = 0;
    while (x) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}
void justdoit() {
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        debug(sumk(i));
        if (sumk(i) == k) res++;
    }
    cout << res << "\n";
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