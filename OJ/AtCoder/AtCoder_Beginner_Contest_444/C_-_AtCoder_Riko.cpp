/*
C - AtCoder Riko
Time Limit: 2000ms Memory Limit: 1024MB
URL: https://atcoder.jp/contests/abc444/tasks/abc444_c
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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (auto &e : a) {
        cin >> e;
        sum += e;
    }
    sort(all(a));
    vector<ll> res;
    if (n % 2 == 0 && sum % (n / 2) == 0 && sum / (n / 2) >= a[n - 1]) {
        res.push_back(sum / (n / 2));
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        if (sum % i == 0 && sum / i >= a[n - 1]) {
            int l = lower_bound(a.begin(), a.end(), sum / i) - a.begin();
            if (l < n && l + i - n / 2 - 1 < n) {
                if (a[l] == sum / i && a[l + i - n / 2 - 1] == sum / i && (l + i - n / 2 == n || a[l + i - n / 2 - 1] == sum / i)) {
                    res.push_back(sum / i);
                }
            }
        }
    }
    debug(res);
    reverse(all(res));
    for (auto &e : res) {
        cout << e <<" ";
    }
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