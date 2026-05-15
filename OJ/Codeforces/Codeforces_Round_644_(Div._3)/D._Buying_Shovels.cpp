/*
D. Buying Shovels
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1360/D
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

void justdoit() {
    debug("------");
    int n, k;
    cin >> n >> k;
    debug(n, k);
    if (k >= n) {
        cout << 1 << "\n";
        return;
    }
    int sq = sqrt(n);
    sq = min(sq, k);
    int res = 1;
    for (int i = sq; i >= 1; i--) {
        if (n % i == 0) {
            res = max(res, max(i, (n / i) > k ? i : n / i));
            debug((n / i) > k ? i : n / i);
            debug(res);
        }
    }
    
    cout << n / res  << "\n";
}
int main() {
    // srand(time(0));
    ios::sync_with_stdio(0);
    cout.tie(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        justdoit();
    return 0;
}