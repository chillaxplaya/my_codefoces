/*
C. Good Subarrays
Time Limit: 2000ms Memory Limit: 256MB
URL: https://codeforces.com/problemset/problem/1398/C
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
    string a;
    int n;
    cin >> n;
    cin >> a;
    map<ll, ll> cnt;
    cnt[0] = 1;
    int s = 0;
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i - 1] - '0';
        debug(s - i);
        res += cnt[s - i]++;
    }
    cout << res << endl;
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